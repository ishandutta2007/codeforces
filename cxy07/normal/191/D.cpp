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
const int MAXM = 6e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], siz, nxt[MAXM], to[MAXM];
	void add(int x, int y) { nxt[++siz] = head[x]; to[siz] = y, head[x] = siz; }
	void clear() { memset(head, 0, sizeof head), siz = 0; }
} e;

int n, m, Ans;
int X[MAXM], Y[MAXM], stk[MAXN], top;
int col[MAXN], colc, ind[MAXN], out[MAXN];
bool instk[MAXN], vis[MAXM], cir[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS(int x) {
	instk[stk[++top] = x] = true;
	for(int i = e.head[x], to; i; i = e.nxt[i]) {
		to = e.to[i]; if(vis[i]) continue;
		vis[i] = vis[i ^ 1] = true;
		if(instk[to]) {
			cir[++colc] = true; col[to] = colc;
			for(int j = top; stk[j] != to; --j) col[stk[j]] = colc;
		} else DFS(to);
	}
	assert(stk[top] == x); instk[stk[top--]] = false;
}

signed main () {
#ifdef FILE
	freopen("CF191D.in", "r", stdin);
	freopen("CF191D.out", "w", stdout);
#endif
	read(n), read(m); e.siz = 1;
	if(n == 1) return puts("0 0"), 0;
	for(int i = 1; i <= m; ++i) {
		read(X[i]), read(Y[i]); ind[X[i]]++, ind[Y[i]]++;
		e.add(X[i], Y[i]), e.add(Y[i], X[i]);
	}
	DFS(1); assert(colc == m - n + 1);
	for(int i = 1; i <= n; ++i) if(!col[i]) col[i] = ++colc;
	if(colc == 1) return printf("%d %d\n", 1, m), 0;
	for(int i = 1; i <= n; ++i) Ans += (ind[i] & 1);
	for(int i = 1; i <= n; ++i) if(cir[col[i]]) if(ind[i] > 2) out[col[i]]++;
	for(int i = 1; i <= colc; ++i) if(cir[i] && out[i] <= 1) Ans += 2;
	assert((Ans & 1) == 0);
	printf("%d %d\n", Ans >> 1, m);
	return 0;
}