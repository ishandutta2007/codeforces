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
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;		
const int nax = (1 << 20) + 1, mod = 1e9 + 7, N = 1e6;
int n, t[nax];
int pot[nax];
int dp[nax][21];
int ans;

int daj(int x, int y) {
	if(x < nax)
		return dp[x][y];
	return 0;
}	

int main() {
	ios
	cin >> n;
	FOR(i, 1, n) {
		cin >> t[i];
		dp[t[i]][0]++;
	}
	pot[0] = 1;
	FOR(i, 1, N)
		pot[i] = (ll) pot[i - 1] * 2 % mod;
	FOR(j, 1, 20) 
		FOR(i, 0, N) {
			if((1 << (j - 1)) & i)
				dp[i][j] = dp[i][j - 1];
			else 
				dp[i][j] = dp[i][j - 1] + daj((i ^ (1 << (j - 1))), j - 1);
			}
	ans = pot[n] - 1;
	FOR(i, 1, N) {
		if(!dp[i][20])
			continue;
		int x = __builtin_popcount(i);
		x = (x % 2 == 0 ? 1 : -1);
		ans = ((ll) ans + x * (pot[dp[i][20]] - 1) + mod) % mod;
	}
	
	cout << ans;
	
	
	
	
	
	
	
	return 0;
}