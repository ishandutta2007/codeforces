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

int t;
vl n(3),m(3),s(4);

ll get(vpi& b, ll n, ll cur, int ind) {
    if (ind == sz(b)) return cur <= n;
    ll ret = 0;
    F0R(i,b[ind].s+1) {
        ret += get(b,n,cur,ind+1);
        cur *= b[ind].f;
    }
    return ret;
}

ll get2(vl& c, ll m, int ind, int sgn) {
    if (ind == sz(c)) return sgn*m;
    return get2(c,m,ind+1,sgn)+get2(c,m/c[ind],ind+1,-sgn);
}

map<int,int> fac(vl v) {
    map<int,int> m;
    for (ll x: v) {
        for (int i = 2; i*i <= x; ++i) {
            while (x % i == 0) {
                m[i] ++;
                x /= i;
            }
        }
        if (x > 1) m[x] ++;
    }
    return m;
}

ll solve() {
    F0R(i,3) cin >> n[i];
    F0R(i,3) cin >> m[i];
    F0R(i,3) cin >> s[i];
    
    auto a = fac(n), b = fac(s);
    auto B = vpi(all(b));
    
    // x divides 2s 
    // gcd(n,k) for 1 <= k <= m 
    // for each prime dividing a if pow_a(p) > pow_b(p) we don't want any multiples of p*p^{powb_p} 
    vl c;
    for (auto p: a) if (p.s > b[p.f]) {
        ll bad = 1; F0R(i,b[p.f]+1) bad *= p.f;
        c.pb(bad);
    }
    
    // k for 1 <= k <= n 
    return get2(c,m[0]*m[1]*m[2],0,1)+get(B,n[0]*n[1]*n[2],1,0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    s[3] = 2;
    cin >> t;
    F0R(i,t) cout << solve() << "\n";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/