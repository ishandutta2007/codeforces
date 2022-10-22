//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
#define min(a, b) (a < b ? a : b)
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 5e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, cr, cb, sum;
int buk[1010], f[1010];
char s[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	a *= f; return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	cr = cb = 0; read(n); sum = 0;
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i) {
		cr += (s[i] == 'R');
		cb += (s[i] == 'B');
	}
	if(cr > cb) return puts("Alice"), void();
	if(cb > cr) return puts("Bob"), void();
	for(int L = 1, R, d; L <= n; L = R + 1) {
		R = L;
		while(R < n && s[R] != s[R + 1]) ++R;
		d = R - L + 1;
		if(d <= 1000) sum ^= f[d];
		else sum ^= f[d % 34 + 34 * 3];
	}
	puts(sum ? "Alice" : "Bob");
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	f[1] = f[0] = 0;
	for(int i = 2; i <= 1000; ++i) {
		for(int j = 0; j + 2 <= i; ++j)
			buk[f[j] ^ f[i - j - 2]] = true;
		while(buk[f[i]]) ++f[i];
		memset(buk, 0, sizeof buk);
	}
	while(T--) solve();
	return 0;
}