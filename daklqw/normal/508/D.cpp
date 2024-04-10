#include <bits/stdc++.h>

const int MAXN = 2e5 + 10 + 62 * 62;
const int MAXM = 4e5 + 10;
const int MAXC = 2e5 + 10;
void bye() {
	std::cout << "NO" << std::endl;
	exit(0);
}
int n;
char buf[MAXC][5];
int head[MAXN], nxt[MAXM], to[MAXM], tot;
int deg[MAXN];
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	++deg[e], --deg[b];
}
int fa[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int idx;
inline int encode(int a, int b) {
	static std::map<int, int> M;
	int at = a * 256 + b;
	return M.count(at) ? M[at] : M[at] = ++idx;
}
int li[MAXN], cnt;
int st[MAXN], top;
void add(int u) {
	if (u <= n || u == idx) li[++cnt] = u;
}
void dfs(int u) {
	for (int & i = head[u]; i; ) {
		int _i = i;
		i = nxt[i];
		if (_i) dfs(to[_i]);
	}
	add(u);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n; idx = n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> buf[i];
		adde(encode(buf[i][0], buf[i][1]), i);
		adde(i, encode(buf[i][1], buf[i][2]));
	}
	for (int i = 1; i <= idx; ++i) fa[i] = i;
	for (int i = 1; i <= idx; ++i)
		for (int j = head[i]; j; j = nxt[j])
			fa[find(i)] = find(to[j]);
	for (int i = 1; i <= idx; ++i)
		if (find(i) != find(1))
			bye();
	int s[2], bak = 0;
	for (int i = 1; i <= idx; ++i)
		if (deg[i] != 0) {
			if (bak == 2) bye();
			if (std::abs(deg[i]) > 1) bye();
			s[bak++] = i;
		}
	if (bak) {
		if (deg[s[0]] > 0)
			std::swap(s[0], s[1]);
		adde(s[1], ++idx);
		adde(idx, s[0]);
	} else {
		adde(1, ++idx);
		adde(idx, 1);
	}
	int rt = bak == 0 ? 1 : s[0];
	dfs(rt);
	std::reverse(li + 1, li + 1 + cnt);
//	for (int i = 1; i <= cnt; ++i)
//		std::cout << li[i] << ' ';
//	std::cout << std::endl;
	auto getn = [] (int x) { return x == cnt ? 1 : x + 1; };
	rt = getn(std::find(li + 1, li + 1 + n, idx) - li);
	std::cout << "YES" << std::endl;
	std::cout << buf[li[rt]][0] << buf[li[rt]][1];
	for (int i = 1; i <= n; ++i)
		std::cout << buf[li[rt]][2], rt = getn(rt);
	std::cout << '\n';
	return 0;
}