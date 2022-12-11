#include <bits/stdc++.h>
 
const int MAXN = 1000010;
int n, fa[MAXN], sz[MAXN];
std::vector<int> out[100010];
int li[MAXN], bak;
int tl[MAXN], idx;
bool cmp(int a, int b) {
	return sz[a] > sz[b];
}
void dfs(int u) {
	li[++bak] = u;
	if (out[u].empty()) return ;
	std::sort(out[u].begin(), out[u].end(), cmp);
	int sz = out[u].size();
	for (int i = 0; i + 1 < sz; ++i) {
		out[out[u][i + 1]].push_back(out[u][i]);
		tl[++idx] = out[u][i];
	}
	dfs(out[u][sz - 1]);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i < n; ++i) std::cin >> fa[i];
	for (int i = 0; i < n; ++i) sz[i] = 1;
	for (int i = n - 1; i; --i) sz[fa[i]] = std::max(sz[fa[i]], sz[i] + 1);
	for (int i = 1; i < n; ++i)
		out[fa[i]].push_back(i);
	dfs(0);
	for (int i = 1; i <= n; ++i)
		std::cout << li[i] << ' ';
	std::cout << std::endl;
	std::cout << idx << std::endl;
	for (int i = idx; i; --i)
		std::cout << tl[i] << ' ';
	std::cout << std::endl;
	return 0;
}