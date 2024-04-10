/*

Code for problem C by cookiedoth
Generated 27 Nov 2019 at 10.16 P


 ] 
 
Il] 


o_O
-_-
z_z

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

vector<pair<int, int> > dir = {
	{1, 1},
	{1, 0},
	{1, -1},
	{0, 1},
	{0, -1},
	{-1, 1},
	{-1, 0},
	{-1, -1}
};

const int INF = 1e9 + 228;
int n, m;
vector<vector<int> > a, d;
queue<pair<int, int> > q;

void bfs() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[i][j] == 0) {
				q.push({i, j});
			}
		}
	}
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for (auto diff : dir) {
			int i1 = i + diff.first;
			int j1 = j + diff.second;
			if (!(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m)) {
				continue;
			}
			if (d[i1][j1] == INF) {
				d[i1][j1] = d[i][j] + 1;
				q.push({i1, j1});
			}
		}
	}
}

int border_dist(int i, int j) {
	return min(min(i + 1, j + 1), min(n - i, m - j));
}

int check(int x) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i][j] = (a[i][j] ? INF : 0);
		}
	}
	bfs();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (border_dist(i, j) > x && d[i][j] > x) {
				d[i][j] = 0;
			} else {
				d[i][j] = INF;
			}
		}
	}
	bfs();
	int ok = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != (d[i][j] <= x)) {
				ok = 0;
			}
		}
	}
	return ok;
}

signed main() {
	fast_io();
	n = readInt();
	m = readInt();
	a.resize(n, vector<int> (m));
	d.resize(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			c = readChar();
			a[i][j] = (c == 'X');
		}
	}
	int l = 0, r = n + m;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid + 1)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	check(l);
	writeInt(l);
	writeChar('\n');
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			writeChar(d[i][j] == 0 ? 'X' : '.');
		}
		writeChar('\n');
	}
}