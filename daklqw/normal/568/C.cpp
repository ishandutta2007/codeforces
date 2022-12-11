#include <bits/stdc++.h>

const int MAXN = 410;
const int MAXM = MAXN * MAXN;
typedef long long LL;
typedef std::bitset<MAXN> B;
B out[MAXN];
void addedge(int b, int e) { out[b].set(e); }
inline int get(int x, int b) { return x * 2 + b; }
char buf[MAXN], src[MAXN];
int S, n, m;
std::vector<int> li[MAXN];
int lim[MAXN][MAXN];
char ans[MAXN], tmp[MAXN];
std::set<LL> vis[MAXN];
LL hash(int S, int * lim) {
	int h1 = 0, h2 = 0;
	for (int i = S; i <= n; ++i) {
		h1 = ((LL) h1 * 311 + 31 + lim[i]) % 998244353;
		h2 = ((LL) h2 * 849 + 33 + lim[i]) % 1004535809;
	}
	return (LL) h1 * 1004535809 + h2;
}
void dfs(int S, bool up = true) {
	tmp[S] = 0;
	if (S == n + 1) { std::cout << tmp + 1 << std::endl; exit(0); }
	int * lim = ::lim[S];
	if (!up) {
		LL ha = hash(S, lim);
		if (vis[S].count(ha)) return ;
		vis[S].insert(ha);
	}
	for (int i = up ? src[S] - 'a' : 0; i < ::S; ++i)
		if (!lim[S] || (lim[S] >> (buf[i] == 'V') & 1)) {
			int p = get(S, buf[i] == 'V');
			bool can = true;
			memcpy(::lim[S + 1], lim, n + 1 << 2);
			for (int t = out[p]._Find_first(); t != MAXN; t = out[p]._Find_next(t))
				if ((::lim[S + 1][t >> 1] |= 1 << (t & 1)) == 3) { can = false; break; }
			tmp[S] = i + 'a';
			if (can) dfs(S + 1, up & (i + 'a' == src[S]));
		}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf >> n >> m; S = strlen(buf);
	for (int i = 1, t1, t2; i <= m; ++i) {
		static char s1[10], s2[10];
		std::cin >> t1 >> s1 >> t2 >> s2;
		addedge(get(t1, *s1 == 'V'), get(t2, *s2 == 'V'));
		addedge(get(t2, *s2 == 'C'), get(t1, *s1 == 'C'));
	}
	for (int i = 2; i <= n * 2 + 1; ++i) out[i][i] = true;
	for (int k = 2; k <= n * 2 + 1; ++k)
		for (int i = 2; i <= n * 2 + 1; ++i) if (out[i][k])
			out[i] |= out[k];
	std::cin >> src + 1; dfs(1);
	std::cout << -1 << std::endl;
	return 0;
}