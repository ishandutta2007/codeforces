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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 20001;
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

int N,ans[MX];
set<int> adj[MX], ADJ[MX];

bool test(vi a, vi b) {
    F0R(i,sz(a)) ans[a[i]] = b[i], ans[b[i]] = a[i];
    trav(x,a) trav(y,adj[x]) if (adj[ans[x]].count(ans[y])) return 0;
    return 1;
}


void rem(vi& a, vi b) {
    trav(t,b) a.erase(find(all(a),t));
}

vi remAdj(vi a) {
    vi res;
    trav(x,a) {
        trav(y,adj[x]) {
            res.pb(y);
            adj[y].erase(x);
        }
        adj[x].clear();
    }
    return res;
}

int getMax(vi a) {
    int bes = a[0];
    trav(t,a) if (sz(adj[t]) > sz(adj[bes])) bes = t;
    return bes;
}

void setAns(int a, int b) {
    ans[a] = b, ans[b] = a;
}

void finish1(vi a, vi b) {
    int w = getMax(a), v = 0, u = 0;
    trav(t,a) if (t != w && !adj[t].count(w)) v = t; 
    assert(v); u = *adj[v].begin();
    int w1 = 0, v1 = 0, u1 = 0;
    trav(t,b) if (sz(adj[t]) == 1) w1 = t;
    assert(w1); v1 = *adj[w1].begin();
    trav(t,b) if (t != w1 && t != v1 && !adj[v1].count(t)) u1 = t;
    setAns(u,u1), setAns(v,v1), setAns(w,w1);
    while (1) {
        while (sz(a) && (a.back() == u || a.back() == v || a.back() == w)) a.pop_back();
        while (sz(b) && (b.back() == u1 || b.back() == v1 || b.back() == w1)) b.pop_back();
        if (!sz(a)) return;
        setAns(a.back(), b.back()); a.pop_back(), b.pop_back();
    }
}

int m(vi a) {
    return sz(a)-1-sz(adj[getMax(a)]);
}

vi leaves(int m, vi a) {
    vi v; int dumb = 0; int bes = getMax(a);
    trav(t,adj[bes]) if (sz(adj[t]) == 1) {
        v.pb(t); dumb = bes;
        break;
    } 
    trav(t,a) if (sz(adj[t]) == 1 && dumb != *adj[t].begin()) {
        v.pb(t); if (sz(v) == 2) return v;
        dumb = *adj[t].begin();
    }
    exit(5);
}

bool ok(vi al, vi AL, vi bl, vi BL) {
    if (ans[AL[0]] == BL[0] || ans[AL[1]] == BL[1]) return 0;
    return 1;
}

void solve(vi a, vi b) {
    if (sz(a) <= 5) {
        sort(all(b));
        do { if (test(a,b)) return;
        } while (next_permutation(all(b)));
        exit(5);
    }
    int A = m(a), B = m(b); assert(A > 0 && B > 0);
    // ps(sz(a),a,b,A,B);
    if (A == 1) { finish1(a,b); return; }
    if (B == 1) { finish1(b,a); return; }
    vi al = leaves(A,a), bl = leaves(B,b);
    vi AL = remAdj(al), BL = remAdj(bl);
    rem(a,al), rem(b,bl); solve(a,b);
    if (!ok(al,AL,bl,BL)) {
        swap(al[0],al[1]), swap(AL[0],AL[1]);
        assert(ok(al,AL,bl,BL));
    }
    // ps("HUH",al,AL,bl,BL);
    F0R(i,2) setAns(al[i],bl[i]);
    // al[0] -> bl[0]
}

int main() {
	re(N);
	F0R(i,2*(N-1)) {
	    int u,v; re(u,v);
	    adj[u].insert(v), adj[v].insert(u);
	    ADJ[u].insert(v), ADJ[v].insert(u);
	}
	FOR(i,1,2*N+1) if (sz(adj[i]) == N-1) {
	    ps("No"); exit(0);
	}
	ps("Yes");
	vi a, b; FOR(i,1,N+1) a.pb(i), b.pb(i+N);
	solve(a,b);
	FOR(i,N+1,2*N+1) trav(t,ADJ[i]) if (ADJ[ans[i]].count(ans[t])) {
	    cout << "OOPS " << i << " " << t << " " << ans[i] << " " << ans[t];
	    exit(0);
	}
	FOR(i,1,N+1) pr(ans[i],' ');
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/