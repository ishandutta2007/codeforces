#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
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
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
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

#define tcTUU tcT, class ...U

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); // pairs

	// re: read
	tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	tcT> str bit_vec(T t) { // bit vector to string
		str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	tcTU> str ts(pair<T,U> p); // pairs
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
		// convert container to string w/ separator sep
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	// for nested DS
	template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	// debug to cerr
	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
}

/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

using T = db; // or long long
const T EPS = 1e-9; // might want to change
using P = pair<T,T>; using vP = V<P>; using Line = pair<P,P>;
int sgn(T a) { return (a>EPS)-(a<-EPS); }
T sq(T a) { return a*a; }

bool close(const P& a, const P& b) { 
	return sgn(a.f-b.f) == 0 && sgn(a.s-b.s) == 0; } 
T norm(const P& p) { return sq(p.f)+sq(p.s); }
T abs(const P& p) { return sqrt(norm(p)); }
T arg(const P& p) { return atan2(p.s,p.f); }
P conj(const P& p) { return P(p.f,-p.s); }
P perp(const P& p) { return P(-p.s,p.f); }
P dir(T ang) { return P(cos(ang),sin(ang)); }

P operator-(const P& l) { return P(-l.f,-l.s); }
P operator+(const P& l, const P& r) { 
	return P(l.f+r.f,l.s+r.s); }
P operator-(const P& l, const P& r) { 
	return P(l.f-r.f,l.s-r.s); }
P operator*(const P& l, const T& r) { 
	return P(l.f*r,l.s*r); }
P operator*(const T& l, const P& r) { return r*l; }
P operator/(const P& l, const T& r) { 
	return P(l.f/r,l.s/r); }
