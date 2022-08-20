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
const int MX = 1<<17;
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

int n;

struct {
	int mxT[2*MX], sumT[2*MX], mxR[2*MX];
	int actL[2*MX];
	void recalc(int ind, int L, int R) {
		mxT[ind] = max(mxT[2*ind],mxT[2*ind+1]);
		sumT[ind] = sumT[2*ind]+sumT[2*ind+1];
		mxR[ind] = max(mxR[2*ind]+sumT[2*ind+1],mxR[2*ind+1]);
	}
	void updL(int pos, int val, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += n;
		if (L == R) { 
			actL[ind] = val; 
			mxR[ind] = mxT[ind]+actL[ind];
			return; 
		}
		int M = (L+R)/2;
		if (pos <= M) updL(pos,val,2*ind,L,M);
		else updL(pos,val,2*ind+1,M+1,R);
		recalc(ind,L,R);
	}
	void updT(int pos, int val, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += n;
		if (L == R) {
			mxT[ind] = sumT[ind] = val;
			mxR[ind] = mxT[ind]+actL[ind];
			return;
		}
		int M = (L+R)/2;
		if (pos <= M) updT(pos,val,2*ind,L,M);
		else updT(pos,val,2*ind+1,M+1,R);
		recalc(ind,L,R);
	}
	int maxT(int pos, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += n;
		if (R < pos) return 0;
		if (pos <= L) return mxT[ind];
		int M = (L+R)/2;
		return max(maxT(pos,2*ind,L,M),maxT(pos,2*ind+1,M+1,R));
	}
	int maxE(int pos, int ind = 1, int L = 0, int R = -1, int after = 0) {
		if (R == -1) R += n;
		if (R < pos) return 0;
		if (pos <= L) return mxR[ind]+after;
		int M = (L+R)/2;
		return max(maxE(pos,2*ind,L,M,after+sumT[2*ind+1]),maxE(pos,2*ind+1,M+1,R,after));
	}
	int getT(int pos, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += n;
		if (L == R) return sumT[L];
		int M = (L+R)/2;
		if (pos <= M) return getT(pos,2*ind,L,M);
		return getT(pos,2*ind+1,M+1,R);
	}
} S;

int L[MX], R[MX], T[MX];
int ans = 0;

pi data(int mid) {
	return {S.maxT(mid), ans-S.maxE(mid+1)};
}

int eval(int mid) {
	auto p = data(mid);
	return min(p.f,p.s);
}

void del(int x) {
	S.updL(x,0);
	S.updT(x,0);
}

pi atLeast(int ind, int mn) { // T value is >= mn
	int lo = -1, hi = ind;
	while (lo < hi) {
		int mid = (lo+hi+1)/2;
		if (S.maxT(mid) >= mn) lo = mid;
		else hi = mid-1;
	}
	if (lo == ind || lo == -1) return {-MOD,-MOD};
	return {eval(lo),lo};
}

int main() {
	// setIO("Z2"); 
	setIO();
	re(n); // 0 0 1 0 -1
	// 0 0 0 2 -1 -1 0 0 0 0 7 0 12
	F0R(i,n) {
		// ps("WUT",i,ans);
		re(L[i],R[i],T[i]); R[i] ++; S.updL(i,L[i]);
		if (max(ans,L[i])+T[i] <= R[i]) {
			ans = max(ans,L[i])+T[i];
			S.updT(i,T[i]);
			pr(0,' '); 
			continue;
		}
		int lo = 0, hi = i;
		while (lo < hi) {
			int mid = (lo+hi)/2;
			pi p = data(mid);
			if (p.f > p.s) lo = mid+1;
			else hi = mid;
		}
		pi p = data(lo);
		/*if (i == 3) {
			ps();
			ps(lo,hi,p,data(0),data(1));
			ps(S.maxE(0),S.maxE(1));
			ps(S.getT(1),S.getT(2));
			ps("HUH",p); exit(0);
		}*/
		pi a = max(atLeast(i,p.f),atLeast(i,p.f+1));
		if (a.f <= 0 || ans-a.f+T[i] > R[i] || ans-a.f+T[i] >= ans) {
			S.updL(i,0); pr(-1,' '); 
			continue;
		}
		// ps("HA",i,a,ans,S.maxE(1),data(0));
		del(a.s); S.updT(i,T[i]); 
		// ps("HUH",ans,a.f,ans-a.f+T[i]);
		ans = ans-a.f+T[i];
		pr(a.s+1,' ');
	}
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/