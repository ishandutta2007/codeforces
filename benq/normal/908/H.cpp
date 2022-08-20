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

vi adj[47], adj2[47], sz2[47];
int n, comp[47], sz[47], cur, CUR, ans;
vector<string> g;

void dfs(int x) {
    if (comp[x] != -1) return;
    comp[x] = cur; sz[comp[x]] ++;
    for (int i: adj[x]) dfs(i);
}

bool badComp[47][47];

void init() {
    setIO(); re(n); g.resize(n);
    re(g); F0R(i,n) comp[i] = -1;
    F0R(i,n) F0R(j,n) if (g[i][j] == 'A') adj[i].pb(j);
    F0R(i,n) if (comp[i] == -1 && sz(adj[i])) {
        dfs(i);
        cur ++;
    }
    CUR = cur;
    F0R(i,n) if (comp[i] == -1) {
        dfs(i);
        cur ++;
    }
    F0R(i,cur) ans += sz[i]-1;
    ans += cur-1;
    F0R(i,n) F0R(j,n) if (g[i][j] == 'X') {
        if (comp[i] == comp[j]) {
            cout << -1;
            exit(0);
        }
        badComp[comp[i]][comp[j]] = 1;
    }  
}

bitset<1<<23> ok;

void sos (vi& dp, int x = 1) { // x = -1 reverses
    int SZ = 31-__builtin_clz(sz(dp));
    F0R(i,SZ) F0R(j,1<<SZ) if (j&(1<<i)) 
        dp[j^(1<<i)] += x*dp[j];
}

int numComp() {
    if (CUR == 0) return 0;
    ok[0] = 1;
    vi res(1<<CUR,1), tmp(1<<CUR);
    //cout << CUR << " " << ans << "\n";
    F0R(i,CUR) F0R(j,1<<i) if (ok[j]) {
        bool bad = 0;
        F0R(k,i) if ((j&(1<<k)) && badComp[i][k]) {
            bad = 1;
            break;
        }
        if (bad) continue;
        int num = j^(1<<i);
        ok[num] = 1;
        tmp[(1<<CUR)-1-num] = 1;
        //cout << num << "\n";
    }
    //exit(0);
    sos(tmp);
    for (int ans = 1; ; ans++) {
        F0R(i,1<<CUR) MUL(res[i],tmp[i]);
        int z = 0;
        F0R(i,1<<CUR) {
            if (__builtin_popcount(i)&1) SUB(z,res[i]);
            else AD(z,res[i]);
        }
        if (z) return ans;
    }
}

int main() {
    init();
    cout << ans+numComp();
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/