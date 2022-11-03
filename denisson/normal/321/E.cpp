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
#include <cassert>
 
using namespace std;
 
typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
 
const ll P = 353251;
const ll P1 = 239017;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

//
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
//

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


int n, k;
int a[4007][4007];
int func[4007][4007];
int dp[807][4007];
int sl;

void dfs(int vl, int vr, int l, int r) {
	if (vl > vr)
		return;
	int v = (vr + vl) / 2;
	int now2;
	for (int i = l; i <= min(v, r); i++) {
		int now = dp[sl - 1][i] + func[i + 1][v];
		if (now <= dp[sl][v])
			now2 = i, dp[sl][v] = now;
	}
	dfs(vl, v - 1, l, now2);
	dfs(v + 1, vr, now2, r);
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	}
	forn(i, 805)
		forn(j, 4005)
			dp[i][j] = INF;
	scanf("%d%d", &n, &k);
	forn(i, n) {
		forn(j, n) {
			char ch;
			while (ch = getChar(), (ch < '0' || ch > '9'))
				;
			a[i][j] = ch - '0';
			if (j > 0)
				a[i][j] += a[i][j - 1];
		}
	}
	for (int len = 2; len <= n; len++)
		for (int l = 0; ; l++) {
			int r = l + len - 1;
			if (r >= n)
				break;
			func[l][r] = func[l][r - 1] + a[r][r] - (l == 0 ? 0 :a[r][l - 1]);
		}
	forn(i, n)
		dp[1][i] = func[0][i];

	for (sl = 2; sl <= k; sl++) {
		dfs(sl - 1, n - 1, 0, n - 1);
	}
	printf("%d", dp[k][n - 1]);
}