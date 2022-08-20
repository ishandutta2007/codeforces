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
const int MX = 500005;
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

int n, nex[2*MX], pre[2*MX];
vi a;
int oc[MX];

vi nextVal;

void no() {
    ps("no");
    exit(0);
}

/*vi child[MX];

void dfs(int x) {
    a.pb(x);
    trav(t,child[x]) {
        dfs(t);
        a.pb(x);
    }
}*/

void init() {
	re(n); a.resz(2*n-1); re(a);
	// FOR(i,2,n+1) child[rand()%min(i-1,500)+1].pb(i); dfs(1);
	assert(sz(a) == 2*n-1);
	if (a[0] && a[2*n-2] && a[0] != a[2*n-2]) no();
	if (a[0] || a[2*n-2]) a[0] = a[2*n-2] = max(a[0],a[2*n-2]);
	// F0R(i,sz(a)) if (a[i]) oc[a[i]].pb(i);
	FOR(i,1,n+1) oc[i] = -1;
	F0R(i,sz(a)) {
	    nex[i] = pre[i] = -1;
	    if (a[i] && oc[a[i]] != -1) {
	        if ((i-oc[a[i]]) % 2 != 0) no();
	        pre[i] = oc[a[i]]; nex[oc[a[i]]] = i;
	    }
	    oc[a[i]] = i;
	}
	FOR(i,1,n+1) if (oc[i] == -1) nextVal.pb(i);
    // if (a[0] == 91641) exit(0);
    vi tmp;
	F0R(i,sz(a)) if (a[i]) {
	    if (sz(tmp) && i == tmp.back()) {
	        tmp.pop_back();
	    } 
	    if (nex[i] != -1) {
	        if (sz(tmp) && nex[i] > tmp.back()) no();
	        tmp.pb(nex[i]);
	    }
	}
}

bool eq(int x, int y) {
    return !a[x] || !a[y] || a[x] == a[y];
}

void assign(vi v) {
    int val = 0; trav(t,v) ckmax(val,a[t]);
    if (val) {
        trav(t,v) a[t] = val;
    } else {
        int x = nextVal.back(); nextVal.pop_back();
        trav(t,v) a[t] = x;
    }
}

void prin(vi v) {
    trav(t,v) pr(a[t],' ');
    ps();
}

int ok[2*MX], nexz[2*MX], prez[2*MX];

struct dumbQueue {
    int dat[5000000], st, en;
    void push(int x) {
        // assert(en < 4999999);
        dat[++en] = x;
    }
    void pop() {
        st ++;
    }
    int front() {
        return dat[st];
    }
    int size() {
        return en-st+1;
    }
    void reset() {
        st = 0, en = -1;
    }
};

dumbQueue t1, t2;

void ins(int t) {
    if (t == -1) return;
    int x = prez[t], y = nexz[t]; if (min(x,y) == -1) return;
    x = a[x], y = a[y];
    if (min(x,y) > 0 && x != y) return;
    if (max(x,y) > 0 && a[t] > 0) {
        ok[t] = 2; t2.push(t);
    } else {
        ok[t] = 1; t1.push(t);
    }
}

vi cool(vi Z) {
    vi v; trav(t,Z) v.pb(a[t]);
    return v;
}

void del(int x) {
    if (prez[x] != -1) nexz[prez[x]] = nexz[x];
    if (nexz[x] != -1) prez[nexz[x]] = prez[x];
}

int tot = 0;

int iter = 0;

void process(const vi& z) {
    t1.reset(); t2.reset();
    tot += sz(z);
    int co = -2; 
    trav(t,z) {
        if (a[t]) co ++;
        nexz[t] = prez[t] = -1;
    }
    F0R(i,sz(z)-1) nexz[z[i]] = z[i+1], prez[z[i+1]] = z[i];
    if (co > (sz(z)-1)/2) no();
    assert(sz(z)%2 == 1);
    trav(t,z) ins(t);
    int lef = sz(z); iter += lef;
    while (lef > 1) {
        int x = -1;
        while (x == -1 && sz(t2)) {
            x = t2.front(); t2.pop(); iter ++;
            if (ok[x] != 2) { x = -1; continue; }
        }
        while (x == -1 && sz(t1)) {
            x = t1.front(); t1.pop(); iter ++;
            if (ok[x] != 1) { x = -1; continue; }
        }
        assert(x != -1); 
        ok[x] = 0; int l = prez[x], r = nexz[x]; iter ++;
        ok[l] = 0; if (prez[l] != -1) ok[prez[l]] = 0; iter ++;
        ok[r] = 0; if (nexz[r] != -1) ok[nexz[r]] = 0; iter ++;
        assign({l,r}); assign({x}); iter ++; iter ++; iter ++;
        del(r); del(x); lef -= 2; iter ++; iter ++;
        ins(l); ins(prez[l]); ins(nexz[l]); iter ++; iter ++; iter ++;
    }
}

void solve(int l, int r) {
    vi z;
    if (l != -1) z.pb(l);
    FOR(i,l+1,r) {
        if (pre[i] != -1) continue;
        z.pb(i); 
        while (nex[i] != -1) {
            solve(i,nex[i]);
            i = nex[i];
        }
    }
    if (r != sz(a)) z.pb(r);
    process(z);  
}

int main() {
    init();
    solve(-1,sz(a));
    // if (n == 500000) ps(tot);
    ps("yes");
    if (sz(a) == 1) {
        ps(1);
        exit(0);
    }
    // if (a[0] == 91641) ps(iter);
    trav(t,a) pr(t,' ');
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/