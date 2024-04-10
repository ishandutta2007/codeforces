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
const int MX = 100001;
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


vi manacher(vpi s) {
    vpi s1 = {{MOD,MOD}};
    for (auto c: s) {
        s1.pb(c);
        s1.pb({MOD,MOD-1});
    }
    s1.pb({MOD,MOD-2});
    
    vi ans(sz(s1)-1);
    int lo = 0, hi = 0; 
    FOR(i,1,sz(s1)-1) {
        if (i != 1) ans[i] = min(hi-i,ans[hi-i+lo]);
        while (s1[i-ans[i]-1] == s1[i+ans[i]+1]) ans[i] ++;
        if (i+ans[i] > hi) lo = i-ans[i], hi = i+ans[i];
    }
    
    ans.erase(ans.begin());
    F0R(i,sz(ans)) if ((i&1) == (ans[i]&1)) ans[i] ++; // adjust lengths
    return ans;
}

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

namespace pairOp {
    template<class T> T operator+=(T& l, const T& r) { return l = l+r; }
    template<class T> T operator-=(T& l, const T& r) { return l = l-r; }
    template<class T> T operator*=(T& l, const T& r) { return l = l*r; }

	pi operator+(const pi& l, const pi& r) { return {ad(l.f,r.f),ad(l.s,r.s)}; }
	pi operator-(const pi& l, const pi& r) { return {sub(l.f,r.f),sub(l.s,r.s)}; }
	pi operator*(const pi& l, const pi& r) { return {mul(l.f,r.f),mul(l.s,r.s)}; }
	pi operator*(const pi& l, const int& r) { return l*pi(r,r); }
	pi operator*(const int& r, const pi& l) { return l*r; }
	pi operator*=(pi& l, const int& r) { return l = l*r; }
}

using namespace pairOp;

string a[250];
pi val[26];
int ch[250];
pi chsh[250];
ll ans;
int n,m;
mt19937 mt(chrono::high_resolution_clock::now()
            .time_since_epoch().count());

void solve(int col) {
    F0R(i,n) {
        chsh[i] = {0,0};
        ch[i] = 0;
    }
    FOR(j,col,m) {
        F0R(i,n) {
            chsh[i] += val[a[i][j]-'a'];
            ch[i] ^= 1<<(a[i][j]-'a');
        }
        for (int i = 0; i < n; ) {
            int I = i; while (i < n && __builtin_popcount(ch[i]) <= 1) i ++;
            vpi v;
            FOR(k,I,i) v.pb(chsh[k]);
            auto V = manacher(v);
            trav(z,V) ans += (z+1)/2;
            if (I == i) i ++;
        }
    }
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,m); F0R(i,n) re(a[i]);
    F0R(i,26) val[i] = {mt()%MOD,mt()%MOD};
    F0R(j,m) solve(j);
    cout << ans;
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/