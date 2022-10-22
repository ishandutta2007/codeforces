//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
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
#define y1 _y1

const int MAXN = 4010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int dp[MAXN][MAXN], f[MAXN][MAXN];
char s[MAXN], t[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

#define dp(x, i) dp[x][i + n + 1]
#define f(x, i) f[x][i + n + 1]

void solve() {
	read(n); scanf("%s%s", s + 1, t + 1);
	for(int i = 2; i <= n; i += 2) {
		if(s[i] != '?') s[i] = '0' + '1' - s[i];
		if(t[i] != '?') t[i] = '0' + '1' - t[i];
	}
	f(0, 0) = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = -i, ls, rs, lt, rt; j <= i; ++j) {
			ls = (s[i] == '1') ? 1 : 0, rs = (s[i] == '0') ? 0 : 1;
			lt = (t[i] == '1') ? 1 : 0, rt = (t[i] == '0') ? 0 : 1;
			for(int a = ls; a <= rs; ++a)
				for(int b = lt; b <= rt; ++b) {
					if(a == b) {
						(f(i, j) += f(i - 1, j)) %= mod;
						(dp(i, j) += dp(i - 1, j)) %= mod;
					}
					if(a && !b) {
						(f(i, j) += f(i - 1, j - 1)) %= mod;
						(dp(i, j) += dp(i - 1, j - 1) + f(i - 1, j - 1) * (j - 1 < 0 ? i : (mod - i))) %= mod;
					}
					if(!a && b) {
						(f(i, j) += f(i - 1, j + 1)) %= mod;
						(dp(i, j) += dp(i - 1, j + 1) + f(i - 1, j + 1) * (j + 1 > 0 ? i : (mod - i))) %= mod;
					}
				}
		}
	printf("%lld\n", dp(n, 0));
	for(int i = 0; i <= n; ++i)
		for(int j = -i; j <= i; ++j) dp(i, j) = f(i, j) = 0;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}