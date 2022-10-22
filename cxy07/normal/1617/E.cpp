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

const int MAXN = 2e5 * 30 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, idc, A, B, Ans = 0;
int a[MAXN], pos[MAXN];
int mx[MAXN], smx[MAXN], mxp[MAXN], smxp[MAXN];
map<int, int> id;
set<pii> link;
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int Getfa(int x) {
	int k = 1;
	while(k < x) k <<= 1;
	return k - x;
}

void DFS(int x, int fa) {
	mx[x] = smx[x] = -INF, mxp[x] = smxp[x] = -1;
	if(pos[x]) mx[x] = 0, mxp[x] = x;
	for(auto to : G[x]) {
		if(to == fa) continue;
		DFS(to, x);
		if(mx[to] + 1 > mx[x]) {
			swap(smx[x], mx[x]), swap(smxp[x], mxp[x]);
			mx[x] = mx[to] + 1, mxp[x] = mxp[to];
		} else if(mx[to] + 1 > smx[x]) 
			smx[x] = mx[to] + 1, smxp[x] = mxp[to];
	}
	if((~mxp[x]) && (~smxp[x]) && (mx[x] + smx[x]) > Ans) {
		Ans = mx[x] + smx[x];
		A = mxp[x], B = smxp[x];
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1, cur; i <= n; ++i) {
		read(a[i]);
		if(!id.count(a[i])) id[a[i]] = ++idc; 
		pos[id[a[i]]] = i;
		cur = a[i];
		while(cur) {
			int f = Getfa(cur);
			if(!id.count(f)) id[f] = ++idc;
			if(link.count(mp(f, cur))) break;
			G[id[f]].pb(id[cur]), G[id[cur]].pb(id[f]);
			link.insert(mp(f, cur));
			cur = f;
		}
	}
	DFS(1, 0);
	printf("%d %d %d\n", pos[A], pos[B], Ans);
	return 0;
}