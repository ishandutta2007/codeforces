#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define rsz resize
#define ins insert 

#define mp make_pair
#define pb push_back
#define eb emplace_back 
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 2e5+5;
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }

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
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
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
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

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
   
	friend bool operator==(const modular& a, const modular& b) { 
		return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { 
		return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { 
		return a.val < b.val; }

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { 
		if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { 
		if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; 
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		assert(a != 0); return pow(a,MOD-2); 
	}
	modular& operator/=(const modular& m) { 
		return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { 
		return a += b; }
	friend modular operator-(modular a, const modular& b) { 
		return a -= b; }
	friend modular operator*(modular a, const modular& b) { 
		return a *= b; }
	
	friend modular operator/(modular a, const modular& b) { 
		return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

namespace factorBasic {
	template<class T> vector<pair<T,int>> factor(T x) { // x <= 10^{14} is fine
		vector<pair<T,int>> pri;
		for (T i = 2; i*i <= x; ++i) if (x % i == 0) {
			int t = 0;
			while (x % i == 0) x /= i, t ++;
			pri.pb({i,t});
		}
		if (x > 1) pri.pb({x,1});
		return pri;
	}
	/* Note:
	 * number of operations needed s.t.
	 *				  phi(phi(...phi(n)...))=1
	 * is O(log n).
	 * Euler's theorem: a^{\phi(p)}\equiv 1 (mod p), gcd(a,p)=1
	 */
	ll phi(ll x) {
		trav(a,factor(x)) x -= x/a.f;
		return x;
	}
	template<class T> void tour(vector<pair<T,int>>& v, vector<T>& V, int ind, T cur) {
		if (ind == sz(v)) V.pb(cur);
		else {
			T mul = 1;
			F0R(i,v[ind].s+1) {
				tour(v,V,ind+1,cur*mul);
				mul *= v[ind].f;
			}
		}
	}
	template<class T> vector<T> getDivi(T x) {
		auto v = factor(x);
		vector<T> V; tour(v,V,0,(T)1); sort(all(V));
		return V;
	}
}

using namespace factorBasic;

int n;
vi a;
ll sum,ans;

ll cost(const vpi& a, ll b) {
	ll tmp = 0;
	trav(t,a) tmp += (ll)abs(t.s-b)*t.f;
	return tmp;
}

void test(ll x) {
	vi A;
	trav(t,a) {
		int T = t%x;
		while (T < x && T+x <= t) T += x;
		A.pb(T);
	}
	//ps("HA",x);
	while (sz(A) && A.back() == 0) A.pop_back();
	ll tmp = 0;
	int cnt = 0;
	for (int i = 0; i < sz(A); ) {
		ll csum = 0, tot = 0; int med = -1;
		while (i < sz(A) && tot < x) {
			ll dif = min((ll)A[i],x-tot);
			tot += dif; A[i] -= dif; csum += (ll)dif*i;
			// ps("HA",sum,dif);
			if (med == -1 && 2*tot >= x) {
				med = i;
				//ps("HA",csum,tot*med);
				tmp -= csum; tmp += tot*med;
				//ps("OH",tmp);
			} else if (med != -1) tmp += dif*(i-med);
			if (A[i] == 0) i ++;
		}
		//ps("??",tot,tmp,med);
		if (!tot) break;
		if (tot != x) exit(5);
	}
	//ps("??",cnt);
	//ps("??",x,tmp);
	ckmin(ans,tmp);
	// exit(0);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); 
	re(n); a.rsz(n); 
	// F0R(i,n) a[i] = rand()%1000000+1;
	re(a);
	trav(t,a) sum += t;
	auto z = factor(sum);
	ans = LLONG_MAX;
	trav(t,z) test(t.f);
	if (ans == LLONG_MAX) ps(-1);
	else ps(ans);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/