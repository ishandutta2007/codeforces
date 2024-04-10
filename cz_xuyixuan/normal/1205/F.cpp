#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = 5055;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
bool dp[MAXN][MAXM];
int main() {
	int n = 100, m = 5050; dp[1][1] = true;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (!dp[i][j]) continue;
		for (int k = 4; i + k - 1 <= n; k++)
			dp[i + k - 1][j + k] = true;
		for (int k = 2; i + k - 1 <= n; k++)
			dp[i + k - 1][j + k * (k + 1) / 2 - 1] = true;
	}
	int T; read(T);
	while (T--) {
		read(n), read(m);
		if (dp[n][m]) {
			puts("YES"); int cur = 2;
			deque <int> ans; ans.push_back(1);
			bool type = true;
			while (n != 1) {
				for (int k = 2; k <= n; k++)
					if (m - k * (k + 1) / 2 + 1 >= 1 && dp[n - k + 1][m - k * (k + 1) / 2 + 1]) {
						if (type) {
							for (int i = 2; i <= k; i++, n--)
								ans.push_back(cur++);
							type = false;
						} else {
							for (int i = 2; i <= k; i++, n--)
								ans.push_front(cur++);
							type = true;
						}
						m -= k * (k + 1) / 2 - 1;
						break;
					}
				for (int k = 4; k <= n; k++)
					if (m - k >= 1 && dp[n - k + 1][m - k]) {
						int bak = cur++;
						for (int i = 3; i <= k; i++, n--)
							if (i & 1) ans.push_back(cur++);
							else ans.push_front(cur++);
						if (k & 1) ans.push_back(bak);
						else ans.push_front(bak);
						n--, m -= k;
						break;
					}
			}
			while (!ans.empty()) {
				printf("%d ", ans.front());
				ans.pop_front();
			}
			printf("\n");
		} else puts("NO");
	}
	return 0;
}