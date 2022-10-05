#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 300005;
int s[maxn], now, n, x, y, a, b;
vector<int> e[maxn];
LL ans;

bool dfs(int u, int fa) {
	bool flag = 0; s[u] = 1;
	for (auto v : e[u])
		if (v != fa) {
			if (dfs(v, u)) flag = 1;
			s[u] += s[v];
		}
	if (u == y) flag = 1;
	if (flag && u != x) now = s[u];
	return flag;
}

int main() {
	scanf("%d%d%d", &n, &x, &y);
	rep (i, 1, n-1) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(x, 0);
	ans = 1LL * n * (n - 1);
	ans -= 1LL * s[y] * (n - now);
	printf("%I64d\n", ans);
	return 0;
}