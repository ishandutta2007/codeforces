#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 1e5 + 10;

ll n, val[MAXN], ans;
vector<pair<ll, ll>>	adj[MAXN];

void dfs(ll v, ll p = -1, ll de = 0, bool burn = 0){
	burn |= de > val[v];
	if (burn)	ans++;
	for (auto e:adj[v])
		if (e.F ^ p)
			dfs(e.F, v, max(0LL, de + e.S), burn);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> val[i];
	for (ll i = 1; i < n; i++){
		ll a, b;	cin >> a >> b, a--;
		adj[a].push_back({i, b});
		adj[i].push_back({a, b});
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}