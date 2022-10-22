#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 3e5 + 10;

ll n, m, d[MAXN], id[MAXN];
bool tf;
ll from[MAXN], to[MAXN], cost[MAXN], ins[MAXN];
vector<ll>	adj[MAXN], vec[MAXN], sec[MAXN];
ll sz, ss[MAXN];
multiset<pair<ll, ll>>	st[MAXN];

void go(ll v, ll p = -1){
	pair<ll, ll>	mx(-1, v);
	ll sm = 0;
	for (ll u:adj[v])
		if (u^p)	
			go(u, v), mx = max(mx, {st[id[u]].size(), u}), sm += d[u];
	if (mx.F == -1)
		id[v] = sz++;
	if (tf || !v)	return;

	id[v] = id[mx.S];
	ss[id[v]] += (sm - d[mx.S]);
	for (ll e:vec[v])
		ins[e] = cost[e] + sm - ss[id[v]], st[id[v]].insert({ins[e], e});
	
	for (ll u:adj[v])
		if (u^p && u^mx.S){
			for (auto e:st[id[u]])
				ins[e.S] = ss[id[u]] + e.F - ss[id[v]] + (sm - d[u]), st[id[v]].insert({ins[e.S], e.S});
			st[id[u]].clear();
		}
	for (ll e:sec[v])
		st[id[v]].erase(st[id[v]].find({ins[e], e}));
	if (st[id[v]].empty())
		tf = 1;
	else
		d[v] = st[id[v]].begin()->F + ss[id[v]];
}

int main(){
	scanf("%I64d %I64d", &n, &m);
	for (ll i = 0; i < n - 1; i++){
		ll a, b;	scanf("%I64d %I64d", &a, &b), a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (ll i = 0; i < m; i++){
		scanf("%I64d %I64d %I64d", &from[i], &to[i], &cost[i]), from[i]--, to[i]--;
		if (from[i] == to[i]){
			m--, i--;
			continue;
		}

		vec[from[i]].push_back(i);
		sec[to[i]].push_back(i);
	}
	
	go(0);
	if (tf)
		printf("-1\n");
	else{
		ll ans = 0;
		for (ll u:adj[0])
			ans += d[u];
		printf("%I64d\n", ans);
	}
	return 0;
}