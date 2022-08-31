#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair 
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
int pc(int x) { return __builtin_popcount(x); } 

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

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; }
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
	
	void ps() { cout << endl; } // print w/ spaces
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
		ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); 
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

int n;
int ans[801];
vi rem[10];
set<int> lst;
// int des[21];

bool query(vi a) {
	pr("? ",sz(a));
	trav(t,a) pr(' ',t);
	ps();
	assert(sz(a) && sz(set<int>(all(a))) == sz(a));
	/*int sum = 0; 
	trav(t,a) {
		assert(1 <= t && t <= n);
		sum += des[t];
	}
	return sum%sz(a) == 0;*/
	bool x; re(x); return x;
}

void fin() {
	pr('!');
	if (ans[1] > n/2) {
		FOR(i,1,n+1) ans[i] = n+1-ans[i];
	}
	FOR(i,1,n+1) pr(' ',ans[i]);
	ps();
	exit(0);
}

vi ad(vi a, int b) {
	trav(t,a) {
		int ind = -1;
		FOR(i,1,n+1) if (ans[i] == t) ind = i;
		assert(ind != -1);
		t = ind;
	}
	a.pb(b); return a;
}

void getRem(vi v) {
	int mod = sz(v)+1;
	int res = 0;
	trav(t,v) res = ((res-t)%mod+mod)%mod;
	assert(lst.count(res)); lst.erase(res);
	FOR(i,1,n+1) if (rem[mod][i] == -1) {
		if (query(ad(v,i))) rem[mod][i] = res;
	}
}

void tri4() {
	rem[4] = vi(n+1,-1);
	FOR(i,1,n+1) if (ans[i] != -1) rem[4][i] = ans[i]%4;
	FOR(i,1,n+1) if (rem[4][i] == -1) {
		if (rem[2][i] == 0) {
			if (query(ad({1,2,3},i))) rem[4][i] = 2;
			else rem[4][i] = 0;
		} else {
			if (query(ad({1,2,4},i))) rem[4][i] = 1;
			else rem[4][i] = 3;
		}
	}
}

void tri8() {
	rem[8] = vi(n+1,-1);
	FOR(i,1,n+1) if (ans[i] != -1) rem[8][i] = ans[i]%8;
	FOR(i,1,n+1) if (rem[8][i] == -1) {
		if (rem[4][i] == 0) {
			vi v = {1,2,3,n-3,n-2,n-1,n};
			if (query(ad(v,i))) rem[8][i] = 0;
			else rem[8][i] = 4;
		} else if (rem[4][i] == 1) {
			vi v = {2,3,4,n-3,n-2,n-1,n};
			if (query(ad(v,i))) rem[8][i] = 5;
			else rem[8][i] = 1;
		} else if (rem[4][i] == 2) {
			vi v = {1,3,4,n-3,n-2,n-1,n};
			if (query(ad(v,i))) rem[8][i] = 6;
			else rem[8][i] = 2;
		} else {
			vi v = {1,2,4,n-3,n-2,n-1,n};
			if (query(ad(v,i))) rem[8][i] = 7;
			else rem[8][i] = 3;
		}
	}
}

int main() {
	re(n);
	/*FOR(i,1,n+1) des[i] = i;
	random_shuffle(des+1,des+n+1); reverse(des+1,des+n+1);
	ps("DES");
	FOR(i,1,n+1) pr(des[i],' ');
	ps();*/
	// INTERACTIVE
	vi en;
	FOR(i,1,n+1) {
		ans[i] = -1;
		vi v; FOR(j,1,n+1) if (j != i) v.pb(j);
		if (query(v)) en.pb(i);
	}
	// ps("AA",en);
	assert(sz(en) == 2);
	//ps("CC");
	rem[2] = vi(n+1,-1);
	rem[2][en.ft] = 1; ans[en.ft] = 1, ans[en.bk] = n;
	//ps("AA");
	FOR(i,1,n+1) if (i != en.ft) {
		if (query({en.ft,i})) rem[2][i] = 1; 
		else rem[2][i] = 0;
	}
	//ps("BB");

	for (int i = 2; i <= 4 && i < n+1-i; ++i) {
		en.clear();
		vi res; FOR(j,1,n+1) if (ans[j] == -1) res.pb(j);
		F0R(a,sz(res)) {
			vi tmp;
			F0R(b,sz(res)) if (b != a) tmp.pb(res[b]);
			if (query(tmp)) en.pb(res[a]);
		}
		assert(sz(en) == 2);
		if (rem[2][en.ft] != (i%2)) swap(en[0],en[1]);
		ans[en.ft] = i, ans[en.bk] = n+1-i;
	}

	if (n <= 8) fin();

	rem[3] = vi(n+1,-1); lst = {0,1,2};
	FOR(i,1,n+1) if (ans[i] != -1) rem[3][i] = ans[i]%3;
	getRem({1,2}); getRem({1,3});
	assert(sz(lst) == 1);
	FOR(i,1,n+1) if (rem[3][i] == -1) rem[3][i] = *begin(lst);

	tri4();

	rem[5] = vi(n+1,-1); lst = {0,1,2,3,4};
	FOR(i,1,n+1) if (ans[i] != -1) rem[5][i] = ans[i]%5;
	getRem({n,n-1,n-2,1});
	getRem({n,n-1,n-2,2});
	getRem({n,n-1,n-2,3});
	getRem({n,n-1,n-2,4});
	assert(sz(lst) == 1);
	FOR(i,1,n+1) if (rem[5][i] == -1) rem[5][i] = *begin(lst);

	rem[7] = vi(n+1,-1); lst = {0,1,2,3,4,5,6};
	FOR(i,1,n+1) if (ans[i] != -1) rem[7][i] = ans[i]%7;
	getRem({1,2,3,n-2,n-1,n});
	getRem({1,2,3,n-3,n-1,n}); // -1
	getRem({1,2,3,n-3,n-2,n}); // -2
	getRem({1,2,3,n-3,n-2,n-1}); // -3
	getRem({1,2,4,n-2,n-1,n}); // +1
	getRem({1,4,3,n-2,n-1,n}); // +2
	assert(sz(lst) == 1);
	FOR(i,1,n+1) if (rem[7][i] == -1) rem[7][i] = *begin(lst);

	tri8();
	/*FOR(i,1,n+1) {
		ps("WUT",i,des[i],ans[i]);
		ps(rem[2][i],rem[3][i],rem[4][i],rem[5][i],rem[7][i],rem[8][i]);
	}*/
	// exit(0);

	FOR(i,1,n+1) if (ans[i] == -1) {
		vi v = {3,5,7,8};
		FOR(j,1,n+1) {
			bool bad = 0;
			trav(t,v) if (rem[t][i] != j%t) bad = 1;
			if (bad) continue;
			ans[i] = j;
			break;
		}
		assert(ans[i] != -1);
		/*if (ans[i] == -1) {
			ps("AH",i,des[i]);
			ps(rem[3][i],rem[5][i],rem[7][i],rem[4][i],rem[8][i]);
			exit(0);
		}*/
	}
	fin();
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
*/