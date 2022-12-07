#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll int
#define pb push_back

const int maxn = 100100;
int n, u, v, m;
vector<int> g[maxn], d[maxn];
map<ll, int> mp;
vector<ll> son[maxn];
ll has[maxn];
int f[maxn];
int cnt[maxn], c[maxn], dep[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
		cnt[u]++;
		cnt[v]++;
	}
	if(n == 1) { printf("1\n"); return 0; }
	mp[1] = m = 1;
	int res = n;
	for(int i = 1; i <= n; ++i)
		if(cnt[i] == 1) d[0].pb(i), c[1]++, res--, dep[i] = 1, has[i] = 1;
	int cyc;
	for(cyc = 1; res; ++cyc){
		for(auto u : d[cyc - 1]){
			for(auto v : g[u]){
				if(dep[v]) continue;
				cnt[v]--;
				son[v].pb(has[u]);
				if(cnt[v] == 1) d[cyc].pb(v), res--;
			}
		}
		for(auto u : d[cyc]){
			dep[u] = cyc + 1;
			sort(all(son[u]));
			has[u] = 1;
			for(auto v : son[u])
				has[u] = has[u] * (n + 1) + v;
			if(!mp[has[u]]) mp[has[u]] = ++m;
			has[u] = mp[has[u]];
			c[has[u]]++;
		}
	}
	int mx = 1;
	for(int i = cyc - 1; i >= 0; --i)
		for(auto u : d[i]){
			if(c[has[u]] > 1) f[u]++;
			for(auto v : g[u])
				if(dep[v] < dep[u]) f[v] = f[u];
			if(f[u] > f[mx]) mx = u;
		}

	printf("%d\n", mx);
	return 0;
}