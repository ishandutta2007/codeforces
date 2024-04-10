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
const int MX = 200001;

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

namespace modOp {
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
    
    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
    
    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
    
    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a); 
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;

int ans = 0;
vi divi[MX];
int n, phi[MX], in[MX], a[MX];
bool comp[MX];

int stor[MX],multiplier[MX];

template<int SZ> struct CentroidDecomp {
    bool done[SZ];
    int sub[SZ], par[SZ];
    vi dist[SZ], adj[SZ];
    int cen[SZ];
    
    void addEdge(int a, int b) { adj[a].pb(b), adj[b].pb(a); }
    
    void dfs (int no) {
        sub[no] = 1;
        for (int i: adj[no]) if (!done[i] && i != par[no]) {
            par[i] = no;
            dfs(i);
            sub[no] += sub[i];
        }
    }
    
    void genDist(int par, int no) {
        for (int i: adj[no]) if (!done[i] && i != par) {
            cen[i] = cen[no]; 
            dist[i].pb(dist[no].back()+1);
            genDist(no,i);
        }
    }
    
    int getCentroid(int x) {
        par[x] = 0; dfs(x);
        int sz = sub[x];
        while (1) {
            pi mx = {0,0};
            for (int i: adj[x]) if (!done[i] && i != par[x]) mx = max(mx,{sub[i],i});
            if (mx.f*2 > sz) x = mx.s;
            else return x;
        }
    }
    
    void upd(int x, int y) {
        // cout << "OOPS " << x << " " << y << "\n";
        for (int i: divi[x]) AD(stor[i],mul(mul(multiplier[i],y),phi[x]));
    }
    
    int query(int x) {
        int res = 0;
        for (int i: divi[x]) AD(res,stor[i]);
        return res;
    }
    
    void goThrough(int par, int no) {
        for (int i: adj[no]) if (!done[i] && i != par) goThrough(no,i);
        // cout << "BEFORE " << no << " " << a[no] << " " << ans << " " << dist[no].back() << "\n";
        AD(ans,mul(dist[no].back(),mul(2*phi[a[no]],query(a[no]))));
        // cout << "AFTER " << no << " " << ans << "\n";
    }
    
    void ad(int par, int no,int sgn) {
        for (int i: adj[no]) if (!done[i] && i != par) ad(no,i,sgn);
        upd(a[no],sgn);
    }
    
    void solve (int x) { // call solve(1) to initialize
        x = getCentroid(x); done[x] = 1;
        dist[x].pb(0);
        for (int i: adj[x]) if (!done[i]) {
            cen[i] = x; 
            dist[i].pb(1);
            genDist(x,i);
        }
        upd(a[x],1);
        for (int i: adj[x]) if (!done[i]) ad(x,i,1);
        for (int i: adj[x]) if (!done[i]) {
            ad(x,i,MOD-1);
            goThrough(x,i);
            ad(x,i,1);
        }
        upd(a[x],MOD-1);
        for (int i: adj[x]) if (!done[i]) ad(x,i,MOD-1);
        // FOR(i,1,n+1) assert(stor[i] == 0);
        // cout << x << " " << ans << "\n";
        
        for (int i: adj[x]) if (!done[i]) solve(i);
    }
};

CentroidDecomp<MX> C;

void init() {
    setIO(); re(n);
    FOR(i,1,n+1) phi[i] = i;
    FOR(i,1,n+1) for (int j = i; j <= n; j += i) {
        divi[j].pb(i);
        if (j != i && i > 1) comp[j] = 1;
    }
    FOR(i,2,n+1) if (!comp[i]) 
        for (int j = i; j <= n; j += i) 
            phi[j] /= i, phi[j] *= i-1;
    
    FOR(i,1,n+1) in[i] = inv(i);
    FOR(i,1,n+1) {
        multiplier[i] = mul(i,in[phi[i]]);
        for (int j: divi[i]) if (j != i) SUB(multiplier[i],multiplier[j]);
    }
    // FOR(i,1,101) cout << i << " " << phi[i] << "\n";
    FOR(i,1,n+1) re(a[i]);
    F0R(i,n-1) {
        int x,y; re(x,y);
        C.addEdge(x,y);
    }
}

int main() {
    init();
    C.solve(1);
    
    // cout << ans << "\n";
    MUL(ans,mul(in[n],in[n-1]));
    cout << ans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/