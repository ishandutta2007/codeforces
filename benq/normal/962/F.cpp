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
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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

template<int SZ> struct BCC {
    int N, ti = 0;
    vi adj[SZ];
    int disc[SZ], low[SZ], comp[SZ], par[SZ];
    vector<vpi> fin;
    vpi st, bridge;
    
    void addEdge(int u, int v) {
        adj[u].pb(v), adj[v].pb(u);
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
                
                if (disc[u] < low[i]) {
                    bridge.pb({u,i});
                }
                
                if ((disc[u] == 0 && child > 1) || (disc[u] != 0 && disc[u] <= low[i])) { // articulation point!
                    vector<pi> tmp;
                    while (st.back() != mp(u,i)) tmp.pb(st.back()), st.pop_back();
                    tmp.pb(st.back()), st.pop_back();
                    fin.pb(tmp);
                }
            } else if (disc[i] < disc[u]) {
                low[u] = min(low[u],disc[i]);
                st.pb({u,i});
            }
        }
    }
    
    void bcc() {
        FOR(i,1,N+1) par[i] = disc[i] = low[i] = -1;
        FOR(i,1,N+1) if (disc[i] == -1) {
            BCCutil(i);
            if (sz(st)) fin.pb(st);
            st.clear();
        }
    }
};

BCC<MX> B;
bool visit[MX];
vi ans;
set<int> cedge;
map<pi,int> bri, M;
int numVert;

void dfs(int ind) {
    if (visit[ind]) return;
    visit[ind] = 1; numVert ++;
    for (int i: B.adj[ind]) if (!bri.count({ind,i}))  {
        dfs(i);
        cedge.insert(M[{ind,i}]);
    }
}

int n,m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    B.N = n;
    FOR(i,1,m+1) {
        int a,b; cin >> a >> b;
        M[{a,b}] = M[{b,a}] = i;
        B.addEdge(a,b);
    }
    B.bcc();
    for (auto a: B.fin) {
        set<int> cur; for (auto b: a) cur.insert(b.f), cur.insert(b.s);
        if (sz(cur) == sz(a)) {
            for (auto z: a) ans.pb(M[z]);
        }
    }
    sort(all(ans));
    cout << sz(ans) << "\n";
    for (int i: ans) cout << i << " ";
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)