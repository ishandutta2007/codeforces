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

int T, n, m, mx;
int d[MAXN], ind[MAXN], a[MAXN], b[MAXN];
bool vis[MAXN];
vec<int> G[MAXN];
queue<int> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n); mx = 0; while(Q.size()) Q.pop();
	for(int i = 1; i <= n; ++i) d[i] = ind[i] = vis[i] = 0, G[i].clear();
	for(int i = 1; i <= n; ++i) read(a[i]), d[a[i]]++;
	for(int i = 1; i <= n; ++i) read(b[i]);
	for(int i = 1; i <= n; ++i) if(!mx || d[i] > d[mx]) mx = i;
	for(int i = 1; i <= n; ++i) {
		if(a[i] == mx || b[i] == mx) continue;
		ind[b[i]]++, G[a[i]].pb(b[i]);
	}
	for(int i = 1; i <= n; ++i) if(!ind[i]) Q.push(i);
	while(Q.size()) {
		int x = Q.front(); Q.pop(); vis[x] = true;
		for(auto to : G[x]) if(!(--ind[to])) Q.push(to);
	}
	for(int i = 1; i <= n; ++i) if(!vis[i]) return puts("WA"), void();
	puts("AC");
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