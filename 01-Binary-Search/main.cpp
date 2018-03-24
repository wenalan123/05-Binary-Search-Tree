#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;

// ���ֲ��ҷ�,����������arr��,����target
// ����ҵ�target,������Ӧ������index
// ���û���ҵ�target,����-1
template<typename T>
int binarySearch(T arr[], int n, T target){
	// ��arr[l...r]֮�в���target
	int l = 0, r = n - 1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (target == arr[mid])
			return	mid;
		else if (target < arr[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	return -1;

}

//�õݹ�ķ���д���ֲ��ҷ�
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target){
	int mid = l + (r - l) / 2;
	if (l > r)
		return -1;
	if (target == arr[mid])
		return	mid;
	else if (target < arr[mid])
		__binarySearch2(arr, l, mid - 1, target);
	else
		__binarySearch2(arr, mid + 1, r, target);
}


template<typename T>
int binarySearch2(T arr[], int n, T target){
	return __binarySearch2(arr, 0, n - 1, target);
}


int main(){
	int n = 1000000;
	int* a = new int[n];
	for (int i = 0; i < n; i++){
		a[i] = i;
	}
	//���Էǵݹ���ַ����ҷ�
	clock_t	startTime = clock();
	for (int i = 0; i < 2*n; i++){
		int v = binarySearch(a, n, i);
		if (i < n)
			assert(v == i);
		else
			assert(v == -1);
	}
	clock_t endTime = clock();
	cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;


	//���Եݹ���ַ����ҷ�
	startTime = clock();
	for (int i = 0; i < 2 * n; i++){
		int v = binarySearch2(a, n, i);
		if (i < n)
			assert(v == i);
		else
			assert(v == -1);
	}
	endTime = clock();
	cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

	delete[] a;

	getchar();
	return 0;
}