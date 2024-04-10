
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<cassert>
using namespace std;
typedef long long ll;
typedef long double ld;

inline int readChar();
inline int readInt();
template <class T> inline void writeInt( T x );
inline void writeChar( int x );
inline void writeWord( const char *s );
inline void flush();

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

inline int readInt() {
  int s = 1, c = readChar();
  int x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

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

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define x first
#define y second
#define mp(a, b) make_pair(a, b)

typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define fi first
#define se second

const int sz1 = 700, ma = 1000010;

int n;
int ans[ma], ak[ma], npos[ma], segtr[ma];
pair<pair<int, int>, int> que[ma];

pair<int, int> a[ma]; 

int gc() {
	int k;
	scanf("%d", &k);
	re k;
}

inline void add(int x, int k) {
	while (x <= n) {
		segtr[x] ^= k;
		x = (x | (x + 1));
	}
}

int get_ans(int x) {
	int ans = 0;
	while (x > 0) {
		ans ^= segtr[x];
		x = (x & (x + 1)) - 1;
	}
	re ans;
}

int get_ans(int l, int r) {
	re (get_ans(l)^get_ans(r));
}


int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	n = readInt();
	forn (i, n) {
		a[i].fi = readInt();
		ak[i] = a[i].fi;
		add(i + 1, a[i].fi);
		a[i].se = i + 1;
	}
	sort(a, a + n);
	int k = 0;
	forn (i, n + 1)
		npos[i] = n + 1;
	forn (i, n) {
		if (i == 0 || a[i].fi != a[i - 1].fi) {
			add(a[i].se, a[i].fi);
		}
		if (i && a[i].fi == a[i - 1].fi)
			npos[a[i - 1].se] = a[i].se;
	}
	int m;
	m = readInt();
	forn (i, m) {
		int a = readInt(), b = readInt();
		a--;
		que[i] = mp(mp(a, b), i);
	}
	sort(que, que + m);
	int l = 1;
	forn (i, m) {
		while (l <= que[i].fi.fi) {
			int num = npos[l], k = ak[l - 1];
			int nu = l;
			add(l, k);
			if (npos[l] <= n) 
				add(npos[l], k);
			l++;
		}
		ans[que[i].se] = get_ans(que[i].fi.fi, que[i].fi.se);
	}
	forn (i, m) {
		writeInt(ans[i]);
		writeChar('\n');
	}////
	flush();
	re 0;
}