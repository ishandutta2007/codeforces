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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, X[MAXN], Y[MAXN], rt;
int dfn[MAXN], low[MAXN], stk[MAXN], top, dfnc;
int scc[MAXN], sccc, ind[MAXN], q[MAXN], p[MAXN];
bool instk[MAXN];
vec<int> G[MAXN], idx[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Tarjan(int x) {
	dfn[x] = low[x] = ++dfnc, stk[++top] = x, instk[x] = true;
	for(auto to : G[x]) {
		if(!dfn[to]) Tarjan(to), low[x] = min(low[x], low[to]);
		else if(instk[to]) low[x] = min(low[x], dfn[to]);
	}
	if(dfn[x] == low[x]) {
		scc[x] = ++sccc, instk[x] = false;
		while(stk[top] ^ x) {
			scc[stk[top]] = sccc;
			instk[stk[top--]] = false;
		}
		top--;
	}
}

int ask(int a, int b) {
	int res;
	cout << "? " << a << ' ' << b << endl;
	cin >> res; return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y); X[i] = x, Y[i] = y;
		G[x].pb(y);
	}
	for(int i = 1; i <= n; ++i) if(!dfn[i]) Tarjan(i);
	for(int i = 1; i <= n; ++i) G[i].clear(), idx[scc[i]].pb(i);
	for(int i = 1; i <= m; ++i)
		if(scc[X[i]] ^ scc[Y[i]]) 
			G[scc[X[i]]].pb(scc[Y[i]]), ind[scc[Y[i]]]++;
	int h = 1, t = 0;
	for(int i = 1; i <= sccc; ++i) if(!ind[i]) q[++t] = i;
	while(h < t) {
		int a = q[h], b = q[h + 1]; ++h;
		while(p[a] < idx[a].size() && p[b] < idx[b].size()) {
			if(ask(idx[a][p[a]], idx[b][p[b]])) p[b]++;
			else p[a]++;
		}
		if(p[a] < idx[a].size()) {
			q[h] = a;
			for(auto to : G[b]) if((--ind[to]) == 0) q[++t] = to;
		} else {
			q[h] = b;
			for(auto to : G[a]) if((--ind[to]) == 0) q[++t] = to;
		}
	}
	cout << "! " << idx[q[h]][p[q[h]]] << endl;
	return 0;
}