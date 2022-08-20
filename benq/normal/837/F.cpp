/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n;
ll k;
vector<pii> x;

ll eval(ll mid, int denom, int init) {
    long double ans = init;
    if ((ll)denom > mid) {
        int t = mid;
        mid = denom;
        denom = t;
    }
    FOR(i,1,denom+1) {
        ans *= (i+mid);
        ans = round(ans/i);
        if (ans >= k) return k;
    }
    return ans;
}

bool ok (ll mid) {
    ll tmp = 0;
    F0R(i,x.size()) {
        tmp += eval(mid,x[i].f,x[i].s);
        if (tmp >= k) return 1;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	F0R(i,n) {
	    int t; cin >> t;
	    if (t >= k) {
	        cout << 0;
	        return 0;
	    }
	    if (t > 0) x.pb({n-1-i,t});
	}
	
	ll lo = 0, hi = 1e18;
	while (lo < hi) {
	    ll mid = (lo+hi)/2;
	    if (ok(mid)) hi = mid;
	    else lo = mid+1;
	}
	
	cout << lo+1;
}