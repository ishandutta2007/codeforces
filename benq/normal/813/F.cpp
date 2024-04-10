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
const int MX = 1<<17;

struct DSU2 {
    pi par[MX];
    int sz[MX];
    vi change;
    
    DSU2() {
        F0R(i,MX) {
            par[i] = {i,0};
            sz[i] = 1;
        }
    }
    
    pi getPar(int a) {
        if (par[a].f == a) return par[a];
        auto x = getPar(par[a].f); x.s ^= par[a].s;
        return x;
    }
    
    bool unite(int a, int b) {
        pi x = getPar(a), y = getPar(b);
        if (x.f == y.f) {
            if (x.s == y.s) return 1;
            change.pb(-1); return 0;
        }
        if (sz[x.f] < sz[y.f]) swap(x,y);
        par[y.f] = {x.f,1^x.s^y.s}; sz[x.f] += sz[y.f];
        change.pb(y.f); return 0;
    }
    
    void rev() {
        if (change.back() != -1) {
            sz[par[change.back()].f] -= sz[change.back()];
            par[change.back()] = {change.back(),0};
        }
        change.pop_back();
    }
};

DSU2 D;

int n,q;
vpi seg[2*MX];
bool ans[MX];
map<pi,int> m;

void ad(int l, int r, pi x, int ind = 1, int L = 0, int R = MX-1) {
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        seg[ind].pb(x);
        return;
    }
    int M = (L+R)/2;
    ad(l,r,x,2*ind,L,M);
    ad(l,r,x,2*ind+1,M+1,R);
}

void genAns(int ind = 1, int L = 0, int R = MX-1, bool bad = 0) {
    int co = 0;
    if (!bad) {
        for (auto a: seg[ind]) {
            if (D.unite(a.f,a.s)) {
                bad = 1;
                break;
            }
            co ++;
        }
    }
    if (L == R) ans[L] = bad;
    else {
        int M = (L+R)/2;
        genAns(2*ind,L,M,bad);
        genAns(2*ind+1,M+1,R,bad);
    }
    F0R(i,co) D.rev();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    F0R(i,q) {
        int x,y; cin >> x >> y;
        if (m.count({x,y})) {
            ad(m[{x,y}],i-1,{x,y});
            m.erase({x,y});
        } else {
            m[{x,y}] = i;
        }
    }
    for (auto a: m) ad(a.s,q-1,a.f);
    genAns();
    F0R(i,q) {
        if (ans[i]) cout << "NO";
        else cout << "YES";
        cout << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/