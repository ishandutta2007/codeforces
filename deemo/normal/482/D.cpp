#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;
const ll MOD = 1e9 + 7;

ll n;
vector<ll>	adj[MAXN];
ll d[MAXN][3];

void dfs(ll v){
	if (adj[v].size() == 0){
		d[v][0] = d[v][1] = 1;
		return;
	}

	d[v][0] = 1;
	ll cc = 1, dd = 0, ee = 1;
	for (ll u:adj[v]){
		dfs(u);

		ll a = d[v][0], b = d[v][1];
		d[v][0] = (a * d[u][0]) % MOD;
		d[v][0] = (d[v][0] + b * d[u][1]) % MOD;
		d[v][1] = (a * d[u][1]) % MOD;
		d[v][1] = (d[v][1] + b * d[u][0]) % MOD;

		cc = (cc * d[u][0]) % MOD;
		a = dd, b = ee;
		dd = (dd + b * d[u][1]) % MOD;
		ee = (ee + a * d[u][1]) % MOD;
	}
	
	d[v][0] = (d[v][0] * 2) % MOD;
	d[v][1] = (d[v][1] * 2) % MOD;

	d[v][0] = (d[v][0] + MOD - cc) % MOD;
	d[v][1] = (d[v][1] + MOD - dd) % MOD;
	swap(d[v][0], d[v][1]);
	d[v][0] = (d[v][0] + 1) % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 1; i < n; i++){
		ll p;	cin >> p;	p--;
		adj[p].push_back(i);
	}
	dfs(0);
	cout << (d[0][0] + d[0][1] + MOD - 1) % MOD << "\n";
	return	0;
}