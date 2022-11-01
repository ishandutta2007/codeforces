#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
const ll inf = 1e18;
int n, m, cnt, dfn[N], last[N];
ll f[N], lazy[N<<2], mn[N<<2];
vector<int> e[N];
vector<pair<int,int>> a[N];
multiset<int> s[N];
ll min(const multiset<int> &s){ return s.empty()?inf:*s.begin();}
void insert(int l, int r, int t, int x, int y){
	if(l==r) return (void)(s[l].insert(y), mn[t]=lazy[t]+min(s[l]));
	int mid=(l+r)>>1, k=t<<1;
	if(x<=mid) insert(l, mid, k, x, y); else insert(mid+1, r, k|1, x, y);
	mn[t]=lazy[t]+min(mn[k], mn[k|1]);
}
void erase(int l, int r, int t, int x, int y){
	if(l==r) return (void)(s[l].erase(s[l].find(y)), mn[t]=lazy[t]+min(s[l]));
	int mid=(l+r)>>1, k=t<<1;
	if(x<=mid) erase(l, mid, k, x, y); else erase(mid+1, r, k|1, x, y);
	mn[t]=lazy[t]+min(mn[k], mn[k|1]);
}
ll query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return mn[t];
	int mid=(l+r)>>1, k=t<<1;
	ll ans=inf;
	if(L<=mid) ans=min(ans, query(l, mid, k, L, R));
	if(R>mid) ans=min(ans, query(mid+1, r, k|1, L, R));
	return ans+lazy[t];
}
void change(int l, int r, int t, int L, int R, ll x){
	if(L<=l && r<=R) return (void)(mn[t]+=x, lazy[t]+=x);
	int mid=(l+r)>>1, k=t<<1;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
	mn[t]=lazy[t]+min(mn[k], mn[k|1]);
}
void init(int u, int fa=0){
	dfn[u]=++cnt;
	for(int v:e[u]) if(v!=fa) init(v, u);
	last[u]=cnt;
}
void dfs(int u, int fa=0){
	for(auto &i:a[u]) insert(1, n, 1, dfn[i.first], i.second);
	ll sum=0;
	for(int v:e[u]) if(v!=fa) dfs(v, u), sum+=f[v];
	for(auto &i:a[u]) erase(1, n, 1, dfn[i.first], i.second);

	change(1, n, 1, dfn[u], dfn[u], sum);
	for(int v:e[u]) if(v!=fa) change(1, n, 1, dfn[v], last[v], sum-f[v]);
	f[u]=query(1, n, 1, dfn[u], last[u]);
	// printf("dfs: %d %lld\n", u, f[u]);
	if(u==1) printf("%lld\n", sum);
	else if(f[u]>=inf) puts("-1"), exit(0);
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1, x, y; i<n; ++i)
		scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
	for(int i=1, x, y, z; i<=m; ++i)
		scanf("%d%d%d", &x, &y, &z), a[y].push_back(make_pair(x, z));
	fill(mn, mn+(N<<2), inf);
	init(1), dfs(1);
	return 0;
}