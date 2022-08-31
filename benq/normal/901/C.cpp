#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 300001;

int n,m, lo[MX];
ll cumlo[MX];

template<int SZ> struct BCC {
    int N, ti = 0;
    vi adj[SZ];
    int disc[SZ], low[SZ], comp[SZ], par[SZ];
    vector<vector<pi>> fin;
    vector<pi> st;
    
    void addEdge(int u, int v) {
        adj[u].pb(v), adj[v].pb(u);
    }
    
    void ad(int u, int i) {
        int mn = u, mx = u;
        while (u != i) {
            u = par[u];
            mn = min(mn,u), mx = max(mx,u);
        }
        lo[mn] = min(lo[mn],mx-1);
    }
    
    void BCCutil(int u) {
        disc[u] = low[u] = ti++;
        int child = 0;
        
        for (int i: adj[u]) if (i != par[u]) {
            if (disc[i] == -1) {
                child ++; par[i] = u;
                st.pb({u,i});
                BCCutil(i);
                low[u] = min(low[u],low[i]);
            } else if (disc[i] < disc[u]) {
                low[u] = min(low[u],disc[i]);
                ad(u,i);
            }
        }
    }
    
    void bcc() {
        FOR(i,1,N+1) par[i] = disc[i] = low[i] = -1;
        FOR(i,1,N+1) if (disc[i] == -1) BCCutil(i);
    }
};

BCC<MX> B;
int M;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> B.N >> M;
    FOR(i,1,B.N+1) lo[i] = B.N;
    F0R(i,M) {
        int a,b; cin >> a >> b;
        B.addEdge(a,b);
    }
    B.bcc();
    FORd(i,1,B.N) lo[i] = min(lo[i],lo[i+1]);
    FOR(i,1,B.N+1) {
        cumlo[i] = lo[i]+cumlo[i-1];
    }
    int q; cin >> q;
    F0R(i,q) {
        int l,r; cin >> l >> r;
        int L = l-1, R = r; // last one < r
        while (L < R) {
            int M = (L+R+1)/2;
            if (lo[M] < r) L = M;
            else R = M-1;
        }
        ll ans = cumlo[L]-cumlo[l-1]+(ll)r*(r-L);
        ans -= (l+r-2)*(r-l+1LL)/2;
        cout << ans << "\n";
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)