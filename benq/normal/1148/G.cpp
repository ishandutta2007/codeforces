#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define NDEBUG 

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

int n,k,cnt[10000001];
vi fac[MX];
vi a;

void dfs(vi& v, int ind, int cur, int sgn) {
    if (ind == sz(v)) {
        cnt[cur] += sgn;
        return;
    }
    dfs(v,ind+1,cur,sgn);
    dfs(v,ind+1,cur*v[ind],sgn);
}

void ad(int x, int y) {
    dfs(fac[x],0,1,y);
}

int dfs2(vi& v, int ind, int cur, int sgn) {
    if (ind == sz(v)) return sgn*cnt[cur];
    return dfs2(v,ind+1,cur,sgn)+dfs2(v,ind+1,cur*v[ind],-sgn);
}

int query(int x) { return dfs2(fac[x],0,1,1); }

vi factor(int x) {
    vi ret;
    for (int i = 2; i*i <= x; ++i) if (x%i == 0) {
        ret.pb(i); while (x%i == 0) x /= i;
    }
    if (x > 1) ret.pb(x);
    return ret;
}

void init() {
	setIO(); re(n,k); a.resz(n); re(a);
	F0R(i,n) fac[i] = factor(a[i]);
	F0R(i,n) ad(i,1);
}

void fin(vi ret) {
    assert(sz(ret) >= k); ret.resz(k);
    trav(t,ret) pr(t+1,' ');
    exit(0);
}

vi clique, dumb;
int cnum;

vi solve(int num) {
    while (cnum > num) ad(dumb[--cnum],-1);
    while (cnum < num) ad(dumb[cnum++],1);
    vi ret; F0R(i,num) if (query(dumb[i])) ret.pb(dumb[i]);
    return ret;
}

vi notIn(vi a, vi b) {
    int ind = 0;
    vi ret;
    trav(t,b) {
        while (ind < sz(a) && a[ind] < t) ind ++;
        if (ind == sz(a) || a[ind] != t) ret.pb(t);
    }
    return ret;
}

vi comb(vi a, vi b) {
    a.insert(a.end(),all(b)); return a;
}

int main() {
    init();
	int ok = -1; F0R(i,n) if (query(i) > 1) ok = i;
	if (ok == -1) {
	    F0R(i,n) ad(i,-1);
	    vi ret;
	    F0R(i,n) if (!query(i)) {
	        ret.pb(i);
	        ad(i,1);
	    }
	    fin(ret);
	}
	vi cool = {ok}; F0R(i,n) if (__gcd(a[i],a[ok]) == 1) cool.pb(i);
	assert(sz(cool) >= 3);
	cool.resz(3); if (k == 3) fin(cool); 
	trav(t,cool) ad(t,-1);
	F0R(i,n) if (find(all(cool),i) == cool.end()) {
	    if (query(i) == 0) clique.pb(i);
	    else dumb.pb(i);
	}
	if (sz(clique) >= k) fin(clique);
	cnum = sz(dumb);
	int lo = 1, hi = sz(dumb);
	while (lo < hi) {
	    int mid = (lo+hi)/2;
	    if (sz(solve(mid))+3 >= k) hi = mid;
	    else lo = mid+1;
	}
	auto a = solve(lo-1), b = solve(lo);
	auto c = notIn(a,b); reverse(all(c)); 
	if (sz(c) > 1) c.resz(max(2,k-sz(a)-3));
	if (sz(a)+3+sz(c) > k) cool.pop_back();
	assert(sz(a)+sz(cool)+sz(c) == k);
	fin(comb(cool,comb(a,c)));
	// sz(a)+4+(at least one from c, )
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/