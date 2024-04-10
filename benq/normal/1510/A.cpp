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

int width(const vs& v) {
	if (!sz(v)) return 0;
	assert(sz(v));
	return sz(v[0]);
}

void output_vec(vs v, bool b = 0) {
	if (b) {
		ps(sz(v),sz(v[0]));
		each(t,v) ps(t);
		dbg("----");
	}
}


vs parse_term(str s);
vs parse_atom(str s);

vs pad_left(vs v, int pad) {
	vs res(sz(v),str(sz(v[0])+pad,' '));
	F0R(i,sz(v)) {
		F0R(j,sz(v[0])) res[i][j+pad] = v[i][j];
	}
	return res;
}

vs pad_right(vs v, int pad) {
	vs res(sz(v),str(sz(v[0])+pad,' '));
	F0R(i,sz(v)) {
		F0R(j,sz(v[0])) res[i][j] = v[i][j];
	}
	return res;
}

vs pad_top(vs v, int pad) {
	rep(pad) v.ins(begin(v),str(width(v),' '));
	return v;
}

vs pad_bottom(vs v, int pad) {
	rep(pad) v.pb(str(width(v),' '));
	return v;
}

void concat(vs& a, vs b) {
	if (!sz(a)) {
		a = b;
		return;
	}
	while (width(a) < width(b)) a = pad_right(a,1);
	while (width(b) < width(a)) b = pad_right(b,1);
	each(t,b) a.pb(t);
}

void concat_hor(vs& a, vs b) {
	if (!sz(a)) {
		a = b;
		return;
	}
	while (sz(a) < sz(b)) a.pb(str(width(a),' '));
	while (sz(b) < sz(a)) b.pb(str(width(b),' '));
	F0R(i,sz(b)) a[i] += b[i];
}


vs parse_expr(str s) {
	dbg("PARSE EXPR",s);
	int paren = 0;
	str so_far;
	vs tokens;
	for (char c: s) {
		if (c == '|') {
			if (paren == 0) {
				tokens.pb(so_far);
				so_far = "";
			} else {
				so_far += '|';
			}
			continue;
		}
		so_far += c;
		if (c == '(') {
			++paren;
		} else if (c == ')') {
			--paren;
		}
	}
	tokens.pb(so_far);
	dbg("PARSE EXPR TOKENS",tokens);
	if (sz(tokens) == 1) {
		return parse_term(tokens[0]);
	}
	V<vs> res;
	// int h = -1, w = 0;
	vs ans;
	vi start;
	each(t,tokens) {
		if (sz(ans)) ans = pad_bottom(ans,1);
		start.pb(sz(ans));
		res.pb(parse_term(t));
		concat(ans,res.bk);
	}
	ans = pad_left(ans,3);
	ans = pad_right(ans,3);
	each(t,start) ++t;
	// int w = width(ans);
	FOR(i,start.ft,start.bk+1) ans[i][0] = ans[i].bk = '|';
	F0R(i,sz(start)) {
		int j = start[i];
		dbg("STARTED",j);
		ans[j][0] = ans[j].bk = '+';
		ans[j][1] = ans[j][sz(ans[j])-3] = '-';
		ans[j][2] = ans[j][sz(ans[j])-2] = '>';
		for (int cur = sz(ans[j])-4; cur >= 0; --cur) {
			if (ans[j][cur] != ' ') break;
			ans[j][cur] = '-';
		}
	}
	output_vec(ans);
	return ans;
}

bool is_rep(char c) {
	return c == '+' || c == '?' || c == '*';
}

vs make(int x, int y) {
	assert(x > 0 && y > 0);
	return vs(x,str(y,' '));
}

vs box_around_str(str s) {
	vs v = make(3,sz(s)+4);
	F0R(j,sz(v[0])) v[0][j] = v[2][j] = '-';
	F0R(i,3) v[i].ft = v[i].bk = '+';
	F0R(i,sz(s)) v[1][i+2] = s[i];
	return v;
}

