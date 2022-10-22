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

const int MAXN = 20;
const int SIZ = (1 << 18) + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, U;
int G[MAXN][MAXN];
int dp[SIZ][MAXN], f[MAXN][SIZ];
int c[MAXN], F[SIZ];
int bak[MAXN][SIZ], Ans[SIZ];
char _s[MAXN];
vec<int> cur;
map<vec<int>, int> M;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void FMT(int *f, int n, int o) {
	for(int i = 0; i < n; ++i)
		for(int S = 0; S < (1 << n); ++S)
			if((S >> i) & 1) f[S] += o * f[S ^ (1 << i)];
}

void calc() {
	int res = 0;
	for(int S = 0; S <= U; ++S)
		res += (((n - popc(S)) & 1) ? -1 : 1) * F[S];
	M[cur] = res;
}

void DFS(int dep, int x, int tot) {
	if(tot == n) return calc(), void();
	memcpy(bak[dep], F, sizeof F);
	for(int i = x; i <= n - tot; ++i) {
		for(int S = 0; S <= U; ++S) F[S] *= f[i][S];
		cur.pb(i); DFS(dep + 1, i, tot + i); cur.pop_back();
		memcpy(F, bak[dep], sizeof F);
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); U = (1 << n) - 1;
	for(int i = 1; i <= n; ++i) {
		scanf("%s", _s + 1);
		for(int j = 1; j <= n; ++j) G[i][j] = _s[j] - '0';
	}
	for(int i = 1; i <= n; ++i) dp[(1 << (i - 1))][i] = 1;
	for(int S = 1; S <= U; ++S)
		for(int i = 1; i <= n; ++i) {
			if(!dp[S][i]) continue;
			for(int j = 1; j <= n; ++j) {
				if(!G[i][j] || ((S >> (j - 1)) & 1)) continue;
				dp[S | (1 << (j - 1))][j] += dp[S][i];
			}
		}
	for(int S = 1; S <= U; ++S)
		for(int i = 1; i <= n; ++i) f[popc(S)][S] += dp[S][i];
	for(int i = 1; i <= n; ++i) FMT(f[i], n, 1);
	for(int S = 0; S <= U; ++S) F[S] = 1;
	DFS(0, 1, 0);
	for(int S = 0, len; S < (1 << (n - 1)); ++S) {
		cur.clear(), len = 1;
		for(int i = 0; i < n - 1; ++i) {
			if((S >> i) & 1) ++len;
			else cur.pb(len), len = 1;
		}
		cur.pb(len); sort(cur.begin(), cur.end());
		Ans[S] = M[cur];
	}
	for(int i = 0; i < n - 1; ++i)
		for(int S = 0; S < (1 << (n - 1)); ++S)
			if((S >> i) & 1) Ans[S ^ (1 << i)] -= Ans[S];
	for(int S = 0; S < (1 << (n - 1)); ++S)
		printf("%lld ", Ans[S]);
	return 0;
}