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

namespace mapOp {
    const int tmp = chrono::high_resolution_clock::now().time_since_epoch().count();

    template<class T> struct hsh {
        size_t operator()(const T& x) const { 
            return hash<T>{}(x)^tmp; // avoid anti-hash tests?
        }
    };

    template<class a, class b> using um = gp_hash_table<a,b,hsh<a>>;

    template<class a, class b> b get(um<a,b>& u, a x) {
        if (u.find(x) == u.end()) return 0;
        return u[x];
    }
}

using namespace mapOp;

ll sim(int x, int y) {
    int g = __gcd(x,y);
    x /= g, y /= g;
    return 1000000LL*x+y;
}

int q, num;
um<ll,vpi> m;
um<ll,int> z;

void upd(vpi& v, pi x, int t) {
    num += t;
    if (t == 1) {
        z[sim(x.f,x.s)] ++;
        for (auto a: v) z[sim(a.f+x.f,a.s+x.s)] += 2;
        v.pb(x);
    } else {
        z[sim(x.f,x.s)] --;
        v.erase(find(all(v),x));
        for (auto a: v) z[sim(a.f+x.f,a.s+x.s)] -= 2;
    }
}

ll dist(ll x, ll y) {
    return x*x+y*y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> q;
    F0R(i,q) {
        ll t,x,y; cin >> t >> x >> y;
        if (t == 1) {
            upd(m[dist(x,y)],{x,y},1);
        } else if (t == 2) {
            upd(m[dist(x,y)],{x,y},-1);
        } else {
            cout << num-get(z,sim(x,y)) << "\n";
        }
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/