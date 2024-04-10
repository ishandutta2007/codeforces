#include <bits/stdc++.h>
using namespace std;

const int N = 510;

char s[N][N];
int chk[N][N], used[N * N], sz[N * N], cnt[N * N];
int T;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, k;

void dfs(int x, int y) {
	chk[x][y] = T, sz[T]++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (min(nx, ny) < 0 || max(nx, ny) >= n || s[nx][ny] == 'X' || chk[nx][ny]) continue;
		dfs(nx, ny);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'X' || chk[i][j]) continue;
			T++; dfs(i, j);
		}
	}
	int ans = k * k;
	T = 0;
	int add = 0;
	for (int sx = 0; sx <= n - k; sx++) {
		for (int sy = 0; sy <= n - k; sy++) {
			int cur = 0;
			T++;
		    if (sy == 0) {
		        memset(cnt, 0, sizeof cnt);
		        add = 0;
		        for (int j = 0; j < k; j++) {
		            for (int i = sx; i < sx + k; i++) {
		                int u = chk[i][j];
		                if (!u) add++;
		                else {
    		                cnt[u]++;
    		                if (cnt[u] == sz[u]) add += sz[u];
		                }
		            }
		        }
		    } else {
		        for (int i = sx; i < sx + k; i++) {
		            {
    		            int u = chk[i][sy - 1];
    		            if (u) {
        		            if (cnt[u] == sz[u]) add -= sz[u];
        		            cnt[u]--;
    		            } else {
    		                add--;
    		            }
		            }
		            {
		                int u = chk[i][sy + k - 1];
		                if (u) {
    		                cnt[u]++;
    		                if (cnt[u] == sz[u]) add += sz[u];
		                } else {
		                    add++;
		                }
		            }
		        }
		    }
		    cur += add;
			for (int j = sy; j < sy + k; j++) {
				if (sx > 0) {
					int u = chk[sx - 1][j];
					if (used[u] != T) {
    					used[u] = T, cur += sz[u];
					}
				}
				if (sx + k < n) {
					int u = chk[sx + k][j];
					if (used[u] != T) {
    					used[u] = T, cur += sz[u];
					}
				}
			}
			for (int j = sx; j < sx + k; j++) {
				if (sy > 0) {
					int u = chk[j][sy - 1];
					if (used[u] != T) {
    					used[u] = T, cur += sz[u];
					}
				}
				if (sy + k < n) {
					int u = chk[j][sy + k];
					if (used[u] != T) {
    					used[u] = T, cur += sz[u];
					}
				}
			}
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
	return 0;
}