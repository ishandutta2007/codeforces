#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 19];

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < 2 * N; i++) scanf("%lld", &A[i]);
	sort(A, A + 2 * N);
	
	long long ret = (A[N - 1] - A[0])*(A[2 * N - 1] - A[N]);
	for (int i = 1; i < N; i++) ret = min(ret, (A[2 * N - 1] - A[0])*(A[i + (N - 1)] - A[i]));
	cout << ret << endl;
	return 0;
}