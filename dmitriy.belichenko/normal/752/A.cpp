#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
using namespace std;

namespace fastinput
{
	/** Interface */

	inline int readChar();
	template <class T = int> inline T readInt();
	template <class T> inline void writeInt(T x, char end = 0);
	inline void writeChar(int x);
	inline void writeWord(const char *s);

	/** Read */

	static const int buf_size = 16384;

	inline int getChar() {
		static char buf[buf_size];
		static int len = 0, pos = 0;
		if (pos == len)
			pos = 0, len = fread(buf, 1, buf_size, stdin);
		if (pos == len)
			return -1;
		return buf[pos++];
	}

	inline int readChar() {
		int c = getChar();
		while (c <= 32)
			c = getChar();
		return c;
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

	/** Write */

	static int write_pos = 0;
	static char write_buf[buf_size];

	inline void writeChar(int x) {
		if (write_pos == buf_size)
			fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
		write_buf[write_pos++] = x;
	}

	template <class T>
	inline void writeInt(T x, char end) {
		if (x < 0)
			writeChar('-'), x = -x;

		char s[24];
		int n = 0;
		while (x || !n)
			s[n++] = (char)('0' + x % 10), x /= 10;
		while (n--)
			writeChar(s[n]);
		if (end)
			writeChar(end);
	}

	inline void writeWord(const char *s) {
		while (*s)
			writeChar(*s++);
	}

	struct Flusher {
		~Flusher() {
			if (write_pos)
				fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
		}
	} flusher;
}

using namespace fastinput;

int main()
{
	::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	--k;
	int x = k / (2 * m);
	int y = k % (2 * m) / 2;
	if (k % 2 == 0)
		cout << x + 1 << " " << y + 1 << " L";
	else
		cout << x + 1 << " " << y + 1 << " R";
	return 0;
}