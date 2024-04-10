#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n;
ll val[MAXN];
ll d[MAXN], e[MAXN], f[MAXN], g[MAXN];
vector<ll>	adj[MAXN];
vector<pair<ll, ll>>	vec[4][MAXN];

void solve(ll v, ll p = -1){
	if (p != -1 && adj[v].size() == 1){
		d[v] = e[v] = f[v] = g[v] = val[v];
		return;
	}

	for (ll u:adj[v])
		if (u != p){
			solve(u, v);
			vec[0][v].push_back({d[u], u});
			vec[1][v].push_back({e[u], u});
			vec[2][v].push_back({f[u], u});
			vec[3][v].push_back({g[u], u});
		}
	for (ll i = 0; i < 4; i++)
		sort(vec[i][v].begin(), vec[i][v].end(), greater<pair<ll, ll>>());

	e[v] = val[v] + vec[1][v][0].first;
	d[v] = max(e[v], vec[0][v][0].first);
	ll sz = vec[1][v].size();
	if (sz > 1)	d[v] = max(d[v], val[v] + vec[1][v][0].first + vec[1][v][1].first);
	
	g[v] = vec[3][v][0].first + val[v];
	if (sz >= 2)
		for (ll i = 0; i < sz; i++)
			for (ll j = 0; j < 2; j++)
				if (vec[1][v][i].second != vec[0][v][j].second){
					g[v] = max(g[v], vec[1][v][i].first + val[v] + vec[0][v][j].first);
					break;
				}

	f[v] = max(g[v], vec[2][v][0].first);
	if (sz > 1)
		f[v] = max(f[v], vec[0][v][0].first + vec[0][v][1].first);
	if (sz >= 3)
		for (ll i = 0; i < sz; i++){
			ll ret = vec[0][v][i].first + val[v];
			ll cnt = 0;
			for (ll j = 0; j < 3; j++)
				if (vec[0][v][i].second != vec[1][v][j].second){
					ret += vec[1][v][j].first;
					cnt++;
					if (cnt == 2)	break;
				}
			f[v] = max(f[v], ret);
		}
	if (sz >= 2)
		for (ll i = 0; i < sz; i++){
			ll ret = vec[3][v][i].first + val[v];
			for (ll j = 0; j < 2; j++)
				if (vec[3][v][i].second != vec[1][v][j].second){
					ret += vec[1][v][j].first;
					break;
				}
			f[v] = max(f[v], ret);
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> val[i];
	for (ll i = 0; i < n - 1; i++){
		ll a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve(0);
	cout << f[0] << "\n";
	return	0;
}