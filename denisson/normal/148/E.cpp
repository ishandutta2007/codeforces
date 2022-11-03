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
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;


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

int n, m;
int dp[107][107];
vector<int> a[107];
int pref[107];
int ans[107][100007];

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
	scanf("%d%d", &n, &m);
	forn(i, n) {
		int sz;
		scanf("%d", &sz);
		a[i].resize(sz);
		forn(j, sz)
			scanf("%d", &a[i][j]);
	}
	forn(i, 100005)
		ans[0][i] = -INF;
	ans[0][0] = 0;
	forn(i, n) {
		pref[0] = a[i][0];
		for (int j = 1; j < a[i].size(); j++)
			pref[j] = pref[j - 1] + a[i][j];
		for (int j = 1; j <= a[i].size(); j++) {
			for (int ss = 0; ss <= min(100005, m); ss++)
				ans[j][ss] = ans[0][ss];
			ans[j][0] = 0;
		}
		for (int k = 1; k <= min((int)a[i].size(), 105); k++) {
			for (int s = 0; s <= k; s++) {
				dp[i][k] = max(dp[i][k], (s == 0 ? 0 : pref[s - 1]) + pref[(int)a[i].size() - 1] - 
														pref[(int)a[i].size() - 1 - (k - s)]);
			}
			for (int j = m; j >= 0; j--) {
				if (j - k >= 0) {
					if (ans[k][j - k] != -INF)
						ans[k][j] = max(ans[k][j], ans[k][j - k] + dp[i][k]);
				}
				else 
					break;
			}
		}
		for (int j = 1; j <= a[i].size(); j++)
			for (int ss = 0; ss <= min(100005, m); ss++)
				ans[0][ss] = max(ans[0][ss], ans[j][ss]);
	}
	cout << ans[0][m];
}