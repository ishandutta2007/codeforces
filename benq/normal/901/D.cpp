#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vl> mat;

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
const int MX = 100001;

int n,m, par[MX], depth[MX], odd[MX];
ll ans[MX], c[MX];
vpi adj[MX], child[MX];
bool done[MX];
map<pi,int> M;
pi bad;

void dfs(int x) {
    for (auto i: adj[x]) {
        if (odd[i.f] == -1) {
            odd[i.f] = odd[x]^1; 
            depth[i.f] = depth[x]+1;
            par[i.f] = x; child[x].pb(i);
            dfs(i.f);
        } else if (odd[i.f] == odd[x]) bad = {i.f,x};
    }
}

void DFS(int x) {
    done[x] = 1;
    for (auto i: adj[x]) if (!done[i.f]) {
        DFS(i.f);
        ans[i.s] += c[i.f]; c[x] -= c[i.f]; c[i.f] = 0;
    }
}

void solveEven() {
    DFS(1);
    if (c[1] != 0) cout << "NO";
    else {
        cout << "YES\n";
        F0R(i,m) cout << ans[i] << "\n";
    }
}

void solveOdd() {
    vi cyc;
    while (bad.f != bad.s) {
        if (depth[bad.f] < depth[bad.s]) swap(bad.f,bad.s);
        cyc.pb(bad.f);
        bad.f = par[bad.f];
    }
    cyc.pb(bad.f); reverse(all(cyc));
    
    DFS(bad.f);
    ll t = c[bad.f];
    F0R(i,sz(cyc)) {
        if (i&1) ans[M[{cyc[i],cyc[(i+1)%sz(cyc)]}]] -= t/2;
        else ans[M[{cyc[i],cyc[(i+1)%sz(cyc)]}]] += t/2;
    }
    cout << "YES\n";
    F0R(i,m) cout << ans[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FOR(i,1,n+1) {
        cin >> c[i];
        odd[i] = -1;
    }
    F0R(i,m) {
        int a,b; cin >> a >> b;
        M[{a,b}] = M[{b,a}] = i;
        adj[a].pb({b,i}), adj[b].pb({a,i});
    }
    odd[1] = 0; dfs(1);
    if (bad == mp(0,0)) solveEven();
    else solveOdd();
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)