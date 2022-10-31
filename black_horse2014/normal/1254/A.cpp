#include <bits/stdc++.h>
using namespace std;
 
const int N = 110;
 
char pat[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char a[N][N], ans[N][N];
int b[N * N];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n, m, k; cin >> n >> m >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) ans[i][j] = 0;
		int tot = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) tot += a[i][j] == 'R';
		for (int i = 0; i < k; i++) b[i] = tot / k;
		tot %= k;
		for (int i = 0; i < k && tot; i++) b[i]++, tot--;
		b[k] = 1e9 + 7;
		int cur = 0, now = 0;
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < m; j++) {
				now += a[i][j] == 'R';
				if (cur < k) ans[i][j] = pat[cur];
				if (now == b[cur]) now = 0, cur++;
			}
			if (i + 1 < n) {
				for (int j = m - 1; j >= 0; j--) {
					now += a[i + 1][j] == 'R';
					if (cur < k) ans[i + 1][j] = pat[cur];
					if (now == b[cur]) now = 0, cur++;
				}
			}
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!ans[i][j]) ans[i][j] = pat[cur - 1];
		for (int i = 0; i < n; i++) cout << ans[i] << "\n";
	}
	
	return 0;
}