//I can't love you in the dark..
//It feels like we're oceans apart..

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 5e3 + 40;
const ll INF = 1e18 + 5;

ll n;
vector<pair<ll, ll>>	adj[MAXN];
ll depth[MAXN];
ll sz[MAXN], s_t[MAXN], f_t[MAXN], cn;
ll par[MAXN];
ll tdis[MAXN], tud[MAXN], d[MAXN];
ll dis[MAXN][MAXN];

ll get_dis(ll u, ll v){
	if (u == v)	return	0;
	if (dis[u][v])	return	dis[u][v];
	
	if (s_t[u] > s_t[v])	swap(u, v);
	if (f_t[u] >= f_t[v])	return	dis[u][v] = dis[v][u] = depth[v] - depth[u];
	return	dis[u][v] = dis[v][u] = (depth[u] - depth[par[u]]) + get_dis(par[u], v);
}

void init(){
	for (ll u = 0; u < n; u++)
		for (ll v = 0; v < n; v++)
			dis[u][v] = get_dis(u, v);
}

void down(ll v, ll p = -1, ll de = 0){
	sz[v] = 1;
	depth[v] = de;
	s_t[v] = cn++;
	par[v] = p;

	for (pair<ll, ll>	e:adj[v]){
		ll u = e.first, w = e.second;
		if (u == p)	continue;
		
		down(u, v, de + w);

		
		d[v] += sz[v] * (tdis[u] + sz[u] * w);
		d[v] += sz[u] * tdis[v];
		d[v] += d[u];
		sz[v] += sz[u];
		tdis[v] += tdis[u] + sz[u] * w;
	}
	f_t[v] = cn;
}

void up(ll v, ll p = -1){
	if (p != -1){
		tud[v] = tud[p] + (n - sz[p]) * (depth[v] - depth[p]);
		ll temp = tdis[p] - tdis[v] - sz[v] * (depth[v] - depth[p]);
		tud[v] += temp + (sz[p] - sz[v]) * (depth[v] - depth[p]);
	}

	for (pair<ll, ll>	e:adj[v]){
		ll u = e.first, w = e.second;
		if (u != p)	up(u, v);
	}
}

ll ZZ;

void getz(ll v, ll p, ll de, ll rt){
	ll temp = tdis[v] + tud[v];
	ZZ = min(ZZ, temp - tud[rt] - (n - sz[rt]) * de);
	for (pair<ll, ll>	e:adj[v]){
		ll u = e.first, w = e.second;
		if (u == p)	continue;
		getz(u, v, de + w, rt);
	}
}

int main(){
	cin >> n;
	for (ll i = 0; i < n - 1; i++){
		ll a, b, c;	cin >> a >> b >> c;	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	down(0);
	ll ans = d[0], sum = d[0];
	init();
	up(0);
	for (ll v = 1; v < n; v++){
		ll temp = sz[v] * tud[v] + (n - sz[v]) * tdis[v], tsum;
		ZZ = INF;
		getz(v, par[v], 0, v);

		ll w = depth[v] - depth[par[v]];
		for (ll u = 0; u < n; u++){
			if (s_t[v] <= s_t[u] && f_t[v] >= f_t[u])	continue;
			ll rem = tud[u] + tdis[u];
			rem -= (dis[u][v] * sz[v]) + tdis[v];
			
			tsum = sum - temp;
			tsum += sz[v] * rem + sz[v] * (n - sz[v]) * w;
			tsum += (n - sz[v]) * ZZ;//XXX
			ans = min(ans, tsum);
		}
	}
	cout << ans << endl;
	return 0;
}