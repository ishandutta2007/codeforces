//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, k, sum;
int a[MAXN], f[MAXN];
int stk[MAXN], top;
bool vis[MAXN];
vec<pii> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void unity(int x, int y) {
	x = find(x), y = find(y);
	if(x ^ y) f[x] = y;
}

void DFS(int x, int fa, int id) {
	vis[x] = true;
	for(auto to : G[x]) {
		if(vis[to.fst]) continue;
		DFS(to.fst, x, to.scd);
	}
	if(!fa) return;
	if(a[x] >= k) a[fa] += a[x] - k, printf("%lld\n", id);
	else stk[++top] = id;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m), read(k);
	for(int i = 1; i <= n; ++i) 
		f[i] = i, read(a[i]), sum += a[i];
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		unity(x, y);
		G[x].pb(mp(y, i)), G[y].pb(mp(x, i));
	}
	for(int i = 1; i <= n; ++i)
		if(find(i) ^ find(1)) return puts("NO"), 0;
	if(sum < (n - 1) * k) return puts("NO"), 0;
	puts("YES"); DFS(1, 0, 0);
	while(top) printf("%lld\n", stk[top--]);
	return 0;
}