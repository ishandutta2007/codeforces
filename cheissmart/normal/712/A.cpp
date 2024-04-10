#include <iostream>
#define inArr(A, n) for(int i=0;i<n;i++) cin >> A[i]

using namespace std;

int a[1005487];

int main()
{
	int n;
	cin >> n;
	inArr(a, n);
	for(int i=0;i<n;i++) cout << a[i] + a[i+1] << " ";
}