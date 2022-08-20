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

ll get(ll mx) {
    return (mx*(mx+1)/2) % MOD;
}

ll case1(ll s, ll x, ll y, ll k, ll ad) {
    ll div = y/s;
    ll temp = (get(min(div*s,k))+min(div*s,k)*ad) % MOD;
    return temp*s % MOD;
}

ll case2(ll s, ll x, ll y, ll k, ll ad) {
    ll div = y/s;
    ll up = min((div+1)*s,k);
    if (up > div*s) {
    	ll temp = (get(up)-get(div*s)+(up-div*s)*ad) % MOD;
    	return (temp*(y-div*s)) % MOD;
    }
    return 0;
}

ll case3(ll s, ll x, ll y, ll k, ll ad) {
    // case 3: upper rectangles excluding one case
    ll div = y/s;
    ll up = min((div/2)*2*s,k);
    ll temp = (get(up)+up*ad) % MOD;
    return (temp*(x-s)) % MOD;
}

ll query (ll x, ll y, ll k, ll ad) { 
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x>y) swap(x,y);
    
    ll s = 1; 
    while (2*s <= x) s *= 2; // correct
    ll div = y/s;
    ll ans = (case1(s,x,y,k,ad)+case2(s,x,y,k,ad)+case3(s,x,y,k,ad)) % MOD;
    if (div % 2 == 1) {
        ll lo = div*s+1, hi = min((div+1)*s,k);
        if (lo <= hi) {
        	ll temp = (get(hi)-get(lo-1)+ad*(hi-lo+1)) % MOD;
        	temp = temp*(x-s) % MOD;
        	ans = (ans+temp) % MOD;
        }
        return (ans+query(x%s,y%s,k-(div-1)*s,(div-1)*s+ad)) % MOD;
    } else {
        return (ans+query(x%s,y%s,k-(div+1)*s,(div+1)*s+ad)) % MOD;
    }
}

int main() {
    int q; cin >> q;
    F0R(i,q) {
        ll x1,x2,y1,y2,k; cin >> x1 >> y1 >> x2 >> y2 >> k;
        ll ans = query(x2,y2,k,0)-query(x1-1,y2,k,0)-query(x2,y1-1,k,0)+query(x1-1,y1-1,k,0);
        ans %= MOD; while (ans<0) ans += MOD;
        cout << ans << "\n";
    }
} 

// 860235199