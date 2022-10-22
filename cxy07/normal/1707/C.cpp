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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, badc;
int dsu[MAXN], dfn[MAXN], siz[MAXN], dfnc, idfn[MAXN];
int X[MAXN], Y[MAXN], sum[MAXN];
int stk[MAXN], top, id[MAXN];
bool anc[MAXN], vis[MAXN], Ans[MAXN];
vec<int> G[MAXN], bad[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }
void unity(int x, int y) { x = find(x), y = find(y); if(x ^ y) dsu[x] = y; }

void DFS1(int x, int fa) {
	siz[x] = 1, idfn[dfn[x] = ++dfnc] = x;
	for(auto to : G[x]) if(to ^ fa) DFS1(to, x), siz[x] += siz[to];
}

void add(int l, int r, int v) { 
	if(l > r) return;
	sum[l] += v, sum[r + 1] -= v; 
}

void DFS2(int x, int fa) {
	anc[x] = true, vis[x] = true;
	stk[++top] = x; id[x] = top;
	for(auto y : bad[x]) {
		if(!vis[y]) continue;
		if(anc[y]) {
			int t = stk[id[y] + 1];
			add(dfn[x], dfn[x] + siz[x] - 1, 1);
			add(1, dfn[t] - 1, 1), add(dfn[t] + siz[t], n, 1);
		} else {
			add(dfn[x], dfn[x] + siz[x] - 1, 1);
			add(dfn[y], dfn[y] + siz[y] - 1, 1);
		}
	}
	for(auto to : G[x]) {
		if(to == fa) continue;
		DFS2(to, x);
	}
	anc[x] = false, --top;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1; i <= m; ++i) read(X[i]), read(Y[i]);
	for(int i = 1; i <= n; ++i) dsu[i] = i;
	for(int i = 1, x, y; i <= m; ++i) {
		x = find(X[i]), y = find(Y[i]);
		if(x == y) {
			++badc; bad[X[i]].pb(Y[i]), bad[Y[i]].pb(X[i]);
			continue;
		}
		unity(x, y); G[X[i]].pb(Y[i]), G[Y[i]].pb(X[i]);
	}
	DFS1(1, 0); DFS2(1, 0);
	for(int i = 1; i <= n; ++i) sum[i] += sum[i - 1];
	for(int i = 1; i <= n; ++i) {
		assert(sum[i] >= 0 && sum[i] <= badc);
		if(sum[i] == badc) Ans[idfn[i]] = 1;
	}
	for(int i = 1; i <= n; ++i) putchar('0' + Ans[i]);
	return 0;
}