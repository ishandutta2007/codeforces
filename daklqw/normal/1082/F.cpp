#include <bits/stdc++.h>

const int MAXN = 510;

void gma(int & x, int y) { x < y ? x = y : 0; }

int nxt[MAXN][10], sz[MAXN], dep[MAXN], tot = 1;
void ins(const char * buf, int c) {
	int now = 1; sz[1] += c;
	while (*buf) {
		int & nt = nxt[now][*buf++ & 15];
		if (!nt) dep[nt = ++tot] = dep[now] + 1;
		sz[now = nt] += c;
	}
}

int n, K;
int dp[MAXN][MAXN][11];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	int ans = 0;
	for (int i = 1, t; i <= n; ++i) {
		static char buf[MAXN];
		std::cin >> buf >> t;
		ins(buf, t);
		ans += strlen(buf) * t;
	}
	for (int u = tot; u; --u) {
		for (int l = 0; l + (u != 1) <= dep[u]; ++l) {
			int * tar = dp[u][l];
			int up = l, self = 0;
			for (int T = 0; T + (u == 1) < 2; ++T) {
				static int tmp[11], tmp2[11];
				memset(tmp, 0, sizeof tmp);
				for (int i = 0; i < 10; ++i) if (int v = nxt[u][i]) {
					int * arr = dp[v][up];
					memset(tmp2, 0, sizeof tmp2);
					for (int j = 0; j <= K; ++j)
						for (int k = 0; k + j <= K; ++k)
							gma(tmp2[j + k], tmp[j] + arr[k]);
					memcpy(tmp, tmp2, sizeof tmp2);
				}
				for (int j = 0; j + T <= K; ++j)
					gma(tar[j + T], self + tmp[j]);
				self = (dep[u] - up) * sz[u];
				up = dep[u];
			}
		}
	}
	ans -= *std::max_element(dp[1][0], dp[1][0] + K + 1);
	std::cout << ans << std::endl;
	return 0;
}