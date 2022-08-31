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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // TYPE ID (StackOverflow)
    
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
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
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
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int n,dp[2001][2001];

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

vi a[2000];

int getRank0(vi v) {
    Tree<int> T; FOR(i,1,sz(v)+1) T.insert(i);
    int ret = 0;
    F0R(i,sz(v)) {
        AD(ret,mul(T.order_of_key(v[i]),dp[0][sz(v)-1-i]));
        T.erase(v[i]);
    }
    // pr("AH",v,ret);
    return ret;
}

bool com[2001];

template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    
    void upd(int k, T val) { // add val to index k
        for( ;k <= SZ; k += (k&-k)) bit[k] += val;
    }
    
    T query(int k) {
        T temp = 0;
        for (;k > 0;k -= (k&-k)) temp += bit[k];
        return temp;
    }
};

BIT<int,2000> B0, B1;

int getRank(vi x, vi y) {
    int a = sz(x), ret = 0;
    FOR(i,1,n+1) {
        com[i] = 1;
        B0.bit[i] = 1;
    }
    FOR(i,1,n+1) {
        int j = i+(i&-i);
        if (j <= n) {
            B0.bit[j] += B0.bit[i];
        }
    }
    F0R(i,sz(y)) {
        int b = sz(y)-i-a;
        // everything less than y[i]
        if (com[x[i]]) {
            // if equal to x[i] -> 0 
            if (a > 1) {
                AD(ret,mul(B0.query(y[i]-1),dp[a-2][b+1]));
                if (y[i] > x[i]) SUB(ret,dp[a-2][b+1]);
            }
            if (a) AD(ret,mul(B1.query(y[i]-1),dp[a-1][b]));
            // y[i] included -> a-2, b+1 
            // y[i] not included -> a-1, b 
        } else {
            // pr("HA",i,ret);
            if (a) AD(ret,mul(B0.query(y[i]-1),dp[a-1][b]));
            if (b) AD(ret,mul(B1.query(y[i]-1),dp[a][b-1]));
            // pr("HA",i,ret);
            // y[i] included -> a-1, b 
            // y[i] not included -> a, b-1 
        }
        if (com[x[i]]) {
            com[x[i]] = 0, a --;
            B0.upd(x[i],-1); B1.upd(x[i],1);
        }
        if (com[y[i]]) {
            com[y[i]] = 0, a --;
            B0.upd(y[i],-1);
        } else {
            B1.upd(y[i],-1);
        }
        // pr("OOPS",a,b,ret);
    }
    // pr(x,y,ret);
    return ret;
}

int main() {
    // you should actually read the stuff at the bottom
    F0R(i,2001) F0R(j,2001-i) {
        if (i == 0 && j == 0) dp[i][j] = 1;
        else if (i == 0) {
            if (j) AD(dp[i][j],mul(j,dp[i][j-1]));
            if (i) AD(dp[i][j],mul(i,dp[i-1][j]));
        } else {
            if (i > 1) AD(dp[i][j],mul(i-1,dp[i-2][j+1]));
            if (i) AD(dp[i][j],mul(j,dp[i-1][j]));
        }
    }
    // pr(getRank0({1,2,3,4})); pr(getRank0({4,3,2,1})); exit(0);
    /*F0R(i,10) {
        F0R(j,10) cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    setIO(); re(n);
    F0R(i,n) {
        a[i].resz(n);
        re(a[i]);
    }
    int ans = 0;
    F0R(i,n) {
        int t = po(dp[n][0],n-1-i);
        if (i == 0) MUL(t,getRank0(a[i]));
        else MUL(t,getRank(a[i-1],a[i]));
        AD(ans,t);
        // pr("HI",ans);
    }
    pr(ans);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/