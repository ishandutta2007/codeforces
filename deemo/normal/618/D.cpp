#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

typedef long long ll;

const ll MAXN = 3e5 + 10;

ll n, x, y, cnt[MAXN];
ll d[MAXN], dd[MAXN];
vector<ll>	adj[MAXN];

void dfs(ll v, ll p = -1){
	if (adj[v].size() == 1 && p != -1){
		d[v] = dd[v] = 1;
		return;
	}

	d[v] = dd[v] = 1;
	ll m1 = -10, m2 = -10;
	for (ll u:adj[v])
		if (u != p){
			dfs(u, v);
			d[v] += d[u];
			m2 = max(m2, d[u] - dd[u]);
			if (m2 > m1)	swap(m1, m2);
		}


	dd[v] = d[v];
	if (m1 >= 0)
		dd[v] = min(dd[v], (d[v] - 1 - m1));

	if (m1 >= 0)
		d[v] = min(d[v], d[v] - 1 - m1);
	if (m2 >= 0)
		d[v] = min(d[v], d[v] - 1 - (m1 + m2));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x >> y;
	ll c = n;
	bool fl = 0;
	for (ll i = 0; i < n - 1; i++){
		ll a, b;	cin >> a >> b;	a--, b--;
		cnt[a]++;
		cnt[b]++;
		if (cnt[a] == 2)	c--;
		if (cnt[b] == 2)	c--;
		if (cnt[a] == n - 1 || cnt[b] == n - 1)	fl = 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (y <= x){
		if (!fl)
			cout << y * (n - 1) << "\n";
		else
			cout << y * (n - 2) + x << "\n";
	}
	else{
		dfs(0);
		cout << (d[0] - 1) * y + (n - 1 - (d[0] - 1)) * x << "\n";
	}
	return	0;
}