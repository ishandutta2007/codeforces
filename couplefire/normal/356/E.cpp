#include <bits/stdc++.h>
 
typedef long long LL;
const int N = 200005;
 
std::string s;
int n, nxt[N][26], fail[N], max[N], lst = 1, idx = 1, pos[N];
void append(int ch, int id) {
	int p = lst, np = lst = ++idx; max[np] = max[p] + 1, pos[id] = np;
	for (; p && !nxt[p][ch]; p = fail[p]) nxt[p][ch] = np;
	if (!p) fail[np] = 1;
	else {
		int q = nxt[p][ch];
		if (max[p] + 1 == max[q]) fail[np] = q;
		else {
			int nq = ++idx; max[nq] = max[p] + 1;
			fail[nq] = fail[q], fail[q] = fail[np] = nq;
			std::memcpy(nxt[nq], nxt[q], 26 << 2);
			for (; nxt[p][ch] == q; p = fail[p]) nxt[p][ch] = nq;
		}
	}
}
int head[N], next[N], in[N], clk;
void link(int x, int y) {next[y] = head[x], head[x] = y; }
int st[18][N];
void dfs(int x) {
	st[0][clk] = max[fail[x]], in[x] = ++clk;
	for (int i = head[x]; i; i = next[i]) dfs(i);
}
int lca(int x, int y) {
	if (x == y) return max[x];
	x = in[x], y = in[y];
	if (x > y) std::swap(x, y);
	int k = std::__lg(y - x);
	return std::min(st[k][x], st[k][y - (1 << k)]);
}
int lcp(int x, int y) {return lca(pos[x], pos[y]); }
void init() {
	for (int i = 2; i <= idx; ++i) link(fail[i], i);
	dfs(1);
	for (int i = 1; i < 18; ++i)
	for (int j = 1; j <= idx - (1 << i); ++j)
		st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
}
 
int distance(int l, int r, int len) {
	int s = lcp(l, r);
	if (s >= len) return 0;
	int t = lcp(l + s + 1, r + s + 1);
	if (s + 1 + t >= len) return 1;
	return 2;
}
 
int sum[26][N], ok[N][17];
LL cost[N], get[N][26];
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> s, n = s.size(), s = '$' + s;
	for (int i = 1; i <= n; ++i) s[i] -= 'a';
	for (int i = n; i >= 1; --i) append(s[i], i);
	init();
	for (int ch = 0; ch < 26; ++ch)
	for (int i = 1; i <= n; ++i)
		sum[ch][i] = sum[ch][i - 1] + (s[i] == ch);
	LL all = n;
	for (int i = 1; i <= n; ++i) ok[i][1] = 1;
	for (int i = 2; 1 << i <= n + 1; ++i) {
		int len = (1 << i) - 1, mid = len >> 1;
		for (int j = 1; j <= n - len + 1; ++j) {
			int ch = s[j + mid], diff = distance(j, j + mid + 1, mid);
			LL val = (LL) len * len;
			ok[j][i] = ok[j][i - 1] && !diff && sum[ch][j + mid - 1] == sum[ch][j - 1];
			if (ok[j][i]) all += val, cost[j] += val, cost[j + len] -= val;
			if (ok[j][i - 1] && !diff) {
				for (int t = 0; t < 26; ++t)
					if (sum[t][j + mid - 1] == sum[t][j - 1])
						get[j + mid][t] += val;
			}
			int pos = lcp(j, j + mid + 1);
			if (ok[j][i - 1] && diff == 1 && sum[ch][j + mid - 1] == sum[ch][j - 1])
				get[j + mid + 1 + pos][s[j + pos]] += val;
			if (ok[j + mid + 1][i - 1] && diff == 1 && sum[ch][j + len - 1] == sum[ch][j + mid])
				get[j + pos][s[j + mid + 1 + pos]] += val;
		}
	}
	for (int i = 1; i <= n; ++i) cost[i] += cost[i - 1];
	LL ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int t = 0; t < 26; ++t) {
			ans = std::max(ans, get[i][t] - cost[i]);
		}
	std::cout << ans + all << '\n';
			
	return 0;
}