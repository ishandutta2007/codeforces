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

int n,y,m,ans;
vi a, b;

void test(int x) {
    vi m;
    if (x == 0) {
        for (int i: a) m.pb(i);
        for (int i: b) m.pb(i);
    } else {
        
        for (int i: a) m.pb((i+x)%(2*x));
        for (int i: b) m.pb(i%(2*x));
    }
    sort(all(m));
    for (int i = 0; i < sz(m); ) {
        int I = i;
        while (i < sz(m) && m[i] == m[I]) i ++;
        ans = max(ans,i-I);
    }
}

int main() {
    io();
    cin >> n >> y; a.resize(n); F0R(i,n) cin >> a[i];
    cin >> m >> y; b.resize(m); F0R(i,m) cin >> b[i];
    test(0);
    for (int i = 1; i <= 1e9; i *= 2) test(i);
    cout << ans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/