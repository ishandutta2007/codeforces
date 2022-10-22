//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

int T, n, m, Ans;
int a[MAXN], p[MAXN], mx[MAXN];
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
	for(auto to : G[x]) {
		if(to == fa) continue;
		DFS(to, x); 
		mx[x] = max(mx[x], mx[to]);
	}
	if(fa && a[x] > mx[x]) {
		Ans += a[x] - mx[x];
		mx[x] = a[x];
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]), G[i].clear(), p[i] = i;
	for(int i = 1, x, y; i < n; ++i)
		read(x), read(y), G[x].pb(y), G[y].pb(x);
	sort(p + 1, p + n + 1, [&](int x, int y) { return a[x] < a[y]; });
	DFS(p[n], 0);
	int v1 = 0, v2 = 0;
	for(auto to : G[p[n]]) {
		if(mx[to] >= v1) v2 = v1, v1 = mx[to];
		else if(mx[to] >= v2) v2 = mx[to];
	}
	Ans += max(a[p[n]] - v1, 0ll) + max(a[p[n]] - v2, 0ll);
	printf("%lld\n", Ans);
	return 0;
}