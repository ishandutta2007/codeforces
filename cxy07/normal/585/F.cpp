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

const int MAXN = 1e3 + 10;
const int MAXD = 55;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, d;
int dp[MAXN * MAXD][MAXD][2];
int ch[MAXN * MAXD][10], fail[MAXN * MAXD], cnt;
int val[MAXD][2];
char X[MAXD], Y[MAXD], s[MAXN];
bool ed[MAXN * MAXD];
queue<int> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void insert(int L, int R) {
	int now = 0;
	for(int i = L; i <= R; ++i) {
		int &to = ch[now][s[i] - '0'];
		if(!to) to = ++cnt;
		now = to;
	}
	ed[now] = true;
}

void modadd(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

void build() {
	int len = d / 2;
	for(int i = 1; i + len - 1 <= n; ++i) 
		insert(i, i + len - 1);
	for(int i = 0; i < 10; ++i)
		if(ch[0][i]) Q.push(ch[0][i]), fail[ch[0][i]] = 0;
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(int i = 0; i < 10; ++i) {
			if(ch[x][i]) {
				fail[ch[x][i]] = ch[fail[x]][i];
				Q.push(ch[x][i]);
			} else ch[x][i] = ch[fail[x]][i];
		}
	}
}

int calc(char *c) {
	memset(dp, 0, sizeof dp);
	memset(val, 0, sizeof val);
	dp[0][0][1] = val[d + 1][0] = val[d + 1][1] = 1;
	for(int i = d, ten = 1; i >= 1; --i) {
		val[i][0] = val[i + 1][0] * 10 % mod;
		val[i][1] = (val[i + 1][1] + ten * (c[i] - '0')) % mod;
		ten = ten * 10 % mod;
	}
	for(int i = 1; i <= d; ++i) {
		for(int x = 0; x <= cnt; ++x) {
			if(ed[x]) continue;
			for(int p = 0; p < 10; ++p) {
				modadd(dp[ch[x][p]][i][0], dp[x][i - 1][0]);
				if(p < c[i] - '0') modadd(dp[ch[x][p]][i][0], dp[x][i - 1][1]);
				else if(p == c[i] - '0') modadd(dp[ch[x][p]][i][1], dp[x][i - 1][1]);
			}
		}
	}
	int res = 0;
	for(int i = 0; i <= cnt; ++i) {
		if(!ed[i]) continue;
		for(int l = d / 2; l <= d; ++l)
			modadd(res, (dp[i][l][0] * val[l + 1][0] + dp[i][l][1] * val[l + 1][1]) % mod);
	}
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	scanf("%s", s + 1); scanf("%s", X + 1); scanf("%s", Y + 1);
	n = strlen(s + 1), d = strlen(X + 1);
	for(int i = d; i; --i) {
		if(X[i] == '0') X[i] = '9';
		else {X[i]--; break;}
	}
	build();
	printf("%lld\n", (calc(Y) - calc(X) + mod) % mod);
	return 0;
}