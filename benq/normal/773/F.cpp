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
#define all(x) begin(x), end(x)
#define rsz resize

int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace vecOp {
    template<class T> vector<T> rev(vector<T> v) { reverse(all(v)); return v; }
    template<class T> vector<T> shift(vector<T> v, int x) { v.insert(v.begin(),x,0); return v; }
    
    template<class T> vector<T>& operator+=(vector<T>& l, const vector<T>& r) {
        l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; return l;
    }
    template<class T> vector<T>& operator-=(vector<T>& l, const vector<T>& r) {
        l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; return l;
    }
    template<class T> vector<T>& operator*=(vector<T>& l, const T& r) { trav(t,l) t *= r; return l;  }
    template<class T> vector<T>& operator/=(vector<T>& l, const T& r) { trav(t,l) t /= r; return l; }

    template<class T> vector<T> operator+(vector<T> l, const vector<T>& r) { return l += r; }
    template<class T> vector<T> operator-(vector<T> l, const vector<T>& r) { return l -= r; }
    template<class T> vector<T> operator*(vector<T> l, const T& r) { return l *= r; }
    template<class T> vector<T> operator*(const T& r, const vector<T>& l) { return l*r; }
    template<class T> vector<T> operator/(vector<T> l, const T& r) { return l /= r;  }

    template<class T> vector<T> operator*(const vector<T>& l, const vector<T>& r) {
        if (min(sz(l),sz(r)) == 0) return {};
        vector<T> x(sz(l)+sz(r)-1); F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
        return x;
    }
    template<class T> vector<T>& operator*=(vector<T>& l, const vector<T>& r) { return l = l*r; }
    
    template<class T> vector<T> rem(vector<T> a,vector<T> b) { 
        while (sz(b) && b.back() == 0) b.pop_back();
        assert(sz(b)); b /= b.back();
        while (sz(a) >= sz(b)) {
            a -= a.back()*shift(b,sz(a)-sz(b));
            while (sz(a) && a.back() == 0) a.pop_back();
        }
        return a;
    }
    template<class T> vector<T> interpolate(vector<pair<T,T>> v) {
        vector<T> ret;
        F0R(i,sz(v)) {
            vector<T> prod = {1};
            T todiv = 1;
            F0R(j,sz(v)) if (i != j) {
                todiv *= v[i].f-v[j].f;
                vector<T> tmp = {-v[j].f,1}; prod *= tmp;
            }
            ret += prod*(v[i].s/todiv);
        }
        return ret;
    }
}

using namespace vecOp;

namespace FFT {
    constexpr int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
    // if vectors are small then multiply directly
    template<class T> bool small(const vector<T>& a, const vector<T>& b) { return (ll)sz(a)*sz(b) <= 500000; } 

