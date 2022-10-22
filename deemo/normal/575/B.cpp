#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;
const ll MAXQ = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll LOG = 18 + 2;

ll n, q, par[MAXN][LOG], depth[MAXN];
ll ss[MAXQ], save[MAXQ], ans;
ll m1[MAXN], m2[MAXN];
vector<pair<ll, bool>>	adj[MAXN];

void plant(ll v, ll p = -1, ll de = 0){
	par[v][0] = p;
	depth[v] = de;
	for (pair<ll, bool>	e:adj[v])
		if (abs(e.first) != p)	plant(abs(e.first), v, de + 1);
}

void init(){
	save[0] = 1;
	for (ll i = 1; i < MAXQ; i++)
		save[i] = (save[i - 1] * 2) % MOD;
	for (ll i = 1; i < MAXQ; i++)
		ss[i] = (ss[i - 1] + save[i - 1]) % MOD;

	for (ll i = 1; i < LOG; i++)
		for (ll j = 1; j <= n; j++)
			if (par[j][i - 1] == -1)
				par[j][i] = -1;
			else
				par[j][i] = par[par[j][i - 1]][i - 1];
}

ll lca(ll u, ll v){
	if (depth[u] < depth[v])	swap(u, v);
	for (ll i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v])	u = par[u][i];
	if (u == v)	return	u;
	for (ll i = LOG - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return	par[v][0];
}

pair<ll, ll> dfs(ll v, ll p = -1, bool t = 0, bool f = 0){
	ll s1 = 0, s2 = 0;
	for (pair<ll, bool>	e:adj[v])
		if (abs(e.first) != p){
			auto temp = dfs(abs(e.first), v, e.second, bool(e.first < 0));
			s1 += temp.first;
			s2 += temp.second;
		}

	s1 += m1[v], s2 += m2[v];
	if (p == -1 || t == 0)	return	{s1, s2};
	if (f)	
		ans = (ans + ss[s2]) % MOD;
	else
		ans = (ans + ss[s1]) % MOD;

	return	{s1, s2};
}

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n - 1; i++){
		ll a, b, c;	scanf("%I64d %I64d %I64d", &a, &b, &c);
		adj[a].push_back({b, c});
		adj[b].push_back({-a, c});
	}
	plant(1);
	init();

	ll q;	scanf("%I64d", &q);
	ll ls = 1;
	for (ll i = 0; i < q; i++){
		ll v;	scanf("%I64d", &v);	
		if (v == ls)	continue;
		ll p = lca(ls, v);
		m1[ls]++;
		m1[p]--;

		m2[v]++;
		m2[p]--;
		ls = v;
	}
	dfs(1);
	cout << ans << endl;
	return	0;
}