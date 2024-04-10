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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const int MX = 1<<18;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...); 
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
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
	
	// friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
	friend void pr(const modular& a) { pr(a.val); }
	friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
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

struct Info {
	int gapMn, gapLst, mx;
	ll sum = 0;
	int lmx = -MOD, rmx = -MOD; // = -MOD
	Info() {
		mx = -MOD;
	}
	Info(int GapLst, int Mx) {
		gapMn = gapLst = GapLst;
		mx = Mx;
	}
	void add(int lazy) {
		gapMn += lazy;
		gapLst += lazy;
	}
};

void pr(const Info& x) {
	ps("Info",x.gapMn,x.gapLst,x.mx,x.sum,x.lmx,x.rmx);
}

Info operator+(Info l, Info r) {
	assert(l.mx != -MOD && r.mx != -MOD);
	if (l.gapMn < r.gapMn) r.lmx = -MOD, r.rmx = -MOD, r.sum = 0;
	if (l.gapMn > r.gapMn) l.lmx = -MOD, l.rmx = -MOD, l.sum = 0;

	Info x;
	x.gapMn = min(l.gapMn,r.gapMn); 
	x.gapLst = r.gapLst;
	x.mx = max(l.mx,r.mx);
	x.sum = l.sum+r.sum;

	if (x.gapMn == l.gapLst) { // separated
		if (l.lmx == -MOD) {
			x.lmx = l.mx;
		} else {
			x.lmx = l.lmx;
			x.sum += l.rmx;
		}
		if (r.rmx == -MOD) {
			x.rmx = r.mx;
		} else {
			x.rmx = r.rmx;
			x.sum += r.lmx;
		}
	} else { // max across two
		if (l.lmx != -MOD && r.rmx != -MOD) {
			x.lmx = l.lmx, x.rmx = r.rmx;
			x.sum += max(l.rmx,r.lmx);
		} else if (l.lmx == -MOD && r.rmx == -MOD) {
			x.lmx = x.rmx = -MOD;
		} else if (l.lmx == -MOD) {
			x.lmx = max(l.mx,r.lmx);
			x.rmx = r.rmx;
		} else {
			x.lmx = l.lmx;
			x.rmx = max(l.rmx,r.mx);
		}
	}
	return x;
}

template<int SZ> struct LazySegTree {
	Info seg[2*SZ];
    int lazy[2*SZ]; // set SZ to a power of 2
    
    ll query() {
    	if (seg[1].lmx == -MOD) return seg[1].mx;
    	return seg[1].sum+seg[1].lmx+seg[1].rmx;
    }

    void push(int ind, int L, int R) {
    	seg[ind].add(lazy[ind]);
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
    	seg[ind] = seg[2*ind]+seg[2*ind+1];
    }
    
    void build(int ind, int L, int R) {
    	if (L == R) { seg[ind] = Info(0,0); return; }
    	int M = (L+R)/2;
    	build(2*ind,L,M); build(2*ind+1,M+1,R);
    	pull(ind);
    }
    
    void updPos(int pos, int val, int ind, int L, int R) {
    	// ps("updPos",pos,val,ind,L,R);
        push(ind,L,R);
        if (pos < L || R < pos) return;
        if (L == pos && R == pos) {
        	seg[ind] = Info(seg[ind].gapLst,val);
        	return;
        }

        int M = (L+R)/2;
        updPos(pos,val,2*ind,L,M); updPos(pos,val,2*ind+1,M+1,R);
        pull(ind);
        // ps("WUT",ind,L,R,seg[ind].gapLst,seg[2*ind+1].gapLst);
    }

    void updInt(int lo, int hi, int inc, int ind, int L, int R) {
    	// ps("updInt",lo,hi,inc,ind,L,R);
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        updInt(lo,hi,inc,2*ind,L,M); updInt(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<MX> L;
int n,q;
set<int> pos[MX];

void ins(int i, int t) {
	if (!sz(pos[i])) return;
	if (t == 1) {
		// ps("INS",i);
		L.updInt(*begin(pos[i]),*prev(end(pos[i]))-1,1,1,0,n-1);
		// ps("RESULT1",L.seg[1]);
		L.updPos(*begin(pos[i]),sz(pos[i]),1,0,n-1);
		// ps("RESULT2",L.seg[1]);
	} else {
		L.updInt(*begin(pos[i]),*prev(end(pos[i]))-1,-1,1,0,n-1);
		L.updPos(*begin(pos[i]),0,1,0,n-1);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		setIO("F"); 
	#else 
		setIO();
	#endif
	re(n,q);
	vi a(n); re(a);
	F0R(i,n) pos[a[i]].insert(i);
	L.build(1,0,n-1);
	FOR(i,1,MX) ins(i,1);
	// ps(L.seg[1]);

	ps(n-L.query());
	F0R(i,q) {
		int p,x; re(p,x); p--;
		if (a[p] != x) {
			int y = a[p];
			ins(y,-1); ins(x,-1);
			pos[y].erase(p); a[p] = x; pos[x].insert(p);
			ins(y,1); ins(x,1);
		}
		ps(n-L.query());
	}
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/