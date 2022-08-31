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

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

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

typedef decay<decltype(MOD)>::type T;
struct mi {
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	// friend ostream& operator<<(ostream& os, const mi& a) { 
		// return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
   
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(a != 0); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

void bad() {
	ps(-1);
	exit(0);
}

int get(vl v) {
	sort(all(v));
	ll g = 0;
	FOR(i,1,4) g = __gcd(g,v[i]-v[0]);
	return g;
}

int countEven(vl v) {
	int res = 0;
	trav(t,v) res += t%2 == 0;
	return res;
}

vl cur;
vpl mov;

void mir(int x, int y) {
	if (cur[x] == cur[y]) return;
	mov.pb({cur[x],cur[y]});
	cur[x] = 2*cur[y]-cur[x];
}

vl getCur() {
	auto z = cur; sort(all(z));
	return z;
}

ll getDif() {
	auto z = getCur(); return z[3]-z[0];
}

void expand() {
	vpl CUR; F0R(i,4) CUR.pb({cur[i],i});
	sort(all(CUR));
	mir(CUR[2].s,CUR[0].s); mir(CUR[1].s,CUR[3].s);
}

void unexpand() {
	vpl CUR; F0R(i,4) CUR.pb({cur[i],i});
	sort(all(CUR));
	mir(CUR[3].s,CUR[2].s); mir(CUR[0].s,CUR[1].s);
}

pair<vpl,vl> red(vl _cur) {
	cur = _cur; mov.clear();
	while (1) {
		// cnt ++; // if (cnt > 10) exit(0);
		vpl CUR; F0R(i,4) CUR.pb({cur[i],i});
		sort(all(CUR)); ll dif = CUR[3].f-CUR[0].f;
		if (dif <= 1) {
			if (CUR[0].f&1) {
				FOR(i,1,4) if (CUR[i].f > CUR[0].f) {
					mir(CUR[i].s,CUR[0].s);
				}
			}
			break;
		}
		bool ok = 1;
		trav(t,CUR) {
			ok = 1;
			if (4*(t.f-CUR[0].f) < dif) ok = 0;
			if (4*(CUR[3].f-t.f) < dif) ok = 0;
			if (ok) {
				if (CUR[3].f-t.f < t.f-CUR[0].f) {
					trav(z,CUR) if (z.f > t.f) {
						mir(z.s,t.s);
					}
				} else {
					trav(z,CUR) if (z.f < t.f) {
						mir(z.s,t.s);
					}
				}
				break;
			}
		}
		if (ok) continue;
		/*if (!ok) {
			ps("HOW TO REDUCE",cur);
			exit(0);
		}*/
		int d1 = min(CUR[1].f-CUR[0].f,CUR[3].f-CUR[1].f);
		int d2 = min(CUR[2].f-CUR[0].f,CUR[3].f-CUR[2].f);
		if (d1 < d2) {
			if (CUR[2].f-CUR[0].f == d2) {
				assert(CUR[1].f-CUR[0].f == d1);
				mir(CUR[1].s,CUR[0].s);
				mir(CUR[1].s,CUR[2].s);
			} else {
				mir(CUR[1].s,CUR[2].s);
				mir(CUR[1].s,CUR[3].s);
			}
		} else if (d1 > d2) {
			if (CUR[1].f-CUR[0].f == d1) {
				mir(CUR[2].s,CUR[1].s);
				mir(CUR[2].s,CUR[0].s);
			} else {
				mir(CUR[2].s,CUR[3].s);
				mir(CUR[2].s,CUR[1].s);
			}
		} else if (d1 == d2) {
			if (CUR[1].f-CUR[0].f == d1 && CUR[2].f-CUR[0].f == d1) {
				mir(CUR[1].s,CUR[0].s);
				mir(CUR[1].s,CUR[2].s);
			} else if (CUR[3].f-CUR[1].f == d1 && CUR[3].f-CUR[2].f == d1) {
				mir(CUR[1].s,CUR[3].s);
				mir(CUR[1].s,CUR[2].s);
			} else {
				mir(CUR[1].s,CUR[2].s);
				mir(CUR[1].s,CUR[3].s);
			}
		}
		// ps("HUH",cur); // exit(0);
	}
	//ps("COOL",cur);
	//exit(0);
	/*ps("ORI",cur);
	expand(); ps(cur);
	expand(); ps(cur);
	expand(); ps(cur);
	exit(0);*/
	
	ll x = getCur()[0]; 
	int cnt = 0;
	while (1) {
		cnt ++; if (cnt > 1000) break;
		// ps("ORI",cur);
		if (!x) break;
		while (getDif() < abs(x)/2) expand();
		if (getDif() > abs(x)/2) unexpand();
		// ps("EXPANDED",cur); exit(0);
		while (x >= 2*getDif()) {
			{
				vpl CUR; F0R(i,4) CUR.pb({cur[i],i}); sort(all(CUR));
				FOR(i,1,4) mir(CUR[i].s,CUR[0].s);
			}
			{
				vpl CUR; F0R(i,4) CUR.pb({cur[i],i}); sort(all(CUR));
				FOR(i,1,4) mir(CUR[i].s,CUR[0].s);
			}
			x -= 2*getDif();
		}
		while (x <= -2*getDif()) {
			{
				vpl CUR; F0R(i,4) CUR.pb({cur[i],i}); sort(all(CUR));
				F0R(i,3) mir(CUR[i].s,CUR[3].s);
			}
			{
				vpl CUR; F0R(i,4) CUR.pb({cur[i],i}); sort(all(CUR));
				F0R(i,3) mir(CUR[i].s,CUR[3].s);
			}
			x += 2*getDif();
		}
		// ps("INTERMEDIATE",cur); exit(0);
		//ps("??",cur);
		//exit(0);
	}
	// exit(0);
	while (getDif() > 1) unexpand();
	trav(t,cur) assert(0 <= t && t <= 1);
	// ps("RESULT",cur); exit(0);
	return {mov,cur};
	// ps("HUH",cur); exit(0);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); 
	vl a(4), b(4);
	re(a,b);
	if (a == b) {
		ps(0);
		exit(0);
	}
	int A = get(a), B = get(b);
	if (!A || !B || A != B) bad();
	if ((a[0]-b[0])%A != 0) bad();
	int dif = a[0]%A;
	trav(t,a) t = (t-dif)/A;
	trav(t,b) t = (t-dif)/A;
	auto aa = a;
	if (countEven(a) != countEven(b)) bad();
	auto y = red(b);
	auto x = red(a); 
	/*F0R(i,4) if (y.s[i] != x.s[i]) {
		FOR(j,i+1,4) if (y.s[j] == x.s[i]) {
			swap(y.s[i],y.s[j]);
			trav(t,y.f) {
				if (t.f == i+1) t.f = j+1;
				else if (t.f == j+1) t.f = i+1;
				if (t.s == i+1) t.s = j+1;
				else if (t.s == j+1) t.s = i+1;
			}
		}
	}
	x.f.insert(end(x.f),all(y.f));
	ps(sz(x.f));
	trav(t,x.f) {
		aa[t.f-1] = 2*aa[t.s-1]-aa[t.f-1];
		ps(t.f,t.s);
	}*/
	reverse(all(y.f));
	trav(t,y.f) x.f.pb({2*t.s-t.f,t.s});
	ps(sz(x.f));
	multiset<ll> m; trav(t,aa) m.insert(t);
	trav(t,x.f) {
		ps(t.f*A+dif,t.s*A+dif);
		if (!(m.count(t.f) && m.count(t.s) && t.f != t.s)) {
			ps("AH",m,t); exit(0);
		}
		m.erase(m.find(t.f));
		m.insert(2*t.s-t.f);
	}
	trav(t,b) {
		assert(m.find(t) != end(m));
		m.erase(m.find(t));
	}
	// ps("HUH",m);
	// ps("??",aa); exit(0);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/