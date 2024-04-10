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
#define sz(x) (int)(x).size()
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
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }

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
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
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
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	#endif
}
template<class A, class B> str ts(pair<A,B> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}

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
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(str s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

using ul = uint64_t;
typedef vector<vector<ul>> Mat;
const ul BIG = 1ULL<<63;

ul ADD(ul a, ul b) {
	if (a == BIG || b == BIG) return BIG;
	assert(a < BIG && b < BIG);
	return min(a+b,BIG);
}

int G,N,M;
Mat dp[1000], done[1000], ID;
vi sing[1000];
vpi lef[1000], rig[1000];

int make(int a, vi b) {
	if (a == -1) {
		assert(sz(b) > 1);
		a = G++;
	}
	dbg(sz(b));
	if (sz(b) == 1) {
		sing[b[0]].pb(a);
	} else {
		assert(sz(b) == 2);
		//dbg("NOT ONE",sz(b));
		lef[b[0]].pb({b[1],a});
		rig[b[1]].pb({b[0],a});
	}
	return a;
}

int compress(vi v) {
	if (sz(v) == 1) return v[0];
	return make(-1,{compress(vi(all(v)-1)),v.bk});
}

map<vi,int> state;
vector<vi> rstate;
int co = 0;

bool endsWith(vi a, vi b) {
	return sz(a) >= sz(b) && vi(end(a)-sz(b),end(a)) == b;
}

int main() {
	// dbg(BIG,2*BIG);
	setIO(); 
	re(G,N,M);
	int _G = G;
	F0R(i,N) {
		int a,k; re(a,k); vi b(k); re(b);
		if (k == 1) make(a,b); // OK
		else {
			int x = compress(vi(all(b)-1));
			make(a,{x,b.bk});
		}
	}
	state[{}] = 0;
	vector<vi> ban;
	F0R(i,M) {
		int L; re(L);
		vi c(L); re(c);
		F0R(j,L+1) {
			vi pref = vi(begin(c),begin(c)+j);
			state[pref] = 0;
		}
		ban.pb(c);
	}
	trav(t,state) {
		bool bad = 0;
		trav(u,ban) if (endsWith(t.f,u)) bad = 1;
		if (bad) {
			t.s = -1;
			continue;
		}
		t.s = co++;
		rstate.pb(t.f);
	}
	dbg(rstate);
	assert(co);
	ID.assign(co,vector<ul>(co,BIG));
	F0R(i,G) {
		dp[i] = ID; // OK
		done[i] = vector<vector<ul>>(co,vector<ul>(co,0));
	}
	typedef pair<ul,array<int,3>> T;
	priority_queue<T,vector<T>,greater<T>> pq;
	auto ad = [&](int i, int j, int k, ul val) {
		if (ckmin(dp[i][j][k],val)) pq.push({dp[i][j][k],{i,j,k}});
	};
	auto process = [&](int x, int b, int c) {
		assert(!done[x][b][c]); done[x][b][c] = 1;
		ul v = dp[x][b][c];
		trav(t,sing[x]) ad(t,b,c,v);
		trav(t,lef[x]) {
			F0R(d,co) if (done[t.f][c][d]) 
				ad(t.s,b,d,ADD(v,dp[t.f][c][d]));
		}
		trav(t,rig[x]) {
			F0R(a,co) if (done[t.f][a][b])
				ad(t.s,a,c,ADD(dp[t.f][a][b],v));
		}
	};
	auto gen = [](int ind) {
		Mat res = ID;
		F0R(i,sz(rstate)) {
			vi v = rstate[i]; v.pb(ind);
			while (!state.count(v)) v.erase(begin(v));
			int label = state[v]; if (label == -1) continue;
			res[i][label] = 1;
		}
		return res;
	};
	F0R(i,2) dp[i] = gen(i);
	F0R(i,2) F0R(j,co) F0R(k,co) if (dp[i][j][k] != BIG) process(i,j,k);
	while (sz(pq)) {
		auto a = pq.top(); pq.pop(); 
		if (a.f > dp[a.s[0]][a.s[1]][a.s[2]]) continue;
		process(a.s[0],a.s[1],a.s[2]);
	}
	FOR(i,2,_G) {
		ul mn = BIG; F0R(j,co) ckmin(mn,dp[i][0][j]);
		if (mn == BIG) ps("YES");
		else ps("NO",mn);
	}
	//dbg(state);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/