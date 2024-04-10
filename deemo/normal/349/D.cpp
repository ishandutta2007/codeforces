#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;
const ll INF = 2e8;
const ll ZZ = 1e13 + 10;

ll n, sm, val[MAXN], save[MAXN], mx = ZZ, ss[MAXN], d[MAXN];
bool fail = 0;
vector<ll>	adj[MAXN];

void dfs(ll v, ll p = -1){
	ss[v] = 1;
	if (adj[v].size() == 1 && p != -1){
		d[v] = 1;
		return;
	}
	
	ll lcm = 1;
	for (ll u:adj[v])
		if (u != p){
			dfs(u, v);
			ll z = lcm/ __gcd(lcm, d[u]);
			if (ZZ / z > d[u])	lcm = z * d[u];
			else	lcm = ZZ;
		}

	for (int u:adj[v])
		if (u != p){
			d[v] = min(ZZ, d[v] + lcm);
			if (ZZ/ss[u] > lcm/d[u])	ss[u] *= lcm/d[u];
			else	ss[u] = ZZ;
		}
	if (d[v] >= ZZ)	fail = 1;
}	

void check(ll v, ll s = 1, ll p = -1){
	if (ZZ/s > ss[v])	s *= ss[v];
	else	s = ZZ;
	if (adj[v].size() == 1 && p != -1){
		save[v] = s;
		mx = min(mx, val[v]/ s);
		return;
	}
	for (ll u:adj[v])	if (u != p)	check(u, s, v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (ll i = 0; i < n; i++)	cin >> val[i], sm += val[i];	for (ll i = 0; i < n - 1; i++){ ll a, b;	cin >> a >> b; a--, b--;	adj[a].push_back(b), adj[b].push_back(a);}	dfs(0);
	check(0);
	if (mx == 0||fail){
		cout << sm << "\n";
		return 0;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)	if (val[i])	ans += val[i] - mx * save[i];
	cout << ans << "\n";
	return	0;
}