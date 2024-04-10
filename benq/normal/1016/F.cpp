
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
const int MX = 300001;

int n,m;
ll sh, sh2, dist[MX], par[MX], num[MX];
vpi adj[MX];
bool onPath[MX];

void addEdge(int a, int b, int c) {
    adj[a].pb({b,c}), adj[b].pb({a,c});
}

void dfs(int x) {
    for (auto a: adj[x]) if (a.f != par[x]) {
        dist[a.f] = dist[x]+a.s;
        par[a.f] = x;
        dfs(a.f);
    }
}

bool ok() {
    FOR(i,1,n+1) if (onPath[i]) {
        vpi co;
        for (auto j: adj[i]) if (!onPath[j.f]) co.pb(j);
        if (sz(co) > 1) return 0;
        for (auto j: co) if (sz(adj[j.f]) > 1) return 0;
        if (sz(co)) num[i] = co[0].s;
    }
    return 1;
}

/*void doSmth() {
    FOR(i,1,n+1) if (onPath[i]) cout << i << " " << num[i] << "\n";
    cout << "HI";
}*/

vi path;

void skip1() {
    ll yes = -INF, no = -INF;
    F0Rd(i,sz(path)) {
        if (num[path[i]]) {
            sh2 = max(sh2,dist[n]+max(yes,no)+dist[path[i]]+num[path[i]]);
            yes = max(yes,num[path[i]]-dist[path[i]]);
        } else {
            sh2 = max(sh2,dist[n]+yes+dist[path[i]]+num[path[i]]);
            no = max(no,num[path[i]]-dist[path[i]]);
        }
    }
}

void skip2() {
    F0R(i,sz(path)-2) sh2 = max(sh2,dist[path[i]]+dist[n]-dist[path[i+2]]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n-1) {
        int v,u,w; cin >> v >> u >> w;
        addEdge(u,v,w);
    }
    dfs(1); sh = dist[n];
    int cur = n;
    for (; cur != 1; cur = par[cur]) {
        path.pb(cur);
        onPath[cur] = 1;
    }
    onPath[1] = 1; path.pb(1);
    reverse(all(path));
    if (ok()) {
        skip1();
        skip2();
    } else sh2 = INF;
    F0R(i,m) {
        int x; cin >> x;
        cout << min(sh,sh2+x) << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/