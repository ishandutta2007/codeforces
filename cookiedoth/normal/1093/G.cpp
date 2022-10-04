/*

Code for problem G by savkinsd2089
Generated 15 Dec 2018 at 06.08 pm
The Moon is Waxing Gibbous (51% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

^_^
~_^
-_-

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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

#ifndef TESTING
	#define endl '\n'
#endif

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
inline void readWord( char *s ); 
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int getChar(); 
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt( T x, char end = 0, int len = -1 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
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

inline void readWord( char *s ) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline bool readLine( char *s ) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
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
inline void writeInt( T x, char end, int output_len ) {
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

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
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



const int INF = 1e9;

struct st {
	vector<int> t;
	int n, n0;

	st() {}

	void build(int *a, int v, int tl, int tr) {
		if (tl == tr) {
			if (tl < n0) {
				t[v] = a[tl];
			}
		}
		else {
			int tm = (tl + tr) >> 1;
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = max(t[v * 2], t[v * 2 + 1]);
		}
	}

	void build(int *a, int _n) {
		n0 = _n;
		n = 1;
		while (n < n0) {
			n <<= 1;
		}
		t.resize(4 * n);
		build(a, 1, 0, n - 1);
	}

	void update(int pos, int val) {
		pos += n;
		t[pos] = val;
		while (true) {
			pos >>= 1;
			if (pos > 0)
				t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
			else
				break;
		}
	}

	int get(int l, int r) {
		l += n;
		r += n;
		int res = -INF;
		while (l <= r) {
			if (l & 1) {
				chkmax(res, t[l]);
				l++;
				continue;
			}
			if ((r & 1) == 0) {
				chkmax(res, t[r]);
				r--;
				continue;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};

const int mx = 2e5;
const int K = 5;
int n, k, a[mx][K], a2[1 << K][mx];
st t[1 << K];

void build(int pos) {
	for (int i = 0; i < (1 << k); ++i) {
		a2[i][pos] = 0;
		for (int j = 0; j < k; ++j) {
			if ((i >> j) & 1) {
				a2[i][pos] -= a[pos][j];
			}
			else {
				a2[i][pos] += a[pos][j];
			}
		}
	}
}

void upd(int pos) {
	for (int i = 0; i < (1 << k); ++i) {
		t[i].update(pos, a2[i][pos]);
	}
}

int get(int l, int r) {
	int ans = 0;
	int val = (1 << k) - 1;
	//cerr << "get " << l << " " << r << endl;
	/*cerr << "arr" << endl;
	for (int i = 0; i < (1 << k); ++i) {
		output(a2[i], a2[i] + n);
	}*/
	for (int i = 0; i < (1 << (k - 1)); ++i) {
		//cerr << "i = " << i << endl;
		int v1 = t[i].get(l, r);
		//cerr << "v1 = " << v1 << endl;
		int v2 = t[val - i].get(l, r);
		chkmax(ans, v1 + v2);
	}
	return ans;
}

signed main() {
	n = readInt();
	k = readInt();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			a[i][j] = readInt();
		}
	}

	for (int i = 0; i < n; ++i) {
		build(i);
	}

	for (int i = 0; i < (1 << k); ++i) {
		t[i].build(a2[i], n);
	}

	int q;
	q = readInt();
	for (int i = 0; i < q; ++i) {
		int type;
		type = readInt();
		if (type == 1) {
			int pos;
			pos = readInt();
			pos--;
			for (int j = 0; j < k; ++j) {
				a[pos][j] = readInt();
			}
			build(pos);
			upd(pos);
		}
		else {
			int l, r;
			l = readInt();
			r = readInt();
			l--;
			r--;
			writeInt(get(l, r));
			writeChar('\n');
		}
	}
}