//One day soon..
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e5 + 10;

ll n, par[MAXN];
vector<ll>	adj[MAXN];
ll d[MAXN][2];
bool t[MAXN];

void dfs(ll v){
	d[v][0] = !t[v];
	d[v][1] = t[v];

	for (ll u:adj[v]){
		ll a = d[v][0], b = d[v][1];
		dfs(u);

		d[v][1] = b * d[u][1];
		d[v][0] = a * d[u][1];
		d[v][1] = (d[v][1] + a * d[u][1]) % MOD;
		d[v][1] = (d[v][1] + b * d[u][0]) % MOD;
		d[v][0] = (d[v][0] + a * d[u][0]) % MOD;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 1; i < n; i++){
		cin >> par[i];
		adj[par[i]].push_back(i);
	}
	for (ll i = 0; i < n; i++)	cin >> t[i];
	dfs(0);
	cout << d[0][1] << "\n";
	return	0;
}