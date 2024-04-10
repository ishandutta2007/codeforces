#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 25;
const int MAXS = 1 << 20;
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
char s[MAXN], t[MAXN];
int n, m, bit[MAXM], mask[MAXM], cnt[MAXS];
bool mp[MAXM][MAXM], done[MAXS], vis[MAXM];
void dfs(int pos) {
	vis[pos] = true;
	for (int i = 1; i <= m; i++)
		if (!vis[i] && mp[pos][i]) dfs(i);
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), m = 20;
		memset(mp, false, sizeof(mp));
		for (int i = 1; i <= m; i++) {
			bit[i] = 1 << (i - 1);
			mask[i] = 0;
		}
		scanf("\n%s", s + 1);
		scanf("\n%s", t + 1);
		for (int i = 1; i <= n; i++) {
			if (s[i] != t[i]) {
				mp[s[i] - 'a' + 1][t[i] - 'a' + 1] = true;
				mp[t[i] - 'a' + 1][s[i] - 'a' + 1] = true;
				mask[s[i] - 'a' + 1] |= bit[t[i] - 'a' + 1];
			}
		}
		int goal = (1 << m) - 1;
		int ans = 0; done[0] = true;
		for (int s = 1; s <= goal; s++) {
			done[s] = false;
			cnt[s] = cnt[s / 2] + s % 2;
			for (int i = 1; i <= m; i++)
				if ((s & bit[i]) != 0 && (mask[i] & s) == 0) {
					done[s] |= done[s ^ bit[i]];
				}
			if (done[s]) chkmax(ans, cnt[s]);
		}
		ans = m * 2 - ans;
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= m; i++)
			if (!vis[i]) {
				ans--;
				dfs(i);
			}
		printf("%d\n", ans);
	}
	return 0;
}