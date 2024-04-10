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

int n,m;
vi adj[MX];
bool inCyc[MX], inStack[MX], visit[MX];
vi sta, ret;

void dfs(int x) {
    if (inCyc[x]) return;
    
    if (inStack[x] && !sz(ret)) {
        int ind = 0; while (sta[ind] != x) ind ++;
        ret = vi(sta.begin()+ind,sta.end());
    }
    
    if (visit[x]) return;
    visit[x] = 1; 
    
    inStack[x] = 1; sta.pb(x);
    for (int i: adj[x]) dfs(i);
    inStack[x] = 0; sta.pop_back();
}

void getCyc(vi x) {
    ret = {};
    FOR(i,1,n+1) visit[i] = inCyc[i] = 0;
    for (int i: x) inCyc[i] = 1;
    /*FOR(i,1,n+1) cout << inCyc[i] << " ";
    cout << "\n";*/
    FOR(i,1,n+1) if (!visit[i]) dfs(i);
}

vi cyc;
int pos[MX], farthest[MX], cum[2*MX];

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        adj[a].pb(b);
    }
    getCyc({}); cyc = ret;
    getCyc(cyc);
    if (sz(ret)) {
        cout << -1;
        exit(0);
    }
}

int dist(int a, int b) {
    if (b == 0) return -MOD;
    int res = pos[b]-pos[a]; while (res <= 0) res += sz(cyc);
    return res;
}

int getFarthest(int x, int ori) {
    if (farthest[x]) return farthest[x];
    int bes = 0;
    for (int i: adj[x]) {
        if (inCyc[i]) {
            if (dist(ori,i) > dist(ori,bes)) bes = i;
        } else {
            int y = getFarthest(i,ori);
            if (dist(ori,y) > dist(ori,bes)) bes = y;
        }
    }
    return farthest[x] = bes;
}

void ad(int a, int b) {
    while (b <= a) b += sz(cyc);
    cum[a+1] ++, cum[b] --;
}

int main() {
    init();
    F0R(i,sz(cyc)) pos[cyc[i]] = i;
    F0R(i,sz(cyc)) {
        int x = getFarthest(cyc[i],cyc[i]);
        ad(pos[cyc[i]],pos[x]);
    }
    FOR(i,1,2*sz(cyc)+1) cum[i] += cum[i-1];
    F0R(i,sz(cyc)) if (cum[pos[cyc[i]]]+cum[pos[cyc[i]]+sz(cyc)] == 0) {
        // cout << cyc[i] << " ";
        getCyc({cyc[i]});
        if (!sz(ret)) {
            cout << cyc[i];
            exit(0);
        } 
        break;
    }
    cout << -1;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/