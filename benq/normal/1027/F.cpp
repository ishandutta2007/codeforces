#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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
const int MX = 2000005;


int tmp = chrono::high_resolution_clock::now().time_since_epoch().count();

template<class T> struct hsh {
    size_t operator()(const T& x) const {
        return hash<T>{}(x)^tmp;
    }
};

template<class a, class b> using um = unordered_map<a,b,hsh<a>>;

int n;
um<int,int> m;
vpi v;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ], co[SZ];
    vi tmp[SZ];
    
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }
    
    int get(int x) { // path compression
    	if (par[x] != x) par[x] = get(par[x]);
    	return par[x];
    }
    
    bool unite(int x, int y) { // union-by-rank
    	x = get(x), y = get(y);
    	if (sz[x] < sz[y]) swap(x,y);
    	co[x] ++;
    	if (x == y) return 0;
    	sz[x] += sz[y], co[x] += co[y], par[y] = x;
    	return 1;
    }
};

DSU<MX> D;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        int x,y; cin >> x >> y;
        m[x] = m[y] = 0;
        v.pb({x,y});
    }
    int co = 0;
    for (auto& a: m) a.s = co++;
    for (auto a: v) D.unite(m[a.f],m[a.s]);
    for (auto& a: m) D.tmp[D.get(a.s)].pb(a.f);
    
    int cans = 0;
    F0R(i,sz(m)) if (D.get(i) == i) {
        if (D.co[i] > D.sz[i]) {
            cout << -1;
            exit(0);
        }
        sort(all(D.tmp[i]));
        if (D.co[i] == D.sz[i]) {
            cans = max(cans,D.tmp[i].back());
        } else {
            cans = max(cans,D.tmp[i][sz(D.tmp[i])-2]);
        }
    }
    cout << cans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/