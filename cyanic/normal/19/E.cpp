#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

const int maxn = 1000009;
int cnt0[maxn], cnt1[maxn], vis[maxn], dep[maxn], ans[maxn];
int ins[maxn], n, m, u, v, tot0, tot1, res;
vector<pair<int,int> > e[maxn], t[maxn];

void dfs1(int u, int fa, int flag = 0) {
	vis[u] = 1; ins[u] = 1;
	rep (i, 0, e[u].size()-1) {
		if (e[u][i].first == fa) continue;
		if (!vis[e[u][i].first]) {
			if (!flag) dep[e[u][i].first] = dep[u] + 1;
			if (!flag) t[u].push_back(e[u][i]);
			dfs1(e[u][i].first, u, flag);
		}
		else if (ins[e[u][i].first]) {
			if (!flag) {
				if ((dep[u] - dep[e[u][i].first]) & 1) {
					tot0++; cnt0[u]++; cnt0[e[u][i].first]--;
				}
				else { 
					tot1++; cnt1[u]++; cnt1[e[u][i].first]--;
				}
			}
			else if ((dep[u] - dep[e[u][i].first]) % 2 == 0)
				ans[++res] = e[u][i].second;
		}
	}
	ins[u] = 0;
}

void dfs2(int u) {
	vis[u] = 1;
	rep (i, 0, t[u].size()-1) {
		dfs2(t[u][i].first);
		cnt0[u] += cnt0[t[u][i].first];
		cnt1[u] += cnt1[t[u][i].first];
		if (cnt1[t[u][i].first] == tot1 && !cnt0[t[u][i].first])
			ans[++res] = t[u][i].second;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	rep (i, 1, m) {
		scanf("%d%d", &u, &v);
		e[u].push_back(make_pair(v, i));
		e[v].push_back(make_pair(u, i));
	}
	rep (i, 1, n) 
		if (!vis[i]) dfs1(i, 0, 0); 
	if (tot1 == 0) {
		printf("%d\n", m);
		rep (i, 1, m) printf("%d ", i);
		return 0;
	}
	if (tot1 == 1) {
		memset(vis, 0, sizeof vis);
		rep (i, 1, n) 
			if (!vis[i]) dfs1(i, 0, 1);
	}
	memset(vis, 0, sizeof vis);
	rep (i, 1, n)
		if (!vis[i]) dfs2(i);
	printf("%d\n", res);
	sort(ans+1, ans+res+1);
	rep (i, 1, res) printf("%d ", ans[i]);
	return 0;
}