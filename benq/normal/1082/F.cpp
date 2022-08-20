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
typedef complex<double> cd;

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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 501;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // Source: StackOverflow
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
}

using namespace io;

int n,k, val[501], sumCost[501], nex = 1;
pi interval[501];
vi adj[501];
map<char,int> m[501];
array<int,11> dp[501], tmp[501], besSoFar;
int sofar = -1;

void ad(string s, int num) {
    int cur = 0;
    for (char c: s) {
        if (!m[cur].count(c)) {
            m[cur][c] = nex;
            adj[cur].pb(nex); nex ++;
        }
        cur = m[cur][c];
    }
    val[cur] += num;
}

void comb(vi& a, vi b) {
    while (sz(a) < sz(b)) a.pb(MOD);
    F0R(i,sz(b)) ckmin(a[i],b[i]);
}

vi conv(vi a, vi b) {
    if (!sz(a) || !sz(b)) return {};
    vi c(sz(a)+sz(b)-1,MOD);
    F0R(i,sz(a)) F0R(j,sz(b)) ckmin(c[i+j],a[i]+b[j]);
    return c;
}

vi todo;

void dfs(int x, int len) {
    sumCost[x] = val[x]*len;
    for (int i: adj[x]) {
        dfs(i,len+1);
        sumCost[x] += sumCost[i];
    }
    todo.pb(x);
}

int zz = 0;

void ckmin(array<int,11>& a, array<int,11> b) {
    F0R(i,11) ckmin(a[i],b[i]);
}

void dfs2(int x) {
    interval[x].f = zz++;
    for (int i: adj[x]) dfs2(i);
    interval[x].s = zz-1;
}

void dfs3(int x, bool f = 0) {
    while (sofar+1 < interval[x].f) ckmin(besSoFar,tmp[++sofar]);
    if (!f) F0R(i,11) F0R(j,10-i) {
        ckmin(tmp[interval[x].s][i+j+1],besSoFar[i]+dp[x][j]-sumCost[x]);
        // cout << "AH " << dp[x][j]-sumCost[x] << "\n";
    }
    for (int i: adj[x]) dfs3(i);
}

void solve(int x) {
    for (int i: adj[x]) solve(i);
    sofar = -1;
    F0R(j,11) besSoFar[j] = 0;
    F0R(i,MX) F0R(j,11) tmp[i][j] = 0;
    dfs(x,0); dfs3(x,1);
    while (sofar+1 < MX) ckmin(besSoFar,tmp[++sofar]);
    // cout << x << " " << besSoFar << "\n";
    F0R(i,11) dp[x][i] = besSoFar[i]+sumCost[x];
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,k);
    FOR(i,1,n+1) {
        string s; int m; re(s,m);
        ad(s,m);
    }
    dfs2(0);
    solve(0);
    int ans = MOD;
    F0R(i,k+1) ckmin(ans,dp[0][i]);
    pr(ans);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/