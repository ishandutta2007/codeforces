#include <bits/stdc++.h>
using namespace std;

const int N = 330000;

int prv[N], nxt[N];
long long d[N], c[N], diff[N];
long long f[19][N], g[19][N];

inline long long get_max(int l, int r) {
	int k = 31 - __builtin_clz(r-l+1);
	return max(f[k][l], f[k][r-(1<<k)+1]);
}

inline long long get_min(int l, int r) {
	int k = 31 - __builtin_clz(r-l+1);
	return min(g[k][l], g[k][r-(1<<k)+1]);
}

int main() {
	ios::sync_with_stdio(0);
	int n, A; cin >> n >> A;
	long long ans = 0;
	for (int i = 1; i <= n; i++) cin >> d[i] >> c[i], c[i] = A - c[i], ans = max(ans, c[i]);
	for (int i = 1; i < n; i++) diff[i] = d[i + 1] - d[i];
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		while (j && diff[i] >= diff[j]) j = prv[j];
		prv[i] = j;
	}
	for (int i = n - 1; i > 0; i--) {
		int j = i + 1;
		while (j < n && diff[i] >= diff[j]) j = nxt[j];
		nxt[i] = j;
	}
	for (int i = 1; i <= n; i++) c[i] += c[i - 1], f[0][i] = g[0][i] = c[i];
	for (int i = 1; i < 19; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = f[i-1][j];
			g[i][j] = g[i-1][j];
			if (j + (1<<i-1) <= n) {
				f[i][j] = max(f[i][j], f[i-1][j+(1<<i-1)]);
				g[i][j] = min(g[i][j], g[i-1][j+(1<<i-1)]);
			}
		}
	}
	for (int i = 1; i < n; i++) ans = max(ans, get_max(i + 1, nxt[i]) - get_min(prv[i], i - 1) - diff[i] * diff[i]);
	cout << ans << endl;
	return 0;
}