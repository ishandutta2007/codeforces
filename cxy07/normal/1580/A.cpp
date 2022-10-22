//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 410;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, Ans;
int sum[MAXN], mx[MAXN], cnt[MAXN][MAXN];
char s[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n), read(m); Ans = INF;
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; ++j)
			cnt[i][j] = cnt[i][j - 1] + (s[i][j] == '1');
	} 
	for(int L = 1; L <= m - 3; ++L) {
		for(int R = L + 3, len; R <= m; ++R) {
			len = R - L - 1;
			for(int i = 0; i <= n; ++i) sum[i] = 0, mx[i] = -INF;
			for(int i = 1, cur; i <= n; ++i) {
				cur = cnt[i][R - 1] - cnt[i][L];
				sum[i] = sum[i - 1] + (s[i][L] == '0') + (s[i][R] == '0') + cur;
				mx[i] = max(mx[i - 1], sum[i] - (len - cur));
				if(i >= 5) Ans = min(Ans, sum[i - 1] - mx[i - 4] + (len - cur));
			}
		}
	} printf("%d\n", Ans);
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