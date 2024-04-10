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

const int MAXN = 2e3 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
const int base = 131;

int n, k, Ans;
int dp[3][MAXN][MAXN][2], tmp[3];
int h[3][3][MAXN], pw[MAXN], hp[MAXN];
char s[3][MAXN], p[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int H(int opt, int l, int r) {
	if(l <= r) return (h[opt][1][r] - h[opt][1][l - 1] * pw[r - l + 1] % mod + mod) % mod;
	else return (h[opt][2][r] - h[opt][2][l + 1] * pw[l - r + 1] % mod + mod) % mod;
}

int P(int l, int r) {
	return (hp[r] - hp[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

void modadd(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

void calc() {
	for(int i = 1; i <= 2; ++i) {
		for(int j = 1; j <= n; ++j)
			h[i][1][j] = (h[i][1][j - 1] * base + s[i][j]) % mod;
		for(int j = n; j >= 1; --j)
			h[i][2][j] = (h[i][2][j + 1] * base + s[i][j]) % mod;
	}
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= 2; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int L = j - 1, v, len; L >= 1; --L) {
				len = j - L + 1;
				if((len << 1) > k) break;
				v = (H(i, j, L) * pw[len] + H(3 - i, L, j)) % mod;
				if(v == P(1, len << 1)) dp[3 - i][j][len << 1][1]++;
			}
			if(s[i][j] == p[1]) dp[i][j][1][0]++;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int o = 1; o <= 2; ++o)
			for(int l = 1; l <= k; ++l)
				if(s[o][i] == p[l]) {
					modadd(dp[o][i][l][0], dp[o][i - 1][l - 1][0]);
					modadd(dp[o][i][l][0], dp[o][i - 1][l - 1][1]);
				}
		for(int l = k; l >= 2; --l) {
			if(s[2][i] == p[l]) modadd(dp[2][i][l][1], dp[1][i][l - 1][0]);
			if(s[1][i] == p[l]) modadd(dp[1][i][l][1], dp[2][i][l - 1][0]);
		}
	}
	for(int i = 1; i <= 2; ++i) {
		for(int j = 1; j <= n; ++j) {
			modadd(Ans, dp[i][j][k][0]);
			modadd(Ans, dp[i][j][k][1]);
			/*if(dp[i][j][k][0] || dp[i][j][k][1]) {
				printf("dp[%d][%d][%d][%d] = %d\n", i, j, k, 0, dp[i][j][k][0]);
				printf("dp[%d][%d][%d][%d] = %d\n", i, j, k, 1, dp[i][j][k][1]);
			}*/
			for(int R = j + 1, len, v; R <= n; ++R) {
				len = R - j + 1;
				if((len << 1) > k) break;
				v = (H(i, j, R) * pw[len] + H(3 - i, R, j)) % mod;
				if(v == P(k - (len << 1) + 1, k)) {
					modadd(Ans, dp[i][j - 1][k - (len << 1)][0]);
					modadd(Ans, dp[i][j - 1][k - (len << 1)][1]);
				}
			}
		}
	}
}

signed main () {
#ifdef FILE
	freopen("CF613E.in", "r", stdin);
	freopen("CF613E.out", "w", stdout);
#endif
	scanf("%s%s%s", s[1] + 1, s[2] + 1, p + 1);
	n = strlen(s[1] + 1), k = strlen(p + 1);
	pw[0] = 1; for(int i = 1; i < MAXN; ++i) pw[i] = pw[i - 1] * base % mod;
	for(int i = 1; i <= k; ++i) hp[i] = (hp[i - 1] * base + p[i]) % mod;
	calc();
	if(k > 1) {
		for(int i = 1; i <= 2; ++i) reverse(s[i] + 1, s[i] + n + 1);
		calc();
		if(k == 2) {
			for(int i = 1; i <= n; ++i) {
				if(p[1] == s[1][i] && p[2] == s[2][i]) Ans--;
				if(p[1] == s[2][i] && p[2] == s[1][i]) Ans--;
			}
			Ans = (Ans + mod) % mod;
		}
	}
	printf("%lld\n", Ans);
	return 0;
}