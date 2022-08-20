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
		ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

typedef array<int,2> T; // pick bases not too close to ends
uniform_int_distribution<int> MULT_DIST(0.1*MOD,0.9*MOD); 
const T base = {MULT_DIST(rng),MULT_DIST(rng)};

T operator+(const T& l, const T& r) { T x; 
	F0R(i,2) x[i] = (l[i]+r[i])%MOD; return x; }
T operator-(const T& l, const T& r) { T x; 
	F0R(i,2) x[i] = (l[i]-r[i]+MOD)%MOD; return x; }
T operator*(const T& l, const T& r) { T x; 
	F0R(i,2) x[i] = (ll)l[i]*r[i]%MOD; return x; }

struct HashRange {
	str S; 
	vector<T> pows, cum;
	void init(str _S) {
		S = _S; pows.rsz(sz(S)), cum.rsz(sz(S)+1);
		pows[0] = {1,1}; FOR(i,1,sz(S)) pows[i] = pows[i-1]*base;
		F0R(i,sz(S)) {
			int c = S[i]-'a'+1;
			cum[i+1] = base*cum[i]+T{c,c};
		}
	}
	T hash(int l, int r) { return cum[r+1]-pows[r+1-l]*cum[l]; }
	int lcp(HashRange& b) {
		int lo = 0, hi = min(sz(S),sz(b.S));
		while (lo < hi) {
			int mid = (lo+hi+1)/2;
			if (cum[mid] == b.cum[mid]) lo = mid;
			else hi = mid-1;
		}
		return lo;
	}
};

template<int SZ> struct PalTree {
	static const int sigma = 26;
	int s[SZ], len[SZ], link[SZ], to[SZ][sigma], oc[SZ], lst[SZ];
	int slink[SZ], diff[SZ];
	array<int,2> ans[SZ], seriesAns[SZ];
	int n = 0, last = 0, sz;
	PalTree() { 
		s[n++] = -1; link[0] = 1; len[1] = -1; sz = 2; 
		ans[0] = {0,MOD};
	}
	int getLink(int v) {
		while (s[n-len[v]-2] != s[n-1]) v = link[v];
		return v;
	}
	/*void updAns() { // serial path has O(log n) vertices
		ans[n-1] = {MOD,MOD};
		for (int v = last; len[v] > 0; v = slink[v]) {
			seriesAns[v] = ans[n-1-(len[slink[v]]+diff[v])];
			if (diff[v] == diff[link[v]]) 
				F0R(i,2) ckmin(seriesAns[v][i],seriesAns[link[v]][i]);
			// previous oc of link[v] = start of last oc of v
			F0R(i,2) ckmin(ans[n-1][i],seriesAns[v][i^1]+1);
		}
	}*/
	void addChar(int c) {
		s[n++] = c;
		last = getLink(last);
		if (!to[last][c]) {
			lst[sz] = n-2;
			len[sz] = len[last]+2;
			link[sz] = to[getLink(link[last])][c];
			diff[sz] = len[sz]-len[link[sz]];
			if (diff[sz] == diff[link[sz]]) 
				slink[sz] = slink[link[sz]];
			else slink[sz] = link[sz]; 
			// slink[v] = max suffix u of v such that diff[v]\neq diff[u]
			to[last][c] = sz++;
		}
		last = to[last][c]; oc[last] ++;
		// updAns();
	}
	void numOc() { // # occurrences of each palindrome
		vpi v; FOR(i,2,sz) v.pb({len[i],i});
		sort(rall(v)); trav(a,v) oc[link[a.s]] += oc[a.s];
	}
};

PalTree<MX> A,B;
str a,b;
map<T,int> ma, mb;
set<T> pala, palb;
HashRange HA, HB;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	re(a,b); HA.init(a), HB.init(b);
	trav(c,a) A.addChar(c-'a');
	trav(c,b) B.addChar(c-'a');
	ll ans = (ll)(A.sz-2)*(B.sz-2);
	FOR(i,2,A.sz) pala.insert(HA.hash(A.lst[i]-A.len[i]+1,A.lst[i]));
	FOR(i,2,B.sz) palb.insert(HB.hash(B.lst[i]-B.len[i]+1,B.lst[i]));
	FOR(i,2,A.sz) if (A.link[i] > 1) {
		int p = A.link[i];
		int period = A.len[i]-A.len[p];
		int cnt = (A.len[i]-1)/period;
		int l = A.lst[i]-A.len[i]+1, r = A.lst[i];
		T head = HA.hash(l,l+period-1);
		ckmax(ma[head],cnt);
		int lenb = period-A.len[i]%period;
		// given aba get bab
		T t = HA.hash(r-period+1,r-period+lenb)*HA.pows[period]+head;
		if (palb.count(t)) ckmax(mb[head],1);
	}
	FOR(i,2,B.sz) if (B.link[i] > 1) {
		int p = B.link[i];
		int period = B.len[i]-B.len[p];
		int cnt = (B.len[i]-1)/period;
		int l = B.lst[i]-B.len[i]+1, r = B.lst[i];
		T head = HB.hash(l,l+period-1);
		T tail = HB.hash(r-period+1,r);
		ckmax(mb[tail],cnt);
		int lenb = period-B.len[i]%period;
		T t = HB.hash(r-period+1,r-period+lenb)*HB.pows[period]+head;
		if (pala.count(t)) ckmax(ma[tail],1);
	}
	trav(t,ma) ans -= t.s*mb[t.f];
	ps(ans);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/