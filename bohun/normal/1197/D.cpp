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
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;		
const int mod = 1e9 + 7, nax = 300005;
int n, m, k;
int t[nax];
ll pref[nax], ans;
bitset <nax> ok;


int main() {
	ios
	cin >> n >> m >> k;
	FOR(i, n)
		cin >> t[i];
	for(int i = 1; i <= m; ++i) {
		ok.reset();
		for(int j = i; j <= n; j += m) 
			ok[j] = 1;
		for(int j = 1; j <= n; ++j) {
			pref[j] = pref[j - 1] + t[j];
			if(ok[j])
				pref[j] -= k;
		}
		ll best = -1e18;
		for(int j = n; 1 <= j; --j) {
			best = max(best, pref[j]);
			if(ok[j])
				ans = max(ans, best - pref[j - 1]);
		}
	}
	cout << ans;
		
		
		
			
		
	
	
	
	
	return 0;
}