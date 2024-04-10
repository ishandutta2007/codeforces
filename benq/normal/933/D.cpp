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

const int MOD = 1000000007; // 998244353
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

namespace modOp {
    int good(ll x) { return (x%MOD+MOD)%MOD; }
    int ad(int a, int b, int mod = MOD) { return (a+b)%MOD; }
    int sub(int a, int b, int mod = MOD) { return (a-b)%MOD; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%MOD; }
    
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

ll m, in[10];
int ans;

/*void brute() {
    FOR(i,-10,11) FOR(j,-10,11) {
        ll d = i*i+j*j;
        if (d <= m) ans += calc(d);
    }
}*/

int cons;

int calc(ll d) {
    int M = m % MOD, D = d % MOD;
    int ret = mul(mul(M+1,mul(sub(M+1,D),ad(M,D))),in[2]);
    AD(ret,mul(mul(mul(D-1,D),2*D-1),in[6]));
    SUB(ret,cons);
    
    return ret;
    // return (m+1)*(m-d+1)*(m+d)/2+(d-1)*d*(2*d-1)/6-m*(m+1)*(2*m+1)/6;
    // d = i^2+j^2 -> 6th degree polynomial 
}

int multiplier[10],cum1[8],cum2[8];

int extend(vi x, int y) {
    if (y <= 7) return x[y];
    int ret = 0;
    cum1[0] = 1; FOR(i,1,8) cum1[i] = (ll)cum1[i-1]*(y-(i-1))%MOD;
    cum2[7] = 1; F0Rd(i,7) cum2[i] = (ll)cum2[i+1]*(y-(i+1))%MOD;
    F0R(i,sz(x)) {
        int t = (ll)x[i]*multiplier[i]%MOD;
        t = (ll)t*((ll)cum1[i]*cum2[i]%MOD)%MOD;
        ret = (ret+t)%MOD;
    }
    return ret;
}

int getSum(ll a, ll b) {
    vi cum(8);
    FOR(i,1,8) cum[i] = ad(cum[i-1],calc(a*a+i*i));
    return extend(cum,b);
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(m);
    FOR(i,1,10) in[i] = inv(i);
    F0R(i,8) {
        multiplier[i] = 1;
        F0R(j,8) if (i != j) {
            MUL(multiplier[i],inv(i-j));
        }
    }
    int M = m % MOD;
    cons = mul(mul(M,mul(M+1,2*M+1)),in[6]);
    AD(ans,calc(0));
    int cum = 0;
    for (ll i = 1; ; ++i) {
        if (i*i <= m) AD(cum,calc(i*i));
        else break;
    }
    AD(ans,mul(4,cum));
    for (ll i = 1; ; ++i) {
        if (i*i < m) AD(ans,mul(4,getSum(i,sqrt((ld)m-i*i))));
        else break;
    }
    ans = (ans%MOD+MOD)%MOD;
    pr(ans);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/