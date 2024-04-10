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
const int MX = 601;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
    // pair
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s;
        return is;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}';
        return os;
    }
    
    // vector
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        int sz; is >> sz; a.resize(sz);
        F0R(i,sz) is >> a[i];
        return is;
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << "{";
        F0R(i,sz(a)) {
            if (i) os << ", ";
            os << a[i];
        }
        os << "}";
        return os;
    }
}

using namespace io;

struct dat {
    vi a, b;
    int numEdge;
};

int n;
vector<dat> v;
vi adj[MX];
bool ok[MX][MX];
bool involve[MX];

int Q(vi ret) {
    if (sz(ret) <= 1) return 0;
    cout << "? " << sz(ret) << endl;
    for (int i: ret) cout << i << " ";
    cout << endl;
    
    int x = 0; cin >> x; 
    // F0R(i,sz(ret)) FOR(j,i+1,sz(ret)) if (ok[ret[i]][ret[j]]) x ++;
    return x;
}

vector<vi> tmp;
    
int query(int x, int l, int r) {
    vi ret = {x}; FOR(i,l,r+1) ret.insert(ret.end(),all(tmp[i]));
    int ans = Q(ret);
    F0R(i,sz(v)) if (l <= 2*i && 2*i+1 <= r) ans -= v[i].numEdge;
    return ans;
}

bool visit[MX];
int par[MX];

void dfs(int a) {
    if (visit[a]) return;
    visit[a] = 1;
    for (int i: adj[a]) if (!visit[i]) { par[i] = a; dfs(i); }
}

void finish() {
    FOR(i,1,n+1) visit[i] = 0, par[i] = 0;
    FOR(i,1,n+1) if (!visit[i]) {
        par[i] = 0;
        dfs(i);
    }
    
    FOR(i,1,n+1) for (int j: adj[i]) if (par[i] != j && par[j] != i) {
        vi A = {i}, B = {j};
        while (par[A.back()]) A.pb(par[A.back()]);
        while (par[B.back()]) B.pb(par[B.back()]);
        B.pop_back(); reverse(all(A)); B.insert(B.end(),all(A));
        /*cout << i << " " << j << "\n";
        FOR(i,1,n+1) cout << par[i] << " ";
        cout << "\n";*/
        cout << "N " << sz(B) << endl;
        for (int i: B) cout << i << " ";
        cout << endl;
        exit(0);
    }
}

void triEdge(int x, vi v) {
    int lo = 1, hi = sz(v);
    while (lo < hi) {
        int mid = (lo+hi)/2;
        vi VV = vi(v.begin(),v.begin()+mid); VV.pb(x);
        if (Q(VV)-Q(vi(v.begin(),v.begin()+mid))) hi = mid;
        else lo = mid+1;
    }
    /*cout << "TT " << lo << "\n";
    cout << x << " | ";
    for (int i: v) cout << i << " ";
    cout << "\n";
    cout << "BAD " << x << " " << v[lo-1] << "\n";*/
    adj[x].pb(v[lo-1]), adj[v[lo-1]].pb(x);
}

void comb(vi& a, vi& b) {
    a.insert(a.end(),all(b));
}

void ad(int x) {
    tmp.clear();
    vi sol;
    for (auto x: v) tmp.pb(x.a), tmp.pb(x.b);
    
    int nex = 0;
    while (nex < sz(tmp)) {
        int l = nex, r = sz(tmp);   
        while (l < r) {
            int m = (l+r)/2;
            if (query(x,l,m)) r = m;
            else l = m+1;
        }
        if (l < sz(tmp)) sol.pb(l);
        nex = l+1;
    }
    
    F0R(i,n) involve[i] = 0;
    vi a = {x},b;
    for (int i: sol) {
        involve[i/2] = 1;
        triEdge(x,tmp[i]);
        if (i % 2 == 1) {
            comb(b,v[i/2].b);
            comb(a,v[i/2].a);
        } else {
            comb(b,v[i/2].a);
            comb(a,v[i/2].b);
        }
    }
    finish();
    F0Rd(i,sz(v)) if (involve[i]) v.erase(v.begin()+i);
    v.pb(dat());
    vi c = a; c.insert(c.end(),all(b));
    v.back().a = a;
    v.back().b = b;
    v.back().numEdge = Q(c);
    /*if (x == 4) {
        cout << "HI\n";
        for (auto a: v) cout << a.a << " " << a.b << " " << a.numEdge << "\n";
        exit(0);
    }*/
}

int main() {
    cin >> n;
    
    /*int m; cin >> m;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        ok[a][b] = ok[b][a] = 1;
    }*/
    
    FOR(i,1,n+1) ad(i);
    cout << "Y " << sz(v[0].a) << endl;
    for (int i: v[0].a) cout << i << " ";
    cout << endl;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/