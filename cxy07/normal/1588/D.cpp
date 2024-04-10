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

const int MAXN = 15;
const int SIZ = (1 << 10) + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, Ans;
int dp[60][SIZ];
int pos[MAXN][60][2], cur[MAXN];
char s[MAXN][510];
bool vis[60][SIZ];
pii pre[60][SIZ], state;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int c(char C) {
	if(islower(C)) return C - 'a' + 1;
	else return C - 'A' + 1 + 26;
}

bool decode(int col, int S) {
	for(int i = 1; i <= n; ++i) {
		if(!pos[i][col][(S >> (i - 1)) & 1]) return false;
		cur[i] = pos[i][col][(S >> (i - 1)) & 1];
	}
	return true;
}

int Getpre(int x) {
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		if(!pos[i][x][1] && !pos[i][x][0]) return -1;
		if(pos[i][x][1] && pos[i][x][1] < cur[i]) res |= (1 << (i - 1));
		else if(pos[i][x][0] >= cur[i]) return -1;
	}
	return res;
}

void print(pii cur) {
	if(!cur.fst) return;
	print(pre[cur.fst][cur.scd]);
	if(cur.fst <= 26) putchar(cur.fst - 1 + 'a');
	else putchar(cur.fst - 27 + 'A');
}

int DP(int i, int S) {
	if(vis[i][S]) return dp[i][S];
	vis[i][S] = true;
	if(!decode(i, S)) return dp[i][S] = 0;
	dp[i][S] = 1, pre[i][S] = mp(0, 0);
	for(int j = 1, T; j <= 52; ++j) {
		decode(i, S);
		T = Getpre(j);
		if(T == -1) continue;
		int tmp = DP(j, T);
		if(dp[i][S] < tmp + 1) {
			dp[i][S] = tmp + 1;
			pre[i][S] = mp(j, T);
		}
	}
	if(Ans < dp[i][S]) {
		Ans = dp[i][S];
		state = mp(i, S);
	}
	return dp[i][S];
}

void solve() {
	read(n); Ans = 0, state = mp(0, 0);
	memset(pos, 0, sizeof pos);
	memset(dp, 0, sizeof dp);
	memset(pre, 0, sizeof pre);
	memset(vis, 0, sizeof vis);
	for(int i = 1, len; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		len = strlen(s[i] + 1);
		for(int j = 1, p; j <= len; ++j) {
			p = c(s[i][j]);
			if(pos[i][p][0]) pos[i][p][1] = j;
			else pos[i][p][0] = j;
		}
	}
	for(int i = 1; i <= 52; ++i)
		for(int S = 0; S < (1 << n); ++S) DP(i, S);
	printf("%d\n", Ans);
	print(state); putchar('\n');
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