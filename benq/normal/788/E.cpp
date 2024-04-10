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
const int MX = 100005;
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


struct range {
	int SZ = 1;
	vmi seg1, seg2, lazy;
	vi cnt;
	void init(int x) {
		while (SZ < x) SZ *= 2;
		seg1.rsz(2*SZ); seg2.rsz(2*SZ);
		lazy.rsz(2*SZ); cnt.rsz(2*SZ);
	}
	void upd1(int x, mi y, int ind = 1, int l = 0, int r = -1) {
		if (r == -1) r = SZ-1;
		if (l == r) { seg1[ind] += y; return; }
		int m = (l+r)/2;
		if (x <= m) upd1(x,y,2*ind,l,m); 
		else upd1(x,y,2*ind+1,m+1,r); 
		seg1[ind] = seg1[2*ind]+seg1[2*ind+1];
	}
	mi query1(int lo, int hi, int ind = 1, int l = 0, int r = -1) {
		if (r == -1) r = SZ-1;
		if (r < lo || hi < l) return 0;
		if (lo <= l && r <= hi) return seg1[ind];
		int m = (l+r)/2;
		return query1(lo,hi,2*ind,l,m)+query1(lo,hi,2*ind+1,m+1,r);
	}
	void push(int ind, int l, int r) {
		if (lazy[ind] != 0) {
			seg2[ind] += cnt[ind]*lazy[ind];
			if (l != r) {
				lazy[2*ind] += lazy[ind];
				lazy[2*ind+1] += lazy[ind];
			}
			lazy[ind] = 0;
		}
	}
	void flip(int x, mi y, int ind = 1, int l = 0, int r = -1) {
		if (r == -1) r = SZ-1;
		push(ind,l,r);
		if (r < x || x < l) return;
		if (l == r) { cnt[ind] ^= 1; seg2[ind] += y; return; }
		int m = (l+r)/2;
		flip(x,y,2*ind,l,m); 
		flip(x,y,2*ind+1,m+1,r); 
		cnt[ind] = cnt[2*ind]+cnt[2*ind+1];
		seg2[ind] = seg2[2*ind]+seg2[2*ind+1];
	}
	void upd2(int lo, int hi, mi y, int ind = 1, int l = 0, int r = -1) {
		if (r == -1) r = SZ-1;
		push(ind,l,r);
		if (r < lo || hi < l) return;
		if (lo <= l && r <= hi) { lazy[ind] += y; push(ind,l,r); return; }
		int m = (l+r)/2;
		upd2(lo,hi,y,2*ind,l,m); upd2(lo,hi,y,2*ind+1,m+1,r); 
		seg2[ind] = seg2[2*ind]+seg2[2*ind+1];
	}
	mi query2(int lo, int hi, int ind = 1, int l = 0, int r = -1) {
		if (r == -1) r = SZ-1;
		push(ind,l,r);
		if (r < lo || hi < l) return 0;
		if (lo <= l && r <= hi) return seg2[ind];
		int m = (l+r)/2;
		return query2(lo,hi,2*ind,l,m)+query2(lo,hi,2*ind+1,m+1,r);
	}
};

Tree<pi> T;
int N,M,bef[MX],aft[MX];
int L[MX], MM[MX], R[MX];
vi pos[MX];
range BEF, AFT;
vi A;
map<int,int> m;
mi ans;

// segtree 1: add to index 
// segtree 2: add to every active in range, query sum

void ins(int x, int s = 1) {
	int l = L[x];
	int m = MM[x];
	int r = R[x];

	mi a = BEF.query1(l,m-1), b = AFT.query1(m+1,r); ans += s*a*b;
	BEF.upd1(m,s*bef[x]); AFT.upd1(m,s*aft[x]); 
	BEF.flip(m,s*a), AFT.flip(m,s*b);
	BEF.upd2(m+1,r,s*bef[x]); AFT.upd2(l,m-1,s*aft[x]);
	ans += s*bef[x]*AFT.query2(m+1,r);
	ans += s*BEF.query2(l,m-1)*aft[x];
}

void init() {
    #ifndef ONLINE_JUDGE
    setIO("A"); 
    #endif
	re(N); A.rsz(N); re(A,M); 
	trav(t,A) m[t] = 0;
	int co = 0; trav(t,m) t.s = ++co;
	trav(t,A) t = m[t];
	F0R(i,N) {
		pi p = {A[i],i};
		bef[i] = T.order_of_key(p);
		T.insert(p);
	}
	T.clear();
	F0Rd(i,N) {
		pi p = {A[i],-i};
		aft[i] = T.order_of_key(p);
		T.insert(p);
	}
	F0R(i,N) pos[A[i]].pb(i);
	int cur = 0;
	FOR(i,1,sz(m)+1) {
		int st = cur;
		F0R(j,sz(pos[i])) {
			int x = pos[i][j];
			L[x] = st;
			MM[x] = cur++;
			R[x] = st+sz(pos[i])-1;
		}
	}
	BEF.init(N);
	AFT.init(N);
	F0R(i,N) {
		ins(i);
	}
}

int main() {
	init();
	F0R(i,M) {
		int t,x; re(t,x); x--;
		if (t == 1) ins(x,-1);
		else ins(x);
		ps(ans);
	}
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/