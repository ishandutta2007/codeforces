//Don't you ever say I just walked away..

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 50;

ll n;
vector<ll>	adj[MAXN];
ll c[MAXN];
ll f[MAXN], g[MAXN];

ll dfs(ll v, ll p = -1){
	if (adj[v].empty())
		return	f[v] = c[v];

	int sz = adj[v].size();
	vector<ll>	od(sz), ev(sz);

	ll cn = 0;
	for (ll u:adj[v]){
		dfs(u);
		if (cn == 0){
			od[cn] = f[u];
			ev[cn++] = g[u];
		}
		else{
			od[cn] = max(od[cn - 1], f[u] + ev[cn - 1]);
			od[cn] = max(od[cn], g[u] + od[cn - 1]);
			ev[cn] = max(ev[cn - 1], f[u] + od[cn - 1]);
			ev[cn] = max(ev[cn], g[u] + ev[cn - 1]);
			cn++;
		}
	}
	
	cn--;
	f[v] = od[cn];
	f[v] = max(f[v], c[v] + ev[cn]);
	g[v] = ev[cn];
	return	max(f[v], g[v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		ll p;	cin >> p >> c[i];	p--;
		if (i)
			adj[p].push_back(i);
	}
	cout << dfs(0) << endl;
	return 0;
}