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
const int MX = 100001;

int n, k, cen, dist[MX], pre[MX];
vpi adj[MX];

void dfs(int cur) {
    for (auto i: adj[cur]) if (i.f != pre[cur]) {
        pre[i.f] = cur;
        dist[i.f] = dist[cur]+i.s;
        dfs(i.f);
    }
}

void genDist(int cur) {
    memset(dist,0,sizeof dist);
    pre[cur] = -1;
    dfs(cur);
}

int treeDiameter() {
    genDist(1);
    int bes = 0; FOR(i,1,n+1) if (dist[i] > dist[bes]) bes = i;
    genDist(bes); 
    FOR(i,1,n+1) if (dist[i] > dist[bes]) bes = i;
    return dist[bes];
}

void genCenter() {
    int t = treeDiameter();
    int bes = 0; FOR(i,1,n+1) if (dist[i] > dist[bes]) bes = i;
    
    pi ret = {MOD,MOD};
    while (bes != -1) {
        ret = min(ret,{max(dist[bes],t-dist[bes]),bes});
        bes = pre[bes];
    }
    
    cen = ret.s;
}

int BOUND, NEED;
bool OK;

int DFS(int cur, int pre) {
    int ret = 0, bad = 0;
    for (auto a: adj[cur]) if (a.f != pre) {
        int x = DFS(a.f,cur);
        if (x != -1 && x+a.s > BOUND) {
            x = -1;
            NEED ++;
        }
        if (x == -1) bad ++;
        else ret = max(ret,x+a.s);
    }
    if (cur == cen) {
        if (bad > 2) OK = 0;
    } else {
        if (bad > 1) OK = 0;
    }
    if (cur == cen) bad = max(bad,1);
    if (bad) {
        NEED ++;
        return -1;
    }
    // cout << cur << " " << pre << " " << ret << " " << bad << "\n";
    return ret;
}

bool ok(int mid) {
    BOUND = mid;
    NEED = 0;
    OK = 1;
    DFS(cen,-1);
    // cout << mid << " " << OK << " " << NEED << "\n";
    if (!OK) return 0;
    if (NEED > k) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    F0R(i,n-1) {
        int u,v,d; cin >> u >> v >> d;
        adj[u].pb({v,d}), adj[v].pb({u,d});
    }
    genCenter();
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (ok(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS