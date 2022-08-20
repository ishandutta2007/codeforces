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
// mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
mt19937 rng(0);
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

// make sure to intialize ALL GLOBAL VARS between tcs!

// ll abs(ll x) {
// 	if (x < 0) x *= -1;
// 	return x;
// }

// ll __gcd(ll a, ll b) {
// 	if (a == 0) return b;
// 	return __gcd(b%a,a);
// }

// str ts(ll x) { return ts((long long)x); }

struct frac {
	ll n,d;
	frac(ll _n, ll _d) {
		n = _n, d = _d;
		ll g = __gcd(n,d); n /= g, d /= g;
		if (d < 0 || (d == 0 && n == -1)) n *= -1, d *= -1;
	}
	frac(ll _n) : frac(_n,1) {}
	frac() : frac(0) {}
	friend frac abs(frac F) { return frac(abs(F.n),F.d); }
	friend str ts(const frac& a) { return ts(a.n)+"/"+ts(a.d); }
 
	friend bool operator<(const frac& l, const frac& r) { 
		assert(l.d == 1 || r.d == 1);
		return l.n*r.d < r.n*l.d; }
	friend bool operator>(const frac& l, const frac& r) { 
		assert(l.d == 1 || r.d == 1);
		return l.n*r.d > r.n*l.d; }
	friend bool operator==(const frac& l, const frac& r) { return l.n == r.n && l.d == r.d; }
	friend bool operator!=(const frac& l, const frac& r) { return !(l == r); }
 
	frac operator-() const { return frac(-n,d); }
	friend frac operator+(const frac& l, const frac& r) { return frac(l.n*r.d+r.n*l.d,l.d*r.d); }
	friend frac operator-(const frac& l, const frac& r) { return frac(l.n*r.d-r.n*l.d,l.d*r.d); }
	friend frac operator*(const frac& l, const frac& r) { return frac(l.n*r.n,l.d*r.d); }
	friend frac operator*(const frac& l, int r) { return l*frac(r,1); }
	friend frac operator*(int r, const frac& l) { return l*r; }
	friend frac operator/(const frac& l, const frac& r) { return l*frac(r.d,r.n); }
	friend frac operator/(const frac& l, const int& r) { return l/frac(r,1); }
	friend frac operator/(const int& l, const frac& r) { return frac(l,1)/r; }
 
	friend frac& operator+=(frac& l, const frac& r) { return l = l+r; }
	friend frac& operator-=(frac& l, const frac& r) { return l = l-r; }
	template<class T> friend frac& operator*=(frac& l, const T& r) { return l = l*r; }
	template<class T> friend frac& operator/=(frac& l, const T& r) { return l = l/r; }
};


bool flag;

namespace mine {
/**
 * Description: Operations with fractions
 * Source: https://martin-thoma.com/fractions-in-cpp/
 * Verification: TopCoder MinimizeAbsoluteDifferenceDiv1
 */

// https://codeforces.com/blog/entry/89968

struct Tag {
	ll c, delta_x, delta_y;
	// transformation:
	// {x,y} -> {x+c*y+delta_x,y+delta_y}

