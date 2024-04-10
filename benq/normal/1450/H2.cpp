#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double; 
using str = string; // yay python!

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { assert(x >= 0);
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set

// INPUT
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(V<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }

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
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(V<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { // containers with begin(), end()
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
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}

// OUTPUT
tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } // print w/ spaces
tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s = "") {
	unsyncIO(); setPrec();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for USACO
}

/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
	* also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

/**
 * Description: pre-compute factorial mod inverses,
 	* assumes $MOD$ is prime and $SZ < MOD$.
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

vi invs, fac, ifac; // make sure to convert to LL before doing any multiplications ...
void genFac(int SZ) {
	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = int(MOD-(ll)MOD/i*invs[MOD%i]%MOD);
	FOR(i,1,SZ) {
		fac[i] = int((ll)fac[i-1]*i%MOD);
		ifac[i] = int((ll)ifac[i-1]*invs[i]%MOD);
	}
}
ll comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}

int N,M;
str S;
int cnt,posi;

mi get_max(int x, int y) {
	mi tmp = 0;
	for (;y >= 0; y -= 2) tmp += comb(x,y);
	return tmp;
}

mi get_max_one(int x, int y) {
	mi tmp = 0;
	for (;y >= 0; y --) tmp += comb(x,y);
	return tmp;
}

V<pair<int,pi>> todo[4];

mi get_ans() {
	assert(posi > 0);
	mi ans = 0;
	// 0 <= i <= -cnt
	ans -= cnt*get_max(posi,-cnt);
	// for (int i = -cnt; i >= 0; i -= 2) {
	// 	ans -= cnt*comb(posi,i);
	// }
	ans -= posi*get_max(posi-1,-cnt-1);
	// for (int i = -cnt; i >= 0; i -= 2) {
	// 	// i*comb(posi,i)
	// 	ans -= posi*comb(posi-1,i-1);
	// }
	ans += cnt*get_max(posi,posi-(-cnt+2));
	ans += posi*get_max(posi-1,posi-(-cnt+2));
	// for (int i = -cnt+2; i <= posi; i += 2) {
	// 	ans += cnt*comb(posi,i);
	// }
	// for (int i = -cnt+2; i <= posi; i += 2) {
	// 	ans += posi*comb(posi-1,i-1);
	// }
	ans /= pow(mi(2),posi);
	return ans;
}

void setup() {
	todo[0].pb({-cnt,{posi,-cnt}});
	todo[1].pb({-posi,{posi-1,-cnt-1}});
	todo[2].pb({cnt,{posi,posi-(-cnt+2)}});
	todo[3].pb({posi,{posi-1,posi-(-cnt+2)}});
}

int main() {
	setIO(); re(N,M,S); 
	genFac(1000005);
	// abs(even-odd) must be even
	F0R(i,sz(S)) {
		if (S[i] == '?') {
			posi ++;
			if (i%2 == 0) {
				// +0,1
			} else {
				cnt --;
				// -0,1
			}
		} else if (S[i] == 'b') {
			if (i%2 == 0) {
				cnt ++;
			} else {
				cnt --;
			}
		}
	}
	setup();
	// ps(get_ans());
	F0R(_,M) {
		int i; char c; re(i,c); -- i;
		if (S[i] == '?') {
			posi --;
			if (i%2 == 0) {
				// +0,1
			} else {
				cnt ++;
				// -0,1
			}
		} else if (S[i] == 'b') {
			if (i%2 == 0) {
				cnt --;
			} else {
				cnt ++;
			}
		}
		S[i] = c;
		if (S[i] == '?') {
			posi ++;
			if (i%2 == 0) {
				// +0,1
			} else {
				cnt --;
				// -0,1
			}
		} else if (S[i] == 'b') {
			if (i%2 == 0) {
				cnt ++;
			} else {
				cnt --;
			}
		}
		setup();
		// ps(get_ans());
	}

	// F0R(i,100) FOR(j,-101,101) {
	// 	// dbg(i,j);
	// 	if (get_max(i,j) != get_max_one(i-1,j)) {
	// 		dbg("OOPS",i,j,get_max(i,j),get_max_one(i-1,j));
	// 	}
	// }
	// exit(0);

	int X = 0, Y = 0;
	mi stor = 1;
	auto chk = [&](str dumb) {
		// if (stor != get_max_one(X,Y)) {
		// 	dbg("FAILED ONE",dumb);
		// 	exit(0);
		// }
	};
	chk("A");
	auto adjust = [&](int xx, int yy) {
		assert(xx >= 0);
		while (X < xx) {
			stor = 2*stor-comb(X,Y);
			++ X;
			chk("B");
		}
		while (X > xx) {
			-- X;
			stor = (stor+comb(X,Y))/2;
			chk("C");
		}
		while (Y < yy) {
			++ Y;
			stor += comb(X,Y);
			chk("D");
		}
		while (Y > yy) {
			stor -= comb(X,Y);
			-- Y;
			chk("E");
		}
	};

	vmi ans(M+1);
	F0R(i,4) {
		F0R(j,M+1) {
			assert(todo[i][j].s.f >= 0);
			// mi verify = get_max(todo[i][j].s.f,todo[i][j].s.s);
			mi ha = 0;
			todo[i][j].s.f --;
			if (todo[i][j].s.f < 0) {
				ha = (todo[i][j].s.s >= 0 && todo[i][j].s.s%2 == 0);
			} else {
				adjust(todo[i][j].s.f,todo[i][j].s.s);
				ha = stor;
			}
			// if (ha != verify) {
			// 	dbg("OOPS",todo[i][j].s.f,todo[i][j].s.s,ha,verify);
			// }
			// assert(ha == verify);
			ans[j] += todo[i][j].f*ha;
		}
	}
	dbg(todo[2]);
	F0R(j,M+1) ans[j] /= pow(mi(2),todo[3][j].f);
	trav(t,ans) ps(t);

	// +1, +1 or +0, 

	// S += S;
	// F0R(i,3) cum[i] = {0};
	// F0R(j,sz(S)) {
	// 	F0R(i,3) cum[i].pb(cum[i].bk);
	// 	if (S[j] == 'b') cum[0].bk ++;
	// 	else if (S[j] == 'w') cum[1].bk ++;
	// 	else cum[2].bk ++;
	// }
	// auto brute = [&](str res) {
	// 	int cnt = 0;
	// 	F0R(i,sz(res)) {
	// 		if (res[i] == 'b') {
	// 			if (i&1) cnt ++;
	// 			else cnt --;
	// 		}
	// 	}
	// 	return abs(cnt)/2;
	// 	// str st;
	// 	// trav(c,res) {
	// 	// 	if (sz(st) && st.bk == c) st.pop_back();
	// 	// 	else st += c;
	// 	// }
	// 	// dbg("HA",st);
	// 	// return sz(st)/4;
	// };
	// int tmp = 0, cnt = 0;
	// F0R(i,1<<N) {
	// 	str res;
	// 	int par = 0;
	// 	F0R(j,N) {
	// 		if (i&(1<<j)) res += 'w';
	// 		else {
	// 			res += 'b';
	// 			par ^= 1;
	// 		}
	// 	}
	// 	bool bad = 0;
	// 	F0R(j,N) if (res[j] != S[j] && S[j] != '?') bad = 1;
	// 	if (bad || (par == 1)) continue;
	// 	tmp += brute(res);
	// 	cnt ++;
	// }
	// dbg(tmp,cnt);
	// // mi ans = 0;
	// // vi tot(3);
	// // F0R(i,3) tot[i] = cum[i][N];
	// // assert(tot[0]+tot[1]+tot[2] == N);
	// // auto same_par = [&](int x, int y) {
	// // 	return (x-y)%2 == 0;
	// // };
	// // for (int len = 1; len < N; len += 2) {
	// // 	F0R(i,N) { // 1,0,1
	// // 		if (cnt(0,i,i) == 0 && cnt(1,i+1,i+len) == 0 && cnt(0,i+len+1,i+len+1) == 0) {
	// // 			int x = cnt(2,i,i+len+1);
	// // 			if (x == tot[2]) {
	// // 				// if (same_par(cnt(1,i,i+len+1),tot[1])) { // even
	// // 				// 	ans += 1/pow(mi(2),x);
	// // 				// }
	// // 				// 2+cnt() must be even

	// // 				// ones+2-cnt(1,i,i+len+1) must be even
	// // 			} else {
	// // 				dbg(i,i+len+1,x,16/pow(mi(2),x+1));
	// // 				ans += 1/pow(mi(2),x+1);
	// // 			}
	// // 		}
	// // 		// BW^{len}B
	// // 		// WB^{len}W
	// // 	}
	// // }
	// // ans *= 16;
	// // // 15/16
	// // ps(ans);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/