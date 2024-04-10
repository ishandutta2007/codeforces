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
 
const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 1e8;
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
 
vi X,Y;
 
vi v, h;
pi lst = {-MX,-MX};
 
int num = 0;

int query(int x, int y) {
    num ++;
    assert(abs(x) <= MX && abs(y) <= MX);
    #ifdef ONLINE_JUDGE
        cout << "0 " << x << " " << y << endl;
        int r; re(r); return r;
    #else 
    	int res = MOD;
    	trav(t,X) ckmin(res,abs(t-x));
    	trav(t,Y) ckmin(res,abs(t-y));
    	return res;
    #endif
}
 
bool ver(int x) {
    if (abs(x) > MX) return 0;
	F0R(i,2) if (query(x,rng()%(2*MX+1)-MX)) return 0;
	v.pb(x); lst.f = x; return 1;
}
 
bool hor(int y) {
    if (abs(y) > MX) return 0;
	F0R(i,2) if (query(rng()%(2*MX+1)-MX,y)) return 0;
	h.pb(y); lst.s = y; return 1;
}
 
void fin() {
    /*ps("TOT",num,v==X,h==Y);
	exit(0);*/
	cout << "1 " << sz(v) << " " << sz(h) << endl;
	trav(t,v) pr(t,' ');
	cout << endl;
	trav(t,h) pr(t,' ');
	cout << endl;
	exit(0);
}
 
void finh() {
	h.clear();
	auto V = v; V.pb(-MX), V.pb(MX); sort(all(V));
	int xx = MOD;
	F0R(i,sz(V)-1) if (V[i+1]-V[i] >= 19900) xx = (V[i]+V[i+1])/2;
	assert(xx != MOD);
	int lst = -MX; hor(lst);
	while (lst < MX) {
		int r = min(8192,MX-lst);
		if (query(xx,lst+r) >= r) {
			lst += r;
			continue;
		}
        int a = 0, b = 0; while ((1<<(b+1)) <= r) b ++;
        while (a < b) {
            int m = (a+b)/2;
            if (query(xx,lst+(1<<m)) < (1<<m)) b = m;
            else a = m+1;
        }
        lst += (1<<a)+query(xx,lst+(1<<a)); 
        assert(hor(lst));
	}
	fin();
}
 
void finv() {
    // ps("V");
	v.clear();
	auto H = h; H.pb(-MX), H.pb(MX); sort(all(H));
	int yy = MOD;
	F0R(i,sz(H)-1) if (H[i+1]-H[i] >= 19900) yy = (H[i]+H[i+1])/2;
	assert(yy != MOD);
	int lst = -MX; ver(lst);
	while (lst < MX) {
		int r = min(8192,MX-lst);
		if (query(lst+r,yy) >= r) {
			lst += r;
			continue;
		}
        int a = 0, b = 0; while ((1<<(b+1)) <= r) b ++;
		while (a < b) {
            int m = (a+b)/2;
            if (query(lst+(1<<m),yy) < (1<<m)) b = m;
            else a = m+1;
		}
		lst += (1<<a)+query(lst+(1<<a),yy); assert(ver(lst));
	}
	fin();
}
 
int main() {
	/*F0R(i,9990) {
		X.pb(rand()%(2*MX+1)-MX);
	}
    F0R(i,9990) Y.pb(rand()%(2*MX+1)-MX);
    sort(all(X)), sort(all(Y));
    X.erase(unique(all(X)),X.end()), Y.erase(unique(all(Y)),Y.end());*/
    X = {100000000};
    Y = {-100000000};
    // int BLOCK = 1<<13;
	ver(-MX), hor(-MX);
	while (1) {
		int r = min(MX-lst.f,MX-lst.s); if (!r) break;
		// if (query(lst.f+r,lst.s+r) == r) break;
        int a = 0, b = 0; while ((1<<(b+1)) <= r) b ++;
        // ps("HUH",a,b); exit(0);
        while (a < b) {
            int m = (a+b)/2;
            int q = query(lst.f+(1<<m),lst.s+(1<<m));
            if (q == (1<<m)) a = m+1;
            else b = m;
        }
        // ps("HUH",a,b,lst.f+(1<<27),lst.s+(1<<a));
        // exit(0);
        int q = query(lst.f+(1<<a),lst.s+(1<<a)); if (q == (1<<a)) break;
        assert(ver(lst.f+(1<<a)+q) || hor(lst.s+(1<<a)+q));
	}
    // exit(0);
    // ps("WUT",num,sz(h),sz(v));
	// ps(lst); exit(0);
	if (lst.f > lst.s) finh();
	else finv();
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/