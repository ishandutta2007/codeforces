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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	pair<int,pi> pre[2], suf[2], ans[2], sum;
	node() { ans[0].f = MOD; }
	// ans[0] stores max when positive
	// ans[1] stores max when negative
	node(int pos, int val) { 
		sum = {val,{pos,pos}};
		if (val >= 0) {
			pre[0] = suf[0] = {val,{pos,pos}};
			pre[1] = {0,{pos,pos-1}}; suf[1] = {0,{pos+1,pos}}; 
		} else {
			pre[1] = suf[1] = {-val,{pos,pos}};
			pre[0] = {0,{pos,pos-1}}; suf[0] = {0,{pos+1,pos}}; 
		}
		F0R(i,2) ans[i] = pre[i];
	}
	void flip() {
		swap(pre[0],pre[1]); //F0R(i,2) pre[i].f *= -1;
		swap(suf[0],suf[1]); //F0R(i,2) suf[i].f *= -1;
		swap(ans[0],ans[1]); //F0R(i,2) ans[i].f *= -1;
		sum.f *= -1;
	}
};

pair<int,pi> sgn(pair<int,pi> a, int b) {
	if (b) a.f *= -1;
	return a;
}

pair<int,pi> comb(pair<int,pi> a, pair<int,pi> b) {
	assert(a.s.s+1 == b.s.f);
	return {a.f+b.f,{a.s.f,b.s.s}};
} 

node operator+(const node& l, const node& r) {
	// ps("HUH ADD");
	if (l.ans[0].f == MOD) return r;
	if (r.ans[0].f == MOD) return l;
	node z; z.sum = comb(l.sum,r.sum);
	F0R(i,2) z.pre[i] = max(l.pre[i],comb(sgn(l.sum,i),r.pre[i]));
	F0R(i,2) z.suf[i] = max(r.suf[i],comb(l.suf[i],sgn(r.sum,i)));
	F0R(i,2) {
		z.ans[i] = max(l.ans[i],r.ans[i]);
		ckmax(z.ans[i],comb(l.suf[i],r.pre[i]));
	}
	return z; // exit(0);
}

template<int SZ> struct LazySegTree {
	node seg[2*SZ];
    bool lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
    	F0R(i,SZ) seg[SZ+i] = node(i,0);
        FORd(i,1,SZ) pull(i);
    }
    void push(int ind, int L, int R) {
    	if (!lazy[ind]) return;
    	seg[ind].flip();
        if (L != R) lazy[2*ind] ^= lazy[ind], lazy[2*ind+1] ^= lazy[ind];
        lazy[ind] = 0;
    }
    void pull(int ind) {
        seg[ind] = seg[2*ind]+seg[2*ind+1];
    }
    
    node maxSum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return node();
        if (lo <= L && R <= hi) return seg[ind];
        
        int M = (L+R)/2;
        return maxSum(lo,hi,2*ind,L,M)+maxSum(lo,hi,2*ind+1,M+1,R);
    }

    void flip(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = 1;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        flip(lo,hi,2*ind,L,M); flip(lo,hi,2*ind+1,M+1,R);
        pull(ind);
    }
    
    void set(int pos, int val, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (R < pos || pos < L) return;
        if (pos <= L && R <= pos) {
        	seg[ind] = node(pos,val);
            return;
        }
        int M = (L+R)/2;
        set(pos,val,2*ind,L,M); set(pos,val,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<1<<17> S;

int n,m;
vi a;

int solve(int l, int r, int k) {
	int ans = 0;
	vpi v;
	// ps("SOLVE"); exit(0);
	// exit(0);
	F0R(i,k) {
		auto z = S.maxSum(l,r);
		pair<int,pi> p = z.ans[0];
		// ps("HUH",l,r,z.ans[0],z.ans[1],i);
		ans += p.f;
		S.flip(p.s.f,p.s.s); v.pb(p.s);
	}
	trav(t,v) S.flip(t.f,t.s);
	return ans;
}

int main() {
    setIO(); re(n); a.rsz(n); re(a,m);
    F0R(i,n) S.set(i,a[i]);
    // ps(S.seg[1].ans[0]);
    // exit(0);
    F0R(i,m) {
    	int t; re(t);
    	if (t == 0) {
    		int ind,val; re(ind,val);
    		S.set(ind-1,val);
    	} else {
    		int l,r,k; re(l,r,k);
    		ps(solve(l-1,r-1,k));
    	}
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/