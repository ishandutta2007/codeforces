#include <bits/stdc++.h>
using namespace std;

long long N, M, K, A[1 << 18];

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	sort(A, A + N);
	reverse(A, A + N);
	long long E1 = M / (K + 1LL);
	long long E2 = M - E1;
	cout << A[0] * E2 + A[1] * E1 << endl;
	return 0;
}