#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, r, q, cnt, u, v, s[N], p[N], dfn[N], last[N];
ll l, f[N];
vector<pair<int,int>> e[N];
pair<ll,int> dfs(int u, int fa=0, ll d=0){
	pair<ll,int> ans(d, u);
	for(auto &i:e[u]) if(i.first!=fa) ans=max(ans, dfs(i.first, u, d+i.second));
	return ans;
}
void dfs2(int u, int fa=0, ll d=0){
	f[u]=max(f[u], d);
	for(auto &i:e[u]) if(i.first!=fa) dfs2(i.first, u, d+i.second);
}
void dfs3(int u, int fa=0){
	dfn[p[u]=u]=++cnt;
	for(auto &i:e[u]) if(i.first!=fa) dfs3(i.first, u);
	last[u]=cnt;
}
bool cmp(int x, int y){ return f[x]!=f[y]?f[x]>f[y]:dfn[x]>dfn[y];}
void modify(int x, int y){ while(x<=n) s[x]+=y, x+=x&-x;}
int query(int x){ int ans=0; while(x) ans+=s[x], x^=x&-x; return ans;}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y, z; i<n; ++i)
		scanf("%d%d%d", &x, &y, &z),
		e[x].emplace_back(y, z), e[y].emplace_back(x, z);
	v=dfs(u=dfs(1).second).second, dfs2(u), dfs2(v);
	dfs3(min_element(f+1, f+n+1)-f), sort(p+1, p+n+1, cmp);
	scanf("%d", &q);
	while(q--){
		scanf("%lld", &l), memset(s, 0, sizeof s);
		int j=1, ans=0;
		for(int i=1; i<=n; ++i){
			modify(dfn[p[i]], 1);
			while(f[p[j]]>f[p[i]]+l) modify(dfn[p[j++]], -1);
			ans=max(ans, query(last[p[i]])-query(dfn[p[i]]-1));
		}
		printf("%d\n", ans);
	}
	return 0;
}