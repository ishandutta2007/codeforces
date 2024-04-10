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

const int MAXN = 410;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, k;
int tp[MAXN], nxt[MAXN][3];
int stk[MAXN * MAXN], top;
char s[MAXN], lim[MAXN];
bool vis[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int type(char c) {return c == 'V' ? 1 : 0;}

bool DFS(int x) {
	if(vis[x > n ? x - n : x + n]) return false;
	vis[x] = true;
	stk[++top] = x;
	for(auto to : G[x]) {
		if(vis[to]) continue;
		if(!DFS(to)) return false;
	}
	return true;
}

bool chk(int p) {
	for(int i = 1; i <= (n << 1); ++i) vis[i] = 0;
	for(int i = 1; i <= p; ++i)
		if(!DFS(i + tp[lim[i] - 'a' + 1] * n)) return false;
	for(int i = p + 1; i <= n; ++i) {
		if(vis[i]) lim[i] = nxt[1][0] + 'a' - 1;
		else if(vis[i + n]) lim[i] = nxt[1][1] + 'a' - 1;
		else {
			int x = min(nxt[1][0], nxt[1][1]);
			int y = max(nxt[1][0], nxt[1][1]);
			top = 0;
			if(DFS(i + tp[x] * n)) lim[i] = x + 'a' - 1;
			else {
				while(top) vis[stk[top--]] = false;
				if(DFS(i + tp[y] * n)) lim[i] = y + 'a' - 1;
				else return false;
			}
		}
	}
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	scanf("%s", s + 1); k = strlen(s + 1);
	for(int i = 1; i <= k; ++i) tp[i] = type(s[i]);
	int tmp[2] = {k + 1, k + 1};
	for(int i = k + 1; i; --i) {
		tmp[tp[i]] = i;
		nxt[i][0] = tmp[0], nxt[i][1] = tmp[1];
	}
	read(n), read(m);
	for(int i = 1, x; i <= m; ++i) {
		read(x); scanf("%s", s + 1);
		int a1 = x, a2 = type(s[1]);
		read(x); scanf("%s", s + 1);
		int b1 = x, b2 = type(s[1]);
		G[a1 + a2 * n].pb(b1 + b2 * n);
		G[b1 + (!b2) * n].pb(a1 + (!a2) * n);
	}
	scanf("%s", lim + 1);
	if(chk(n)) return printf("%s\n", lim + 1), 0;
	else if(nxt[1][0] == k + 1 || nxt[1][1] == k + 1) return puts("-1"), 0;
	for(int i = n; i; --i) {
		int x = min(nxt[lim[i] - 'a' + 2][0], nxt[lim[i] - 'a' + 2][1]);
		int y = max(nxt[lim[i] - 'a' + 2][0], nxt[lim[i] - 'a' + 2][1]);
		if(x != k + 1) {
			lim[i] = x + 'a' - 1;
			if(chk(i)) return printf("%s\n", lim + 1), 0;
		}
		if(y != k + 1) {
			lim[i] = y + 'a' - 1;
			if(chk(i)) return printf("%s\n", lim + 1), 0;
		}
	}
	puts("-1");
	return 0;
}