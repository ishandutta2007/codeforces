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

int k,R,g[2][31];
pi pos;
str ans;

void prin() {
	F0R(i,2) {
		F0R(j,R) pr(g[i][j],' ');
		ps();
	}
	ps("-------");
}

void upMov() {
	assert(pos.f == 1 && pos.s%k == 0);
	swap(g[pos.f][pos.s],g[pos.f-1][pos.s]);
	pos.f --;
}
void up() {
	upMov();
	ans += 'u';
}

void downMov() {
	assert(pos.f == 0 && pos.s%k == 0);
	swap(g[pos.f][pos.s],g[pos.f+1][pos.s]);
	pos.f ++;
}
void down() {
	downMov();
	ans += 'd';
}

void leftMov() {
	assert(pos.s);
	swap(g[pos.f][pos.s],g[pos.f][pos.s-1]);
	pos.s --;
}
void left() {
	leftMov();
	ans += 'l';
}

void rightMov() {
	assert(pos.s < R-1);
	swap(g[pos.f][pos.s],g[pos.f][pos.s+1]);
	pos.s ++;
}
void right() {
	rightMov();
	ans += 'r';
}

void gor() {
	if (pos == mp(1,0)) up();
	else if (pos == mp(0,R-1)) down();
	else if (pos.f == 1) left();
	else right();
}


void ROT() {
	ans += 'B';
	F0R(i,k) leftMov();
	upMov();
	F0R(i,R-1) rightMov();
	downMov();
	F0R(i,k) leftMov();
}
void ROT2() {
	ans += 'C';
	F0R(i,k) leftMov();
	downMov();
	F0R(i,R-1) rightMov();
	upMov();
	F0R(i,k) leftMov();
}

void RIGHT(int x) {
	while (pos != mp(1,k)) gor();
	while (g[0][k] != x) ROT();
	up();
}

void LEFT(int x) {
	while (pos != mp(0,k)) gor();
	while (g[1][k] != x) ROT2();
	down();
}

void rmap() {
	// R+1 to 2R-1
	F0R(i,2) F0R(j,R) if (g[i][j] > R) g[i][j] = 3*R-g[i][j];
}

str tmp, rot, rot2; 

bool done() {
	F0R(i,R) if (g[0][i] != i+1) return 0;
	int cnt = R;
	R0F(i,R) if (i != k) {
		cnt ++;
		if (g[1][i] != cnt) return 0;
	}
	return 1;
}

void solve() {
	re(k); R = 2*k+1; ans = tmp = rot = rot2 = "";
	int cnt = 0;
	F0R(j,R) g[0][j] = ++cnt;
	R0F(j,R) if (j != k) g[1][j] = ++cnt;
	pos = {1,k};
	RIGHT(1);
	RIGHT(1);
	RIGHT(2);
	LEFT(3);
	LEFT(2);
	LEFT(3);
	while (g[0][0] != 2 || pos != mp(1,k)) gor();
	swap(tmp,ans);
	
	F0R(i,2) {
		F0R(j,R) {
			str s; re(s);
			if (s == "E") {
				g[i][j] = 0;
				pos = {i,j};
			} else g[i][j] = stoi(s);
		}
	}
	while (pos.s < R-1) right();
	if (pos.f == 0) down();
	int inv = 0;
	F0R(i,2*R-1) FOR(j,i+1,2*R-1) {
		if (g[i/R][i%R] > g[j/R][j%R]) inv ++;
	}
	if (inv&1) {
		ps("SURGERY FAILED");
		return;
	}
	while (pos.s > k) left();
	rmap();
	F0R(i,k) rot += 'l';
	rot += 'u';
	F0R(i,R-1) rot += 'r';
	rot += 'd';
	F0R(i,k) rot += 'l';
	rot2 = rot; 
	trav(t,rot2) {
		if (t == 'u') t = 'd';
		else if (t == 'd') t = 'u';
	}
	while (!done()) {
		ROT();
		if (g[0][0] != 2*R-1 && g[0][1] != 2*R-1 && g[0][2] != 2*R-1) {
			while (g[0][0] > min(g[0][1],g[0][2])) {
				swap(g[0][0],g[0][1]);
				swap(g[0][1],g[0][2]);
				ans += 'A';
			}
		} 
	}
	rmap();
	while (pos.s < R-1) right();
	// ps(sz(tmp));
	// prin();
	ps("SURGERY COMPLETE");
	ps(ans);
	ps("A",tmp);
	ps("B",rot);
	ps("C",rot2);
	// prin();
	ps("DONE");
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int t; re(t); F0R(i,t) solve();
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/