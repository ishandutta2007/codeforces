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
const int MX = 300001;
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

int n, ans[MX], val[MX], par[MX], depth[MX], tmp;
ll ret, cur;
priority_queue<pi> todo[MX];
vi adj[MX], co[MX];

int dfs(int a) {
    int mx = 0;
    co[a].resize(2);
    for (int i: adj[a]) if (i != par[a]) {
        par[i] = a;
        co[a][1] ++;
        depth[i] = depth[a]+1;
        ckmax(mx,dfs(i));
    }
    val[a] = 1;
    todo[co[a][1]].push({depth[a],a});
    mx ++; ret += mx;
    return mx;
}

void prop(int x, int y) {
    if (!x || ans[x] >= y) return;
    cur += y-ans[x]; ans[x] = y;
    prop(par[x],y);
}

void process(int x) {
    while (sz(todo[x])) {
        auto a = todo[x].top(); todo[x].pop();
        bool ok = 0;
        while (val[a.s] < sz(co[a.s]) && co[a.s][val[a.s]] >= x) {
            ok = 1;  val[a.s] ++;
            while (sz(co[par[a.s]]) <= val[a.s]) co[par[a.s]].pb(0);
            co[par[a.s]][val[a.s]] ++;
            prop(a.s,val[a.s]);
        }
        if (val[a.s] < sz(co[a.s])) todo[co[a.s][val[a.s]]].push(a);
        if (ok && a.s != 1) todo[x].push({a.f-1,par[a.s]});
    }
    /*cout << x << " " << cur << "\n";
    FOR(i,1,n+1) cout << ans[i] << " ";
    cout << "\n";*/
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n);
    F0R(i,n-1) {
        int u,v; re(u,v);
        adj[u].pb(v), adj[v].pb(u);
    }
    // FOR(i,1,n+1) cout << sz()
    dfs(1);
    cur = n; FOR(i,1,n+1) ans[i] = 1;
    FORd(i,2,n+1) {
        process(i);
        ret += cur;
    }
    cout << ret;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/