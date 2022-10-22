#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;
const int nax = 3e5 + 111, mod = 998244353;
int n, a, b;
vector <int> v[nax];	
int dp[nax][3];

int pt(int a, int b) {
	int r = 1; while(b) { if(b & 1) r = (ll) a * r % mod; a = (ll) a * a % mod; b /= 2;} return r;
}

void dfs(int u, int p) {
	for(auto it: v[u]) 
		if(it != p) 
			dfs(it, u);
	
	int sum = 1;
	for(auto it: v[u]) 
		if(it != p) 
			sum = (ll) sum * (dp[it][0] + dp[it][1]) % mod;
			
	dp[u][2] = sum;
	for(auto it: v[u]) 
		if(it != p)
			dp[u][1] = (dp[u][1] + (ll) sum * dp[it][2] % mod * pt(dp[it][0] + dp[it][1], mod - 2) % mod) % mod;
	dp[u][0] = dp[u][1];
	sum = 1;
	for(auto it: v[u])
		if(it != p)
			sum = (ll) sum * dp[it][0] % mod;
	dp[u][0] = (dp[u][0] + sum) % mod;
}
			
	
	
int main() {	
	ios;
	cin >> n;
	FOR(i, 1, n - 1) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(1, 0);
	cout << dp[1][0];
	
	
	
	
	
	return 0;
}