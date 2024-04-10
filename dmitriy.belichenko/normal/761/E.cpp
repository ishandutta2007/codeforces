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

vector <int> g[N];

long long location[N][2];

long long cur[2] = { 0LL, 0LL };
long long dirx[4] = { -1, 0, 1, 0 };
long long diry[4] = { 0, 1, 0, -1 };
long long step = 1LL << 30;

void dfs(int v, int p = -1, int dirfrom = -1)
{
	location[v][0] = cur[0];
	location[v][1] = cur[1];
	vector <int> havedirs;
	for (int i = 0; i < 4; ++i)
		if (i != dirfrom)
			havedirs.push_back(i);
	int id = 0;
	for (int i = 0; i < g[v].size(); ++i)
	{
		if (g[v][i] == p)
			continue;
		int dir = havedirs[id++];

		cur[0] += dirx[dir] * step;
		cur[1] += diry[dir] * step;
		step >>= 1;

		dfs(g[v][i], v, (dir + 2) % 4);

		step <<= 1;
		cur[0] -= dirx[dir] * step;
		cur[1] -= diry[dir] * step;
	}
}

int main()
{
	int n;
	n = readInt();
	for (int i = 0; i < n - 1; ++i)
	{
		int a = readInt(), b = readInt();
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		if (g[i].size() > 4)
		{
			writeWord("NO\n");
			return 0;
		}
	dfs(rand() % n);
	writeWord("YES\n");
	for (int i = 0; i < n; ++i)
		writeInt(location[i][0], ' '),
		writeInt(location[i][1], '\n');

	return 0;
}