#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 
 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 
 
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 10007; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
 
template<class T> bool ckmin(T& a, const T& b) { 
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
    return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }
 
template<class T, class U> T fstTrue(T lo, T hi, U f) { 
    // note: if (lo+hi)/2 is used instead of half(lo+hi) then this will loop infinitely when lo=hi
    hi ++; assert(lo <= hi); // assuming f is increasing
    while (lo < hi) { // find first index such that f is true 
        T mid = half(lo+hi);
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
    lo --; assert(lo <= hi); // assuming f is decreasing
    while (lo < hi) { // find first index such that f is true 
        T mid = half(lo+hi+1);
        f(mid) ? lo = mid : hi = mid-1;
    } 
    return lo;
}
template<class T> void remDup(vector<T>& v) { 
    sort(all(v)); v.erase(unique(all(v)),end(v)); }
 
// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);
 
template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
 
template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }
 
// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
    #ifdef LOCAL
        return b ? "true" : "false"; 
    #else 
        return ts((int)b);
    #endif
}
template<class A> str ts(complex<A> c) { 
    stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
    str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; F0R(i,SZ) res += char('0'+b[i]);
    return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
    #ifdef LOCAL
        bool fst = 1; str res = "{";
        for (const auto& x: v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(x);
        }
        res += "}"; return res;
    #else
        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += " ";
            fst = 0; res += ts(x);
        }
        return res;
 
    #endif
}
template<class A, class B> str ts(pair<A,B> p) {
    #ifdef LOCAL
        return "("+ts(p.f)+", "+ts(p.s)+")"; 
    #else
        return ts(p.f)+" "+ts(p.s);
    #endif
}
 
// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
    pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
    pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << ts(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
    #define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
         << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
    #define dbg(...) 0
    #define chk(...) 0
#endif
 
// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
    unsyncIO();
    // cin.exceptions(cin.failbit); 
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}
 
/**
 * Description: modular arithmetic operations 
 * Source: 
    * KACTL
    * https://codeforces.com/blog/entry/63903
    * https://codeforces.com/contest/1261/submission/65632855 (tourist)
    * https://codeforces.com/contest/1264/submission/66344993 (ksun)
    * also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
    * https://open.kattis.com/problems/modulararithmetic
 */
 
