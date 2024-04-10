/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back       
#define all(a) (a).begin(), (a).end()

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

typedef pair <int, int> pii;
typedef long long ll;

const int N = 1e5;

int n, M, centroid, color[N], level[N];
int inv10[N + 1], pow10[N + 1];
vector<pii> c[N];

inline int mul( int a, int b ) { return (ll)a * b % M; }
int Euclid( int a, int b, int &x, int &y ) { // a * x + b * y = gcd
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int k = a / b, gcd = Euclid(b, a % b, x, y);
	swap(x, y), y -= k * x;
	return gcd;
}
int Inv( int a ) { // x * a + y * MOD == 1
	int x, y;
	Euclid(M, a, y, x);
	return x < 0 ? x + M : x;
}
int Div( int a, int b ) { return mul(a, Inv(b)); }

vector<int> add;
ll ans;

const int max_size = 3e5 + 7;

struct hashTable {
  int hash[max_size];
  int f[max_size];
  int size, cc, used[max_size];

  hashTable()  { size = 0, cc = 1; }
  void clear() { size = 0, cc++; }

  int position( int H ) const {
    int i = H % max_size;
    while (used[i] == cc && hash[i] != H)
      if (++i == max_size)
        i = 0;
    return i;
  }
  bool count( int H ) const { return hash[position(H)] == H; }

  int & operator [] ( int H ) {
    int i = position(H);
    if (used[i] != cc)
      size++, hash[i] = H, used[i] = cc, f[i] = 0;
    return f[i];
  }
} table;

int get_centroid( int v, int p, int n ) {
	int size = 1;
	for (auto e : c[v]) {
		int x = e.first;
		if (x != p && level[x] == -1)
			size += get_centroid(x, v, n);
	}
	if (centroid == -1 && (size * 2 >= n || p == -1))
		centroid = v;
	return size;
}

void calc( int v, int p, int dep, int x1, int x2 ) {
	add.pb(x2);
	int da = table[mul(M - x1, inv10[dep])];	
	if (da) 
		ans += da;
	for (auto e : c[v]) {
		int x = e.first;
		if (x != p && level[x] == -1) 
			calc(x, v, dep + 1, ((ll)x1 * 10 + e.second) % M, ((ll)e.second * pow10[dep] + x2) % M);
	}
}

void build( int v, int size ) {
	centroid = -1;
	get_centroid(v, -1, size);
	int C = centroid;
	level[C] = 0;
	forn(tmp, 2) {
		table.clear();
		if (!tmp) table[0] = 1;
		for (auto e : c[C]) {
			int x = e.first;
			if (level[x] == -1) {
				add.clear();
				calc(x, C, 1, e.second, e.second);
				for (int value : add)
					table[value] += 1;
			}
		}
		if (tmp) ans += table[0];
		reverse(all(c[C]));
	}
	for (auto e : c[C]) {
		int x = e.first;
		if (level[x] == -1)
			build(x, size / 2);
	}
}

int main() {
	n = readInt();
	M = readInt();
	inv10[0] = pow10[0] = 1;
	inv10[1] = Inv(10), pow10[1] = 10 % M;
	for (int i = 2; i <= n; i++) {
		inv10[i] = mul(inv10[i - 1], inv10[1]);
		pow10[i] = mul(pow10[i - 1], pow10[1]);
	}
	
	forn(i, n - 1) {
		int a = readInt();
		int b = readInt();
		int w = readInt() % M;
		c[a].pb(pii(b, w));
		c[b].pb(pii(a, w));
	}
	
	memset(level, -1, sizeof(level));
	build(0, n);
	writeInt(ans, '\n');
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

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;