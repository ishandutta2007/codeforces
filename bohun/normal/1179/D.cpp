#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)
#define po(x) cerr << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int mod = 1e9 + 7, nax = 500005;

int n;
int big[nax], siz[nax];
int a, b;
ll dp[nax];
vector <int> v[nax];
ll ans = 0;
ll jej = 2e18;
vector <pair<ll, ll>> good[nax];


ll daj(int x) {
	return (ll) x * x;
}

void dfs(int node, int p) {
	siz[node] = 1;
	for(auto it: v[node]) {
		if(it != p) {
			dfs(it, node);
			siz[node] += siz[it];
			if(siz[it] > siz[big[node]])
				big[node] = it;
		}
	}
}

void licz(int node, int p) {
	if(ss(v[node]) == 1 && p != -1) {
		dp[node] = 1;
		return ;
	}
	for(auto it: v[node]) {
		if(it == p)
			continue;
		licz(it, node);
		good[node].pb({dp[it] + daj(siz[node] - siz[it]), it});
	}
	sort(good[node].begin(), good[node].end());
	for(int i = 0; i <= min(40, ss(good[node]) - 1); ++i)
		for(int j = 0; j <= i - 1; ++j) {
			int x = good[node][i].se;
			int y = good[node][j].se;
			jej = min(jej, dp[x] + dp[y] + daj(n - siz[x] - siz[y]));
		}
	dp[node] = good[node][0].fi;
}
		
	

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	if(n == 2) {
		cout << 2;
		return 0;
	}
	int root = -1;
	for(int i = 1; i <= n; ++i) {
		if(ss(v[i]) > 1) {
			root = i;
			break;
		}
	}
	
	dfs(root, -1);	
	ans = (ll) n * (n - 1) / 2;
	licz(root, -1);
	ans += (daj(n) - jej) / 2;
	cout << ans;
	
	
	
	
				
	
	
	return 0;
}