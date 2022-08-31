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

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { return invGeneral(a.val,MOD); } 
    // inv is equivalent to return exp(b,b.mod-2) if prime
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

int t, n, ans[MX];
// vi col = {1,1,1,1,1,1,1,1,1,1};

vi query(vpi a) {
    if (!sz(a)) return {};
    trav(t,a) assert(t.f != t.s);
    cout << "Q " << sz(a) << " ";
    trav(t,a) cout << t.f+1 << " " << t.s+1 << " ";
    cout << endl;
    string x = ""; 
    /*trav(t,a) if (col[t.f] == col[t.s]) x += '1';
    else x += '0';*/
    // ps("WHAT",x);
    re(x); 
    vi ret;
    trav(t,x) ret.pb(t-'0');
    // ps("WAT",ret);
    trav(t,ret) assert(t == 0 || t == 1);
    return ret;
}

vi solve(vi cyc) {
    assert(sz(cyc) > 1);
    vpi a, b, c; 
    c.pb({cyc.back(),cyc.front()});
    for (int i = 0; i+1 < sz(cyc); i += 2) a.pb({cyc[i],cyc[i+1]});
    for (int i = 1; i+1 < sz(cyc); i += 2) b.pb({cyc[i],cyc[i+1]});
    vi A = query(a), B = query(b), C = query(c);
    vi ret(sz(cyc));
    F0R(i,sz(cyc)) {
        if (i == sz(cyc)-1) ret[i] = C[0];
        else if (i&1) ret[i] = B[i/2];
        else ret[i] = A[i/2];
    }
    return ret;
}

vector<vi> compress(vi cyc) {
    if (sz(cyc) == 1) return {cyc};
    auto x = solve(cyc);
    int ind = 0; while (ind < sz(x) && x[ind] == 1) ind ++;
    ind = (ind+1)%sz(cyc);
    rotate(cyc.begin(),cyc.begin()+ind,cyc.end());
    rotate(x.begin(),x.begin()+ind,x.end());
    vector<vi> V;
    for (int i = 0; i < sz(cyc); ) {
        vi cur = {cyc[i]};
        while (i < sz(cyc)-1 && x[i] == 1) {
            i ++;
            cur.pb(cyc[i]);
        }
        V.pb(cur); i ++;
    }
    return V;
    // ps(x,ind,x[ind]); exit(0);
}

void zz(vi a) {
    trav(t,a) pr(t+1,' ');
    cout << endl;
}

void answer() {
    vi a,b,c;
    F0R(i,n) {
        if (ans[i] == 0) a.pb(i);
        else if (ans[i] == 1) b.pb(i);
        else c.pb(i);
    }
    cout << "A " << sz(a) << " " << sz(b) << " " << sz(c) << endl;
    zz(a); zz(b); zz(c);
}

void assign(vi x, int y) {
    trav(t,x) ans[t] = y;
}

int getCol(vi& x) {
    return ans[x[0]];
}

void solve() {
    re(n); F0R(i,n) ans[i] = 0;
    vi cyc; F0R(i,n) cyc.pb(i);
    auto a = compress(cyc);
    if (sz(a) == 1) { answer(); return; }
    vpi q0, q1;
    for (int i = 0; i < sz(a); i += 4) {
        if (i+2 < sz(a)) q0.pb({a[i].back(),a[i+2].back()});
        if (i+3 < sz(a)) q0.pb({a[i+1].back(),a[i+3].back()});
        if (i+4 < sz(a)) q1.pb({a[i+2].back(),a[i+4].back()});
        if (i+5 < sz(a)) q1.pb({a[i+3].back(),a[i+5].back()});
    }
    int i0 = 0, i1 = 0;
    vi Q0 = query(q0); vi Q1 = query(q1);
    // ps(a);
    // ps(q0,q1,Q0,Q1);
    vi Q;
    F0R(i,sz(a)-2) {
        // ps("??",i%4,i%4 <= 1);
        if (i % 4 <= 1) Q.pb(Q0[i0++]);
        else Q.pb(Q1[i1++]);
    }
    // ps("ER",Q1[0],i0,i1);
    // ps(Q); exit(0);
    assign(a[0],0); assign(a[1],1);
    FOR(i,2,sz(a)) {
        if (Q[i-2] == 1) assign(a[i],getCol(a[i-2]));
        else {
            int x = 3-getCol(a[i-1])-getCol(a[i-2]);
            assign(a[i],x);
        }
    }
    answer();
}

int main() {
    re(t);
    F0R(i,t) solve();
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/