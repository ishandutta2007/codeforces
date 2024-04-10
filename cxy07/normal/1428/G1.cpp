//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int q, n, k, F[6];
int dp[MAXN], c[MAXN], w[MAXN], cnt = 0;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(k);
	for(int i = 0, tmp, ten = 3; i <= 5; ++i) {
		read(F[i]); tmp = 3 * (k - 1);
		while(tmp) {
			for(int j = 1; j <= tmp; j <<= 1) {
				++cnt; c[cnt] = j * ten, w[cnt] = F[i] * j;
				tmp -= j;
			}
		}
		ten *= 10;
	}
	memset(dp, -0x3f, sizeof dp); dp[0] = 0;
	for(int j = 1; j <= cnt; ++j)
		for(int i = 999999; i >= c[j]; --i)
			dp[i] = max(dp[i], dp[i - c[j]] + w[j]);
	for(int i = 0, ten = 1; i <= 5; ++i) {
		for(int v = 999999; v; --v) {
			for(int s = 0, w; s <= 9; ++s) {
				if(v < s * ten) break;
				w = (s % 3) ? 0 : (s / 3) * F[i];
				dp[v] = max(dp[v], dp[v - s * ten] + w);
			}
		}
		ten *= 10;
	}
	read(q);
	while(q--) {
		int x; read(x);
		printf("%lld\n", dp[x]);
	}
	return 0;
}