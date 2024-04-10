

//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct info {
	int o, p, v;
	info(int _o = 0, int _p = 0, int _v = 0) : o(_o), p(_p), v(_v) {}
};

int n, m, Ans;
int a[2][MAXN], s[3][MAXN], nxt[3][MAXN];
int dp[MAXN], mnp[2];
vec<info> val[MAXN];
map<int, int> mmp[3];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	a *= f; return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void add(int a, int b, int v) {
	dp[max(a, b)] = max(dp[max(a, b)], v);
	val[min(a, b)].pb(info((bool)(a <= b), max(a, b), v));
}

void update(int a, int b, int v) {
	if(nxt[0][a + 1] <= n) add(nxt[0][a + 1], b, v + 1);
	if(nxt[1][b + 1] <= n) add(a, nxt[1][b + 1], v + 1);
	int p = nxt[2][max(a, b) + 1];
	if(p <= n) add(p, p, v + 1);
}

signed main () {
#ifdef FILE
	freopen("GT.in", "r", stdin);
	freopen("GT.out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(a[0][i]);
	for(int i = 1; i <= n; ++i) read(a[1][i]);
	nxt[0][n + 1] = nxt[1][n + 1] = nxt[2][n + 1] = INF;
	mmp[0][0] = mmp[1][0] = mmp[2][0] = n;
	for(int i = n; i >= 1; --i) {
		s[0][i] = s[0][i + 1] + a[0][i], s[1][i] = s[1][i + 1] + a[1][i];
		s[2][i] = s[2][i + 1] + a[0][i] + a[1][i];
		for(int j = 0; j < 3; ++j) {
			nxt[j][i] = nxt[j][i + 1];
			if(mmp[j].count(s[j][i])) 
				nxt[j][i] = min(nxt[j][i], mmp[j][s[j][i]]);
			mmp[j][s[j][i]] = i - 1;
		}
	}
	for(int i = 0; i < n; ++i) {
		update(i, i, dp[i]); 
		mnp[0] = mnp[1] = INF;
		for(auto p : val[i]) if(p.v == dp[i] + 1) mnp[p.o] = min(mnp[p.o], p.p);
		if(mnp[0] <= n) update(mnp[0], i, dp[i] + 1);
		if(mnp[1] <= n) update(i, mnp[1], dp[i] + 1);
	}
	Ans = *max_element(dp, dp + n + 1);
	printf("%lld\n", Ans);
	return 0;
}