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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, dfnc, colc;
int p[MAXN], dfn[MAXN], low[MAXN], stk[MAXN], top, ind[MAXN];
int col[MAXN];
int a[MAXN], b[MAXN];
bool ok[MAXN], instk[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool cmpa(int x, int y) { return a[x] < a[y]; }
bool cmpb(int x, int y) { return b[x] < b[y]; }

void tarjan(int x) {
	dfn[x] = low[x] = ++dfnc;
	stk[++top] = x, instk[x] = true;
	for(auto to : G[x]) {
		if(!dfn[to]) {
			tarjan(to);
			low[x] = min(low[x], low[to]);
		} else if(instk[to]) low[x] = min(low[x], dfn[to]);
	}
	if(dfn[x] == low[x]) {
		col[x] = ++colc, instk[x] = false;
		while(stk[top] != x) {
			col[stk[top]] = colc;
			instk[stk[top--]] = false;
		}
		top--;
	}
}

void solve() {
	read(n); top = dfnc = colc = 0;
	for(int i = 1; i <= n; ++i) {
		p[i] = i, ind[i] = 0;
		dfn[i] = low[i] = 0, G[i].clear();
	}
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= n; ++i) read(b[i]);
	sort(p + 1, p + n + 1, cmpa);
	for(int i = 2; i <= n; ++i) G[p[i]].pb(p[i - 1]);
	sort(p + 1, p + n + 1, cmpb);
	for(int i = 2; i <= n; ++i) G[p[i]].pb(p[i - 1]);
	for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
	for(int x = 1; x <= n; ++x)
		for(auto to : G[x]) if(col[to] ^ col[x]) ind[col[to]]++;
	for(int i = 1; i <= n; ++i) putchar((ind[col[i]] == 0) + '0');
	putchar('\n');
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