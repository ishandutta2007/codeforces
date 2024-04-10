
// Problem : E. Blood Cousins
// Contest : Codeforces Round #130 (Div. 2)
// URL : https://codeforces.com/problemset/problem/208/E
// Memory Limit : 256.000000 MB
// Time Limit : 2000.000000 milisec
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN = 1e5+3, LOG = 17;
int depth[MN], p[MN][LOG], big[MN], sz[MN], st[MN], ed[MN], which[MN], ans[MN], cnt[MN], tt;
vector<int> adj[MN];
vector<pii> queries[MN];
void getsz (int cur) {
	st[cur] = ++tt;
	which[tt] = cur;
	for (int i : adj[cur]) {
		depth[i] = depth[cur] + 1;
		getsz(i);
		if (!big[cur] || sz[i] > sz[big[cur]]) {
			big[cur] = i;
		}
		sz[cur] += sz[i];
	}
	ed[cur] = tt;
	++sz[cur];
}
int kth (int a, int b) {
	int od = depth[a];
	for (int i = LOG-1; i >= 0; i--)
		if (~p[a][i] && od-depth[p[a][i]]<=b)
			a = p[a][i];
	return a;
}
void dfs (int cur, bool keep) {
	for (int i : adj[cur]) if (i != big[cur]) dfs(i,0);
	if (big[cur]) dfs(big[cur],1);
	for (int i : adj[cur]) if (i != big[cur]) for (int j = st[i]; j <= ed[i]; j++) ++cnt[depth[which[j]]];
	++cnt[depth[cur]];
	for (pii &q : queries[cur]) ans[q.second] = cnt[q.first];
	if (!keep) for (int i = st[cur]; i <= ed[cur]; i++) --cnt[depth[which[i]]];
}
int main () {
	int n;
	scanf ("%d",&n);
	memset(p,-1,sizeof p);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&p[i][0]);
		adj[p[i][0]].push_back(i);
		for (int j = 1; j < LOG; j++)
			if (~p[i][j-1])
				p[i][j] = p[p[i][j-1]][j-1];
			else break;
	}
	getsz(0);
	int q; scanf ("%d",&q);
	for (int i = 1; i <= q; i++) {
		int a,b; scanf ("%d %d",&a,&b);
		if(b>=depth[a]) ans[i] = 1;
		else queries[kth(a,b)].push_back({depth[a],i});
	}
	dfs(0,1);
	for (int i = 1; i <= q; i++) printf ("%d%c",--ans[i]," \n"[i==q]);
	return 0;
}