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

map<ll,vpl> m;

vpl comb(vpl a, vpl b) {
    int ia = 0, ib = 0;
    vpl c;
    while (ia < sz(a) && ib < sz(b)) {
        if (a[ia].f < b[ib].f) {
            c.pb(b[ib++]);
        } else if (a[ia].f > b[ib].f) {
            c.pb(a[ia++]);
        } else {
            c.pb({a[ia].f,a[ia].s+b[ib].s});
            ia ++, ib ++;
        }
    }
    while (ia < sz(a)) c.pb(a[ia++]);
    while (ib < sz(b)) c.pb(b[ib++]);
    return c;
}

vpl get(ll x) {
    if (m.count(x)) return m[x];
    if (x == 0) return {};
    return m[x] = comb(comb(get((x-1)/2),{{(x-1)/2,1}}),get(x/2));
}

ll co(vpl& x, ll y) {
    for (auto a: x) if (a.f == y) return a.s;
    return 0;
}

ll search(ll x, ll y) {
    vpl a = get((x-1)/2), b = get(x/2), c = get(x);
    
    ll ca = 0, cb = 0;
    for (auto z: c) {
        if (z.s < y) {
            ca += co(a,z.f);
            cb += co(b,z.f);
            y -= z.s;
        } else {
            ll A = co(a,z.f);
            if (A >= y) return search((x-1)/2,ca+y);
            y -= A;
            if (z.f == (x-1)/2) {
                if (y == 1) return (x+1)/2;
                y --;
            }
            return (x+1)/2+search(x/2,cb+y);
        }
    }
    
    exit(5);
}

ll get(ll n, ll k) {
    if (k == 1) return 1;
    if (k == 2) return n;
    return search(n-2,k-2)+1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k; 
    while (cin >> n >> k) {
        cout << get(n,k) << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/