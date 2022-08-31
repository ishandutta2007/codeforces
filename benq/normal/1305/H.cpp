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
int pct(int x) { return __builtin_popcount(x); } 

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
		// cin.exceptions(cin.failbit); 
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

int n,m;
ll t;
vi ques;
vpi Q, scores;

ll sum(vi v) {
	ll res = 0; trav(t,v) res += t;
	return res;
}

vi eval(int mid) {
	vi cur;
	trav(t,Q) cur.pb(min(max(t.f,mid),t.s));
	return cur;
}

void bad() {
	ps(-1,-1);
	exit(0);
}

void genQues() {
	int lo = 0, hi = m;
	// ps("WHOOPS",t,sum(eval(lo)),sum(eval(hi)));
	if (sum(eval(lo)) > t || sum(eval(hi)) < t) bad();
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (sum(eval(mid)) >= t) hi = mid;
		else lo = mid+1;
	}
	vi cur = eval(lo);
	ll csum = sum(cur);
	F0R(i,sz(Q)) if (cur[i] == lo && lo > Q[i].f && csum > t) {
		cur[i] --; csum --;
	}
	assert(csum == t);
	ques = cur; sort(all(ques));
}

void init() {
	setIO(); re(n,m); 
	Q.rsz(n); re(Q);
	int q; re(q); 
	scores.rsz(q); re(scores);
	scores.pb({m+1,0});
	sort(all(scores));
	re(t);
	genQues();
}

ll cdiv(ll a, ll b) { return (a+b-1)/b; }

bool check(vi rec) {
	assert(sz(rec) == m+1); assert(sum(rec) == t);
	FOR(i,2,m+1) assert(rec[i] <= rec[i-1]);
	ll a = 0, b = 0; int ind = 0;
	FOR(i,1,m+1) {
		a += rec[i];
		while (ind < n && ques[ind] <= i) b += ques[ind++];
		if (a > b+(ll)(n-ind)*i) return 0;
	}
	assert(a == b);
	/*if (a != b) {
		ps("WUT",a,b,rec,ques);
		exit(0);
	}*/
	return 1;
	// ps("AH",rec,ques); exit(0);
}

bool ok(int mid) {
	trav(t,scores) if (t.f <= mid && t.s != scores[0].s) return 0;
	vi rec = {0};
	int lst = scores[0].s, pos = 0;
	FOR(i,1,m+1) {
		if (pos < sz(scores) && scores[pos].f == i) 
			lst = scores[pos++].s;
		rec.pb(lst);
	}
	ll csum = sum(rec); assert(csum >= t);
	int pre = mid;
	trav(u,scores) if (u.f > pre) {
		ll dif = rec[u.f-1]-u.s;
		ll maxDec = dif*(u.f-1-pre); ckmin(maxDec,csum-t);
		FOR(j,pre+1,u.f) {
			ll amt = min(dif,maxDec/(u.f-j));
			rec[j] -= amt; maxDec -= amt; csum -= amt;
		}
		pre = u.f;
	}
	if (csum != t) return 0;
	return check(rec);
}

ll getMax() {
	if (!sz(scores)) return 0;
	int lst = scores[0].s, pos = 0;
	ll ret = 0;
	FOR(i,1,m+1) {
		if (pos < sz(scores) && scores[pos].f == i) {
			lst = scores[pos++].s;
		}
		ret += lst;
	}
	return ret;
}

int solve() {
	if (!ok(scores[0].f)) return -1;
	int lo = scores[0].f, hi = m;
	while (lo < hi) {
		int mid = (lo+hi+1)/2;
		if (ok(mid)) lo = mid;
		else hi = mid-1;
	}
	return lo;
}

int maxPosi(ll need) {
	if (need > n) return -1;
	scores.insert(begin(scores),{1,need});
	int x = solve();
	scores.erase(begin(scores));
	// ps("OH",need,x);
	return x;
}

int main() {
	init();
	ll dif = t-getMax();
	// ps("??",t,getMax());
	if (dif > 0) {
		int fst = scores[0].f-1; if (fst == 0) bad();
		ll need = cdiv(dif,fst)+scores[0].s;
		int x = maxPosi(need); if (x == -1) bad();
		int lo = need, hi = n;
		while (lo < hi) {
			ll mid = (lo+hi+1)/2;
			if (maxPosi(mid) == x) lo = mid;
			else hi = mid-1;
		}
		ps(x,lo);
	} else {
		int x = solve(); if (x == -1) bad();
		ps(x,scores[0].s);
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
*/