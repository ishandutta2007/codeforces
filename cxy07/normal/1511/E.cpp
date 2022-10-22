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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, cnt, Ans;
int p2[MAXN], dp[MAXN];
char s[MAXN];
vec<int> s1[MAXN], s2[MAXN];

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
	read(n), read(m);
	p2[0] = 1;
	for(int i = 1; i < MAXN; ++i) p2[i] = p2[i - 1] * 2 % mod;
	s1[0].resize(m + 1), s2[0].resize(m + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		s1[i].resize(m + 1), s2[i].resize(m + 1);
		for(int j = 1; j <= m; ++j) {
			cnt += (s[j] == 'o');
			s1[i][j] = s2[i][j] = (s[j] == 'o');
		}
	}
	dp[2] = dp[3] = 1, dp[4] = 2;
	for(int i = 6; i <= cnt; i += 2) dp[i] = (dp[i - 2] * 4 + 2) % mod;
	for(int i = 5; i <= cnt; i += 2) dp[i] = (dp[i - 2] * 4 + 1) % mod;
	for(int i = 4; i <= cnt; i += 2) dp[i]++;
	for(int i = 1; i <= cnt; ++i) dp[i] = dp[i] * p2[cnt - i] % mod;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s1[i][j]) {
				s1[i][j] += s1[i][j - 1];
				(Ans += dp[s1[i][j]]);
			}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s2[i][j]) {
				s2[i][j] += s2[i - 1][j];
				(Ans += dp[s2[i][j]]) %= mod;
			}
	printf("%lld\n", Ans);
	return 0;
}