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

const int N = 100;
const int CNT = 62;
const long long INF = 1LL << 62;

long long dp2[N][CNT]; //minimal number to get here
string k;
long long base;

long long parsenum(int x, int y)
{
	long long cur = 0;
	for (int i = x; i <= y; ++i)
		cur *= 10,
		cur += k[i] - '0';
	return cur;
}

long long dp(int len, int cnt)
{
	if (len == -1 && cnt == 0)
		return 0;
	if (cnt == 0)
		return -1;
	if (dp2[len][cnt] != -2)
		return dp2[len][cnt];
	long long mx = -1;
	for (int j = max(0, len - 10); j <= len; ++j)
	{
		long long number = parsenum(j, len);
		if (k[j] == '0' && number != 0)
			continue;
		if (number == 0 && len != j)
			continue;
		if (number < base)
			if (dp(j - 1, cnt - 1) != -1)
			{
				long long val = dp(j - 1, cnt - 1);
				if ((INF - number) / base < val)
					val = INF;
				else
					val = val * base + number;
				if (mx == -1 || mx > val)
					mx = val;
			}
	}
	return dp2[len][cnt] = mx;
}

int main()
{
	cin >> base;
	cin >> k;
	int n = k.length();
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < CNT; ++j)
			dp2[i][j] = -2;
	for (int i = 1; i <= n; ++i)
	{
		long long value = dp(n - 1, i);
		if (value != -1)
		{
			cout << value << endl;
			return 0;
		}
	}
	return 0;
}