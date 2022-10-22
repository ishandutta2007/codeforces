#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, w[MAXN];
vector<ll>	adj[MAXN], sec[MAXN], gec[MAXN];
ll d[MAXN];

ll solve(ll v, ll p = -1){
	ll sm = 0;
	for (ll u:adj[v])
		if (u != p){
			sec[v].push_back(solve(u, v) + 1);
			sm += w[u];
		}
	
	ll i;
	sort(sec[v].begin(), sec[v].end(), greater<ll>());
	for (i = 0; i < w[v] && i < sec[v].size(); i++)
		d[v] += sec[v][i] + 1;
	w[v] -= i;
	ll z = min(w[v], sm);
	d[v] += z * 2;
	w[v] -= z;
	return	d[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> w[i];
	for (ll i = 0; i < n - 1; i++){
		ll a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll s;	cin >> s;	s--;
	for (int i = 0; i < n; i++)	if (i != s)	w[i]--;
	cout << solve(s) << "\n";
	return	0;
}