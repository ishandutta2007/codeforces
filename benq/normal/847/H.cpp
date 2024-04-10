#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
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

int n;
pll lef[100000], ri[100000];
vector<ll> x;
ll ans = 1e18;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; x.resize(n);
	F0R(i,n) cin >> x[i];
	F0R(i,n) {
	    if (i == 0) lef[i] = {x[i],0};
	    else {
	        lef[i].f = max(lef[i-1].f+1,x[i]);
	        lef[i].s = lef[i-1].s+lef[i].f-x[i];
	    }
	}
	F0Rd(i,n) {
	    if (i == n-1) ri[i] = {x[i],0};
	    else {
	        ri[i].f = max(ri[i+1].f+1,x[i]);
	        ri[i].s = ri[i+1].s+ri[i].f-x[i];
	    }
	}
	F0R(i,n) {
	    ll cost = lef[i].s+ri[i].s;
	    cost -= min(lef[i].f-x[i],ri[i].f-x[i]);
	    ans = min(ans,cost);
	}
	cout << ans;
}

// read!
// ll vs. int!