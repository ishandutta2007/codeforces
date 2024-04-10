#include <iostream>
#include <stdio.h>
#include <complex>
#include <memory>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;

namespace fastinput {
	/** Interface */

	template <class T = int> inline T readInt();
	inline long double readDouble();
	inline int readUInt();
	inline int readChar();
	inline void readWord(char *s);
	inline bool readLine(char *s); // do not save '\n'
	inline bool isEof();
	inline int peekChar();
	inline bool seekEof();

	template <class T> inline void writeInt(T x, int len = -1);
	template <class T> inline void writeUInt(T x, int len = -1);
	inline void writeChar(int x);
	inline void writeWord(const char *s);
	inline void writeDouble(long double x, int len = 0);
	inline void flush();

	/** Read */

	static const int buf_size = 4096;

	static char buf[buf_size];
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
		while ('0' <= c && c <= '9')
			x = x * 10 + c - '0', c = getChar();
		return s == 1 ? x : -x;
	}

	inline long double readDouble() {
		int s = 1, c = readChar();
		long double x = 0;
		if (c == '-')
			s = -1, c = getChar();
		while ('0' <= c && c <= '9')
			x = x * 10 + c - '0', c = getChar();
		if (c == '.') {
			c = getChar();
			long double coef = 1;
			while ('0' <= c && c <= '9')
				x += (c - '0') * (coef *= 0.1), c = getChar();
		}
		return s == 1 ? x : -x;
	}

	inline void readWord(char *s) {
		int c = readChar();
		while (c > 32)
			*s++ = (char)c, c = getChar();
		*s = 0;
	}

	inline bool readLine(char *s) {
		int c = getChar();
		while (c != '\n' && c != -1)
			*s++ = (char)c, c = getChar();
		*s = 0;
		return c != -1;
	}

	/** Write */

	static int write_buf_pos = 0;
	static char write_buf[buf_size];

	inline void writeChar(int x) {
		if (write_buf_pos == buf_size)
			fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
		write_buf[write_buf_pos++] = (char)x;
	}

	inline void flush() {
		if (write_buf_pos)
			fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
	}

	template <class T>
	inline void writeInt(T x, int output_len) {
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
	}

	template <class T>
	inline void writeUInt(T x, int output_len) {
		char s[24];
		int n = 0;
		while (x || !n)
			s[n++] = (char)('0' + (char)(x % 10)), x /= 10;
		while (n < output_len)
			s[n++] = '0';
		while (n--)
			writeChar(s[n]);
	}

	inline void writeWord(const char *s) {
		while (*s)
			writeChar(*s++);
	}

	inline void writeDouble(long double x, int output_len) {
		if (x < 0)
			writeChar('-'), x = -x;
		int t = (int)x;
		writeUInt(t), x -= t;
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
}

using namespace fastinput;


vector <pair <int, int> > v;

bool can(int x) {
	//floors are [1..x] [x + 1...2x]
	for (auto lr : v) {
		int f = lr.second;
		int k = lr.first;
		--k, --f;
		if (k / x != f) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	v.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	vector <int> might;
	for (int i = 1; i <= 1000; ++i) {
		if (can(i)) {
			might.push_back(i);
		}
	}
	set <int> ss;
	--n;
	for (auto x : might) {
		ss.insert(n / x);
	}
	if (ss.size() != 1) 
		cout << "-1";
	else
		cout << *ss.begin() + 1;
 	return 0;
}