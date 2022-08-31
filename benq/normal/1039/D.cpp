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

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

vi adj[MX];
int n, ans[MX];
int cur, len;

int dfs(int x, int y) {
    pi bes = {0,0};
    for (int i: adj[x]) if (i != y) {
        int k = dfs(i,x);
        if (k > bes.f) bes.s = bes.f, bes.f = k;
        else if (k > bes.s) bes.s = k;
    }
    if (1+bes.f+bes.s >= len) {
        cur ++;
        return 0;
    }
    return bes.f+1;
}

int eval(int x) {
    cur = 0; len = x;
    dfs(1,0);
    return cur;
}

void divi (int l, int r, int L, int R) {
    if (l > r) return;
    if (L == R) {
        FOR(i,l,r+1) ans[i] = L;
        return;
    }
    int m = (l+r)/2;
    ans[m] = eval(m);
    divi(l,m-1,ans[m],R);
    divi(m+1,r,L,ans[m]);
}

int main() {
    io();
    cin >> n;
    F0R(i,n-1) {
        int u,v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    divi(1,n,0,n);
    FOR(i,1,n+1) cout << ans[i] << "\n";
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/