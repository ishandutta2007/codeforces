#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

const int maxn = 10009;
int used[maxn], vis[maxn], del[maxn], deg[maxn], odd[maxn];
int n, m, a, b, cnt, flag, Res, res[2], s[maxn][5], ans[2][maxn];
vector<pair<int,int> > e[maxn];

void dfs(int u) {
	if (vis[u]) return; vis[u] = 1; 
	if (deg[u]&1) { odd[cnt]++; if (odd[cnt] <= 4) s[cnt][odd[cnt]] = u; }
	rep (i, 0, e[u].size()-1) dfs(e[u][i].first);
}

void fleury(int u, int cur) { for (;;) {
	while (!e[u].empty() && del[e[u].back().second]) e[u].pop_back(); 
	if (e[u].empty()) break;
	int tmp = e[u].back().second;
	del[e[u].back().second] = 1;
	fleury(e[u].back().first, cur);
	ans[cur][++res[cur]] = tmp;
}}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &m);
	rep (i, 1, m) {
		scanf("%d%d", &a, &b);
		e[a].push_back(make_pair(b, i));
		e[b].push_back(make_pair(a, i));
		n = max(n, max(a, b));
		deg[a]++; deg[b]++;
		used[a] = used[b] = 1;
	}
	rep (i, 1, n) if (used[i] && !vis[i]) {
		cnt++; s[cnt][1] = i; dfs(i);
	}
	if (m <= 1 || cnt > 2 || odd[1] + odd[2] > 4 || cnt == 2 && (odd[1] == 4 || odd[2] == 4)) {
		puts("-1"); return 0;
	}
	if (cnt == 1) {
		if (odd[1] <= 2) {
			fleury(s[1][1], 0);
			printf("%d\n", res[0]-1);
			rep (i, 1, res[0]-1) printf("%d ", ans[0][i]);
			printf("\n1\n%d", ans[0][res[0]]);
		}
		else {
			e[s[1][3]].push_back(make_pair(s[1][4], m+1));
			e[s[1][4]].push_back(make_pair(s[1][3], m+1));
			fleury(s[1][1], 0);
			rep (i, 1, res[0])
				if (ans[0][i] == m+1) Res = i-1; 
				else if (Res) ans[1][++res[1]] = ans[0][i];
			printf("%d\n", res[0] = Res);
			rep (i, 1, res[0]) printf("%d ", ans[0][i]);
			printf("\n%d\n", res[1]);
			rep (i, 1, res[1]) printf("%d ", ans[1][i]);
		}
	}
	else {
		fleury(s[1][1], 0); fleury(s[2][1], 1);
		printf("%d\n", res[0]);
		rep (i, 1, res[0]) printf("%d ", ans[0][i]);
		printf("\n%d\n", res[1]);
		rep (i, 1, res[1]) printf("%d ", ans[1][i]);
	}
	return 0;
}