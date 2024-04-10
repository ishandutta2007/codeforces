
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
const int MX = 1000001;

vi adj[MX];
int n, depth[MX], ans[MX];

struct HeavyLightSet {
    int val[MX];
    vi child[MX];
    unordered_map<int,int> dat[MX];
    pi bes[MX];
    
    void comb(int a, int b) {
        bool swa = 0;
        if (sz(dat[a]) < sz(dat[b])) swap(a,b), swa = 1;
        for (auto& x: dat[b]) {
            dat[a][x.f] += x.s;
            bes[a] = max(bes[a],{dat[a][x.f],-x.f});
        }
        //cout << "ZZ " << a << " " << b << "\n";
        dat[b].clear();
        if (swa) {
            swap(dat[a],dat[b]);
            swap(bes[a],bes[b]);
        }
    }
    
    void process(int ind) {
        dat[ind][depth[ind]] ++; 
        bes[ind] = {1,-depth[ind]};
        for (int i: child[ind]) {
            process(i); 
            comb(ind,i);
        }
        //cout << "OH " << ind << " " << bes[ind].f << " " << bes[ind].s << "\n";
        //for (auto a: dat[ind]) cout << a.f << " " << a.s << "\n";
        ans[ind] = -bes[ind].s-depth[ind];
        // now do stuff with values
    }
};

HeavyLightSet H;

void dfs(int a, int b) {
    for (int i: adj[a]) if (i != b) {
        H.child[a].pb(i);
        depth[i] = depth[a]+1;
        dfs(i,a);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1,0);
    H.process(1);
    FOR(i,1,n+1) cout << ans[i] << "\n";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/