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

const int MAXN = 1e6 + 10;
const int MAXM = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct VAL {
	int v, p;
	VAL(int _v = 0, int _p = 0) : v(_v), p(_p) {}
	bool operator < (const VAL &b) const {return (v == b.v && p > b.p) || v < b.v;}
	VAL operator + (const VAL &b) const {return VAL(v + b.v, p);}
} sum[MAXN * 20];

int n, m, q, cnt = 1, pre = 1, siz;
int ch[MAXN][26], len[MAXN], link[MAXN];
int ls[MAXN * 20], rs[MAXN * 20], root[MAXN];
int p[MAXN][21], pos[MAXN], posl[MAXN];
char S[MAXN], T[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void update(int &x, int l, int r, int p) {
	if(!x) x = ++siz;
	if(l == r) return sum[x] = VAL(sum[x].v + 1, p), void();
	int mid = (l + r) >> 1;
	if(p <= mid) update(ls[x], l, mid, p);
	else update(rs[x], mid + 1, r, p);
	sum[x] = max(sum[ls[x]], sum[rs[x]]);
}

int merge(int a, int b, int l, int r) {
	if(!a || !b) return (a | b);
	int now = ++siz, mid = (l + r) >> 1;
	if(l == r) return sum[now] = sum[a] + sum[b], now;
	ls[now] = merge(ls[a], ls[b], l, mid);
	rs[now] = merge(rs[a], rs[b], mid + 1, r);
	sum[now] = max(sum[ls[now]], sum[rs[now]]);
	return now;
}

VAL query(int x, int l, int r, int L, int R) {
	if(!x) return VAL();
	if(L <= l && r <= R) return sum[x];
	int mid = (l + r) >> 1; VAL res = VAL();
	if(L <= mid) res = max(res, query(ls[x], l, mid, L, R));
	if(R > mid) res = max(res, query(rs[x], mid + 1, r, L, R));
	return res;
}

void Extend(int c, int id) {
	int p = pre, np; np = pre = ++cnt;
	len[np] = len[p] + 1; update(root[np], 1, m, id);
	for(; p && !ch[p][c]; p = link[p]) ch[p][c] = np;
	if(!p) {link[np] = 1; return;}
	int q = ch[p][c];
	if(len[q] == len[p] + 1) {link[np] = q; return;}
	int nq = ++cnt;
	link[nq] = link[q]; len[nq] = len[p] + 1; 
	memcpy(ch[nq], ch[q], sizeof ch[nq]);
	link[q] = link[np] = nq;
	for(; p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
}

void DFS(int x, int f) {
	p[x][0] = f;
	for(int i = 1; i <= 20; ++i)
		p[x][i] = p[p[x][i - 1]][i - 1];
	for(auto to : G[x]) {
		DFS(to, x);
		root[x] = merge(root[x], root[to], 1, m);
	}
}

void solve() {
	int a, b, L, R; read(L), read(R), read(a), read(b);
	int l = b - a + 1;
	if(posl[b] < l) return printf("%d %d\n", L, 0), void();
	int cur = pos[b];
	for(int i = 20; ~i; --i)
		if(p[cur][i] && len[p[cur][i]] >= l) cur = p[cur][i];
	VAL res = query(root[cur], 1, m, L, R);
	if(!res.v) res.p = L;
	printf("%d %d\n", res.p, res.v);
}

signed main () {
#ifdef FILE
	freopen("CF666E.in", "r", stdin);
	freopen("CF666E.out", "w", stdout);
#endif
	scanf("%s%d", S + 1, &m); n = strlen(S + 1);
	for(int i = 1, l; i <= m; ++i) {
		scanf("%s", T + 1); l = strlen(T + 1); pre = 1;
		for(int j = 1; j <= l; ++j) Extend(T[j] - 'a', i);
	}
	for(int i = 2; i <= cnt; ++i) G[link[i]].pb(i);
	DFS(1, 0); assert(siz < MAXN * 20);
	for(int i = 1, c, cur = 1, nowlen = 0; i <= n; ++i) {
		c = S[i] - 'a';
		if(ch[cur][c]) cur = ch[cur][c], nowlen++;
		else {
			while(cur && !ch[cur][c]) cur = link[cur];
			if(!cur) cur = 1, nowlen = 0;
			else nowlen = len[cur] + 1, cur = ch[cur][c];
		}
		pos[i] = cur, posl[i] = nowlen;
	}
	read(q);
	while(q--) solve();
	return 0;
}