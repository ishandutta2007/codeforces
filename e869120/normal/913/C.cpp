#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, L, A[100];

long long solve(long long B) {
	long long sum = 0;
	long long S = B / (1LL << (N - 1));
	sum += S * A[N - 1]; B -= S * (1LL << (N - 1));
	for (int i = N - 1; i >= 0; i--) {
		if ((B / (1LL << i)) % 2 == 1) sum += A[i];
	}
	return sum;
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 1; i < N; i++) A[i] = min(A[i], A[i - 1] * 2);

	long long ans = (1LL << 60);
	while (L <= (1LL << 32)) {
		ans = min(ans, solve(L));
		L += (L&-L);
	}
	cout << ans << endl;
	return 0;
}