template<int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() { v = 0; }
    mint(ll _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD; }
    friend bool operator==(const mint& a, const mint& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b) { 
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { 
        return a.v < b.v; }
    friend void re(mint& a) { ll x; re(x); a = mint(x); }
    friend str ts(mint a) { return ts(a.v); }
   
    mint& operator+=(const mint& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mint& operator-=(const mint& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mint& operator*=(const mint& m) { 
        v = (ll)v*m.v%MOD; return *this; }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
        mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend mint inv(const mint& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }
        
    mint operator-() const { return mint(-v); }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
};
 
typedef mint<10007,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;
 
vector<vmi> scmb; // small combinations
void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FOR(i,1,SZ) F0R(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}
 
 
/**
 * Description: Basic poly ops including division. Can replace \texttt{T} with double, complex.
 * Source: Own. Also see
    * https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/PolyInterpolate.h
    * https://github.com/ecnerwala/icpc-book/blob/master/content/numerical/fft.cpp
 * Verification: see FFT
 */
 
// #include "../../number-theory (11.1)/Modular Arithmetic/ModInt.h"
 
using T = mi; using poly = vector<T>;
void remz(poly& p) { while (sz(p)&&p.bk==T(0)) p.pop_back(); }
poly REMZ(poly p) { remz(p); return p; }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { 
    if (x >= 0) p.insert(begin(p),x,0); 
    else assert(sz(p)+x >= 0), p.erase(begin(p),begin(p)-x);
    return p; 
}
poly RSZ(const poly& p, int x) { 
    if (x <= sz(p)) return poly(begin(p),begin(p)+x);
    poly q = p; q.rsz(x); return q;  }
T eval(const poly& p, T x) { // evaluate at point x
    T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
    return res; }
poly dif(const poly& p) { // differentiate
    poly res; FOR(i,1,sz(p)) res.pb(T(i)*p[i]); 
    return res; }
poly integ(const poly& p) { // integrate
    poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]/T(i+1);
    return res; }
 
poly& operator+=(poly& l, const poly& r) {
    l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
    return l; }
poly& operator-=(poly& l, const poly& r) {
    l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
    return l; }
poly& operator*=(poly& l, const T& r) { trav(t,l) t *= r; 
    return l;    }
poly& operator/=(poly& l, const T& r) { trav(t,l) t /= r; 
    return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { trav(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;  }
poly operator*(const poly& l, const poly& r) {
    if (!min(sz(l),sz(r))) return {};
    poly x(sz(l)+sz(r)-1); 
    F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
    return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }
 
pair<poly,poly> quoRem(poly a, poly b) { 
    remz(a); remz(b); assert(sz(b));
    T lst = b.bk, B = T(1)/lst; trav(t,a) t *= B; 
    trav(t,b) t *= B;
    poly q(max(sz(a)-sz(b)+1,0));
    for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
        q[dif] = a.bk; F0R(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
    trav(t,a) t *= lst;
    return {q,a}; // quotient, remainder
}
poly operator/(const poly& a, const poly& b) { return quoRem(a,b).f; }
poly operator%(const poly& a, const poly& b) { return quoRem(a,b).s; }
/**poly a = {1,3,5,8,6,0,0,0,0}, b = {1,5,1};
ps(quoRem(a,b)); a = 2*a, b = 2*b; ps(quoRem(a,b));*/
poly gcd(poly a, poly b) { return b == poly{} ? a : gcd(b,a%b); }
T resultant(poly a, poly b) { // R(A,B)
    // =b_m^n*prod_{j=1}^mA(mu_j)
    // =b_m^na_m^n*prod_{i=1}^nprod_{j=1}^m(mu_j-lambda_i)
    // =(-1)^{mn}a_n^m*prod_{i=1}^nB(lambda_i)
    // =(-1)^{nm}R(B,A)
    // Also, R(A,B)=b_m^{deg(A)-deg(A-CB)}R(A-CB,B)
    int ad = sz(a)-1, bd = sz(b)-1; 
    if (bd <= 0) return bd < 0 ? 0 : pow(b.bk,ad);
    int pw = ad; a = a%b; pw -= (ad = sz(a)-1);
    return resultant(b,a)*pow(b.bk,pw)*T((bd&ad&1)?-1:1);
}
 
/**
 * Description: Berlekamp-Massey, computes linear recurrence 
    * \texttt{C} of order $N$ for sequence \texttt{s} of $2N$ terms.
 * Time: \texttt{init} $\Rightarrow O(N|C|),$ 
    * \texttt{eval} $\Rightarrow O(|C|^2\log p)$.
 * Usage: LinRec L; L.init({0,1,1,2,3,5,8}); // Fibonacci
 * Source: 
    * https://en.wikipedia.org/wiki/Berlekamp%E2%80%93Massey_algorithm
    * http://codeforces.com/blog/entry/61306
    * MIT ICPC notebook
 * Verification: http://codeforces.com/contest/506/problem/E
 */
 
struct LinRec {
    poly s, C, rC; 
    void init(const poly& _s) { 
        s = _s; int x = 0; T b = 1; // B is fail vector, gives 0,0,...,b
        poly B; B = C = {1}; // invariant: sz(B)+x = M
        F0R(i,sz(s)) { ++x; int L = sz(C), M = i+3-L;
            T d = 0; F0R(j,L) d += C[j]*s[i-j]; 
            if (d == 0) continue; // rec still works
            poly _C = C; T coef = d/b; // invariant: sz(B)+x=_L
            C.rsz(max(L,M)); F0R(j,sz(B)) C[j+x] -= coef*B[j];
            if (L < M) B = _C, b = d, x = 0;
        }
        rC = C; reverse(all(rC)); // poly for getPo
        C.erase(begin(C)); trav(t,C) t *= -1;
    } // x[i]=sum_{j=0}^{sz(C)-1}C[j]*x[i-j-1]
    poly getPo(ll p) { // get x^p mod rC
        if (p == 0) return {1};
        poly r = getPo(p/2); r = (r*r)%rC;
        return p&1?(r*poly{0,1})%rC:r;
    }
    T dot(poly v) { // dot product with seq
        T ans = 0; F0R(i,sz(v)) ans += v[i]*s[i];
        return ans; } // get p-th term of rec
    T eval(ll p) { assert(p >= 0); return dot(getPo(p)); } 
};
 
const int L = 1501;
 
int dp[203][203][L],n;
vmi ans(L);
string s;
 
int mul(int a, int b) { return (a*b%MOD+MOD)%MOD; }
void AD(int& a, int b) { a = (a+b)%MOD; }
void SUB(int& a, int b) { a = (a-b+MOD)%MOD; }
int po(int a, int b) { return !b?1:po(a*a%MOD,b/2)*(b&1?a:1)%MOD; }
int inv(int a) { return po(a,MOD-2); }
 
void adDP(int i, int j, int k, int v) {
    if (k >= L) return;
    AD(dp[i][j][k],v);
}
 
void adANS(int k, int v) {
    if (k >= L) return;
    ans[k] += v;
}
 
void gen() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> n;
    dp[1][sz(s)][0] = 1;
    for (int dif = sz(s)-1; dif >= -1; dif --) for (int i = 1; i+dif <= sz(s); ++i) F0R(k,L) {
        int j = i+dif;
        int v = dp[i][j][k];
        if (i-1 == j) {
            adANS(k+1,mul(26,v)); adANS(k,v);
            adDP(i,j,k+2,mul(26,v));
        } else if (i == j) {
            adANS(k,v);
            adDP(i,j-1,k+1,v);
            adDP(i,j,k+2,mul(v,25));
        } else if (s[i-1] == s[j-1]) {
            adDP(i+1,j-1,k,v); adDP(i,j,k+2,mul(v,25));
        } else {
            adDP(i+1,j,k+1,v); adDP(i,j-1,k+1,v); adDP(i,j,k+2,mul(v,24));
        }
    }
}
 
int main() {
    gen();
    LinRec L; L.init(ans);
    ps(L.eval(n));
}