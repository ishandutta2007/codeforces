#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<map>

using namespace std;

typedef long long ll;

const ll max_n = 3e5 + 10;
const ll MOD = 1e9 + 7;
const ll BASE = 721;
const ll MOD2 = 1e9 + 7;
const ll BASE2 = 71;

ll n;
ll c[max_n];
char ss[max_n];
ll save[max_n], save2[max_n];
set<pair<ll, ll>>	st[max_n];
ll ans[max_n], id[max_n];
ll depth[max_n], max_depth;
vector<ll>	adj[max_n];
ll h[max_n], h2[max_n], add2[max_n], add[max_n];

void init(){
	save[0] = 1;
	for (ll i = 1; i < max_n; i++)
		save[i] = (save[i - 1] * BASE) % MOD;
	save2[0] = 1;
	for (ll i = 1; i < max_n; i++)
		save2[i] = (save2[i - 1] * BASE2) % MOD2;
}

void dfs(ll v,ll par){
	if (adj[v].size() == 0 || (adj[v].size() == 1 && par != -1)){
		add[v] = add2[v] = 0;
		id[v] = v;
		st[v].insert({h[v], h2[v]});
		ans[v] = 1;
		return;
	}
	
	for (ll u:adj[v])
		if (u != par)	dfs(u, v);

	ll maxi = -1, ind = -1;
	for (ll i = 0; i < adj[v].size(); i++){
		ll u = adj[v][i];
		if (u != par && (ll)st[id[u]].size() > maxi){
			maxi = st[id[u]].size();
			ind = u;
		}
	}

	id[v] = id[ind];
	for (ll u:adj[v]){
		if (u == par || u == ind)	continue;
		for (pair<ll, ll> x:st[id[u]]){
			x.first = (x.first + add[id[u]]) % MOD;
			x.first = (x.first + MOD - add[id[v]]) % MOD;
			x.second = (x.second + add2[id[u]]) % MOD2;
			x.second = (x.second + MOD2 - add2[id[v]]) % MOD2;
			st[id[v]].insert(x);
		}
		st[id[u]].clear();
	}
	st[id[v]].insert({(0 + MOD - add[id[v]]) % MOD, (0 + MOD2 - add2[id[v]]) % MOD});
	add[id[v]] = (add[id[v]] + h[v]) % MOD;
	add2[id[v]] = (add2[id[v]] + h2[v]) % MOD2;
	ans[v] = st[id[v]].size();
}

void run(ll v, ll par, ll de){
	depth[v] = de;
	for (ll u:adj[v])
		if (par != u)
			run(u, v, de + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> c[i];
	for (ll i = 0; i < n; i++)	cin >> ss[i];
	for (ll i = 0; i < n - 1; i++){
		ll a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	run(0, -1, 0);
	max_depth = 0;
	for (ll i = 0; i < n; i++)
		max_depth = max(max_depth, depth[i]);
	for (ll i = 0; i < n; i++){
		h[i] = (ss[i] * save[max_depth - depth[i]]) % MOD;
		h2[i] = (ss[i] * save2[max_depth - depth[i]]) % MOD2;
	}	
	
	dfs(0, -1);
	ll maxi = -1;
	for (ll i = 0; i < n; i++)
		maxi = max(maxi, c[i] + ans[i]);
	ll ret = 0;
	for (ll i = 0; i < n; i++)
		if (maxi == c[i] + ans[i])	ret++;
	cout << maxi << endl;
	cout << ret << endl;
	return 0;
}