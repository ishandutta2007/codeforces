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

struct Heap {int ls, rs, v, id, dis, tag;} T[MAXN];

int n, m, cnt, Ans;
int root[MAXN], Y[MAXN], V[MAXN], sum[MAXN], dep[MAXN];
vec<int> add[MAXN], G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Add(int x, int v) {
	if(x) T[x].v += v, T[x].tag += v;
}

void pushdown(int x) {
	if(!T[x].tag) return;
	Add(T[x].ls, T[x].tag);
	Add(T[x].rs, T[x].tag);
	T[x].tag = 0;
}

int merge(int x, int y) {
	if(!x || !y) return (x | y);
	pushdown(x), pushdown(y);
	if(T[x].v > T[y].v) swap(x, y);
	T[x].rs = merge(T[x].rs, y);
	if(T[T[x].rs].dis > T[T[x].ls].dis) swap(T[x].ls, T[x].rs);
	T[x].dis = T[T[x].ls].dis + 1;
	return x;
}

void DFS(int x, int f) {
	dep[x] = dep[f] + 1;
	for(auto to : G[x]) {
		if(to == f) continue;
		DFS(to, x); root[x] = merge(root[x], root[to]);
		sum[x] += sum[to];
	}
	if(x != 1 && !sum[x]) puts("-1"), exit(0);
	for(auto s : add[x]) {
		cnt++; T[cnt].v = V[s], T[cnt].id = s;
		root[x] = merge(root[x], cnt);
	}
	while(dep[Y[T[root[x]].id]] >= dep[x]) 
		root[x] = merge(T[root[x]].ls, T[root[x]].rs);
	if(root[x]) Ans += T[root[x]].v, Add(root[x], -T[root[x]].v);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	for(int i = 1, x, y, c; i <= m; ++i) {
		read(x), read(y), read(c);
		add[x].pb(i); Y[i] = y, V[i] = c;
		sum[x]++, sum[y]--;
	}
	DFS(1, 0);
	printf("%lld\n", Ans);
	return 0;
}