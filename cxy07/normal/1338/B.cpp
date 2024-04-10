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

int n, m, rt, mn, mx;
int ind[MAXN], dep[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS(int x, int fa) {
	dep[x] = dep[fa] + 1;
	bool o = false;
	for(auto to : G[x]) {
		if(to == fa) continue;
		DFS(to, x);
		if(ind[to] == 1 && !o) o = true, ++mx;
		if(ind[to] > 1) ++mx;
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), rt = 1;
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y), G[x].pb(y), G[y].pb(x);
		++ind[x], ++ind[y];
	}
	while(ind[rt] == 1) ++rt;
	assert(rt <= n); DFS(rt, 0);
	int p = 0; mn = 1;
	for(int i = 1; i <= n; ++i) {
		if(ind[i] != 1) continue;
		if(!p) p = i;
		if((dep[p] & 1) != (dep[i] & 1)) { mn = 3; break; }
	}
	printf("%d %d\n", mn, mx);
	return 0;
}