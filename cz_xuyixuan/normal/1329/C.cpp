#include<bits/stdc++.h>
using namespace std;
const int MAXN = 25;
const int MAXS = 1 << 20;
const long long INF = 1e18;
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
bool ans[MAXS];
int h, g, n, m, a[MAXS]; ll dp[MAXS];
int p[MAXS], from[MAXS], depth[MAXS];
pair <int, int> home[MAXS][MAXN];
void getans(int pos, int dep) {
	if (pos == 0) return;
	ans[pos] = true;
	getans(home[pos][dep].first, dep + 1);
	getans(home[pos][dep].second, dep + 1);
}
void work(int pos, int cur) {
	if (pos != 1) work(pos >> 1, cur);
	if (depth[pos] == g) {
		if (dp[pos] == INF) {
			dp[pos] = a[cur], from[pos] = cur;
			home[cur][depth[pos]] = make_pair(0, 0);
		} 
	} else if (depth[pos] < g) {
		if (a[cur] + dp[pos * 2] + dp[pos * 2 + 1] < dp[pos]) {
			dp[pos] = a[cur] + dp[pos * 2] + dp[pos * 2 + 1], from[pos] = cur;
			home[cur][depth[pos]] = make_pair(from[pos * 2], from[pos * 2 + 1]);
		}
	}
}
int main() {
	int T; read(T);
	while (T--) {
		read(h), read(g);
		n = (1 << h) - 1;
		m = (1 << g) - 1;
		for (int i = 1; i <= n; i++)
			read(a[i]), dp[i] = INF;
		depth[1] = 1;
		for (int i = 2; i <= n; i++)
			depth[i] = depth[i / 2] + 1;
		for (int i = 1; i <= n; i++)
			p[i] = i;
		sort(p + 1, p + n + 1, [&] (int x, int y) {return a[x] < a[y]; });
		for (int i = 1; i <= n; i++)
			work(p[i], p[i]);
		printf("%lld\n", dp[1]);
		for (int i = 1; i <= n; i++)
			ans[i] = false;
		getans(from[1], 1);
		for (int i = n; i >= 1; i--)
			if (!ans[i]) printf("%d ", i);
		printf("\n");
	}
	return 0;
}