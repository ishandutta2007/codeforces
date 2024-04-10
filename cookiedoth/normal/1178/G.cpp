/*

Code for problem G by cookiedoth
Generated 09 Aug 2019 at 03.55 P










(@)(@)(@)(@)(@)

~_^
=_=
>_<

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/** Fast input-output */

template <class T = int> inline T readInt();						
inline double readDouble();
inline int readUInt();					 
inline int readChar(); // first non-blank character
inline void readWord(char *s); 
inline bool readLine(char *s); // do not save '\n'
inline bool isEof();
inline int getChar(); 
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt(T x, char end = 0, int len = -1);
inline void writeChar(int x); 
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();

static struct buffer_flusher_t {
	~buffer_flusher_t() {
		flush();
	}
} buffer_flusher;

/** Read */

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
	if (buf_pos == buf_len) {
		buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
		if (buf_pos == buf_len)
			return 1;
	}
	return 0;
}

inline int getChar() { 
	return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() { 
	return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() { 
	int c;
	while ((c = peekChar()) != -1 && c <= 32)
		buf_pos++;
	return c == -1;
}

inline void skipBlanks() {
	while (!isEof() && buf[buf_pos] <= 32U)
		buf_pos++;
}

inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}

inline int readUInt() {
	int c = readChar(), x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	else if (c == '+')
		c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	if (c == '.') {
		c = getChar();
		double coef = 1;
		while ('0' <= c && c <= '9')
			x += (c - '0') * (coef *= 1e-1), c = getChar();
	}
	return s == 1 ? x : -x;
}

inline void readWord(char *s) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline bool readLine(char *s) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
	if (write_buf_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
	write_buf[write_buf_pos++] = x;
}

inline void flush() {
	if (write_buf_pos) {
		fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
		fflush(stdout);
	}
}

template <class T> 
inline void writeInt(T x, char end, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord(const char *s) {
	while (*s)
		writeChar(*s++);
}

inline void writeDouble(double x, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = std::min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = std::min(9, (int)(x + 0.5));
	writeChar('0' + t);
}

const ll BINF = 8e18;
const ld DINF = 8e18;

struct line {
	ld k, b, x;
	line(ld _k, ld _b): k(_k), b(_b), x(-DINF) {}
};

ld intersect(const line &l1, const line &l2) {
	return -(l1.b - l2.b) / (l1.k - l2.k);
}

int better(const line &st_l, const line &l) {
	if (st_l.k == l.k) {
		return (l.b > st_l.b);
	}
	else {
		return intersect(st_l, l) < st_l.x;
	}
}

struct cht {
	cht() {}

	vector<pair<ll, ll> > lines;
	vector<line> st;

	void add_line_to_st(line l) {
		while (!st.empty()) {
			if (better(st.back(), l)) {
				st.pop_back();
			}
			else {
				break;
			}
		}
		if (!st.empty() && st.back().k == l.k) {
			return;
		}
		l.x = (st.empty() ? -DINF : intersect(st.back(), l));
		st.push_back(l);
	}

	void add_line(ll k, ll b) {
		if (k < 0) {
			k = -k;
			b = -b;
		}
		lines.emplace_back(k, b);
		//lines.emplace_back(-k, -b);
	}

	void build() {
		sort(all(lines));
		for (int i = (int)lines.size() - 1; i >= 0; --i) {
			add_line_to_st(line(-lines[i].first, -lines[i].second));
		}
		for (int i = 0; i < lines.size(); ++i) {
			add_line_to_st(line(lines[i].first, lines[i].second));
		}
		lines.clear();
	}

	ll get(ll x) {
		int l = 0, r = (int)st.size() - 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if ((ld)x >= st[mid + 1].x) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		ll res = (ll)((ld)x * st[l].k + st[l].b + 0.5);
		return res;
	}

	void clear() {
		st.clear();
	}
};

struct query {
	int type, v;
	ll x;
	query(int _type, int _v, ll _x): type(_type), v(_v), x(_x) {}
};

const int K = 1000;
const int N = 2e5 + 228;
int n, q, p[N], tin[N], tout[N], timer;
vector<vector<int> > children;
ll a[N], b[N];
vector<query> ask;

void dfs(int v) {
	tin[v] = timer++;
	for (auto v1 : children[v]) {
		dfs(v1);
	}
	tout[v] = timer - 1;
}

void read() {
	n = readInt();
	q = readInt();
	children.resize(n);
	for (int i = 1; i < n; ++i) {
		p[i] = readInt();
		p[i]--;
		children[p[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		a[i] = readInt();
	}
	for (int i = 0; i < n; ++i) {
		b[i] = readInt();
	}
	for (int i = 1; i < n; ++i) {
		b[i] += b[p[i]];
	}
	for (int i = 0; i < q; ++i) {
		int type, v;
		ll x = 0;
		type = readInt();
		v = readInt();
		v--;
		if (type == 1) {
			x = readInt();
		}
		ask.emplace_back(type, v, x);
	}
	dfs(0);
}

ll sum_a[N], mod_a[K + 1];
int type[N], good_cnt;
vector<int> good_v;
vector<cht> hulls;

void init() {
	hulls.resize(K + 1);
}

void precalc(int l, int r) {
	sum_a[0] = a[0];
	for (int i = 1; i < n; ++i) {
		sum_a[i] = sum_a[p[i]] + a[i];
	}
	good_v.push_back(0);
	for (int i = l; i <= r; ++i) {
		good_v.push_back(ask[i].v);
	}
	sort(all(good_v));
	good_v.erase(unique(all(good_v)), good_v.end());
	good_cnt = good_v.size();
	fill(type, type + n, -1);
	for (int i = 0; i < good_v.size(); ++i) {
		type[good_v[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		if (type[i] == -1) {
			type[i] = type[p[i]];
		}
		hulls[type[i]].add_line(b[i], sum_a[i] * b[i]);
	}
	for (int i = 0; i < good_cnt; ++i) {
		hulls[i].build();
	}
}

int upper(int u, int v) {
	return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

void handle_queries(int l, int r) {
	for (int i = l; i <= r; ++i) {
		int v = ask[i].v;
		if (ask[i].type == 1) {
			a[v] += ask[i].x;
			for (int j = 0; j < good_cnt; ++j) {
				if (upper(v, good_v[j])) {
					mod_a[j] += ask[i].x;
				}
			}
		}
		else {
			ll ans = -BINF;
			for (int j = 0; j < good_cnt; ++j) {
				if (upper(v, good_v[j])) {
					chkmax(ans, hulls[j].get(mod_a[j]));
				}
			}
			writeInt(ans);
			writeChar('\n');
		}
	}
}

void clear() {
	good_v.clear();
	for (int i = 0; i < good_cnt; ++i) {
		hulls[i].clear();
	}
	fill(mod_a, mod_a + good_cnt, 0);
}

void process() {
	for (int i = 0; i < q; i += K) {
		int r = min(q - 1, i + K - 1);
		precalc(i, r);
		handle_queries(i, r);
		clear();
	}
}

signed main() {
	cerr << setprecision(5) << fixed;
	fast_io();
	read();
	init();
	process();
}