P operator*(const P& l, const P& r) { 
	return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
P operator/(const P& l, const P& r) { 
	return l*conj(r)/norm(r); }
P& operator+=(P& l, const P& r) { return l = l+r; }
P& operator-=(P& l, const P& r) { return l = l-r; }
P& operator*=(P& l, const T& r) { return l = l*r; }
P& operator/=(P& l, const T& r) { return l = l/r; }
P& operator*=(P& l, const P& r) { return l = l*r; }
P& operator/=(P& l, const P& r) { return l = l/r; }

P unit(const P& p) { return p/abs(p); }
T dot(const P& a, const P& b) { return a.f*b.f+a.s*b.s; }
T cross(const P& a, const P& b) { return a.f*b.s-a.s*b.f; }
T cross(const P& p, const P& a, const P& b) {
	return cross(a-p,b-p); }
P reflect(const P& p, const Line& l) { 
	P a = l.f, d = l.s-l.f;
	return a+conj((p-a)/d)*d; }
P foot(const P& p, const Line& l) { 
	return (p+reflect(p,l))/(T)2; }
bool p_on_seg(const P& p, const Line& l) {
	return sgn(cross(l.f,l.s,p)) == 0 && sgn(dot(p-l.f,p-l.s)) <= 0; }

/** 
 * Description: Computes the intersection point(s) of lines $AB$, $CD.$
 	* Returns ${-1,{0,0}}$ if infinitely many, ${0,{0,0}}$ if none, 
 	* ${1,x}$ if $x$ is the unique point.
 * Source: KACTL
 * Verification: ?
 */

// #include "Point.h"

P ext(P a, P b, P c, P d) { // extension in asymptote
	T x = cross(a,b,c), y = cross(a,b,d);
	return (d*x-c*y)/(x-y); }
pair<int,P> lineIsect(P a, P b, P c, P d) { 
	return cross(b-a,d-c) == 0 ? mp(-(cross(a,c,d) == 0),P()) 
	: mp(1,ext(a,b,c,d)); }

int N,L;
vP poly;

int nex(int x) { return (x+1)%N; }
int pre(int x) { return (x+N-1)%N; }

vd pref;

db perim(int st, int en) {
	db tmp = pref[en+(en<st?N:0)]-pref[st];
	return tmp;
	// db ans = 0;
	// for (int k = st; k != en; k = nex(k)) {
	// 	ans += abs(poly[nex(k)]-poly[k]);
	// }
	// dbg("HUH",tmp,ans); exit(0);
	// return ans;
}

db get_val(int i, int j) {
	if (cross(poly[i],poly[nex(i)],poly[j]) < cross(poly[i],poly[nex(i)],poly[nex(j)])) {
		db ans = perim(nex(j),i);
		P ext_ij = ext(poly[i],poly[nex(i)],poly[j],poly[nex(j)]);
		return ans+abs(ext_ij-poly[i])+abs(ext_ij-poly[nex(j)]);
	}
	return INF;
}

P farthest_l(int i, int j) { // i, nex(i), j
	db perim_ij = perim(j,i);
	auto get_point = [&](db mid) {
		return poly[nex(i)]+unit(poly[nex(i)]-poly[i])*mid;
	};
	db lo = 0, hi = 1e9;
	rep(60) {
		db mid = (lo+hi)/2;
		P p = get_point(mid);
		if (perim_ij+abs(p-poly[i])+abs(p-poly[j]) <= L) lo = mid;
		else hi = mid;
	}
	return get_point(lo);
}

P farthest_r(int i, int j) { // i, j, nex(j)
	db perim_ij = perim(nex(j),i);
	auto get_point = [&](db mid) {
		return poly[j]+unit(poly[j]-poly[nex(j)])*mid;
	};
	db lo = 0, hi = 1e9;
	rep(60) {
		db mid = (lo+hi)/2;
		P p = get_point(mid);
		if (perim_ij+abs(p-poly[i])+abs(p-poly[nex(j)]) <= L) lo = mid;
		else hi = mid;
	}
	return get_point(lo);
}

db polygon, sectors;

void foci(int i, int j, P l, P r) {
	polygon += cross(l,r)/2;
	// dbg("POLY TRAN",l,r);
	P f0 = poly[i], f1 = poly[j];
	// dbg("DOING",i,j,f0,f1,l,r);
	{
		P mid = (f0+f1)/2;
		l -= mid, r -= mid, f0 -= mid, f1 -= mid;
	}
	// dbg(abs(f0-l),abs(f1-l));
	assert(abs(f0-l) < abs(f0-r));


	db dl = abs(f0-l)+abs(f1-l);
	db dr = abs(f0-r)+abs(f1-r);
	// dbg("??",l,dr,abs(dl-dr));
	assert(abs(dl-dr) < 1e-6);

	db sum = dl;
	db dif = abs(f0-f1);
	db minor = sqrt(sum*sum-dif*dif);
	// P x_neg = sum/2*unit(f0-f1);
	P x_pos = sum/2*unit(f1-f0);
	P y_pos = minor/2*unit(f0-f1)*P(0,1);
	// P y_neg = minor/2*unit(f1-f0)*P(0,1);
	auto simp = [&](P p) -> P {
		db x = dot(p,x_pos)/norm(x_pos);
		db y = dot(p,y_pos)/norm(y_pos);
		return {x,y};
	};
	
	l = simp(l), r = simp(r);
	assert(abs(norm(l)-1) < 1e-6);
	assert(abs(norm(r)-1) < 1e-6);
	// dbg("??",norm(l),norm(r));
	db ang_between = abs(arg(l)-arg(r));
	while (ang_between > PI) ang_between -= 2*PI;
	ang_between = abs(ang_between);
	db ellipse = sum/2*minor/2/2*(ang_between-sin(ang_between));
	// dbg("HUH",l,r,ang_between);
	// dbg("CONTRIB",ellipse);
	// dbg("----");
	sectors += ellipse;
	// dbg("HA",l,r);

	// dbg("??",f0,f1,l,r);
	// return cur;
	// assert(abs(f0-l) < abs(f1-l));
	// dbg("??",dl,dr);
	// return 0;
}

int main() {
	setIO(); re(N,L);
	poly.rsz(N); re(poly);
	pref.pb(0);
	FOR(i,1,2*N+5) pref.pb(pref.bk+abs(poly[i%N]-poly[(i-1)%N]));
	int j = 0;
	while (get_val(0,nex(j)) < L) j = nex(j);
	F0R(i,sz(poly)) {
		P pre = farthest_l(i,nex(j));
		// dbg(pre);
		while (get_val(nex(i),nex(j)) < L) {
			j = nex(j);
			// foci: nex(i), j
			P b = farthest_r(nex(i),j);
			foci(nex(i),j,pre,b);
			pre = b;
			// dbg(b);
		}
		P c = farthest_l(nex(i),nex(j));
		foci(nex(i),nex(j),pre,c);
		// dbg(c);
		// foci: nex(i), nex(j)

		// while (cross(poly[i],poly[nex(i)],poly[nex(j)]) < cross(poly[pre(i)],poly[i],poly[nex(nex(j))])) {
		// 	if (get_val(i,nex(j)) < L) {

		// 	}
		// }
	}
	dbg(polygon,sectors);
	ps(polygon+sectors);
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/