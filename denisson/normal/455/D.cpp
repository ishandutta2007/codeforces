#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/


/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

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

/** Example */


const int magic = 5000;

int n, m;
int a[100007];
int s[100][100007];
int was[100][110007];
pair<int, int> uk[100];
int mm[1000007];
int mm2[1000007];
bool can[1000007];

void build() {
	for (int i = 0; i < 100; i++)
		uk[i].XX = 50000, uk[i].YY = 50000;
	for (int i = 0; i < n; i++) {
		int v = mm2[i];
		s[v][uk[v].YY++] = a[i];
		was[v][a[i]]++;
	}
}

void rebuild() {
	int ss = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = uk[i].XX; j < uk[i].YY; j++)
			a[ss++] = s[i][j];
		memset(was[i], 0, sizeof(was[i]));
	}
	build();
}

int getha(int k) {
	int v = mm2[k];
	int need = mm[k];
	return s[v][uk[v].XX + need];
}

int get(int l, int r, int k) {
	int ans = 0;
	for (int i = l; i <= r; ) {
		int v = mm2[i];
		int need = mm[i];
		int sz = uk[v].YY - uk[v].XX;
		if (need == 0 && (i + sz - 1) <= r) {
			i = i + sz;
			ans += was[v][k];
			continue;
		}
		if (getha(i) == k)
			ans++;
		i++;
	}
	return ans;
}

void sd(int l, int r) {
	int x = getha(r);
	while (mm2[l] != mm2[r]) {
		int v = mm2[r];
		int need = mm[r];
		was[v][s[v][uk[v].XX + need]]--;
		was[v][s[v - 1][uk[v - 1].YY - 1]]++;
		if (need == magic - 1) {
			uk[v].YY--, uk[v].XX--, s[v][uk[v].XX] = s[v - 1][uk[v - 1].YY - 1];
			r -= magic;
			continue;
		}
		for (int i = uk[v].XX + need; i >= uk[v].XX; i--, r--) {
			if (i == uk[v].XX) {
				s[v][i] = s[v - 1][uk[v - 1].YY - 1];
			} else {
				s[v][i] = s[v][i - 1];
			}
		}
	}
	int v = mm2[l];
	int need1 = mm[l];
	int need2 = mm[r];
	was[v][s[v][uk[v].XX + need2]]--;
	was[v][x]++;
	for (int i = uk[v].XX + need2; i > uk[v].XX + need1; i--)
		s[v][i] = s[v][i - 1];
	s[v][uk[v].XX + need1] = x;
}

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("just.in", "r", stdin);
        //freopen("just.out","w", stdout);
    }
	for (int i = 0; i < 1000007; i++)
		mm[i] = i % magic, mm2[i] = i / magic, can[i] = ((i % 40000) == 0);
	n = readInt();
	for (int i = 0; i < n; i++)
		a[i] = readInt();
	build();
	m = readInt();
	int last = 0;
	int pp = 1;
	for (int it = 0; it < m; it++) {
		if (can[pp])
			rebuild();
		int type, l, r;
		type = readInt();
		l = readInt();
		r = readInt();
		l = (l + last - 1);
		if (l >= n)
			l -= n;
		r = (r + last - 1);
		if (r >= n)
			r -= n;
		if (l > r)
			swap(l, r);
		if (type == 1) {
			sd(l, r);
			pp++;
		} else {
			int k;
			k = readInt();
			k = (k + last - 1);
			if (k >= n)
				k -= n;
			k++;
			last = get(l, r, k);
			writeInt(last, '\n');
		}
		//rebuild();
	}
}