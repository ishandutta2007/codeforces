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

int k,n,avg;
vi a;
vi cum = {0};
pi ans = {0,0};
vector<pair<int,vi>> meet;
map<int,vi> oc;
vi nex[MX];

int getNum(int t) {
	int rem = n%(k-1);
	int cur = t, res = 0;
	for (int ind = sz(nex[t])-1; ind >= 0; --ind) {
		if (ind < sz(nex[cur]) && nex[cur][ind] <= t+n) {
			res ^= 1<<ind;
			cur = nex[cur][ind];
		}
	}
	if (res >= rem) {
		res -= (res-rem)%(k-1);
		return res;
	} else return -1;
}

void solve(vi v) {
	int s = sz(v);
	FOR(i,s,2*s) v.pb(v[i-s]+n);
	reverse(all(v));
	map<int,int> stor;
	// ps("HA",v);
	trav(t,v) {
		int r = t%(k-1);
		int R = (r+1)%(k-1);
		nex[t].clear();
		if (stor.count(R)) nex[t].pb(stor[R]);
		else nex[t].pb(MOD);
		while (nex[t].back() != MOD) {
			int s = sz(nex[t])-1;
			if (s < sz(nex[nex[t][s]])) nex[t].pb(nex[nex[t][s]][s]);
			else nex[t].pb(MOD);
		}
		if (t < n) ckmax(ans,{getNum(t),t});
		stor[r] = t;
	}
}

void ok(vi& v, int l, int r, int des) {
	int sum = 0; FOR(i,l,r+1) sum += a[v[i]];
	sum -= des+(r-1-l)*avg;
	assert(sum >= 0);
	meet.eb(); meet.back().f = v[l];
	meet.back().s.pb(des);
	F0R(i,r-1-l) meet.back().s.pb(avg);
	meet.back().s.pb(sum);
	while (sz(meet.back().s) < k) {
		meet.back().s.pb(a[(meet.back().f+sz(meet.back().s))%n]);
	}
	F0R(i,k) a[(meet.back().f+i)%n] = meet.back().s[i];
	// l should have des
	// l+1 to r-1 should have avg
}

void solve(vi& v, int l, int des) {
	if (l == sz(v)-1) {
		if(a[v[l]] != des) {
			ps("HUH",v);
			ps(l,a[v[l]],des);
			exit(0);
		}
		return;
	}
	int r = min(l+k,sz(v))-1;
	int tot = 0; FOR(i,l,r+1) tot += a[v[i]];
	// l+1 to r-1
	int need = (r-l-1)*avg+des;
	if (tot < need) { // need+avg = tot+(?-a[v[r]])
		solve(v,r,avg+need-tot+a[v[r]]);
		ok(v,l,r,des);
	} else {
		ok(v,l,r,des);
		solve(v,r,avg);
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); 
	re(n,k); a.rsz(n); re(a);
	trav(t,a) avg += t;
	assert(avg%n == 0);
	avg /= n;
	trav(t,a) cum.pb(cum.back()+t-avg);
	F0R(i,n) oc[cum[i]].pb(i);
	trav(t,oc) solve(t.s);
	vector<vi> res; res.eb();
	int sum = 0, cur = ans.s;
	F0R(i,n) {
		res.back().pb(cur); sum += a[cur]; cur = (cur+1)%n;
		if (sz(res) < ans.f && sum == avg*(i+1) && (sz(res.back())%(k-1) == 1 || k == 2)) res.eb();
	}
	// ps("HUH",ans,sz(res),res); exit(0);
	if (ans.f) assert(sz(res) == ans.f);
	trav(t,res) solve(t,0,avg);
	// ps(a);
	ps(sz(meet));
	trav(t,meet) {
		pr(t.f);
		trav(z,t.s) pr(' ',z);
		ps();
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/