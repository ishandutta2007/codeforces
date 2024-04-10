#include <iostream>

using namespace std;

int n,m,k;
int g[100][100];
int row_diff[100][100];

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(n > m) cin >> g[i][j];
			else cin >> g[j][i];
		}
	}
	if(n < m) swap(n,m);
	for(int i = 0; i < n; ++i) {
		row_diff[i][i] = 0;
		for(int j = i+1; j < n; ++j) {
			row_diff[i][j] = 0;
			for(int k = 0; k < m; ++k)
				row_diff[i][j] += g[i][k] != g[j][k];
			row_diff[j][i] = row_diff[i][j];
		}
	}
	int ans = k+1;
	if(n <= k) {
		for(int mask = (1<<m)-1; mask >= 0; --mask) {
			int disc = 0;
			for(int i = 0; i < n; ++i) {
				int dt = 0;
				for(int j = 0; j < m; ++j) {
					dt += g[i][j] != !!(mask&(1<<j));
				}
				disc += min(dt, m-dt);
			}
			ans = min(ans, disc);
		}
	} else {
		for(int i1 = 0; i1 < n; ++i1) {
			int disc = 0;
			for(int i2 = 0; i2 < n; ++i2) {
				disc += min(row_diff[i1][i2], m-row_diff[i1][i2]);
				if(disc >= ans) goto brk;
			}
			ans = disc;
			brk:;
		}
	}
	if(ans > k) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}