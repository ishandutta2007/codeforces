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

int T, n, m, cnt;
int col[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS(int x, int fa) {
	cnt++;
	col[x] = 1;
	for(auto to : G[x])
		if(col[to] == 1) col[x] = 0;
	for(auto to : G[x]) {
		if(~col[to]) continue;
		DFS(to, x);
	}
}

void solve() {
	read(n), read(m);
	for(int i = 1; i <= n; ++i) G[i].clear();
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	for(int i = 1; i <= n; ++i) col[i] = -1;
	cnt = 0; DFS(1, 0);
	int tmp = 0;
	if(cnt != n) puts("NO");
	else {
		puts("YES");
		for(int i = 1; i <= n; ++i) tmp += col[i];
		printf("%d\n", tmp);
		for(int i = 1; i <= n; ++i)
			if(col[i] == 1) printf("%d ", i);
		putchar('\n');
	}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}