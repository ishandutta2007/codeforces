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

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 

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
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
str ts(vector<bool> v) { 
	bool fst = 1; str res = "{";
	F0R(i,sz(v)) {
		if (!fst) res += ", ";
		fst = 0; res += ts(v[i]);
	}
	res += "}"; return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class T> str ts(T v) {
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
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
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

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

/**
 * Description: Product of nimbers is associative, commutative, and distributive 
 	* over addition (xor). Forms finite field of size $2^{2^k}.$ Application: 
 	* Given 1D coin turning games $G_1,G_2$ $G_1\times G_2$ is the 2D coin turning 
 	* game defined as follows. If turning coins at $x_1,x_2,\ldots,x_m$ is legal 
 	* in $G_1$ and $y_1,y_2,\ldots,y_n$ is legal in $G_2$, then turning coins at 
 	* all positions $(x_i,y_j)$ is legal assuming that the coin at $(x_m,y_n)$ 
 	* goes from heads to tails. Then the grundy function $g(x,y)$ of $G_1\times G_2$ 
 	* is $g_1(x)\times g_2(y).$ 
 * Source: Andrew He
 	* also see pg 35 of https://www.fmf.uni-lj.si/~juvan/Seminar1/ferguson.pdf
 	* https://en.wikipedia.org/wiki/Nimber
 * Time: $64^2$ xors per multiplication, memorize to speed up.
 * Verification: https://codeforces.com/gym/102341/problem/L
 	* https://projecteuler.net/problem=459
 */

using ul = uint64_t; 
ul _nimProd[64][64];
ul nimProd(int i, int j) { // nim prod of 2^i, 2^j
	ul& u =_nimProd[i][j]; if (u) return u;
	if (!(i&j)) return u = 1ULL<<(i|j);
	int a = (i&j)&-(i&j); // 2^{2^k}
	return u=nimProd(i^a,j)^nimProd((i^a)|(a-1),(j^a)|(i&(a-1)));
	// 2^{2^k}*2^{2^k} = 2^{2^k}+2^{2^k-1}
} // 2^{2^i}*2^{2^j} = 2^{2^i+2^j} if i<j
struct nb { // nimber
	ul x; nb() { x = 0; }
	nb(ul _x): x(_x) {}
	explicit operator ul() { return x; }
	nb operator+(nb y) { return nb(x^y.x); }
	nb operator*(nb y) {
		ul res = 0;
		F0R(i,64)if(x>>i&1)F0R(j,64)if(y.x>>j&1)res^=nimProd(i,j);
		return nb(res);
	}
	friend nb pow(nb b, ul p) {
		nb res = 1; for (;p;p/=2,b=b*b) if (p&1) res = res*b;
		return res; } // b^{2^{2^A}-1}=1 where 2^{2^A} > b
	friend nb inv(nb b) { return pow(b,-2); }
};

int t;
ll n;

void solve() {

}

bool in(vi a, int b) {
	return find(all(a),b) != end(a);
}

ll huh(ll a, int b) {
	if (b == 0) return a;
	if (b == 2) return huh(a,1)^huh(a,0);
	return (nb(2)*nb(a)).x;
}

ll get(ll a, int b) {
	for (int i = 0; ; ++i) {
		ll p = 1LL<<(2*i);
		if (p >= a) return p*(b+1)+huh(a-1,b);
		a -= p;
	}
}

int main() {
	setIO();
	//FOR(z,1,101) ps(get(z,0));
	vi seq;
	F0R(z,100) {
		int cur = 1; while (in(seq,cur)) cur ++;
		int CUR = cur+1; while (in(seq,CUR) || in(seq,cur^CUR)) CUR ++;
		seq.pb(cur); seq.pb(CUR); seq.pb(cur^CUR);
		ll p = 1; while (p*4 <= cur) p *= 4;
		// dbg(cur,CUR,cur^CUR,cur-p,CUR-2*p,(cur^CUR)-3*p);
	}
	FOR(a,1,101) F0R(b,3) {
		assert(get(a,b) == seq[3*(a-1)+b]);
	}
	re(t);
	F0R(i,t) {
		ll n; re(n);
		ps(get((n+2)/3,(n-1)%3));
	}
	// trav(t,seq) ps(t);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/