vs parse_term(str s) {
	dbg("PARSE TERM",s);
	int ind = 0;
	vs tokens;
	while (ind < sz(s)) {
		if ('A' <= s[ind] && s[ind] <= 'Z') {
			str tmp; tmp += s[ind];
			tokens.pb(tmp);
			ind ++;
		} else {
			assert(s[ind] == '(');
			int paren = 1; ++ind;
			str expr = "(";
			for(;paren > 0;++ind) {
				expr += s[ind];
				if (s[ind] == '(') ++paren;
				else if (s[ind] == ')') --paren;
			}
			assert(expr.bk == ')');
			tokens.pb(expr);
		}
		while (ind < sz(s) && is_rep(s[ind])) {
			tokens.bk += s[ind];
			++ind;
		}
	}
	// dbg("TERM",s,tokens);
	// // exit(0);
	// auto all_sing = [&]() {
	// 	each(t,tokens) if (sz(t) != 1) return 0;
	// 	return 1;
	// };
	vs _tokens; swap(tokens,_tokens);
	for (int i = 0; i < sz(_tokens); ) {
		if (sz(_tokens[i]) > 1) {
			tokens.pb(_tokens[i]);
			++i;
			continue;
		}
		str tmp;
		for (;i < sz(_tokens) && sz(_tokens[i]) == 1;++i) {
			tmp += _tokens[i];
		}
		tokens.pb(tmp);
	}
	// if (all_sing()) {
	// 	str todo; each(t,tokens) todo += t[0];
	// 	return box_around_str(todo);
	// }
	vs v;
	each(t,tokens) {
		if (sz(v)) {
			v = pad_right(v,2);
			v[1][width(v)-2] = '-';
			v[1][width(v)-1] = '>';
		}
		concat_hor(v,parse_atom(t));
		dbg("INTERMEDIATE");
		output_vec(v);
	}
	dbg("PARSE TERM RESULT",s);
	output_vec(v);
	return v;
	// exit(0);
}

vs add_plus(vs res) {
	res = pad_left(res,3);
	res = pad_right(res,3);
	res = pad_bottom(res,2);
	res[1][2] = '>';
	res[1][1] = '-';
	res[1][0] = '+';
	int x = 2;
	while (x < sz(res)) {
		res[x][0] = '|';
		++x;
	}
	--x;
	res[x][0] = '+';
	res[x][1] = '<';
	int y = 2;
	while (y < width(res)) {
		res.bk[y] = '-';
		++y;
	}
	--y;
	res.bk[y] = '+';
	x = sz(res)-1;
	while (x > 1) {
		-- x;
		res[x].bk = '|';
	}
	res[x].bk = '+';
	res[x][width(res)-2] = '>';
	res[x][width(res)-3] = '-';
	return res;
}

vs add_question(vs res) {
	res = pad_left(res,3);
	res = pad_right(res,3);
	res = pad_top(res,2);
	res[3][0] = res[3].bk = '+'; 
	res[3][1] = res[3][sz(res[3])-3] = '-'; 
	res[3][2] = res[3][sz(res[3])-2] = '>';

	R0F(i,3) res[i][0] = res[i].bk = '|';

	res[0][0] = '+';
	FOR(i,1,width(res)) res[0][i] = '-';
	res[0][width(res)-2] = '>';
	res[0].bk = '+';
	res = pad_top(res,1);
	return res;
}

vs add_wild(vs res) {
	res = add_question(res);
	// output_vec(res,1);
	res = pad_bottom(res,2);

	int x = 5;
	while (x < sz(res)) {
		res[x][0] = '|';
		++x;
	}
	--x;
	res[x][0] = '+';
	res[x][1] = '<';
	int y = 2;
	while (y < width(res)) {
		res.bk[y] = '-';
		++y;
	}
	--y;
	res.bk[y] = '+';
	x = sz(res)-1;
	while (x > 5) {
		-- x;
		res[x].bk = '|';
	}
	// output_vec(res,1);
	return res;
}

vs parse_atom(str s) {
	if ('A' <= s.bk && s.bk <= 'Z') {
		return box_around_str(s);
	}
	// assert(sz(s) > 1);
	vs res;
	int nex;
	if (s[0] == '(') {
		int ind = sz(s)-1; while (s[ind] != ')') --ind;
		res = parse_expr(str(begin(s)+1,begin(s)+ind));
		nex = ind+1;
	} else {
		assert('A' <= s[0] && s[0] <= 'Z');
		str only; only += s[0];
		res = box_around_str(only);
		nex = 1;
	}
	for(;nex < sz(s);++nex) {
		char c = s[nex];
		if (c == '+') {
			res = add_plus(res);
		} else if (c == '?') {
			res = add_question(res);
		} else {
			assert(c == '*');
			res = add_wild(res);
		}
	}
	dbg("DONE TERM");
	output_vec(res);
	// exit(0);
	return res;
}

int main() {
	setIO();
	str inp; re(inp);
	vs v = parse_expr(inp);
	v = pad_left(v,3);
	v = pad_right(v,3);
	v[1][0] = 'S';
	v[1][1] = '-';
	v[1][2] = '>';
	v[1][sz(v[0])-3] = '-';
	v[1][sz(v[0])-2] = '>';
	v[1][sz(v[0])-1] = 'F';
	output_vec(v,1);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/