/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

typedef long long ll;

const int MOD = 1e9 + 7;
inline void add( int &a, int b ) { if ((a += b) >= MOD) a -= MOD; }
inline void sub( int &a, int b ) { if ((a -= b) < 0) a += MOD; }
inline int mul( int a, int b ) { return (ll)a * b % MOD; }

int Euclid( int a, int b, int &x, int &y ) { // a * x + b * y = gcd
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int k = a / b, gcd = Euclid(b, a % b, x, y);
  swap(x, y), y -= k * x;
  return gcd;
}

int Inv( int a ) { // x * a + y * m == 1
  int x, y;
  Euclid(MOD, a, y, x);
  return x < 0 ? x + MOD : x;
}

int Div( int a, int b ) {
  return mul(a, Inv(b));
}

const int C = 1e6 + 3, N = 2e5 + 3;

int cnt[C], f[C], num[N];
vector<int> d[C];

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x );
inline void writeChar( int x ); 
inline void flush();

int main() {
	for (int i = 1; i < C; i++)
		for (int j = i; j < C; j += i)
			cnt[j]++;
	for (int i = 1; i < C; i++)
		d[i].reserve(cnt[i]), cnt[i] = 0;
	for (int i = C; i >= 1; i--)
		for (int j = i; j < C; j += i)
			d[j].push_back(i);
/*
	int ma = 0, su = 0;
	for (int i = 1; i < C; i++)
		ma = max(ma, sz(d[i])), su += sz(d[i]);
	cerr << ma << " " << su << endl;
	for (int i = 1; i < C; i++) {
		su = 0;
		for (int x : d[i])
			su += d[x].size();
		ma = max(ma, su);
	}
	cerr << ma << endl;
	return 0;
*/
	
	int n, k, q, sum = 0, cur_num = 1;
	n = readInt();
	k = readInt();
	q = readInt();
	for (int t = k - 1; t < N; t++) {
		num[t] = cur_num;
		cur_num = Div(mul(cur_num, t + 1), t + 1 - (k - 1));
	}		
	forn(i, n + q) {
		int a = readInt(); 
		for (int x : d[a]) {
			//printf("i = %d, x = %d : cnt = %d of %d\n", i, x, cnt[x], k - 1);
			f[x] = num[cnt[x]++];
		}
		for (int x : d[a])
			for (int y : d[x])
				if (x != y)
					sub(f[y], f[x]);
		for (int x : d[a]) {
			//printf("i = %d, x = %d : f = %d\n", i, x, f[x]);
			add(sum, mul(f[x], x)), f[x] = 0;
		}
		if (i >= n)
			writeInt(sum), writeChar('\n');
	}
	flush();
}

/** Read */

static const int buf_size = 4096;

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

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

inline void flush() {
	if (write_pos)
		fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T> 
inline void writeInt( T x ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
}