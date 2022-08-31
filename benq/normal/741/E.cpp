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
 
template<class T, int SZ> struct RMQ {
    constexpr static int level(int x) { return 31-__builtin_clz(x); } // floor(log_2(x))
    int stor[SZ][level(SZ)+1];
    vector<T> v;
    
    int comb(int a, int b) { return v[a] == v[b] ? min(a,b) : (v[a] < v[b] ? a : b); } // index of minimum
    
    void init(const vector<T>& _v) {
        v = _v; F0R(i,sz(v)) stor[i][0] = i; 
        FOR(j,1,level(sz(v))+1) F0R(i,sz(v)-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],stor[i+(1<<(j-1))][j-1]);
    }
    
    int index(int l, int r) { // get index of min element
        int x = level(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
    T query(int l, int r) { return v[index(l,r)]; }
};
 
struct LCP {
    string S; int N;
    void init(string _S) {
        S = _S; N = sz(S);
        suffixArray(); lcpArray();
        R.init(lcp);
    }
    
    vi sa;
    void suffixArray() { // http://ekzlib.herokuapp.com
        sa.rsz(N); vi classes(N);
        F0R(i,N) sa[i] = N-1-i, classes[i] = S[i];
        stable_sort(all(sa), [this](int i, int j) { return S[i] < S[j]; });
        for (int len = 1; len < N; len *= 2) { 
            vi c(classes);
            F0R(i,N) { // compare first len characters of each suffix
                bool same = i && sa[i-1] + len < N
                              && c[sa[i]] == c[sa[i-1]]
                              && c[sa[i]+len/2] == c[sa[i-1] + len/2];
                classes[sa[i]] = same ? classes[sa[i-1]] : i;
            }
            vi nex(N), s(sa); F0R(i,N) nex[i] = i; // suffixes with <= len chars will not change pos 
            F0R(i,N) {
                int s1 = s[i]-len;
                if (s1 >= 0) sa[nex[classes[s1]]++] = s1; // order pairs w/ same first len chars by next len chars 
            }
        }
    }
    
    vi inv, lcp;
    void lcpArray() { // KACTL
        int h = 0;
        inv.rsz(N), lcp = vi(N,-1); F0R(i,N) inv[sa[i]] = i; // pos -> suffix rank
        F0R(i,N) if (inv[i]) {
            int pre = sa[inv[i]-1];
            while (max(i,pre)+h < N && S[i+h] == S[pre+h]) h++;
            lcp[inv[i]] = h; // lcp of suffixes starting at p0 and i
            if (h) h--; // if we cut off first chars of two strings with lcp h, then remaining portions still have lcp h-1 
        }
    }
    
    RMQ<int,MX> R; 
    int getLCP(int a, int b) {
        if (max(a,b) >= N) return 0;
        if (a == b) return N-a;
        int t0 = inv[a], t1 = inv[b];
        if (t0 > t1) swap(t0,t1);
        return R.query(t0+1,t1);
    }
};
 
LCP L;
int n;
string S,T;
RMQ<int,100005> R, R2;
vi rr, rr2;
 
bool cmp(int i, int j) {
	if (i == j) return 0;
	bool flip = 0;
	if (i > j) swap(i,j), flip = 1;
	if (j-i > sz(T)) {
		int t = L.getLCP(sz(S),i);
		if (t < sz(T)) return (T[t] < S[i+t]) ^ flip;
		t = L.getLCP(i,i+sz(T));
		if (t < j-i-sz(T)) return (S[i+t] < S[i+sz(T)+t]) ^ flip;
		t = L.getLCP(j-sz(T),sz(S));
		if (t < sz(T)) return (S[j-sz(T)+t] < T[t]) ^ flip;
	} else {
		int t = L.getLCP(sz(S),i);
		//ps("HUH",t);
		if (t < j-i) return (T[t] < S[i+t]) ^ flip;
		t = L.getLCP(sz(S)+j-i,sz(S));
		if (t < sz(T)-(j-i)) return (T[j-i+t] < T[t]) ^ flip;
		//ps("HUH");
		t = L.getLCP(i,sz(S)+sz(T)-(j-i));
		if (t < j-i) return (S[i+t] < T[sz(T)-(j-i)+t]) ^ flip;
	}
	// ps("HA");
	return !flip;
}
 
int q,ans[100005];
 
void init() {
    setIO(); re(S,T,q); n = sz(S);
    L.init(S+T);
    //ps(cmp(4,6)); exit(0);
    vi v; F0R(i,sz(S)+1) v.pb(i);
    sort(all(v),cmp);
    rr.rsz(sz(v));
    F0R(i,sz(v)) rr[v[i]] = i;
    R.init(rr);
    //ps(cmp(4,6),cmp(6,4));
}
 
int k,l,r,x,y,w[100005],W[100005];
 
int brute() {
	int res = -1;
	for (int i = 0; i <= sz(S); i += k) {
		int ll = max(l,i+x), rr = min(r,i+y);
		if (ll <= rr) {
			int t = R.index(ll,rr);
			if (res == -1) res = t;
			else res = R.comb(res,t);
		}
	}
	return res;
}
 
vector<array<int,5>> Q[100005];
 
void solve() {
	if (17*n+(ll)k*sz(Q[k]) < (ll)sz(S)/k*sz(Q[k])) { // 
		rr2.clear();
		F0R(i,k) for (int j = i; j <= sz(S); j += k) {
			W[sz(rr2)] = j, w[j] = sz(rr2);
			rr2.pb(rr[j]);
		}
		R2.init(rr2);
		trav(t,Q[k]) {
			tie(l,r,x,y) = {t[0],t[1],t[2],t[3]};
			int res = -1;
			FOR(z,x,y+1) {
				// k*?+z <= r
				int L = (l-z+k-1)/k, R = r-z >= 0 ? (r-z)/k : -1;
				if (L > R) continue;
				L = L*k+z, R = R*k+z;
				assert(w[L] <= w[R]);
				// ps("WUT",L,R,w[L],w[R]);
				int RES = R2.index(w[L],w[R]);
				if (res == -1) res = RES;
				else res = R2.comb(res,RES);
			}
			ans[t[4]] = (res == -1) ? res : W[res];
			// ps("HUH",t[4],res);
		}
	} else {
		trav(t,Q[k]) {
			tie(l,r,x,y) = {t[0],t[1],t[2],t[3]};
			ans[t[4]] = brute();
		}
	}
}
 
int main() {
	init();
    // ps(v); exit(0);
    F0R(i,q) {
    	array<int,5> a;
    	int k;
    	re(a[0],a[1],k,a[2],a[3]);
    	a[4] = i;
    	Q[k].pb(a);
    }
    FOR(i,1,n+1) {
    	k = i;
    	solve();
    }
    F0R(i,q) pr(ans[i],' ');
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/