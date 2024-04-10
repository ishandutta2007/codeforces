#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 19];
long long B[1 << 20];

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		B[A[i] - i + (1 << 19)] += A[i];
	}
	long long maxn = 0;
	for (int i = 0; i < (1 << 20); i++) maxn = max(maxn, B[i]);
	cout << maxn << endl;
	return 0;
}