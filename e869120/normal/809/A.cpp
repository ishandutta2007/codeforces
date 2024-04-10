#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 19], ans = 0, sum = 0, r = 1, mod = 1000000007;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	sort(A, A + N);

	r = 2;
	for (int i = N - 1; i >= 0; i--) {
		sum += A[i]; sum %= mod;
		ans += (sum - A[i] * (r - 1LL)); ans += mod * mod; ans %= mod;
		r *= 2; r %= mod;
		sum *= 2; sum %= mod;
	}
	if (ans % 2 == 1) ans += mod;
	cout << ans / 2 << endl;
	return 0;
}