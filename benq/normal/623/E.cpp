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
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
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

template<int SZ> struct Combo {
    mi smallInv[SZ], fac[SZ], ifac[SZ]; 
    vpi factors; vi cnt[SZ];

    void genInv() {
        if (sz(factors) == 1 && factors[0].s == 1) {
            F0R(i,2) smallInv[i] = i;
            FOR(i,2,SZ) { // use only O(SZ) operations for MOD a prime
                int x = (MOD+i-1)/i;
                smallInv[i] = smallInv[i*x-MOD]*x;
            }
        } else {
            F0R(i,SZ) {
                int x = invGeneral(i,MOD);
                if (x == -1) smallInv[i] = 0;
                else smallInv[i] = x;
            }
        }
    }
    
    void init() {
        // factors = factor(MOD); 
        factors = {{MOD,1}}; 
        genInv(); cnt[0] = vi(sz(factors)); fac[0] = ifac[0] = 1;
        FOR(i,1,SZ) {
            cnt[i] = cnt[i-1]; int I = i;
            F0R(j,sz(factors)) while (I % factors[j].f == 0)
                I /= factors[j].f, cnt[i][j] ++;
            fac[i] = fac[i-1]*I; ifac[i] = ifac[i-1]*smallInv[I];
        }
    }

    mi comb(int a, int b) {
        if (a < b || b < 0) return 0;
        auto tmp = fac[a]*ifac[b]*ifac[a-b];
        F0R(i,sz(factors)) {
            int t = cnt[a][i]-cnt[a-b][i]-cnt[b][i];
            tmp *= pow(mi(factors[i].f),t);
        }
        return tmp;
    }
};

Combo<30005> C;

// const int MOD = (119 << 23) + 1, root = 3; // = 998244353
// NTT: For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.


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
    template<class T> bool small(const vector<T>& a, const vector<T>& b) { 
        return (ll)sz(a)*sz(b) <= 500000; // for small vectors, multiply directly
    } 

    /*void genRoots(vmi& roots) { // primitive n-th roots of unity
        int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
        roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r;
    }*/
    void genRoots(vcd& roots) { // change cd to complex<double> instead?
        int n = sz(roots); double ang = 2*PI/n;
        F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); // is there a way to do this more quickly?
    }
    template<class T> void fft(vector<T>& a, const vector<T>& roots, bool inv = 0) {
        int n = sz(a);
        for (int i = 1, j = 0; i < n; i++) { // sort by reverse bit representation
            int bit = n >> 1;
            for (; j&bit; bit >>= 1) j ^= bit;
            j ^= bit; if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) 
            for (int i = 0; i < n; i += len) 
                F0R(j,len/2) {
                    int ind = n/len*j; if (inv && ind) ind = n-ind;
                    auto u = a[i+j], v = a[i+j+len/2]*roots[ind];
                    a[i+j] = u+v, a[i+j+len/2] = u-v;
                }
        if (inv) { T i = T(1)/T(n); trav(x,a) x *= i; }
    }

    /*template<class T> vector<T> mult(vector<T> a, vector<T> b) {
        int s = sz(a)+sz(b)-1, n = 1<<size(s);
        vector<T> roots(n); genRoots(roots);
        a.rsz(n), fft(a,roots); 
        b.rsz(n), fft(b,roots);
        F0R(i,n) a[i] *= b[i];
        fft(a,roots,1); return a;
    }
    vcd smart(const vcd& a, const vcd& b) { return mult(a,b); }
    vl smart(const vl& a, const vl& b) {
        auto X = smart(vcd(all(a)),vcd(all(b)));
        vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
        return x;
    }
    vmi smart2(const vmi& a, const vmi& b) { return mult(a,b); }*/
    vmi smart(const vmi& a, const vmi& b) { // arbitrary MOD, ensure precision by splitting in half
        const int BIT = 15; 
        int s = sz(a)+sz(b)-1, n = 1<<size(s);
        vcd roots(n); genRoots(roots);
        
        vcd ax(n), bx(n);
        F0R(i,sz(a)) {
            int A = (int)a[i];
            ax[i] = cd(A>>BIT, A&((1<<BIT)-1)); // v1(x)=a1(x)+i*a0(x)
        }
        F0R(i,sz(b)) {
            int B = (int)b[i];
            bx[i] = cd(B>>BIT, B&((1<<BIT)-1)); // v2(x)=b1(x)+i*b0(x)
        }
        fft(ax,roots), fft(bx,roots);
        
        vcd v1(n), v0(n);
        F0R(i,n) {
            int j = (i ? (n-i) : i);
            cd a1 = (ax[i]+conj(ax[j]))*cd(0.5, 0);  // all should be real
            cd a0 = (ax[i]-conj(ax[j]))*cd(0, -0.5); 
            cd b1 = (bx[i]+conj(bx[j]))*cd(0.5, 0);  
            cd b0 = (bx[i]-conj(bx[j]))*cd(0, -0.5);
            v1[i] = a1*(b1+b0*cd(0,1));
            v0[i] = a0*(b1+b0*cd(0,1));
        }
        fft(v1,roots,1), fft(v0,roots,1);
        
        vmi ret(n);
        F0R(i,n) {
            ll V2 = (ll)round(v1[i].real()); // a0*b0
            ll V1 = (ll)round(v1[i].imag())+(ll)round(v0[i].real()); // a0*b1+a1*b0
            ll V0 = (ll)round(v0[i].imag()); // a1*b1
            ret[i] = ((((((V2%MOD)<<BIT)+V1)%MOD)<<BIT)+V0)%MOD;
        }
        ret.rsz(s); return ret;
    } // ~0.8s when sz(a)=sz(b)=1<<19
    template<class T> vector<T> conv(const vector<T>& a, const vector<T>& b) {
        if (small(a,b)) return a*b;
        return smart(a,b);
    } 
}

using namespace FFT;

ll n,k;

vmi comb(vmi x, vmi y, int r) {
	F0R(i,k+1) {
		x[i] *= pow(mi(2),i*r)*C.ifac[i];
		y[i] *= C.ifac[i];
	}
	auto z = conv(x,y); z.rsz(k+1);
	F0R(i,k+1) z[i] *= C.fac[i];
	return z;
}

vmi solve(int x) {
	if (x == 1) {
		// ps("HA",vmi(k+1,1));
		vmi v = vmi(k+1,1); v[0] = 0; return v;
	}
	//ps("HUH",x);
	if (x&1) return comb(solve(x-1),solve(1),1);
	auto a = solve(x/2); return comb(a,a,x/2);
}

int main() {
	C.init();
    setIO(); re(n,k);
    if (n > k) { ps(0); exit(0); }
    auto a = solve(n);
    // ps("HA",a);
    mi res = 0;
    F0R(i,k+1) res += C.comb(k,i)*a[i];
    ps(res);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/