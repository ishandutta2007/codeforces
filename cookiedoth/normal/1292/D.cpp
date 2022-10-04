/*

Code for problem D by cookiedoth
Generated 19 Jan 2020 at 05.39 P



10%

30%

50%

70%

100%

z_z
>_<
\_()_/

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
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

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

//!!!
const int MX = 5010;
const int PP = 700;
vector<int> primes;
int f[MX + 1][PP], P, n, cnt[MX + 1], v[PP], alive[MX + 1];

void find_primes() {
	for (int i = 2; i <= MX; ++i) {
		int ok = 1;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			primes.push_back(i);
		}
	}
	P = primes.size();
}

void factorize(int x) {
	for (int i = 0; i < primes.size(); ++i) {
		int y = x, cnt = 0;
		while (y % primes[i] == 0) {
			y /= primes[i];
			cnt++;
		}
		f[x][i] = f[x - 1][i] + cnt;
	}
}

void build_f() {
	for (int i = 1; i <= MX; ++i) {
		factorize(i);
	}

	// cerr << "f" << endl;
	// for (int i = 0; i <= MX; ++i) {
	// 	for (int j = 0; j < P; ++j) {
	// 		cerr << f[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }
}

void read() {
	n = readInt();
	for (int i = 0; i < n; ++i) {
		int x;
		x = readInt();
		cnt[x]++;
	}

	// cerr << "cnt" << endl;
	// output(cnt, cnt + MX + 1);
}

void find_v() {
	fill(alive, alive + MX + 1, 1);
	for (int i = P - 1; i >= 0; --i) {
		while (true) {
			v[i]++;
			int ch_cnt = 0;
			for (int j = 0; j <= MX; ++j) {
				if (alive[j] && v[i] <= f[j][i]) {
					ch_cnt += cnt[j];
				}
			}
			if (2 * ch_cnt < n) {
				v[i]--;
				break;
			}
			for (int j = 0; j <= MX; ++j) {
				if (v[i] > f[j][i]) {
					alive[j] = 0;
				}
			}
		}
		for (int j = 0; j <= MX; ++j) {
			if (v[i] != f[j][i]) {
				alive[j] = 0;
			}
		}
	}

	// cerr << "v" << endl;
	// output(v, v + P);
}

ll ans;

void calc_ans() {
	for (int i = 0; i <= MX; ++i) {
		int res = 0;
		for (int j = P - 1; j >= 0; --j) {
			if (v[j] != f[i][j]) {
				res += abs(v[j] - f[i][j]);
				for (int x = 0; x < j; ++x) {
					res += v[x] + f[i][x];
				}
				break;
			}
		}
		ans += (ll)res * (ll)cnt[i];
	}
}

signed main() {
	fast_io();
	find_primes();
	build_f();
	read();
	find_v();
	calc_ans();
	cout << ans << endl;
}