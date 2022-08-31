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

pll cum[1000001];
int n,x,y,num;
ll ans = 1e18;

ll test(int gcd) {
    ll cur = 0;
    for (int i = 1; ; ++i) {
        ll lo = (i-1)*gcd, hi = i*gcd;
        if (hi >= 1000000) {
            // (lo,f) should delete
            ll f = min(1000001LL,max(lo+1,hi-num)); // do stuff
            cur += (cum[f-1].s-cum[lo].s)*x;
            ll cnt = cum[1000000].s-cum[f-1].s;
            cur += (cnt*hi-(cum[1000000].f-cum[f-1].f))*y;
            if (cnt*hi-(cum[1000000].f-cum[f-1].f) >= 1e18/y) return ans;
            if (cur > ans) return ans;
            return cur;
        } else {
            ll f = max(lo+1,hi-num);
            cur += (cum[f-1].s-cum[lo].s)*x;
            ll cnt = cum[hi].s-cum[f-1].s;
            if (cnt*hi-(cum[hi].f-cum[f-1].f) >= 1e18/y) return ans;
            cur += (cnt*hi-(cum[hi].f-cum[f-1].f))*y;
            if (cur > ans) return ans;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> x >> y; num = x/y; // do at most num incrementations
	F0R(i,n) {
	    int z; cin >> z;
	    cum[z].f += z, cum[z].s ++;
	}
	FOR(i,1,1000001) {
	    cum[i].f += cum[i-1].f;
	    cum[i].s += cum[i-1].s;
	}
	FOR(i,2,1000001) ans = min(ans,test(i));
	cout << ans;
}

// read!
// ll vs. int!