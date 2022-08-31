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

template<class A, class B> A operator+=(A& l, const B& r) { return l = l+r; }
template<class A, class B> A operator-=(A& l, const B& r) { return l = l-r; }
template<class A, class B> A operator*=(A& l, const B& r) { return l = l*r; }
template<class A, class B> A operator/=(A& l, const B& r) { return l = l/r; }

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
        bool fst = 1; trav(a,x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); } 
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

template<class T> struct modInt {
    T val;
    T mod = 0;
    // static const T mod = MOD;

    void normalize() {
        if (mod == 0) return;
        val %= mod; if (val < 0) val += mod;
    }
    modInt(T v = 0, T m = 0) : val(v), mod(m) { normalize(); }
    // modInt(T v = 0, T m = 0) : val(v) { normalize(); }

    explicit operator T() const { return val; }
    friend ostream& operator<<(ostream& os, const modInt& a) { return os << a.val; }
    friend bool operator==(const modInt& a, const modInt& b) { return a.val == b.val; }
    friend bool operator!=(const modInt& a, const modInt& b) { return !(a == b); }

    friend void check(modInt& a, modInt& b) { // make sure all operations are valid
        // comment out if mod is static const
        if (a.mod > 0 && b.mod > 0) { assert(a.mod == b.mod); return; }
        T mod = max(a.mod,b.mod); if (mod == 0) mod = MOD;
        if (a.mod != mod) { a.mod = mod; a.normalize(); }
        if (b.mod != mod) { b.mod = mod; b.normalize(); }
    }
    friend modInt operator+(modInt a, modInt b) {
        check(a,b); a.val += (T)b;
        if (a.val >= a.mod) a.val -= a.mod;
        return a;
    }
    friend modInt operator-(modInt a, modInt b) {
        check(a,b); a.val -= (T)b; 
        if (a.val < 0) a.val += a.mod; 
        return a;
    }
    friend modInt operator-(const modInt& a) { return modInt(0)-a; }

    friend modInt operator*(modInt a, modInt b) {
        check(a,b); a.val = (ll)a.val*(T)b%a.mod; return a;
    }
    friend modInt exp(modInt a, ll p) {
        modInt ans(1,a.mod);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modInt inv(const modInt& a) {
        return {invGeneral(a.val,a.mod),a.mod};
        // return exp(b,b.mod-2) if prime
    }
    friend modInt operator/(modInt a, modInt b) { 
        check(a,b); return a*inv(b); 
    }
};

typedef modInt<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

vl v = {1,2,3,4,5,6,7,8,9};

bool ok(int x) {
    return find(all(v),x) != v.end();
}

int index(int x) {
    return ub(all(v),x)-v.begin();
}

vi tmp = {9+1, 4+1, 0+1, -3+1, -5+1, -6+1, -6+1, -5+1, -3+1, 0+1, 4+1};

int getRank(string s) {
    int c = s.back()-'0';
    if (sz(s) == 1) return c;
    int x = getRank(s.substr(0,sz(s)-1)); if (x == -1) return -1;
    if (x <= c) return -1;
    return (c+5*x+tmp[x])%11;
}

void dumb() {
    // FOR(i,1,500) ps(i,getRank(to_string(i)));
    /*
    F0R(i,1000) {
        int c = (i+1)%11;
        F0R(j,c) v.pb(10*v[i]+j);
    }
    FOR(i,1,1000) if (find(all(v),i) == v.end()) assert(getRank(to_string(i)) == -1);
    F0R(i,sz(v)) ps(v[i],i,(i+1)%11,getRank(to_string(v[i])));*/
    // F0R(i,sz(v)) ps(v[i],index(v[i]),index(v[i]/10));
    // F0R(i,sz(v)) ps(i+1,v[i]);
    // F0R(i,sz(v)) ps(v[i],ok())
    //F0R(i,sz(v)) ps(i+1,v[i],v[i]%11,(i+1)%11);
}

typedef array<int,11> T;

T nex[10];

T id() {
    T res = T();
    F0R(i,11) res[i] = i;
    return res;
}

T operator+(const T& l, const T& r) {
    T res = T();
    F0R(i,11) {
        if (l[i] == -1) res[i] = -1;
        else res[i] = r[l[i]];
    }
    return res;
}

string s; 

void init() {
    setIO(); re(s);
    F0R(i,sz(tmp)) {
        tmp[i] += 5*i;
        tmp[i] %= 11;
    }
    F0R(i,10) {
        F0R(j,11) {
            if (j <= i) nex[i][j] = -1;
            else nex[i][j] = (i+tmp[j])%11;
        }
    }
}

template<int SZ> struct Seg { // SZ should be power of 2
    T seg[2*SZ], ID = id();

    Seg() { F0R(i,2*SZ) seg[i] = ID;  }
    T comb(T a, T b) { return a+b; }
    // easily change this to min or max
    // comb(ID,b) must equal b

    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]);
            // make sure non-commutative operations work
    }

    int query(int c, T& z, int ind = 1, int l = 0, int r = SZ-1) {  // sum on interval [l, r]
        // ps("WAT",c,z,ind,z+seg[ind],l,r);
        int m = (l+r)/2;
        // first index such that ok 
        if ((z+seg[ind])[c] != -1) {
            z = z+seg[ind];
            return r;
        }
        if (l == r) return l-1;
        int x = query(c,z,2*ind,l,m);
        if (x == m) return query(c,z,2*ind+1,m+1,r);
        return x;
    }
};

Seg<1<<17> S;

int main() {
    init();
    ll ans = 0;
    F0Rd(i,sz(s)) {
        int c = s[i]-'0';
        if (c) {
            T tmp = id();
            int r = S.query(c,tmp);
            // ps("WHAT",i,r);
            ckmin(r,sz(s)-1);
            ans += r-i+1;
        }
        S.upd(i,nex[c]);
        // ps("??",nex[c],S.seg[1]);
    }
    ps(ans);
    /*ps(tmp);
    F0R(i,sz(s)) if (s[i] != '0') {
        int cur = s[i]-'0'; ans ++;
        FOR(j,i+1,sz(s)) {
            if (cur <= s[j]-'0') break;
            cur = (s[j]-'0'+tmp[cur])%11; ans ++;
        }
    }
    ps(ans);*/
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/