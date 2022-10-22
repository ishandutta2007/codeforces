//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, dis[MAXN];
int dfn[MAXN], low[MAXN], cnt;
int stk[MAXN], top, col[MAXN], colcnt;
vec<int> G[MAXN], T[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Tarjan(int x, int fa) {
	dfn[x] = low[x] = ++cnt;
	stk[++top] = x;
	for(auto to : G[x]) {
		if(to == fa) continue;
		if(!dfn[to]) {
			Tarjan(to, x);
			low[x] = min(low[x], low[to]);
			if(low[to] > dfn[x]) {
				col[to] = ++colcnt;
				while(stk[top] ^ to) col[stk[top--]] = colcnt;
				top--;
			} 
		} else low[x] = min(low[x], dfn[to]);
	}
}

void DFS(int x, int fa) {
	dis[x] = dis[fa] + 1;
	for(auto to : T[x]) {
		if(to == fa) continue;
		DFS(to, x);
	}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n), read(m);
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	Tarjan(1, 0);
	if(top) {
		++colcnt;
		while(top) col[stk[top--]] = colcnt;
	}
	for(int x = 1; x <= n; ++x)
		for(auto y : G[x]) 
			if(col[x] ^ col[y]) T[col[x]].pb(col[y]);
	n = colcnt;
	DFS(1, 0);
	int a = max_element(dis + 1, dis + n + 1) - dis;
	memset(dis, 0, sizeof dis);
	DFS(a, 0);
	printf("%d\n", *max_element(dis + 1, dis + n + 1) - 1);
	return 0;
}