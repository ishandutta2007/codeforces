
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

int n,q;
vi c[MX];
vector<array<int,3>> c2[MX];
vpi todo;
bool use[MX], col[MX], clear[MX];
int push[MX];

void dfs1(int x, int p = 0, int white = 0, int dis = 0) {
    if (use[x]) {
        if (p) c2[p].pb({x,white,dis});
        for (int y: c[x]) dfs1(y,x,0,0);
    } else {
        if (!col[x]) white ++;
        for (int y: c[x]) dfs1(y,p,white,dis+1);
    }
}

void dfs2(int x, int _push = 0, int _clear = 0) {
    if (use[x]) {
        _push = push[x];
        _clear |= clear[x];
    } else {
        if (_clear) col[x] = 0;
        if (_push && !col[x]) col[x] = 1, _push --;
    }
    for (int y: c[x]) dfs2(y,_push,_clear);
}

void ad(int x) {
    if (!col[x]) { col[x] = 1; return; }
    push[x] ++;
    for (auto a: c2[x]) if (a[1] < push[x]) ad(a[0]);
}

void clr(int x) {
    col[x] = 0; push[x] = 0; clear[x] = 1;
    for (auto& a: c2[x]) { a[1] = a[2]; clr(a[0]); }
}

void process() {
    FOR(i,1,n+1) {
        use[i] = 0;
        clear[i] = 0;
        push[i] = 0;
        c2[i].clear();
    }
    for (auto a: todo) use[a.s] = 1;
    dfs1(1);
    for (auto a: todo) {
        if (a.f == 1) ad(a.s);
        else if (a.f == 2) clr(a.s);
        else cout << (col[a.s]?"black":"white") << "\n";
    }
    dfs2(1);
    todo.clear();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    FOR(i,2,n+1) {
        int p; cin >> p;
        c[p].pb(i);
    }
    F0R(i,q) {
        int t,v; cin >> t >> v;
        todo.pb({t,v});
        if (sz(todo) >= 600) process();
    }
    process();
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/