    /*void genRoots(vmi& roots) { // primitive n-th roots of unity
        int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
        roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r;
    }*/
    void genRoots(vcd& roots) { // change cd to complex<double> instead?
        int n = sz(roots); ld ang = 2*PI/n;
        F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); // is there a way to do this more quickly?
    }
    
    template<class T> void fft(vector<T>& a, vector<T>& roots) {
        int n = sz(a);
        for (int i = 1, j = 0; i < n; i++) { // sort by reverse bit representation
            int bit = n >> 1;
            for (; j&bit; bit >>= 1) j ^= bit;
            j ^= bit; if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) 
            for (int i = 0; i < n; i += len) 
                F0R(j,len/2) {
                    auto u = a[i+j], v = a[i+j+len/2]*roots[n/len*j];
                    a[i+j] = u+v, a[i+j+len/2] = u-v;
                }
    }

    template<class T> vector<T> conv(vector<T> a, vector<T> b) {
        if (small(a,b)) return a*b;
        int s = sz(a)+sz(b)-1, n = 1<<size(s);
        vector<T> roots(n); genRoots(roots);
        
        a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
        F0R(i,n) a[i] *= b[i];
        reverse(begin(roots)+1,end(roots)); fft(a,roots); // inverse FFT
        
        T in = T(1)/T(n); trav(x,a) x *= in;
        a.rsz(s); return a;
    } 
    vl conv(const vl& a, const vl& b) { 
        if (small(a,b)) return a*b;
        vcd X = conv(vcd(all(a)),vcd(all(b)));
        vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
        return x;
    } // ~0.55s when sz(a)=sz(b)=1<<19
    vl conv(const vl& a, const vl& b, ll mod) { // http://codeforces.com/contest/960/submission/37085144
        if (small(a,b)) return a*b;
        int s = sz(a)+sz(b)-1, n = 1<<size(s);
        
        vcd v1(n), v2(n), r1(n), r2(n);
        F0R(i,sz(a)) v1[i] = cd(a[i]>>15, a[i]&32767); // v1(x)=a0(x)+i*a1(x)
        F0R(i,sz(b)) v2[i] = cd(b[i]>>15, b[i]&32767); // v2(x)=b0(x)+i*b1(x)
        
        vcd roots(n); genRoots(roots);
        fft(v1,roots), fft(v2,roots);
        F0R(i,n) {
            int j = (i ? (n-i) : i);
            cd ans1 = (v1[i]+conj(v1[j]))*cd(0.5, 0); // a0(x)
            cd ans2 = (v1[i]-conj(v1[j]))*cd(0, -0.5); // a1(x)
            cd ans3 = (v2[i]+conj(v2[j]))*cd(0.5, 0); // b0(x)
            cd ans4 = (v2[i]-conj(v2[j]))*cd(0, -0.5); // b1(x)
            r1[i] = (ans1*ans3)+(ans1*ans4)*cd(0, 1); // a0(x)*v2(x)
            r2[i] = (ans2*ans3)+(ans2*ans4)*cd(0, 1); // a1(x)*v2(x)
        }
        reverse(begin(roots)+1,end(roots));
        fft(r1,roots), fft(r2,roots); F0R(i,n) r1[i] /= n, r2[i] /= n;
        
        vl ret(n);
        F0R(i,n) {
            ll av = (ll)round(r1[i].real()); // a0*b0
            ll bv = (ll)round(r1[i].imag())+(ll)round(r2[i].real()); // a0*b1+a1*b0
            ll cv = (ll)round(r2[i].imag()); // a1*b1
            av %= mod, bv %= mod, cv %= mod;
            ret[i] = (av<<30)+(bv<<15)+cv;
            ret[i] = (ret[i]%mod+mod)%mod;
        }
        ret.rsz(s); return ret;
    } // ~0.8s when sz(a)=sz(b)=1<<19
}

using namespace FFT;

vl CONV(const vl& a, const vl& b) {
    auto x = conv(a,b);
    trav(t,x) t %= MOD;
    return x;
}

int n, mxa;
mi ans;

array<vl,2> solve(int x) {
    array<vl,2> res;
    res[0] = {1}, res[1] = {0};
    if (x > 1) {
        int b = x/2;
        array<vl,2> tmp = solve(b);
        vl sum; F0R(i,n) sum.pb((tmp[0][i]+tmp[1][i])%MOD);
        F0R(j,2) {
            vl y;
            FOR(i,1,n+1) y.pb(tmp[j^(b&1)][i]);
            vl z = CONV(sum,y);
            FOR(i,1,n+1) res[j].pb(tmp[j][i]+z[i-1]);
        }
    }
    F0R(i,2) while (sz(res[i]) <= n) res[i].pb(0);
    if (x&1) {
        // ps("AA",res);
        F0Rd(i,sz(res[0])-1) F0R(j,2) 
            res[x&1][i+1] += res[j][i];
        // ps("BB",res);
    }
    F0R(i,2) trav(t,res[i]) t %= MOD;
    // ps("HA",x,res);
    for (int i = 1; i <= n; i += 2) ans += res[1][i];
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        setIO("A");
    #endif 
    re(n,mxa,MOD);
    solve(mxa/2);
    ps(ans);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/