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

namespace ModOp {
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    int ad(int a, int b) { return (a+b)%MOD; }
    int sub(int a, int b) { return (a-b+MOD)%MOD; }
    int mul(int a, int b) { return (ll)a*b%MOD; }
    
    int AD(int& a, int b) { return a = ad(a,b); }
    int SUB(int& a, int b) { return a = sub(a,b); }
    int MUL(int& a, int b) { return a = mul(a,b); }
}

using namespace ModOp;

int n;
vpi adj[MX];
pi ret[MX];

void dfs(int x, int y) {
    pi sum = {0,0};
    if (sz(adj[x]) == 1) {
        ret[x] = sum;
        return;
    }
    for (auto i: adj[x]) {
        if (i.f != y) {
            dfs(i.f,x);
            AD(sum.f,ret[i.f].f);
            AD(sum.s,ad(ret[i.f].s,i.s));
        } else {
            AD(sum.s,i.s);
        }
    }
    // ans[x] = (sum.f*ans[x]+sum.s+ans[par[x]])/sz(adj[x])
    // (sz(adj[x])-sum.f)*ans[x] = ans[par[x]]+sum.s
    ret[x].f = inv(sub(sz(adj[x]),sum.f));
    ret[x].s = mul(ret[x].f,sum.s);
    // cout << x << " " << ret[x].f << " " << ret[x].s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n-1) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].pb({b,c}), adj[b].pb({a,c});
    }
    dfs(0,-1);
    cout << ret[0].s;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/