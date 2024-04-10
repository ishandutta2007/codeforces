#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, k;
struct edge {
	int to, nxt;
	inline edge() {}
	inline edge(int to, int nxt) : to(to), nxt(nxt) {} 
} E[maxn * 2];
int fir[maxn], sz[maxn], top, dep[maxn], val[maxn];
long long Ans;
bool b[maxn];
inline void add(int x, int y) {
	E[++top] = edge(y, fir[x]); fir[x] = top;
}
void dfs(int x, int fa) {
	sz[x] = 1; dep[x] = dep[fa] + 1;
	for (int i = fir[x]; i; i = E[i].nxt) {
		int v = E[i].to;
		if (v == fa) continue;
		dfs(v, x);
		sz[x] += sz[v];
	}
}
inline bool comp(const int &x, const int &y) {
	return x > y;
}
int main() {
//	freopen(".in", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) val[i] = dep[i] - sz[i];
	sort(val + 1, val + 1 + n, comp);
	for (int i = 1; i <= k; ++i) Ans += val[i];
	printf("%lld\n", Ans);
	return 0;
}