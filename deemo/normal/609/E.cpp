#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<utility>

using namespace std;

typedef long long ll;

#define Edge pair<pair<ll, ll>, pair<ll, ll>>
#define U first.first
#define V first.second
#define W second.first
#define id second.second

const ll MAXN = 3e5 + 20;
const ll MAXM = 3e5 + 20;
const ll LOG = 20;

ll n, m, comp[MAXN];
Edge ed[MAXM];
vector<pair<ll, ll>>	adj[MAXN];
ll par[MAXN][LOG], up[MAXN][LOG], depth[MAXN];
ll ans[MAXM], sum;
bool mark[MAXM];

bool cmp(Edge a, Edge b){
	if (a.W != b.W)	
		return	a.W < b.W;
	return	a.id < b.id;
}

ll get_comp(ll v){
	if (comp[v] == v)	
		return	v;
	return	comp[v] = get_comp(comp[v]);
}

bool join(ll u, ll v){
	if (get_comp(u) == get_comp(v))	return	false;
	comp[get_comp(u)] = get_comp(v);
	return	true;
}

void dfs(ll v, ll p = -1, ll de = 0, ll w = 0){
	depth[v] = de;
	par[v][0] = p;
	up[v][0] = w;
	for (pair<ll, ll>	e:adj[v])
		if (e.first != p)
			dfs(e.first, v, de + 1, e.second);
}

void init(){
	for (ll i = 1; i < LOG; i++)
		for (ll j = 0; j < n; j++)
			if (par[j][i - 1] == -1)
				par[j][i] = -1, up[j][i] = up[j][i - 1];
			else
				par[j][i] = par[par[j][i - 1]][i - 1], up[j][i] = max(up[j][i - 1], up[par[j][i - 1]][i - 1]);
}

ll lca(ll u, ll v){
	if (depth[u] < depth[v])	swap(u, v);
	for (ll i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v])
			u = par[u][i];
	if (u == v)	return	v;
	for (ll i = LOG - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])	
			u = par[u][i], v = par[v][i];
	return	par[u][0];
}

ll get(ll u, ll p){
	ll ret = 0;
	for (ll i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[p]){
			ret = max(ret, up[u][i]);
			u = par[u][i];
		}
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < m; i++){
		cin >> ed[i].U >> ed[i].V >> ed[i].W;	ed[i].V--, ed[i].U--;
		ed[i].id = i;
	}

	sort(ed, ed + m, cmp);
	iota(comp, comp + n, 0);
	for (ll i = 0; i < m; i++)
		if (join(ed[i].U, ed[i].V)){
			sum += ed[i].W;
			mark[ed[i].id] = 1;
			adj[ed[i].U].push_back({ed[i].V, ed[i].W});
			adj[ed[i].V].push_back({ed[i].U, ed[i].W});
		}
	dfs(0);
	init();

	for (ll i = 0; i < m; i++)
		if (mark[ed[i].id])
			ans[ed[i].id] = sum;
		else{
			ll u = ed[i].U, v = ed[i].V;
			ll p = lca(u, v);
			ans[ed[i].id] = sum + ed[i].W - max(get(u, p), get(v, p));
		}

	for (ll i = 0; i < m; i++)
		cout << ans[i] << "\n";
	return	0;
}