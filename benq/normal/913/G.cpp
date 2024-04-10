#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}


namespace RPM {
    const int bits = 15; // if all numbers are less than 2^k, set bits = 63-k
    const ll po = 1<<bits;
    
    ll mod_mul(ll a, ll b, ll &c) {  // return (__int128(a)*b) % c;
    	ll x = 0;
    	for (; b; b >>= bits, a = (a << bits) % c) 
    		x = (x + (a * (b & (po-1))) % c) % c;
    	return x;
    }
    
    ll mod_pow(ll a, ll b, ll mod) {
    	if (b == 0) return 1;
    	ll res = mod_pow(a, b / 2, mod);
    	res = mod_mul(res, res, mod);
    	if (b & 1) return mod_mul(res, a, mod);
    	return res;
    }
}

using namespace RPM;

ll po5[18];
pl tmp[18];

void solve() {
    ll a; cin >> a; a *= 1000000;
    a = ((a>>17)+1)<<17; // congruent to this mod 10^16 
    if (a % 5 == 0) a += 1<<17;
    
    ll ans = 0, cur = 1;
    FOR(i,1,18) {
        ll des = a % po5[i];
        while (cur % po5[i] != des) {
            cur = mod_mul(cur,tmp[i].f,po5[17]);
            ans += tmp[i].s;
        }
    }
    
    if (ans < 17) ans += 4*po5[16];
    cout << ans << "\n";
}

int main() {
    io();
    po5[0] = 1;
    FOR(i,1,18) po5[i] = 5*po5[i-1];
    FOR(i,1,18) {
        if (i == 1) tmp[i].s = 1;
        else if (i == 2) tmp[i].s = 4;
        else tmp[i].s = 5*tmp[i-1].s;
        tmp[i].f = mod_pow(2,tmp[i].s,po5[17]);
    }
    int n; cin >> n;
    F0R(i,n) solve();
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/