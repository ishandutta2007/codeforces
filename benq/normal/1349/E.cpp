#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		int mid = (lo+hi)/2; 
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

int n;
vl t; ll T[MX];

bool allZero() { // OK
	trav(u,t) if (u) return 0;
	return 1;
}
bool consistent0(vector<pair<int,ll>> v) { // OK
	F0R(i,sz(v)-1) if (v[i].s != v.bk.s+1) return 0;
	return 1;
}
bool consistent1(vector<pair<int,ll>> v) { // OK
	F0R(i,sz(v)-1) if (v[i].s != v.bk.s) return 0;
	return 1;
}

void fassert(bool b) {
	if (!b) {
		ps("OOPS");
		exit(0);
	}
}

str ans;
void verify() {
	dbg("HUH",ans);
	t.pb(0); ll sum = 0; int lst = -1;
	F0R(i,sz(ans)) if (ans[i] == '1') {
		sum += n-i; if (t[i]) fassert(sum == t[i]); // failing ...
		FOR(j,lst+1,i) if (t[j]) fassert(sum+1 == t[j]);
		lst = i;
	}
	ans.pop_back(); ps(ans);
	exit(0);
} // OK

vector<vector<pair<int,ll>>> tmp; // OK
ll ari(int l, int r) { return (ll)(l+r)*(r-l+1)/2; } // OK

bool posiSum(ll sum, int l, int r) {
	if (sum < 0) return 0;
	if (sum == 0) return 1;
	if (l > r) return 0;
	int lo = 0, hi = r-l+1;
	while (lo < hi) {
		int mid = (lo+hi+1)/2;
		if (ari(l,l+mid-1) <= sum) lo = mid;
		else hi = mid-1;
	}
	//dbg("HUH",sum,l,r,lo,ari(r-lo+1,r));
	return ari(r-lo+1,r) >= sum;
} // OK

void add(int t) { assert(0 <= t && t <= n); ans[n-t] = '1'; } // OK

void make(ll sum, int l, int r) {
	int lo = 0, hi = r-l+1;
	while (lo < hi) {
		int mid = (lo+hi+1)/2;
		if (ari(l,l+mid-1) <= sum) lo = mid;
		else hi = mid-1;
	}
	vi v; FOR(i,l,l+lo) v.pb(i);
	ll lef = sum-ari(l,l+lo-1); fassert(lef >= 0);
	R0F(i,sz(v)) {
		ll maxInc = r-(l+lo-1); ckmin(maxInc,lef);
		v[i] += maxInc; lef -= maxInc;
	}
	assert(!lef);
	trav(t,v) add(t);
}


int dp[MX][2];
int _j[MX][2],_lo[MX][2],_hi[MX][2];
ll _sum[MX][2];

void check(int i, int parity, int j, int pos, ll sum, int lo, int hi) {
	if (pos <= dp[i][parity]) return;
	dp[i][parity] = pos;
	_j[i][parity] = j;
	_sum[i][parity] = sum;
	_lo[i][parity] = lo;
	_hi[i][parity] = hi;
}

void rec(int i, int parity) {
	fassert(i >= 0);
	dbg("REC",i,parity,dp[i][parity]); fassert(dp[i][parity] != -1);
	if (i == 0) verify();
	add(dp[i][parity]);
	make(_sum[i][parity],_lo[i][parity],_hi[i][parity]);
	rec(i-1,_j[i][parity]);
}

void tri(int pos) {
	fassert(T[pos]);
	int i = sz(tmp)-1;
	F0R(j,2) if (dp[i-1][j] > tmp[i].ft.f) {
		ll st = tmp[i-1].bk.s-j, en = T[pos];
		int lo = tmp[i].ft.f+1, hi = dp[i-1][j]-1;
		if (posiSum(en-pos-st,lo,hi)) {
			add(pos); make(en-pos-st,lo,hi);
			rec(i-1,j);
		}
	}
}