	// this + t -> {(x+c*y+delta_x)+t.c*(y+delta_y)+t.delta_x,(y+delta_y)+t.delta_y}
	Tag with_tag(Tag t) { // OK
		return {c+t.c,delta_x+t.c*delta_y+t.delta_x,delta_y+t.delta_y};
	}
	Tag inv() { // OK
		return {-c,c*delta_y-delta_x,-delta_y};
	}
	friend str ts(const Tag& t) { 
		return "{c: "+ts(t.c)+", delta_x:"+ts(t.delta_x)+ts(", delta_y:")+ts(t.delta_y)+"}"; 
	}
};

Tag undo_front(Tag a, Tag result) { // OK
	ll t_c = result.c-a.c;
	return {t_c,result.delta_x-a.delta_x-t_c*a.delta_y,result.delta_y-a.delta_y};
}

// a.delta_x+t.c*a.delta_y+t.delta_x = result.delta_x
// a.delta_y+t.delta_y = result.delta_y
// a.c+t.c = result.c

// result.c-a.c, result.delta_x-a.delta_x-(result.c-a.c)*a.delta_y, result.delta_y-a.delta_y

const Tag ID{0,0,0};
Tag tag_x_plus_y() { return {1,0,0}; }
Tag tag_z(int z) { return {0,z,z}; }

int N;

struct Vertex {
	ll x,y,k;
	Vertex(ll _x, ll _y, ll _k) {
		assert(_k > 0);
		ll g = __gcd(__gcd(abs(_x),abs(_y)),_k);
		x = _x/g;
		y = _y/g;
		k = _k/g;
		// if (!(k <= N)) dbg("HUH",_x,_y,_k,x,y,k);
		// assert(k <= N);
		assert(abs(x) <= (ll)1e14);
		assert(abs(y) <= (ll)1e14);
	}
	Vertex(ll _x, frac _y) : Vertex(_x*_y.d,_y.n,_y.d) {}
	Vertex(frac _x, ll _y) : Vertex(_x.n,_y*_x.d,_x.d) {}
	Vertex(ll _x, ll _y) : Vertex(_x,_y,1) {}
	Vertex with_tag(Tag t) { return Vertex(x+t.c*y+t.delta_x*k,y+t.delta_y*k,k); }
	bool operator==(const Vertex& o) { return x == o.x && y == o.y && k == o.k; }
	frac get_x() const { return frac(x,k); }
	frac get_y() const { return frac(y,k); }
	friend str ts(const Vertex& v) { 
		V<frac> fracs{v.get_x(),v.get_y()};
		return ts(fracs);
	}
};

frac slope_between (Vertex a, Vertex b) {
	// (a.y/a.k-b.y/b.k)/(a.x/a.k-b.x/b.k)
	ll num = a.y*b.k-b.y*a.k;
	ll den = a.x*b.k-b.x*a.k;
	frac res = frac(num,den);
	// dbg(res);
	assert(res.n == 1 || res.n == 0);
	return res;
}

bool flag;

Vertex isect_x(Vertex a, Vertex b, int x) {
	if (flag) dbg("ISECT X",a,b,x);
	Vertex result2{0,0,1};
	frac _slope = slope_between(a,b);
	if (_slope.n == 0) {
		return Vertex(x*a.k,a.y,a.k);
	}
	ll slope = _slope.d;
	return Vertex(x*a.k*slope,x*a.k+a.y*slope-a.x,a.k*slope);
}

Vertex isect_y(Vertex a, Vertex b, int y) {
	frac _slope = slope_between(a,b); 
	ll slope = _slope.d;
	ll x_intercept = a.x-slope*a.y; // over a.k
	Vertex result = Vertex(slope*y*a.k+x_intercept,y*a.k,a.k);
	return result;
}

void apply_tag(Tag& a, Tag b) {
	a = a.with_tag(b);
}


bool collinear(Vertex a, Vertex b, Vertex c) {
	frac f = (b.get_y()-a.get_y())*(c.get_x()-a.get_x())-(b.get_x()-a.get_x())*(c.get_y()-a.get_y());
	return f.n == 0;
}

struct Hull {
	deque<pair<Vertex,Tag>> verts;
	// tag should be applied to vertex and everything before it
	Tag prod = ID;
	Hull() {}
	Hull(V<Vertex> _verts) { // OK
		for (Vertex v: _verts) add_back(v);
	}
	Vertex get_back() { // OK
		assert(!verts.empty());
		return verts.bk.f.with_tag(verts.bk.s);
	}
	Vertex get_front() { // OK
		assert(!verts.empty());
		return verts.ft.f.with_tag(prod);
	}
	void apply_back(Tag t) { // OK
		assert(!verts.empty());
		apply_tag(verts.bk.s,t);
		apply_tag(prod,t);
	}
	void x_plus_y() { // OK
		apply_back(tag_x_plus_y());
	}
	void advance_z(int z) { // OK
		apply_back(tag_z(z));
	}
	Vertex poll_front() { // OK
		Vertex v = get_front();
		prod = undo_front(verts.ft.s,prod);
		verts.pop_front();
		assert(sz(verts));
		return v;
	}
	Vertex poll_back() { // OK
		Vertex v = get_back();
		Tag last_tag = verts.bk.s;
		verts.pop_back(); assert(sz(verts));
		apply_tag(verts.bk.s,last_tag);
		return v;
	}
	frac get_front_x() { return get_front().get_x(); }
	frac get_front_y() { return get_front().get_y(); }
	frac get_back_x() { return get_back().get_x(); }
	frac get_back_y() { return get_back().get_y(); }
	void add_front(Vertex v) {
		if (!verts.empty() && v == get_front()) return;
		verts.push_front({v,prod.inv()}); prod = ID;
	}
	void add_back(Vertex v) {
		if (!verts.empty() && v == get_back()) return;
		verts.pb({v,ID});
	}
	void cut_y_lower(int yl) {
		while (get_front_y() < yl) {
			Vertex v = poll_front();
			assert(!verts.empty());
			if (get_front_y() > yl)
				add_front(isect_y(v,get_front(),yl));
		}
	}
	void cut_y_upper(int yu) {
		while (get_back_y() > yu) {
			Vertex v = poll_back();
			assert(!verts.empty());
			if (get_back_y() < yu)
				add_back(isect_y(v,get_back(),yu));
		}
	}
	void cut_x_lower(int xl) {
		while (get_front_x() < xl) {
			Vertex v = poll_front();
			assert(!verts.empty());
			if (get_front_x() > xl)
				add_front(isect_x(v,get_front(),xl));
		}
	}
	void cut_x_upper(int xu) {
		while (get_back_x() > xu) {
			Vertex v = poll_back(); 
			assert(!verts.empty());
			if (get_back_x() < xu)
				add_back(isect_x(v,get_back(),xu));
		}
	}
	friend str ts(const Hull& h) {
		V<Vertex> converted;
		set<int> cands;
		cands.ins(0);
		cands.ins(sz(h.verts)-1);
		for (int i: cands) {
			Vertex v = h.verts[i].f;
			if (i == 0) {
				v = v.with_tag(h.prod);
			} else {
				FOR(j,i,sz(h.verts)) v = v.with_tag(h.verts[j].s);
			}
			converted.pb(v);
			// while (sz(converted) > 2 && collinear(converted[sz(converted)-3],converted[sz(converted)-2],converted.bk)) {
			// 	converted.erase(begin(converted)+sz(converted)-2);
			// }
		}
		// F0R(i,sz(converted)-1) {
		// 	frac f = slope_between(converted[i],converted[i+1]);
		// 	frac y_intercept = converted[i].get_y()-converted[i].get_x()*f;
		// 	// if (y_intercept.d) if (f.d%y_intercept.d != 0) {
		// 	// 	dbg("FAILED",converted[i],converted[i+1]);
		// 	// }
		// }
		return ts(converted);
	}
};

vpi X,Y,Z;
Hull lower, upper;
// if single point, both have it

bool hull_empty() {
	return lower.verts.empty();
}

void x_plus_y() {
	if (hull_empty()) return;
	lower.x_plus_y(); upper.x_plus_y();
}

void advance_z(int zl, int zu) {
	if (hull_empty()) return;
	lower.advance_z(zl); upper.advance_z(zu);
	upper.add_front(lower.get_front());
	lower.add_back(upper.get_back());
}

void clear() {
	upper.verts = lower.verts = {};
}

void cut_y_lower(int yl) {
	if (hull_empty()) return;
	if (lower.get_back_y() < yl) return clear();
	upper.cut_y_lower(yl);
	lower.cut_y_lower(yl);
	lower.add_front(upper.get_front());
}

void cut_y_upper(int yu) {
	if (hull_empty()) return;
	if (lower.get_front_y() > yu) return clear();
	upper.cut_y_upper(yu);
	lower.cut_y_upper(yu);
	upper.add_back(lower.get_back());
}

void cut_x_lower(int xl) {
	if (hull_empty()) return;
	if (lower.get_back_x() < xl) return clear();
	upper.cut_x_lower(xl);
	lower.cut_x_lower(xl);
	upper.add_front(lower.get_front());
}

void cut_x_upper(int xu) {
	if (hull_empty()) return;
	if (lower.get_front_x() > xu) return clear();
	upper.cut_x_upper(xu);
	lower.cut_x_upper(xu);
	lower.add_back(upper.get_back());
}


void print_hulls() {
	// if (flag) {
	dbg("HULLS");
	dbg(lower);
	dbg(upper);
	dbg("----");
	// }
	// dbg(lower);
	// dbg(upper);
}

pi rand_pair() {
	int a = rng()%21-10;
	int b = rng()%21-10;
	if (a > b) swap(a,b);
	return {a,b};
}

int rng_int(int l, int r) { return uniform_int_distribution<int>(l,r)(rng); }

pi rand_around(int x) {
	int a = rng_int(-1e8,1e8), b = rng_int(1e8,1e8);
	if (a > b) swap(a,b);
	return {a,b};
	// return {rng_int(-1e8,x),rng_int(x,1e8)};
	// return {rng_int(max(-(int)1e8,x-5),x),rng_int(x,min((int)1e8,x+5))};
}

pair<bool,vs> solve(int tc, int N, vpi X, vpi Y, vpi Z) {
	dbg(tc);
	// N = 3; 

	// if (tc == 6649) {
	// 	ps(N);
	// 	each(t,X) ps(t.f,t.s);
	// 	each(t,Y) ps(t.f,t.s);
	// 	each(t,Z) ps(t.f,t.s);
	// 	// ps(ts_sep(X,"\n"));
	// 	// ps(ts_sep(Y,"\n"));
	// 	// ps(ts_sep(Z,"\n"));
	// }

	// dbg(N);
	// dbg(X);
	// dbg(Y);
	// dbg(Z);

	Vertex lower_left(X[1].f,X[1].f-X[0].s);
	Vertex upper_left(X[1].f,X[1].f-X[0].f);
	Vertex upper_right(X[1].s,X[1].s-X[0].f);
	Vertex lower_right(X[1].s,X[1].s-X[0].s);
	upper = Hull({lower_left,upper_left,upper_right});
	lower = Hull({lower_left,lower_right,upper_right});
	cut_y_lower(Y[0].f); cut_y_upper(Y[0].s);
	// dbg("SOLUTION 1");
	vs rec;
	if (!hull_empty()) {
		rec.pb("UPPER: "+ts(upper));
		rec.pb("LOWER: "+ts(lower));
	}
	// ps("UPPER",upper);
	// ps("LOWER",lower);
	FOR(i,2,N) {
		// dbg("IT",i);
		// dbg(sz(lower.verts),sz(upper.verts));
		// assert(!hull_empty());
		// flag = tc == 6649;
		// flag = N == 100000 && tc == 2 && i == 99999;
		// if (N == 100000 && tc == 2 && i == 99999) {
		// 	ps("HULL EMPTY BEFORE",i);
		// 	ps(X[i]);
		// 	ps(Y[i-1]);
		// 	ps(Z[i-2]);
		// if (tc == 6649) {
		// 	dbg("ITERATION",i);
		// 	dbg(upper);
		// 	dbg(lower);
		// }
		// 	ps(upper);
		// 	ps(lower);
		// }
		// if (flag) ps("BEFORE ITERATION",i,X[i],Y[i-1],Z[i-2]);
		// print_hulls();

		x_plus_y();

		// if (flag) dbg("AFTER X PLUS Y",i);
		// print_hulls();

		advance_z(Z[i-2].f,Z[i-2].s);

		// if (flag) dbg("AFTER Z",i,Z[i-2]);
		// print_hulls();

		cut_x_lower(X[i].f); 

		// if (flag) 
		// 	dbg("AFTER X LOWER",i,X[i].f);
		// print_hulls();

		cut_x_upper(X[i].s);

		// if (flag) 
		// 	dbg("AFTER X HIGHER",i,X[i].s);
		// print_hulls();

		cut_y_lower(Y[i-1].f); 

		// if (flag) 
			// dbg("AFTER Y LOWER",i,Y[i-1].f);
		// print_hulls();

		cut_y_upper(Y[i-1].s);

		// dbg("AFTER Y HIGHER",i,Y[i-1].s);
		// print_hulls();
		// if (N == 100000 && tc == 2 && hull_empty()) {
		// 	ps("HULL EMPTY AFTER",i);
		// }
		if (!hull_empty()) {
			rec.pb("UPPER: "+ts(upper));
			rec.pb("LOWER: "+ts(lower));
		}
		// ps("UPPER",upper);
		// ps("LOWER",lower);
	}
	dbg(rec);
	// assert(!hull_empty());
	if (hull_empty()) return {0,rec};
	else return {1,rec};
}

}

