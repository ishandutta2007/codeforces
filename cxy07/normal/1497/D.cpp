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

const int MAXN = 5010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, mx[3], mn[3];
int dp[MAXN], tag[MAXN], s[MAXN], tmp[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n); memset(dp, 0, sizeof(int) * (n + 5));
	for(int i = 1; i <= n; ++i) read(tag[i]);
	for(int i = 1; i <= n; ++i) read(s[i]);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < i; ++j) tmp[j] = 0;
		for(int j = 1; j < i; ++j) 
			if(tag[i] ^ tag[j]) tmp[j] = dp[j] + abs(s[i] - s[j]), dp[i] = max(dp[i], tmp[j]);
		for(int j = i - 1, val = 0; j >= 1; --j) {
			if(tag[j] ^ tag[i]) dp[j] = max(dp[j], val + abs(s[i] - s[j]));
			val = max(val, tmp[j]);
		}
	} printf("%lld\n", *max_element(dp + 1, dp + n + 1));
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