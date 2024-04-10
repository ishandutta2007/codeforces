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

const int MAXN = (1 << 12) + 10;
const int MAXQ = (1 << 16) + 10;
const int MAXS = 3e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 19260817;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct NODE {
	int x, l, r;
	NODE(int _x = 0, int _l = 0, int _r = 0) : x(_x), l(_l), r(_r) {}
	bool operator == (const NODE &b) const { return x == b.x && l == b.l && r == b.r; }
	int key() { return (((1ll * x * l) % mod) * r) % mod; }
};

struct HashTable {
	int head[mod + 10], siz;
	int nxt[MAXS], id[MAXS]; NODE who[MAXS];
	int ask(NODE p) {
		int k = p.key();
		for(int i = head[k]; i; i = nxt[i]) if(who[i] == p) return id[i];
		return -1;
	}
	void add(NODE p, int v) {
		int k = p.key();
		nxt[++siz] = head[k]; 
		id[siz] = v, who[siz] = p, head[k] = siz;
	}
} H;

int n, q, cnt;
int a[MAXN], pos[MAXN], Ans[MAXQ];
vec<int> idx[MAXN << 2];
//map<pii, int> sav[MAXN << 2];
vec<pii> ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int merge(int a, int b) {
	if(!a || !b) return (a | b);
	ans.pb(mp(a, b)); return ++cnt;
}

void add(int x, int l, int r, int v, int p) {
	idx[x].pb(p);
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(v <= mid) add(x << 1, l, mid, v, p);
	else add(x << 1 | 1, mid + 1, r, v, p);
}

int query(int x, int l, int r, int L, int R) {
	if(R < idx[x][0] || L > idx[x].back()) return 0;
	auto it = lower_bound(idx[x].begin(), idx[x].end(), L);
	if(it == idx[x].end()) return 0;
	L = *it; it = upper_bound(idx[x].begin(), idx[x].end(), R);
	if(it == idx[x].begin()) return 0;
	R = *prev(it); if(L > R) return 0;
	if(L == R) return L;
	int mid = (l + r) >> 1, res = 0, tmp = H.ask(NODE(x, L, R));
	if(~tmp) return tmp;
	res = merge(res, query(x << 1, l, mid, L, R));
	res = merge(res, query(x << 1 | 1, mid + 1, r, L, R));
	return H.add(NODE(x, L, R), res), res;
}

signed main () {
#ifdef FILE
	freopen("CF1375H.in", "r", stdin);
	freopen("CF1375H.out", "w", stdout);
#endif
	read(n), read(q); cnt = n;
	for(int i = 1; i <= n; ++i) read(a[i]), pos[a[i]] = i;
	for(int i = 1; i <= n; ++i) add(1, 1, n, a[i], i);
	for(int i = 1, l, r; i <= q; ++i) {
		read(l), read(r);
		Ans[i] = query(1, 1, n, l, r);
	}
	printf("%d\n", cnt);
	for(auto p : ans) printf("%d %d\n", p.fst, p.scd);
	for(int i = 1; i <= q; ++i) printf("%d ", Ans[i]);
	return 0;
}