namespace model {

using LL = long long;

inline char GET_CHAR(){
    const int maxn = 131072;
    static char buf[maxn],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
    int res(0);
    char c = getchar();
    while(c < '0') c = getchar();
    while(c >= '0') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(int x, int width = 0) {
    string res;
    if(x == 0) res.push_back('0');
    while(x) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    while((int)res.size() < width) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
    fwrite(buf, 1, _bl, stdout);
    _bl = 0;
}
__inline void _putchar(char c) {
    if(_bl == _B) flush();
    buf[_bl++] = c;
}
inline void print(LL x, char c) {
    static char tmp[20];
    int l = 0;
    if(!x) tmp[l++] = '0';
    else {
        while(x) {
            tmp[l++] = x % 10 + '0';
            x /= 10;
        }
    }
    for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
    _putchar(c);
}
const int N = 100011;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void no() {
    printf("NO\n");
}
void yes() {
    printf("YES\n");
}
const int L = 1e9;
struct Frac {
    LL x, y;
    Frac() {
        y = 1;
        x = 0;
    }
    Frac(LL _x, LL _y) : x(_x), y(_y){
        if(y < 0) {
            y = -y; x = -x;
        }
        LL d = gcd(abs(x), y);
        x /= d; y /= d;
    }
    Frac(LL a) {
        x = a; y = 1;
    }
    Frac operator + (const Frac & b) const {
        return Frac(x * b.y + y * b.x, y * b.y);
    }
    Frac operator - (const Frac & b) const {
        return Frac(x * b.y - y * b.x, y * b.y);
    }
    Frac operator * (const Frac & b) const {
        return Frac(x * b.x, y * b.y);
    }
    Frac operator / (const Frac & b) const {
        LL dx = gcd(x, b.x);
        LL dy = gcd(y, b.y);
        return Frac(x / dx * (b.y / dy), (y / dy) * (b.x / dx));
    }
    bool operator == (const Frac & b) const {
        return x * b.y == y * b.x;
    }
    bool operator != (const Frac & b) const {
        return x * b.y != y * b.x;
    }
    bool operator < (const Frac & b) const {
        return x * b.y < y * b.x;
    }
    bool operator > (const Frac & b) const {
        return x * b.y > y * b.x;
    }
    bool operator <= (const Frac & b) const {
        return x * b.y <= y * b.x;
    }
    bool operator >= (const Frac & b) const {
        return x * b.y >= y * b.x;
    }
    Frac operator - () const {
        return Frac(-x, y);
    }

    friend str ts(Frac f) {
    	return ts(frac(f.x,f.y));
    	// return
    	// return ts(x)+"/"+ts(y)+c;
    }
};
LL xmin[N], ymin[N], zmin[N], xmax[N], ymax[N], zmax[N];
struct P {
    Frac x, y;
    bool operator == (const P & b) const {
        return x == b.x && y == b.y;
    }
    bool operator != (const P & b) const {
        return x != b.x || y != b.y;
    }
    friend str ts(const P& p) {
    	V<Frac> v{p.x,p.y};
    	return ts(v);
    }
    // void print(char c = '\n') {
    //     putchar('(');
    //     x.print(',');
    //     y.print(')');
    //     putchar(c);
    // }
    // void check() {
    // }
};
struct Op {
    LL c, dx, dy;
    //x -> x + c * y + dx, y -> y + dy
    //x + c * y + dx - (y + dy) * c - dx + c * dy = x
    Op() {
        c = dx = dy = 0;
    }
    Op(LL z) {
        c = 1;
        dx = dy = z;
    }
    Op(const LL & c, const LL & dx, const LL & dy) : c(c), dx(dx), dy(dy) {
    }
    Op operator * (const Op & b) const {
        return Op{c + b.c, dx + c * b.dy + b.dx, dy + b.dy};
    }
    Op inv() const {
        return Op{-c, -dx + c * dy, -dy};
    }
    P operator * (const P & b) const {
        return P{b.x + (Frac)c * b.y + dx, b.y + dy};
    }
    bool operator == (const Op & b) const {
        return c == b.c && dx == b.dx && dy == b.dy;
    }
    void print() const {
        printf("op: %lld %lld %lld\n", c, dx, dy);
    }
    void check() {
    }
};

bool collinear(P a, P b, P c) {
	Frac f = (b.y-a.y)*(c.x-a.x)-(b.x-a.x)*(c.y-a.y);
	return f.x == 0;
}

struct Deq {
    deque<P> v;
    deque<Op> op;
    Op u;
    bool empty() {
        return v.empty();
    }
    int size() {
        return v.size();
    }
    P back() {
        return op.back() * v.back();
    }
    P front() {
        return u * v.front();
    }
    P bac() {
        return op.back() * op[size() - 2] * v[size() - 2];
    }
    P fron() {
        return u * op.front().inv() * v[1];
    }
    void push_back(const P & x) {
        v.push_back(x);
        op.push_back(Op());
    }
    void push_front(const P & x) {
        if(!v.empty()) {
            op.push_front(u.inv());
        }else {
            op.push_front(Op());
        }
        u = Op();
        v.push_front(x);
    }
    void pop_back() {
        if(v.size() == 1) {
            v.pop_back(); op.pop_back(); u = Op();
        }else {
            op[v.size() - 2] = op.back() * op[v.size() - 2];
            v.pop_back(); op.pop_back();
        }
    }
    void pop_front() {
        if(v.size() == 1) {
            v.pop_back(); op.pop_back(); u = Op();
        }else {
            u = u * op.front().inv();
            v.pop_front();
            op.pop_front();
        }
    }

    void setback(const P & x) {
        pop_back();
        push_back(x);
/*        if(v.size() >= 2) {
            
            op[v.size() - 2] = op.back() * op[v.size() - 2];
        }else {
            u = Op();
        }
        v.back() = x;
        op.back() = Op();*/
    }
    void setfront(const P & x) {
        pop_front();
        push_front(x);
/*        op.front() = u.inv() * op.front();
        u = Op();
        v.front() = x;*/
    }
    void apply(const Op & z) {        
        if(!op.empty()) {
            u = z * u;
            op.back() = z * op.back();
        }
    }

    friend str ts(const Deq& d) {
		V<P> converted;
		set<int> cands;
		cands.ins(0);
		cands.ins(d.op.size()-1);

		for (int i: cands) {
            P p = d.v[i];
            if (i == 0) p = d.u*p;
            else {
	            for (int j = i; j < d.op.size(); ++j) {
	                p = d.op[j]*p;
	            }
            }
            if (sz(converted) && converted.bk == p) continue;
            // while (sz(converted) > 1 && collinear(converted[sz(converted)-2],converted.bk,p)) 
            // 	converted.pop_back();
            converted.pb(p);
        }
		return ts(converted);
    }
};

pair<bool,vs> solve(int N, vpi X, vpi Y, vpi Z) {
	// dbg("SOLUTION 2");
	n = N;
	FOR(i,1,n+1) {
		xmin[i] = X[i-1].f;
		xmax[i] = X[i-1].s;
	}
	FOR(i,2,n+1) {
		ymin[i] = Y[i-2].f;
		ymax[i] = Y[i-2].s;
	}
	FOR(i,3,n+1) {
		zmin[i] = Z[i-3].f;
		zmax[i] = Z[i-3].s;
	}
    ymin[1] = -L;
    ymax[1] = L;
    zmin[2] = -L;
    zmax[2] = L;

    Deq v[2];
    v[0].v.pb(P{xmin[1], -L});
    v[0].v.pb(P{xmin[1], L});
    v[0].v.pb(P{xmax[1], L});
    v[1].v.pb(P{xmin[1], -L});
    v[1].v.pb(P{xmax[1], -L});
    v[1].v.pb(P{xmax[1], L});

    for(int i = 0; i < 2; i++) {
        v[i].op.resize(v[i].v.size());
    }
    vs rec;
    for(int i = 2; i <= n + 1; i++) {
        if(i == n + 1) break;
        v[0].apply(Op(zmax[i]));
        v[1].apply(Op(zmin[i]));
        if(zmin[i] != zmax[i]) {
            v[0].push_front(v[1].front());
            v[1].push_back(v[0].back());
        }

        for(int d = 0; d < 2; d++) {
            P t1, t2;
            while(!v[d].empty() && (t1 = v[d].back()).y > ymax[i]) {
                if(v[d].size() > 1 && (t2 = v[d].bac()).y <= ymax[i]) {
                    Frac c = (t1.x - t2.x) / (t1.y - t2.y);
                    Frac delta = t1.x - t1.y * c;
                    v[d].setback(P{(Frac)ymax[i] * c + delta, ymax[i]});
                    if(d == 0) {
                        v[d].push_back(P{L, ymax[i]});
                    }
                    break;
                }else {
                    v[d].pop_back();
                }
            }
            while(!v[d].empty() && (t1 = v[d].back()).x > xmax[i]) {
                if(v[d].size() > 1 && (t2 = v[d].bac()).x <= xmax[i]) {
                    Frac c = (t1.y - t2.y) / (t1.x - t2.x);
                    Frac delta = t1.y - t1.x * c;
                    v[d].setback(P{xmax[i], (Frac)xmax[i] * c + delta});
                    if(d == 1) {
                        v[d].push_back(P{xmax[i], L});   
                    }
                    break;
                }else {
                    v[d].pop_back();
                }
            }
            while(!v[d].empty() && (t1 = v[d].front()).y < ymin[i]) {
                if(v[d].size() > 1 && (t2 = v[d].fron()).y >= ymin[i]) {
                    Frac c = (t1.x - t2.x) / (t1.y - t2.y);
                    Frac delta = t1.x - t1.y * c;
                    v[d].setfront(P{(Frac)ymin[i] * c + delta, ymin[i]});
                    if(d == 1) v[d].push_front(P{-L, ymin[i]});
                    break;
                }else {
                    v[d].pop_front();
                }
            }

            while(!v[d].empty() && (t1 = v[d].front()).x < xmin[i]) {
                if(v[d].size() > 1 && (t2 = v[d].fron()).x >= xmin[i]) {
                    Frac c = (t1.y - t2.y) / (t1.x - t2.x);
                    Frac delta = t1.y - t1.x * c;
                    v[d].setfront(P{xmin[i], (Frac)xmin[i] * c + delta});
                    if(d == 0) v[d].push_front(P{xmin[i], -L});
                    break;
                }else {
                    v[d].pop_front();
                }
            }
        }
        if(v[0].empty() || v[1].empty()) {
        	return {0,rec};
        }

        P t[2];
        for(int d = 0; d < 2; d++) {
            t[d] = v[d].back();
        }
        if(t[0].x > t[1].x) t[0].x = t[1].x;
        if(t[1].y > t[0].y) t[1].y = t[0].y;


        /*        tmp = Op();
                  for(int j = v[0].size() - 1; j >= 0; j--) {
                  tmp = tmp * v[0].op[j];
                  }
                  if(i == 9998) {
                  printf("!!%d\n", v[0].size());
                  printf("%lld %lld %lld %lld \n", xmin[i - 1], xmax[i - 1], ymin[i - 1], ymax[i - 1]);
                  printf("%lld %lld %lld %lld \n", xmin[i], xmax[i], ymin[i], ymax[i]);
                  printf("%d %d\n", i, v[0].size());
                  v[0].op.back().print();
                  v[0].op[v[0].size() - 2].print();
                  tmp.print();
                  v[0].u.print();
                  }*/


        v[0].pop_back();

        /*tmp = Op();
          for(int j = v[0].size() - 1; j >= 0; j--) {
            tmp = tmp * v[0].op[j];
        }
        if(i == 9998) {
            printf("!!%d\n", v[0].size());
            printf("%lld %lld %lld %lld \n", xmin[i - 1], xmax[i - 1], ymin[i - 1], ymax[i - 1]);
            printf("%lld %lld %lld %lld \n", xmin[i], xmax[i], ymin[i], ymax[i]);
            printf("%d %d\n", i, v[0].size());
            v[0].op.back().print();
            
            tmp.print();
            v[0].u.print();
        }*/


        v[0].push_back(t[0]);
        v[1].setback(t[1]);
        
        if(t[0] != t[1]) {
            if(t[0].x == t[1].x) {
                v[1].push_back(v[0].back());
            }else if(t[1].y == t[0].y) {
                v[0].push_back(v[1].back());
            }else {
                v[0].push_back(P{t[1].x, t[0].y});
                v[1].push_back(P{t[1].x, t[0].y});
            }
        }
        
        for(int d = 0; d < 2; d++) {
            t[d] = v[d].front();
        }
        if(t[0].y < t[1].y) t[0].y = t[1].y;
        if(t[1].x < t[0].x) t[1].x = t[0].x;
        v[0].setfront(t[0]);
        v[1].setfront(t[1]);
        if(t[0] != t[1]) {
            if(t[0].x == t[1].x) {
                v[0].push_front(v[1].front());
            }else if(t[1].y == t[0].y) {
                v[1].push_front(v[0].front());
            }else {
                v[0].push_front(P{t[0].x, t[1].y});
                v[1].push_front(P{t[0].x, t[1].y});
            }
        }
        // if (flag && (i-1)%1000 == 0) {
    	// rec.pb("UPPER: "+ts(v[0]));
    	// rec.pb("LOWER: "+ts(v[1]));
        // }
        // v[1].print();
        // v[0].print();
    }
    return {1,rec};
}
}

int main() {
	setIO();

	// while (1) {

	// }

	// Tag x{3,4,5}, y{6,7,8};
	// Tag z = x.with_tag(y);
	// dbg(z);
	// dbg(z.with_tag(y.inv())); // {c: 3, delta_x:4, delta_y:5}
	// dbg(z.with_tag(x.inv())); 
	// dbg(undo_front(x,z)); // {c: 6, delta_x:7, delta_y:8}
	// exit(0);

	int TC; re(TC);
	// int TC = 1000000;
	FOR(it,1,TC+1) {
		// dbg("GOING",it);

		int N = mine::rng_int(3,10);
		re(N); 

		vpi X(N), Y(N-1), Z(N-2);
		vi sol(N);
		F0R(i,N) sol[i] = mine::rng_int(-1e7,1e7);
		// X.rsz(N), Y.rsz(N-1), Z.rsz(N-2); 
		F0R(i,N) X[i] = mine::rand_around(sol[i]);
		F0R(i,N-1) Y[i] = mine::rand_around(sol[i+1]-sol[i]);
		F0R(i,N-2) Z[i] = mine::rand_around(sol[i+2]-2*sol[i+1]+sol[i]);

		re(X,Y,Z);

		flag = it == 2 && N == 100000;

		auto a = mine::solve(it,N,X,Y,Z);
		// ps();
		auto b = model::solve(N,X,Y,Z);
		// assert(sz(a.s) == sz(b.s));
		// F0R(i,min(sz(a.s),sz(b.s))) if (a.s[i] != b.s[i]) {
		// 	ps("FAILED",it,i);
		// 	ps(a.s[i]);
		// 	ps(b.s[i]);
		// 	exit(0);
		// }
		// F0R(i,sz(a.rec))
		dbg(a);
		dbg(b);

		// ps();

		// assert(a == b);
		if (a.f) ps("YES");
		else ps("NO");
	}
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/