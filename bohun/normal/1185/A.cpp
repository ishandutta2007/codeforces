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

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int mod = 1e9 + 7, nax = 200005;

int t[3], d, a, b, c;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll res = 0;
	cin >> t[0] >> t[1] >> t[2] >> d;
	sort(t, t + 3);
	if(t[1] - t[0] < d) {
		res += d - t[1] + t[0];
	}
	if(t[2] - t[1] < d) {
		res += (ll) d - t[2] + t[1];
	}
	cout << res;
	
	
						
	
	
				
	
	
	return 0;
}