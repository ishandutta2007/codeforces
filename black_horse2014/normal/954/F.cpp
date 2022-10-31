#include <bits/stdc++.h>
using namespace std;

const int N = 11000;
const int MOD = 1e9 + 7;

int d[3][3], e[3][3], f[3][3], a[N], used[3][2*N];
long long l[N], r[N], x[2*N];
int dp[3][2*N];

void modMul(int x[3][3], int y[3][3]) {
	memset(d, 0, sizeof d);
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			long long temp = 0;
			for (int l = 0; l < 3; l++) {
				temp += x[j][l] * 1LL * y[l][k];
			}
			d[j][k] = temp % MOD;
		}
	}
	memcpy(x, d, sizeof d);
}

void modExp(int e[3][3], long long n, int f[3][3]) {
	if (n == 0) return;
	for (int i = 62; i >= 0; i--) {
		if ((1LL<<i) > n) continue;
		modMul(f, f);
		if (n>>i&1) modMul(f, e);
	}
}

int main() {
	int n; long long m; scanf("%d%lld", &n, &m);
	int xn = 0;
	x[xn++] = 1, x[xn++] = m;
	for (int i = 1; i <= n; i++) {
		scanf("%d%lld%lld", &a[i], &l[i], &r[i]);
		a[i]--, x[xn++] = l[i], x[xn++] = r[i]+1;
	}
	sort(x, x + xn);
	xn = unique(x, x + xn) - x;
	for (int i = 1; i <= n; i++) {
		l[i] = lower_bound(x, x + xn, l[i]) - x;
		r[i] = lower_bound(x, x + xn, r[i]+1) - x;
		for (int j = l[i]; j < r[i]; j++) used[a[i]][j] = 1;
	}
	dp[1][0] = 1;
	for (int j = 0; j < xn-1; j++) {
		memset(e, 0, sizeof e);
		for (int k = 0; k < 3; k++) {
			for (int l = 0; l < 3; l++) {
				if (abs(k - l) > 1) continue;
				if (used[k][j] || used[l][j]) continue;
				e[k][l] = 1;
			}
		}
		for (int k = 0; k < 3; k++) for (int l = 0; l < 3; l++) f[k][l] = (k == l);
		modExp(e, x[j+1] - x[j] - 1, f);
		int temp[3] = {0};
		for (int k = 0; k < 3; k++) if (dp[k][j]) {
			for (int l = 0; l < 3; l++) temp[l] = (temp[l] + dp[k][j] * 1LL * f[k][l]) % MOD;
		}
		for (int k = 0; k < 3; k++) {
			for (int l = 0; l < 3; l++) {
				if (abs(k - l) > 1) continue;
				if (used[l][j+1]) continue;
				dp[l][j+1] = (dp[l][j+1] + temp[k]) % MOD;
			}
		}
//		cout << "x = " << x[j] << ' ' << x[j+1] << endl;
//		for (int k = 0; k < 3; k++) cout << dp[k][j] << ' ';
//		cout << endl;
	}
	cout << dp[1][xn-1] << endl;
	return 0;
}