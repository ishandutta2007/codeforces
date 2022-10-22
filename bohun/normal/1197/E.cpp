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
const int nax = 4e5 + 11, mod = 1e9 + 7;
int n;
pair <int, int> t[nax];
set <int> secik;
map <int, int> mapka, ans;
pair<int, int> dp[nax];
int dl[nax];
int maxi;

struct zd {
	int x, type, nr;
	bool operator < (zd a) {
		return mp(x, type) < mp(a.x, a.type);
	}
};
vector <zd> v;
	
int main() {	
	ios;
	cin >> n;
	FOR(i, 1, n) {
		cin >> t[i].fi >> t[i].se;
		swap(t[i].fi, t[i].se);
		zd L = {t[i].fi, 1, i};
		v.pb(L);
		zd R = {t[i].se, 0, i};
		v.pb(R);
		dl[i] = t[i].se - t[i].fi;
		maxi = max(maxi, t[i].fi);
	}
	
	secik.insert(0);
	mapka[0] = 1;
	
	sort(v.begin(), v.end());
	
	for(auto it: v) {
		if(it.type == 1) {
			int ways = mapka[*--secik.end()];
			int Size = dl[it.nr] + *--secik.end();
			dp[it.nr] = mp(ways, Size);
		}
		else {
			secik.insert(dp[it.nr].se);
			mapka[dp[it.nr].se] += dp[it.nr].fi;
			mapka[dp[it.nr].se] %= mod;
			if(it.x > maxi) {
			//	cout << it.nr << " "  << dp[it.nr].fi << " " << it.x - dp[it.nr].se << endl;
				ans[it.x - dp[it.nr].se] = (ans[it.x - dp[it.nr].se] + dp[it.nr].fi) % mod;
			}
		}
	}
	cout << (ans.begin())->se;
			
	
	
	
	return 0;
}