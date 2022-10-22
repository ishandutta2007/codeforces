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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, cnt, L, R;
int x[MAXN], y[MAXN], c[MAXN], t[MAXN];
int pre[MAXN], suf[MAXN];
int col[MAXN], dfn[MAXN], low[MAXN], dfnc, st[MAXN], top, colc;
bool instk[MAXN];
vec<pii> G[MAXN];
vec<int> rev[MAXN], Ans;
vec<pair<int*, int>> stk;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void make(int &x, int y, bool opt = false) {
	if(opt) stk.pb(mp(&x, x));
	x = y;
}

struct EDGE {
	int head[MAXN], siz;
	int nxt[MAXN << 1], to[MAXN << 1];
	void add(int x, int y, bool opt = false) {
		make(siz, siz + 1, opt);
		make(nxt[siz], head[x], opt);
		make(to[siz], y, opt);
		make(head[x], siz, opt);
	}
} e;

void roll() {
	while(stk.size()) {
		*(stk.back().fst) = stk.back().scd;
		stk.pop_back();
	}
}

void Tarjan(int x) {
	dfn[x] = low[x] = ++dfnc;
	st[++top] = x, instk[x] = true;
	for(int i = e.head[x], to; i; i = e.nxt[i]) {
		to = e.to[i];
		if(!dfn[to]) {
			Tarjan(to);
			low[x] = min(low[x], low[to]);
		} else if(instk[to]) low[x] = min(low[x], dfn[to]);
	}
	if(dfn[x] == low[x]) {
		col[x] = ++colc, instk[x] = false;
		while(st[top] ^ x) {
			col[st[top]] = colc;
			instk[st[top--]] = false;
		}
		top--;
	}
}

bool chk(int lim) {
	roll();
	for(int i = 1; i <= m; ++i)
		if(t[i] > lim) e.add(i + m, i, true);
	memset(col, 0, sizeof col), memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low), memset(st, 0, sizeof st);
	top = dfnc = colc = 0;
	for(int i = 1; i <= (m << 1); ++i)
		if(!dfn[i]) Tarjan(i);
	for(int i = 1; i <= m; ++i)
		if(col[i] == col[i + m]) return false;
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m); cnt = (m << 1);
	for(int i = 1; i <= m; ++i) {
		read(x[i]), read(y[i]), read(c[i]), read(t[i]);
		G[x[i]].pb(mp(c[i], i));
		G[y[i]].pb(mp(c[i], i));
	}
	for(int i = 1; i <= n; ++i) sort(G[i].begin(), G[i].end());
	for(int i = 1, cnt; i <= n; ++i) {
		cnt = 1;
		for(int j = 1; j < G[i].size(); ++j) {
			if(G[i][j].fst != G[i][j - 1].fst) cnt = 0;
			if((++cnt) > 2) return puts("No"), 0;
			if(cnt == 2) {
				rev[G[i][j].scd].pb(G[i][j - 1].scd); 
				rev[G[i][j - 1].scd].pb(G[i][j].scd);
			}
		}
	}
	for(int i = 1; i <= m; ++i)
		for(auto x : rev[i]) {
			e.add(i, x + m), e.add(x, i + m);
			e.add(i + m, x), e.add(x + m, i);
		}
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < G[i].size(); ++j) {
			pre[j] = ++cnt;
			if(j) e.add(pre[j], pre[j - 1]);
			e.add(pre[j], G[i][j].scd);
		}
		for(int j = G[i].size() - 1; j >= 0; --j) {
			suf[j] = ++cnt;
			if(j < G[i].size() - 1) e.add(suf[j], suf[j + 1]);
			e.add(suf[j], G[i][j].scd);
		}
		for(int j = 0; j < G[i].size(); ++j) {
			if(j) e.add(G[i][j].scd + m, pre[j - 1]);
			if(j < G[i].size() - 1) e.add(G[i][j].scd + m, suf[j + 1]);
		}
	}
	L = 0, R = (int)1e9;
	while(L < R) {
		int mid = (L + R) >> 1;
		if(chk(mid)) R = mid;
		else L = mid + 1;
	}
	if(!chk(L)) return puts("No"), 0;
	puts("Yes");
	for(int i = 1; i <= m; ++i)
		if(col[i] > col[i + m]) Ans.pb(i);
	printf("%d %ld\n", L, Ans.size());
	for(auto x : Ans) printf("%d ", x);
	putchar('\n');
	return 0;
}