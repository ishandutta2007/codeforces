#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt(T x);
inline void writeChar(int x);
inline void writeWord(const char *s);
inline void flush();

/** Read */

static const int buf_size = 4096;

inline int getChar()
{
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar()
{
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt()
{
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

inline void writeChar(int x)
{
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

inline void flush()
{
	if (write_pos)
		fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T>
inline void writeInt(T x)
{
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
}

inline void writeWord(const char *s)
{
	while (*s)
		writeChar(*s++);
}


const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 500 * 1000 + 228;

int n, q;
int arr[MAX_N];
int tree[4 * MAX_N];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void build(int v, int l, int r)
{
	if (r - l == 1)
	{
		tree[v] = arr[l];
	}
	else
	{
		int m = (l + r) >> 1;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);

		tree[v] = gcd(tree[2 * v + 1], tree[2 * v + 2]);
	}
}

void change(int v, int l, int r, int at, int x)
{
	if (at < l || at >= r) return;
	else if (r - l == 1) tree[v] = x;
	else
	{
		int m = (l + r) >> 1;
		change(2 * v + 1, l, m, at, x);
		change(2 * v + 2, m, r, at, x);
		tree[v] = gcd(tree[2 * v + 1], tree[2 * v + 2]);
	}
}

int get_up(int v, int l, int r, int at, int x)
{
	if (r <= at) return r;
	else if (r - l == 1)
	{
		return (tree[v] % x == 0) ? r : l;
	}
	else if (l < at)
	{
		int m = (l + r) >> 1;

		int lf = get_up(2 * v + 1, l, m, at, x);
		if (lf == m) return get_up(2 * v + 2, m, r, at, x);
		else return lf;
	}
	else
	{
		int m = (l + r) >> 1;
		
		if (tree[2 * v + 1] % x == 0) return get_up(2 * v + 2, m, r, at, x);
		else return get_up(2 * v + 1, l, m, at, x);
	}
}

bool get(int l, int r, int x)
{
	int next = get_up(0, 0, n, l, x);
	if (next >= r) return true;
	int g_next = get_up(0, 0, n, next + 1, x);
	return g_next >= r;
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	n = readInt();
	for (int i = 0; i < n; ++i) arr[i] = readInt();

	q = readInt();
	
	build(0, 0, n);
	int type, l, r, x;
	while (q--)
	{
		type = readInt();
		if (type == 1)
		{
			l = readInt() - 1;
			r = readInt();
			x = readInt();
			if (get(l, r, x)) writeWord("YES\n");
			else writeWord("NO\n");
		}
		else
		{
			l = readInt() - 1;
			x = readInt();
			change(0, 0, n, l, x);
		}
	}

	flush();

	return 0;
}