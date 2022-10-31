#include <bits/stdc++.h>
using namespace std;

const int N = 1100000;
const int MOD = 1e9 + 7;

long long sqr[N];
int ssqr[N], c2[N], c3[N], s2[N], s3[N], t2[N], t3[N];

int main() {
	long long M; scanf("%lld", &M);
	for (int x = 0; x < N; x++) sqr[x] = 1LL * x * x;
	for (int x = 1; x < N; x++) ssqr[x] = (ssqr[x - 1] + sqr[x]) % MOD;
	for (int x = 1; x < N; x++) {
		int cur = 1LL * x * x % MOD;
		s2[x] = (s2[x - 1] + 1LL * cur * (cur - 1)) % MOD;
	}
	const int R2 = (MOD + 1) / 2, R3 = (MOD + 1) / 3, R4 = (MOD + 1) / 4, R6 = (MOD + 1) / 6;
	for (int x = 1; x < N; x++) {
		int cur = 1LL * x * x % MOD;
		s3[x] = (s3[x - 1] + 1LL * cur * (cur - 1) % MOD * R3 % MOD * (cur - 2)) % MOD;
	}
	t2[0] = 2;
	for (int x = 1; x < N; x++) {
		int cur = (sqr[x] + MOD - 1) % MOD;
		cur = (3LL * cur * cur + MOD - 1) % MOD;
		t2[x] = (t2[x - 1] + 2LL * cur) % MOD;
	}
	t3[0] = -3;
	for (int x = 1; x < N; x++) {
		int cur = (sqr[x] + MOD - 1) % MOD;
		t3[x] = (t3[x - 1] + 6LL * cur) % MOD;
	}
	int m = M % MOD;
	int A = (1LL * m * (m + 1) / 2 % MOD * m % MOD - 1LL * m * (m + 1) % MOD * (m - 1) % MOD * R3 % MOD + MOD) % MOD;
	int ans = 0;
	for (int x = 0; x < N && sqr[x] <= M; x++) {
		int y = upper_bound(sqr, sqr + N, M - sqr[x]) - sqr - 1;
		int x2 = sqr[x] % MOD;
		int x4 = 1LL * x2 * x2 % MOD;
		int x6 = 1LL * x2 * x4 % MOD;
		int sum2 = s2[y];
		sum2 = (sum2 + 1LL * x4 * (2 * y + 1) % MOD * R2) % MOD;
		sum2 = (sum2 + 2LL * x2 * ssqr[y]) % MOD;
		sum2 = (sum2 + 1LL * x2 * (MOD - R2) % MOD * (2 * y + 1)) % MOD;
		int sum3 = s3[y];
		sum3 = (sum3 + t2[y] * 1LL * R6 % MOD * x2) % MOD;
		sum3 = (sum3 + t3[y] * 1LL * R6 % MOD * x4) % MOD;
		sum3 = (sum3 + x6 * 1LL * R6 % MOD * (2 * y + 1)) % MOD;
		int add = ((2 * y + 1) * 1LL * A + sum2 * 1LL * (MOD - m) + sum3 * 2LL) % MOD;
		if (x == 0) ans = (ans + add) % MOD;
		else ans = (ans + 2LL * add) % MOD;
	}
	cout << ans << endl;
	return 0;
}