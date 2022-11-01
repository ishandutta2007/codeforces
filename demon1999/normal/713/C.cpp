#include <bits/stdc++.h>
    /** Interface */

inline int readChar();
template <class T = int> inline T getInt(); 

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
inline T getInt() {
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

using namespace std;
 
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
 
const ll mod = int(1e9) + 7, szz = 2 * 1024 * 1024;
 
int get_int() {
	int k;
	scanf("%d", &k);
	re k;
}

ll n, dp[3000][3000], qq[3000][3000];
vector<ll> a;


int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	a.resize(n);
	forn (i, n) cin >> a[i];
	forn (i, n) {
		forn (j, n) {
			qq[i][j] = a[j] + i - j;
		}
		sort(qq[i], qq[i] + n);
	}
	forn (i, n) {
		dp[0][i] = abs(a[0] - qq[0][i]);
		if (i) dp[0][i] = min(dp[0][i], dp[0][i - 1]);
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int nu = (lower_bound(qq[i - 1], qq[i - 1] + n, qq[i][j]) - qq[i - 1]) - 1;
			dp[i][j] = mod * mod;
			if (nu >= 0)
				dp[i][j] = dp[i - 1][nu] + abs(qq[i][j] - a[i]);
			if (j > 0)
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
	}
	cout << dp[n - 1][n - 1] << "\n";
	re 0;
}