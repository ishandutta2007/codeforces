#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 40;
const ll LOG = 20;

ll n, q;
ll depth[MAXN], par[LOG][MAXN], nxt[MAXN], comp[MAXN];
vector<pair<ll, ll>>	adj[MAXN];
pair<ll, ll>	ed[MAXN];

void plant(ll v, ll p = -1, ll de = 0, ll nx = 1){
	nxt[v] = nx;
	depth[v] = de;
	par[0][v] = p;
	for (auto e:adj[v])
		if (e.first == p)
			comp[v] = e.second == 1?p:v;
		else
			plant(e.first, v, de + 1, e.second);
}

void init(){
	for (ll i = 1; i < LOG; i++)
		for (ll j = 0; j < n; j++)
			if (par[i - 1][j] == -1)
				par[i][j] = -1;
			else
				par[i][j] = par[i - 1][par[i - 1][j]];
}

ll lca(ll u, ll v){
	if (depth[u] < depth[v])	swap(u, v);
	for (ll w = LOG - 1; w >= 0; w--)
		if (depth[u] - (1<<w) >= depth[v])	u = par[w][u];
	if (u == v)	return	u;
	for (ll w = LOG - 1; w >= 0; w--)
		if (par[w][v] != par[w][u])	v = par[w][v], u = par[w][u];
	return	par[0][v];
}

ll get_comp(ll v){
	if (comp[v] == v)	return	v;
	return	comp[v] = get_comp(comp[v]);
}

ll move_up(ll u, ll v, ll x){
	while (depth[u] > depth[v]){
		u = get_comp(u);
		if (depth[u] <= depth[v])	continue;
		x /= nxt[u];
		u = par[0][u];
		if (x == 0)	break;
	}
	return	x;
}

ll move_down(ll u, ll v, ll x){
	while (depth[u] < depth[v]){
		ll z = v;
		for (ll w = LOG - 1; w >= 0; w--)
			if (depth[z] - (1<<w) > depth[u] && depth[get_comp(par[w][z])] > depth[u])	z = par[w][z];
		
		if (z == v && nxt[v] == 1)	break;
		u = z;
		x /= nxt[u];
		if (x == 0)	break;
	}
	return	x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n - 1; i++){
		ll a, b, c;	cin >> a >> b >> c;	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
		ed[i] = {a, b};
	}
	plant(0);
	init();

	while (q--){
		ll type;	cin >> type;
		if (type == 1){
			ll s; ll a, b;	cin >> a >> b >> s;	a--, b--;
			ll p = lca(a, b);
			s = move_up(a, p, s);
			s = move_down(p, b, s);
			cout << s << "\n";
		}
		else{
			ll e, x;	cin >> e >> x;	e--;
			ll u = ed[e].first, v = ed[e].second;
			if (depth[u] < depth[v])	swap(u, v);
			nxt[u] = x;
			if (x == 1)
				comp[u] = v;
		}
	}
	return	0;
}