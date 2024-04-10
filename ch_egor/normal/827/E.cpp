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
#include <complex>

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
const int MAX_LG = (1 << 20);

const double pi = acos(-1.0);

int n, lg, lgn;
char st[MAX_N];
complex<double> arr1[MAX_LG];
complex<double> arr2[MAX_LG];
complex<double> arr3[MAX_LG];
int rev[MAX_LG];
bool good[MAX_LG];
vector<int> ans;

void fft(complex<double> arr[], int invert) 
{
	for (int i = 0; i < lgn; ++i)
	{
		if (i < rev[i])
		{
			swap(arr[i], arr[rev[i]]);
 		}
	}

	double ang;
	complex<double> wlen, v, u, now;
	for (int len = 2; len <= lgn; len <<= 1)
	{
		ang = 2 * pi / len * invert;
		wlen = complex<double>(cos(ang), sin(ang));
		for (int i = 0; i < lgn; i += len) 
		{
			now = 1;
			for (int j = 0; j < (len >> 1); ++j)
			{
				v = arr[i + j];
				u = arr[i + j + (len >> 1)] * now;
				
				arr[i + j] = v + u;
				arr[i + j + (len >> 1)] = v - u;
				
				now *= wlen;
			}
		}
	}
	
	if (invert == -1)
	{
		for (int i = 0; i < lgn; ++i)
		{
			arr[i] /= lgn;
		}
	}
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

	int t;
	scanf("%d", &t);

	while (t--)
	{
		ans.clear();
		
		scanf("%d", &n);
		scanf("%s", st);
		
		lg = 1;
		while ((1 << lg) < n) ++lg;
		++lg;
		lgn = (1 << lg);
		assert(lgn <= MAX_LG);
		
		for (int i = 0; i < lgn; ++i)
		{
			arr1[i] = 0;
			arr2[i] = 0;
			good[i] = true;
		}

		for (int i = 1, j = 0; i < lgn; ++i)
		{
			int bit = lgn >> 1;
			for (; j >= bit; bit >>= 1)
			{
				j -= bit;
			}
			j += bit;
			rev[i] = j;
		}	

		for (int i = 0; i < n; ++i)
		{
			if (st[i] == 'V')
			{
				arr1[i] = 1;
			}
			else if (st[i] == 'K')
			{
				arr2[n - 1 - i] = 1;
			}
		}

		fft(arr1, 1);
		fft(arr2, 1);

		for (int i = 0; i < lgn; ++i)
		{
			arr3[i] = arr1[i] * arr2[i]; 
		}
		fft(arr3, -1);

		for (int i = 0; i < n; ++i)
		{
			if (round(arr3[i].real()) > 0)
			{
				good[n - 1 - i] = false;
			}
		}
		for (int i = n; i < 2 * n; ++i)
		{
			if (round(arr3[i].real()) > 0)
			{
				good[i - (n - 1)] = false;
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = i; j < n; j += i)
			{
				good[i] &= good[j];
			}
			
			if (good[i])
			{
				ans.push_back(i);
			}
		}

		writeInt((int)ans.size());
		writeChar('\n');
		for (int i = 0; i < (int)ans.size(); ++i)
		{
			writeInt(ans[i]);
			writeChar(' ');
		}
		writeChar('\n');
	}

	flush();

	return 0;
}