pl bound(vector<pair<int,ll>> v) {
	ll mn = INF, mx = -INF;
	trav(t,v) {
		ckmin(mn,t.s);
		ckmax(mx,t.s);
	}
	return {mn,mx};
}

bool allEqual(vector<pair<int,ll>> a, ll b) {
	trav(t,a) if (t.s != b) return 0;
	return 1;
}

int main() {
	setIO(); re(n); 
	ans = str(n,'0')+'1';
	t.rsz(n); re(t); 
	if (allZero()) verify();
	tmp.eb(); tmp.bk.pb({n+1,0});
	F0R(i,n) if (t[i]) {
		T[n-i] = t[i];
		if (tmp.bk.bk.s < t[i]) tmp.eb();
		tmp.bk.pb({n-i,t[i]});
	}
	/*if (sz(tmp) > 2) {
		pl p = bound(tmp[sz(tmp)-2]);
		pl q = bound(tmp[sz(tmp)-1]);
		dbg("WUT",p,q);
		if (p.f+1 == q.f && q.f == q.s && p.f == tmp[sz(tmp)-2].bk.s) {
			dbg("MERGE");
			tmp[sz(tmp)-2].insert(end(tmp[sz(tmp)-2]),all(tmp.bk));
			tmp.pop_back();
		}
	}*/
	dbg(tmp);
	F0R(i,sz(tmp)) dp[i][0] = dp[i][1] = -1;
	dp[0][0] = n+1; // OK
	FOR(i,1,sz(tmp)) { dbg("DOING",i);
		if (i == sz(tmp)-1) {
			F0R(j,2) if (dp[i-1][j] > tmp[i].ft.f) {
				ll st = tmp[i-1].bk.s-j;
				if (allEqual(tmp[i],st+1)) {
					dbg("OKALLEQUAL",st);
					rec(i-1,j);
				}
			}
			// last is somewhere inside
			ll mx = 0; trav(t,tmp[i]) ckmax(mx,t.s);
			int pos = -1; F0R(z,sz(tmp[i])) if (tmp[i][z].s < mx) pos = tmp[i][z].f;
			dbg("HA",pos);
			if (pos != -1) {
				tri(pos);
				fassert(0);
			}
			if (sz(tmp.bk) == 1) tri(tmp.bk[0].f);
			dbg("LASTTRI");
			for (int pos = tmp[i].ft.f; pos >= 0; --pos) if (!T[pos]) {
				dbg("TRYING",pos);
				F0R(j,2) if (dp[i-1][j] > tmp[i].ft.f) {
					ll st = tmp[i-1].bk.s-j, en = mx-1;
					int lo = tmp[i].ft.f+1, hi = dp[i-1][j]-1;
					//dbg("HUH",j,st,en,en-pos-st,lo,hi,posiSum(en-pos-st,lo,hi));
					if (posiSum(en-pos-st,lo,hi)) {
						add(pos); make(en-pos-st,lo,hi);
						rec(i-1,j);
					}
				}
			}
			assert(0);
		} else {
			F0R(j,2) if (dp[i-1][j] > tmp[i].ft.f) {
				ll st = tmp[i-1].bk.s-j;
				if (consistent0(tmp[i])) { // k == 0
					int pos = tmp[i].bk.f; ll en = tmp[i].bk.s;
					int lo = tmp[i].ft.f+1, hi = dp[i-1][j]-1;
					if (!posiSum(en-pos-st,lo,hi)) pos = -1;
					check(i,0,j,pos,en-pos-st,lo,hi);
				}
				// k == 1
				if (consistent1(tmp[i])) {
					int pos = tmp[i].bk.f-1; ll en = tmp[i].bk.s-1;
					int lo = tmp[i].ft.f+1, hi = dp[i-1][j]-1;
					while (pos > tmp[i+1].ft.f && !posiSum(en-pos-st,lo,hi)) pos --;
					if (pos <= tmp[i+1].ft.f) pos = -1;
					check(i,1,j,pos,en-pos-st,lo,hi);
				}
			}
			dbg(i,dp[i][0],dp[i][1]);
		}
	}
	assert(0);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/