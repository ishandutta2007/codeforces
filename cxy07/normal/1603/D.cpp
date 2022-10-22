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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, k;
int phi[MAXN], sumphi[MAXN], pr[MAXN], cnt;
int sum1[MAXN][320], sum2[MAXN][320], lim[MAXN];
int dp[20][MAXN];
bool np[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void sieve(int siz) {
	phi[1] = 1;
	for(int i = 2; i <= siz; ++i) {
		if(!np[i]) { pr[++cnt] = i; phi[i] = i - 1; }
		for(int j = 1; j <= cnt && i * pr[j] <= siz; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) { phi[i * pr[j]] = phi[i] * pr[j]; break; }
			phi[i * pr[j]] = phi[i] * phi[pr[j]];
		}
	}
	for(int i = 1; i <= siz; ++i) sumphi[i] = sumphi[i - 1] + phi[i];
	for(int r = 1; r <= siz; ++r) {
		for(int i = 1; i * i <= r; ++i) {
			sum1[r][i] = sum1[r][i - 1] + (r / i - r / (i + 1)) * sumphi[i];
			lim[r] = i;
		} sum2[r][r / (lim[r] + 1) + 1] = sum1[r][lim[r]];
		for(int i = r / (lim[r] + 1); i; --i)
			sum2[r][i] = sum2[r][i + 1] + sumphi[r / i];
	}
}

int c(int l, int r) {
	if(l > r) return INF;
	if(r / l <= lim[r]) return sum1[r][r / l] - sumphi[r / l] * (l - 1 - r / (r / l + 1));
	else return sum2[r][l];
}

void solve(int x, int l, int r, int L, int R) {
	if(l > r) return;
	int mid = (l + r) >> 1, b = 0, pos = -1;
	for(int i = L, v; i <= min(mid - 1, R); ++i) {
		v = dp[x - 1][i] + c(i + 1, mid);
		if(pos == -1 || b > v) pos = i, b = v;
	} dp[x][mid] = b;
	solve(x, l, mid - 1, L, pos);
	solve(x, mid + 1, r, pos, R);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T); sieve(1e5);
	for(int i = 1; i <= (int)1e5; ++i) dp[1][i] = c(1, i);
	for(int i = 2; i <= 17; ++i) solve(i, 1, 1e5, 0, 1e5);
	while(T--) {
		read(n), read(k);
		if(k > 17) printf("%lld\n", n);
		else printf("%lld\n", dp[k][n]);
	}
	return 0;
}