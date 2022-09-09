#include<bits/stdc++.h>
using namespace std;
#define MAXN	305
#define P	1000000007
long long fac[MAXN], inv[MAXN];
long long C[MAXN][MAXN];
long long ans[MAXN][MAXN];
int n, value[MAXN], cnt[MAXN], sum[MAXN];
long long power(long long x, long long y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
void init() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fac[i] = fac[i - 1] * i % P;
	inv[MAXN - 1] = power(fac[MAXN - 1], P - 2);
	for (int i = MAXN - 2; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % P;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j <= i; j++)
			C[i][j] = fac[i] * inv[j] % P * inv[i - j] % P;
}
int main() {
	init();
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
		int tmp = value[i], ans = 1, j = 2;
		while (j * j <= tmp) {
			if (tmp % j == 0) {
				int cnt = 0;
				while (tmp % j == 0) {
					tmp /= j;
					cnt++;
				}
				if (cnt & 1) ans *= j;
			}
			j++;
		}
		if (tmp != 1) ans *= tmp;
		value[i] = ans;
	}
	sort(value + 1, value + n + 1);
	int now = 1, m = 0;
	for (int i = 2; i <= n; i++) {
		if (value[i] == value[i - 1]) now++;
		else {
			cnt[++m] = now;
			now = 1;
		}
	}
	cnt[++m] = now;
	n = m;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + cnt[i];
	ans[1][cnt[1] - 1] = fac[cnt[1]];
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= sum[i]; j++) {
			long long tmp = ans[i][j] * fac[cnt[i + 1]] % P;
			for (int k = 0; k <= j && k <= cnt[i + 1]; k++)
				for (int l = 1; l <= cnt[i + 1]; l++) {
					ans[i + 1][j + cnt[i + 1] - k - l] += tmp * C[j][k] % P * C[cnt[i + 1] - 1][l - 1] % P * C[sum[i] + 1 - j][l - k] % P;
					ans[i + 1][j + cnt[i + 1] - k - l] %= P;
				}
		}
	cout << ans[n][0] << endl;
	return 0;
}