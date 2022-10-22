#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;		
const int nax = 505, mod = 998244353;
int n, m;
int p[nax], sa[nax];	
int dp[nax][nax];
int mini[nax][nax];

int daj(int l, int r) {
	if(l > r)
		return 1;
	return dp[l][r];
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &p[i]);
		sa[p[i]] = i;
	}
	
	for(int dl = 1; dl <= n; ++dl)
		for(int l = 1; l + dl - 1 <= n; ++l) {
			int r = dl + l - 1;
			if(dl == 1)
				mini[l][r] = p[l];
			else
				mini[l][r] = min(mini[l + 1][r], mini[l][r - 1]);
			}
		
	
	for(int dl = 1; dl <= n; ++dl) {
		for(int l = 1; l + dl - 1 <= n; ++l) {
			int r = dl + l - 1;
			if(dl == 1)
				dp[l][r] = 1;
			else {
				int x = sa[mini[l][r]];
				ll u = 0;
				for(int k = l; k <= x; ++k)
					u = (u + (ll) daj(l, k - 1) * daj(k, x - 1) % mod) % mod;
				ll w = 0;
				for(int k = x; k <= r; ++k)
					w = (w + (ll) daj(x + 1, k) * daj(k + 1, r) % mod) % mod;
				dp[l][r] = (ll) u * w % mod;
			}
		}
	}
	printf("%d", dp[1][n]);
				
	
	
	
	
	
	return 0;
}