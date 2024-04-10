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

int n,k;
vpi adj[MX];

pi dfs(int x, int y) {
    vpi v;
    for (auto a: adj[x]) if (a.f != y){
        auto z = dfs(a.f,x);
        v.pb({z.f+a.s,z.s+a.s});
    }
    int a = 0, b = 0, nex = 0;
    // z.f: k-1 then return 
    // z.s: k-1 then go
    sort(all(v)); reverse(all(v));
    F0R(i,min(sz(v),k-1)) a += v[i].f;
    if (sz(v) >= k) nex = v[k-1].f;
    F0R(i,sz(v)) {
        if (i < k-1) {
            b = max(b,a-v[i].f+nex+v[i].s);
        } else {
            b = max(b,a+v[i].s);
        }
    }
    // cout << x << " " << y << " " << a << " " << b << "\n";
    return {a,b};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    F0R(i,n-1) {
        int u,v,c; cin >> u >> v >> c;
        adj[u].pb({v,c}), adj[v].pb({u,c});
    }
    cout << dfs(0,-1).s;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/