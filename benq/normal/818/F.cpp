#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

ll solve(ll n) {
	ll lo = 0, hi = n-1; // num bridges	
	// first one such that at least half
	while (lo<hi) {
		ll mid = (lo+hi)/2;
		ll res = (n-mid)*(n-mid-1)/2;
		if (mid < res) lo = mid+1;
		else hi = mid;
	}
	ll ans = 0;
	ans = max(ans,2*(lo-1));
	ans = max(ans,lo+(n-lo)*(n-lo-1)/2);
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q; cin >> q;
	F0R(i,q) {
		int n; cin >> n;
		cout << solve(n) << "\n";
	}
}

// read!
// ll vs. int!