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

const int MAXN = 55;
const int MAXM = 5e4 + 10;
const int SIZ = 5e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct Query { int opt; LL a, b; } qs[MAXM];

int n, m, rt, cnt = 1;
int ls[SIZ], rs[SIZ], tag[SIZ], dsu[SIZ], Ans[MAXM];
char _o[10];
vec<int> t[MAXM], G[SIZ];
LL U;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool isleaf(int x) { return !ls[x] && !rs[x]; }

void push(int x, int v) { tag[x] = v; }

void pushdown(int x) {
	if(!tag[x]) return;
	if(!ls[x]) ls[x] = ++cnt;
	if(!rs[x]) rs[x] = ++cnt;
	tag[ls[x]] = tag[rs[x]] = tag[x]; tag[x] = 0;
}

void update(int &x, LL l, LL r, LL L, LL R, int v) {
	if(!x) x = ++cnt;
	if(L <= l && r <= R) return push(x, v), void();
	LL mid = (l + r) >> 1; pushdown(x);
	if(L <= mid) update(ls[x], l, mid, L, R, v);
	if(R > mid) update(rs[x], mid + 1, r, L, R, v);
}

int Id(LL p, int x = rt, LL l = 0, LL r = U) {
	if(isleaf(x)) return x;
	LL mid = (l + r) >> 1; pushdown(x);
	if(p <= mid) return Id(p, ls[x], l, mid);
	else return Id(p, rs[x], mid + 1, r);
}

void push_tag(int x, LL l, LL r) {
	if(isleaf(x)) return t[tag[x]].pb(x), void();
	LL mid = (l + r) >> 1; pushdown(x);
	push_tag(ls[x], l, mid), push_tag(rs[x], mid + 1, r);
}

void Add(int x, int y) {
	if(isleaf(x) && isleaf(y)) {
		if(tag[x] < tag[y]) G[x].pb(y);
		else G[y].pb(x);
		return;
	}
	if(isleaf(x)) return Add(x, ls[y]), Add(x, rs[y]), void();
	if(isleaf(y)) return Add(ls[x], y), Add(rs[x], y), void();
	Add(ls[x], ls[y]), Add(rs[x], rs[y]);
}

int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }

void unity(int x, int y) { (find(x) != find(y)) && (dsu[find(x)] = find(y)); }

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m); U = (1ll << n) - 1;
	for(int i = 1; i <= m; ++i) {
		scanf("%s", _o + 1);
		if(_o[1] == 'a') qs[i].opt = 1;
		else qs[i].opt = 2;
		read(qs[i].a), read(qs[i].b);
	}
	tag[rt = 1] = m + 1;
	for(int i = 1; i <= m; ++i)
		if(qs[i].opt == 2) update(rt, 0, U, qs[i].a, qs[i].b, i);
	push_tag(rt, 0, U);
	for(int i = 1; i <= cnt; ++i) {
		dsu[i] = i;
		if(!isleaf(i)) Add(ls[i], rs[i]);
	}
	for(auto x : t[m + 1]) for(auto y : G[x]) unity(x, y);
	for(int i = m; i >= 1; --i) {
		if(qs[i].opt == 1) {
			LL a = qs[i].a, b = qs[i].b;
			a = Id(a), b = Id(b);
			Ans[i] = (find(a) == find(b));
		} else for(auto x : t[i]) for(auto y : G[x]) unity(x, y);
	}
	for(int i = 1; i <= m; ++i)
		if(qs[i].opt == 1) printf("%d\n", Ans[i]);
	return 0;
}