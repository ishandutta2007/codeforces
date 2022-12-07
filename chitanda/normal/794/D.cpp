#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define all(a) a.begin(), a.end()
#define B 233

const int maxn = 300100;
int n, m;
vector<int> f[maxn], g[maxn];
int u[maxn], v[maxn];
int x[maxn], fa[maxn];
int cnt;

void error(){
	printf("NO\n");
	exit(0);
}

ull gethas(vector<int> &vec){
	sort(all(vec));
	ull has = 0;
	for(auto v : vec)
		has = has * (300001) + v;
	return has;
}

void dfs(int t){
	x[t] = ++cnt;
	if(g[t].size() > 2) error();
	for(auto v : g[t])
		if(!x[v]) dfs(v);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", u + i, v + i);
		f[u[i]].pb(v[i]);
		f[v[i]].pb(u[i]);
	}

	map<pair<int, ull>, int> mp;
	for(int i = 1; i <= n; ++i){
		f[i].pb(i);
		fa[i] = i;
		auto h = mkp(f[i].size(), gethas(f[i]));
		if(mp.count(h)) fa[i] = mp[h];
		else mp[h] = i;
	}
	
	for(int i = 1; i <= m; ++i)
		if(fa[u[i]] == u[i] && fa[v[i]] == v[i])
			g[u[i]].pb(v[i]), g[v[i]].pb(u[i]);
	
	for(int i = 1; i <= n; ++i)
		if(fa[i] == i && g[i].size() < 2 && !x[i]) dfs(i), cnt += 5;
		else if(g[i].size() > 2) error();
	
	printf("YES\n");
	for(int i = 1; i <= n; ++i){
		if(fa[i] != i) x[i] = x[fa[i]];
		printf("%d ", x[i]);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}