#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;
const ll INF = 2e18 + 2;

ll n, rt, d[MAXN], uu[MAXN], depth[MAXN], sec[MAXN], sz[MAXN], comp[MAXN];
vector<pair<ll, ll>>	adj[MAXN];

ll down(ll v, ll p = -1){
	d[v] = 0;
	for (pair<ll, ll>	e:adj[v])
		if (e.first != p)
			d[v] = max(d[v], e.second + down(e.first, v));
	
	ll mx = 0;
	for (ll i = 0; i < adj[v].size(); i++){
		pair<ll, ll>	e = adj[v][i];
		if (e.first == p)	continue;
		uu[adj[v][i].first] = mx + e.second;
		mx = max(mx, d[adj[v][i].first] + e.second);
	}

	mx = 0;
	for (ll i = adj[v].size() - 1; i >= 0; i--){
		pair<ll, ll>	e = adj[v][i];
		if (e.first == p)	continue;
		uu[adj[v][i].first] = max(uu[adj[v][i].first], mx + e.second);
		mx = max(mx, d[adj[v][i].first] + e.second);
	}
	return	d[v];
}

void up(ll v, ll p = -1, ll x = 0){
	if (p != -1)
		uu[v] = max(uu[v], uu[p] + x);
	for (pair<ll, ll>	e:adj[v])
		if (p != e.first)
			up(e.first, v, e.second);
	d[v] = max(d[v], uu[v]);
}

void plant(ll v, ll p = -1, ll de = 0){
	depth[v] = de;
	for (pair<ll, ll>	e:adj[v]){
		ll u = e.first;
		if (u != p)	plant(u, v, de + 1);
	}
}

bool cmp(ll a, ll b){
	if (d[a] != d[b])	
		return	d[a] > d[b];
	return	depth[a] > depth[b];
}

ll get_comp(ll v){
	if (comp[v] == v)	return	v;
	return	comp[v] = get_comp(comp[v]);
}

ll solve(ll x){
	iota(comp, comp + n, 0);
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	memset(sz, 0, sizeof(sz));

	ll r = 0, ret = 0;
	for (ll i = 0; i < n; i++){
		while (r < n && d[sec[i]] - d[sec[r]] <= x){
			ll v = sec[r];
			sz[get_comp(v)] = 1;
			for (pair<ll, ll>	e:adj[v]){
				ll u = e.first;
				if (sz[get_comp(u)] == 0)	continue;
				sz[get_comp(v)] += sz[get_comp(u)], comp[get_comp(u)] = get_comp(v);
			}

			ret = max(ret, sz[get_comp(v)]);
			r++;
		}
		sz[get_comp(sec[i])]--;
	}
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n - 1; i++){
		ll a, b, c;	cin >> a >> b >> c;	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	down(0);
	up(0);
	ll mini = INF;
	for (ll i = 0; i < n; i++)
		if (mini > d[i]){
			rt = i;
			mini = d[i];
		}
	plant(rt);
	
	ll q; cin >> q;
	while (q--){
		ll x;	cin >> x;
		cout << solve(x) << "\n";
	}
	return	0;
}