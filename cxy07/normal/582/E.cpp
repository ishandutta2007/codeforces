//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 510;
const int SIZ = (1 << 16) + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, len;
int idc = 1, p = 1, fa[MAXN];
int opt[20][5], dp[MAXN][SIZ];
int ta[SIZ], tb[SIZ], tmp[SIZ];
char id[MAXN], s[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void modadd(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

void FWTOR(int *A, int opt) {
	for(int mid = 1; mid < n; mid <<= 1)
		for(int i = 0; i < n; i += (mid << 1))
			for(int j = 0; j < mid; ++j)
				modadd(A[i + j + mid], (A[i + j] * opt + mod) % mod);
}

void FWTAND(int *A, int opt) {
	for(int mid = 1; mid < n; mid <<= 1)
		for(int i = 0; i < n; i += (mid << 1))
			for(int j = 0; j < mid; ++j)
				modadd(A[i + j], (A[i + j + mid] * opt + mod) % mod);
}

void OR(int x) {
	int a = G[x][0], b = G[x][1];
	memcpy(ta, dp[a], sizeof ta), memcpy(tb, dp[b], sizeof tb);
	FWTOR(ta, 1), FWTOR(tb, 1);
	for(int i = 0; i < n; ++i) tmp[i] = 1ll * ta[i] * tb[i] % mod;
	FWTOR(tmp, -1);
	for(int i = 0; i < n; ++i) modadd(dp[x][i], tmp[i]);
}

void AND(int x) {
	int a = G[x][0], b = G[x][1];
	memcpy(ta, dp[a], sizeof ta), memcpy(tb, dp[b], sizeof tb);
	FWTAND(ta, 1), FWTAND(tb, 1);
	for(int i = 0; i < n; ++i) tmp[i] = 1ll * ta[i] * tb[i] % mod;
	FWTAND(tmp, -1);
	for(int i = 0; i < n; ++i) modadd(dp[x][i], tmp[i]);
}

void DFS(int x) {
	if(!G[x].size()) {
		if(id[x] == '?') {
			for(int c = 0, state; c < 4; ++c) {
				state = 0;
				for(int i = 0; i < m; ++i) state |= (opt[i][c] << i);
				dp[x][state]++;
				state = 0;
				for(int i = 0; i < m; ++i) state |= ((!opt[i][c]) << i);
				dp[x][state]++;
			}
		} else {
			if('A' <= id[x] && id[x] <= 'D') {
				int c = id[x] - 'A', state = 0;
				for(int i = 0; i < m; ++i) state |= (opt[i][c] << i);
				dp[x][state]++;
			} else {
				int c = id[x] - 'a', state = 0;
				for(int i = 0; i < m; ++i) state |= ((!opt[i][c]) << i);
				dp[x][state]++;
			}
		}
		return;
	}
	assert(G[x].size() == 2);
	for(auto to : G[x]) DFS(to);
	if(id[x] != '&') OR(x);
	if(id[x] != '|') AND(x);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	scanf("%s", s + 1); len = strlen(s + 1);
	read(m); n = (1 << m);
	for(int i = 1; i <= len; ++i) {
		if(s[i] == '(') G[p].pb(++idc), fa[idc] = p, p = idc;
		else if(s[i] == ')') p = fa[p];
		else id[p] = s[i];
	}
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < 5; ++j) read(opt[i][j]);
	DFS(1); int state = 0;
	for(int i = 0; i < m; ++i) state |= (opt[i][4] << i);
	printf("%d\n", dp[1][state]);
	return 0;
}