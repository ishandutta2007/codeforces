#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define x first
#define y second
using namespace std;
typedef pair<int,int> P;
typedef pair<P,P> PP;

inline int read() {
	char ch = getchar(); int x = 0, op = 1;
	while (ch < '0' || '9' < ch) { if (ch == '-') op = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return op * x;
}

const int maxn = 500009;
vector<int> e[2][maxn];
vector<PP> ans;
int pa[maxn], fa[2][maxn];
int n, a, b, res;

int getpa(int u) {
	return pa[u] == u ? u : pa[u] = getpa(pa[u]);
}

bool check(int k, int u, int v) {
	return fa[k][u] == v || fa[k][v] == u;
}

void dfs(int u, int k) {
	rep (i, 0, e[k][u].size()-1) 
		if (e[k][u][i] != fa[k][u]) {
			fa[k][e[k][u][i]] = u;
			dfs(e[k][u][i], k);
		}
}

void solve(int u) {
	int v;
	rep (i, 0, e[0][u].size()-1)
		if (e[0][u][i] != fa[0][u]) {
			solve(v = e[0][u][i]);
			if (!check(1, u, v))
				ans.push_back(make_pair(make_pair(u, v), make_pair(getpa(v), fa[1][getpa(v)])));
		}
}

int main() {
	n = read();
	rep (k, 0, 1) {
		rep (i, 1, n-1) {
			a = read(); b = read();
			e[k][a].push_back(b);
			e[k][b].push_back(a);
		}
		dfs(1, k);
	}
	rep (i, 1, n) pa[i] = i;
	rep (i, 2, n)
		if (check(0, i, fa[1][i])) 
			pa[i] = fa[1][i];
	solve(1);
	res = ans.size();
	printf("%d\n", res);
	rep (i, 0, res-1)
		printf("%d %d %d %d\n", ans[i].x.x, ans[i].x.y, ans[i].y.x, ans[i].y.y);
	return 0;
}