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
const int MX = 1<<19;

template<int SZ> struct Seg {
    pi seg[2*SZ];
    
    int query(int p, int ind) {  // set value at position p
        for (p += SZ; p; p >>= 1) if (seg[p].s > ind) return seg[p].f;
        return 0;
    }
    
    void ins(pi& u, pi v) {
        if (v.s > u.s) u = v;
    }
    
    void upd(int l, int r, int mx, int v) {  // sum on interval [l, r]
        for (l += SZ, r += SZ+1; l < r; l >>= 1, r >>= 1) {
            if (l&1) ins(seg[l++],{v,mx});
            if (r&1) ins(seg[--r],{v,mx});
        }
    }
};

Seg<MX> S;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int n, a[MX], ans[MX], cind[MX];
vi oc[MX];
vpi query[MX];
pi lst[MX];

void process(int ind) {
    int v = a[ind];
    
    S.upd((cind[v] == 0 ? 0 : oc[v][cind[v]-1])+1,ind, (cind[v]+1 < sz(oc[v]) ? oc[v][cind[v]+1] : MOD),v); 
    
    for (auto x: query[ind]) ans[x.s] = S.query(x.f,ind);
    cind[v] ++;
}

int main() {
    io();
    cin >> n;
    FOR(i,1,n+1) {
        cin >> a[i];
        oc[a[i]].pb(i);
    }
    int q; cin >> q;
    F0R(i,q) {
        int l,r; cin >> l >> r;
        query[r].pb({l,i});
    }
    FOR(i,1,n+1) process(i);
    F0R(i,q) cout << ans[i] << "\n";
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/