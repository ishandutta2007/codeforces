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

const int MAXN = 110;
const int SIZ = 2e4 + 10;
const int INF = 2e16;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, now, pre, sum;
int Ans, D = 10001, val;
int a[MAXN], b[MAXN];
bitset<SIZ> dp[2];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n); Ans = 0; 
	now = 1, pre = 0, sum = 0, val = INF;
	for(int i = 1; i <= n; ++i) read(a[i]), Ans += (n - 2) * a[i] * a[i], sum += a[i];
	for(int i = 1; i <= n; ++i) read(b[i]), Ans += (n - 2) * b[i] * b[i], sum += b[i];
	if(n == 1) return puts("0"), void();
	dp[0].reset(), dp[1].reset(); dp[now].set(D);
	for(int i = 1, d; i <= n; ++i) {
		swap(now, pre); d = abs(a[i] - b[i]);
		dp[now] = (dp[pre] << d) | (dp[pre] >> d);
	}
	for(int i = -10000, A, B; i <= 10000; ++i) {
		if(!dp[now][i + D]) continue;
		A = (sum + i) >> 1, B = (sum - i) >> 1;
		val = min(val, A * A + B * B);
	}
	cout << Ans + val << endl;
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