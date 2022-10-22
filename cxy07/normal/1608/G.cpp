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

const int MAXN = 4e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], siz;
	int nxt[MAXN], to[MAXN]; char w[MAXN];
	void add(int x, int y, char c) {
		nxt[++siz] = head[x];
		to[siz] = y, w[siz] = c, head[x] = siz;
	}
} e;

struct info {
	int id, l, r, o;
	info(int _id = 0, int _l = 0, int _r = 0, int _o = 0) :
		id(_id), l(_l), r(_r), o(_o) {}
};

int n, m, q, Ans[MAXN], lim;
int fa[MAXN], siz[MAXN], son[MAXN], top[MAXN], dep[MAXN], maxd[MAXN];
int loc[MAXN];
int sa[MAXN], rnk[MAXN], ht[MAXN], st[MAXN][21];
int idx[MAXN], idlen[MAXN], num;
int up_pos[MAXN], dn_pos[MAXN];
int FT[MAXN];
vec<int> G[MAXN];
vec<info> qs[MAXN];
string S, _t, up[MAXN], dn[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS1(int x, int fa) {
	::fa[x] = fa, siz[x] = 1, dep[x] = dep[fa] + 1;
	for(int i = e.head[x], to; i; i = e.nxt[i]) {
		to = e.to[i]; if(to == fa) continue;
		DFS1(to, x);
		siz[x] += siz[to];
		if(!son[x] || siz[to] > siz[son[x]]) son[x] = to;
	}
}

void DFS2(int x, int t, char c) {
	top[x] = t; 
	maxd[top[x]] = max(maxd[top[x]], dep[x]);
	if(c) dn[top[x]].pb(c);
	for(int i = e.head[x], to; i; i = e.nxt[i]) {
		to = e.to[i]; if(to == fa[x]) continue;
		if(to == son[x]) DFS2(to, t, e.w[i]);
		else DFS2(to, to, e.w[i]);
	}
}

void SuffixArray() {
	static int c[MAXN], x[MAXN], y[MAXN], n, m;
	n = S.size(), m = 125;
	for(int i = 0; i < n; ++i) c[x[i] = S[i]]++;
	for(int i = 1; i <= m; ++i) c[i] += c[i - 1];
	for(int i = n - 1; ~i; --i) sa[--c[x[i]]] = i;
	for(int k = 1, cnt; k <= n; k <<= 1) {
		cnt = 0;
		for(int i = n - k; i < n; ++i) y[cnt++] = i;
		for(int i = 0; i < n; ++i) if(sa[i] >= k) y[cnt++] = sa[i] - k;
		for(int i = 1; i <= m; ++i) c[i] = 0;
		for(int i = 0; i < n; ++i) c[x[i]]++;
		for(int i = 1; i <= m; ++i) c[i] += c[i - 1];
		for(int i = n - 1; ~i; --i) {
			sa[--c[x[y[i]]]] = y[i], y[i] = 0;
		}
		swap(x, y); x[sa[0]] = cnt = 1;
		for(int i = 1; i < n; ++i) {
			if(y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) x[sa[i]] = cnt;
			else x[sa[i]] = ++cnt;
		}
		if(cnt == n) break;
		m = cnt;
	}
	for(int i = 0; i < n; ++i) rnk[sa[i]] = i;
	for(int i = 0, k = 0, j; i < n; ++i) {
		if(rnk[i] == 0) continue;
		if(k) k--;
		j = sa[rnk[i] - 1];
		while(j + k < n && i + k < n && S[i + k] == S[j + k]) k++;
		ht[rnk[i] - 1] = k;
	}
	for(int i = 0; i < n - 1; ++i) st[i][0] = ht[i];
	for(int p = 1; p < 20; ++p)
		for(int i = 0; i + (1 << p) - 1 < n - 1; ++i)
			st[i][p] = min(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
}

int LCP(int a, int b) {
	if(a == b) return S.size() - a + 1;
	a = rnk[a], b = rnk[b];
	if(a > b) swap(a, b);
	--b; int len = __lg(b - a + 1);
	return min(st[a][len], st[b - (1 << len) + 1][len]);
}

int LCA(int x, int y) {
	while(top[x] ^ top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return (dep[x] < dep[y] ? x : y);
}

int chk(int suf) {
	suf = sa[suf];
	for(int i = 1, l; i <= num; ++i) {
		l = LCP(idx[i], suf);
		if(l < idlen[i]) return S[suf + l] < S[idx[i] + l] ? -1 : 1;
		suf += idlen[i];
	}
	return 0;
}

void add(int x, int y, int _L, int _R, int _t) {
	static int idx2[MAXN], idlen2[MAXN], num2;
	num = num2 = 0;
	while(top[x] ^ top[y]) {
		if(dep[top[x]] > dep[top[y]]) {
			++num;
			idx[num] = up_pos[top[x]] + maxd[top[x]] - dep[x];
			idlen[num] = dep[x] - dep[top[x]] + 1;
			x = fa[top[x]];
		} else {
			++num2;
			idx2[num2] = dn_pos[top[y]];
			idlen2[num2] = dep[y] - dep[top[y]] + 1;
			y = fa[top[y]];
		}
	}
	if(dep[x] > dep[y]) {
		++num;
		idx[num] = up_pos[top[x]] + maxd[top[x]] - dep[x];
		idlen[num] = dep[x] - dep[y];
	} else if(dep[x] < dep[y]) {
		++num2; 
		int t = dep[x] - dep[top[y]] + (top[y] != 1);
		idx2[num2] = dn_pos[top[y]] + t;
		idlen2[num2] = dep[y] - dep[x];
	}
	while(num2) {
		idx[++num] = idx2[num2];
		idlen[num] = idlen2[num2--];
	}
	int L = -1, R = S.size();
	for(int i = 19; ~i; --i) {
		if(L + (1 << i) >= (int)S.size()) continue;
		if(chk(L + (1 << i)) < 0) L += (1 << i);
	}
	for(int i = 19; ~i; --i) {
		if(R - (1 << i) < 0) continue;
		if(chk(R - (1 << i)) > 0) R -= (1 << i);
	}
	if(~L) qs[L].pb(info(_t, _L, _R, -1));
	if(R >= 1) qs[R - 1].pb(info(_t, _L, _R, 1));
}

void Add(int x, int v) { for(; x < MAXN; x += lowbit(x)) FT[x] += v; }

int Ask(int x) {
	int res = 0;
	for(; x; x -= lowbit(x)) res += FT[x];
	return res;
}

signed main () {
#ifdef FILE
	freopen("CF1608G.in", "r", stdin);
	freopen("CF1608G.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i = 1, x, y; i < n; ++i) {
		char c; cin >> x >> y >> c;
		e.add(x, y, c), e.add(y, x, c);
	}
	for(int i = 1; i <= m; ++i) {
		cin >> _t; _t.pb('|');
		S += _t;
		loc[i] = S.size() - 1; 
	}
	lim = S.size();
	DFS1(1, 0), DFS2(1, 1, 0);
	for(int i = 1; i <= n; ++i) {
		if(top[i] != i) continue;
		up[i] = dn[i]; 
		reverse(up[i].begin(), up[i].end());
		up_pos[i] = S.size(); S += up[i];
		dn_pos[i] = S.size(); S += dn[i];
	}
	SuffixArray();
	for(int i = 1, l, r, u, v; i <= q; ++i) {
		cin >> u >> v >> l >> r;
		add(u, v, l, r, i);
	}
	for(int i = 0, p; i < (int)S.size(); ++i) {
		if(sa[i] < lim && S[sa[i]] != '|') {
			p = lower_bound(loc + 1, loc + m + 1, sa[i]) - loc;
			if(p <= m) Add(p, 1);
		}
		for(auto q : qs[i]) Ans[q.id] += q.o * (Ask(q.r) - Ask(q.l - 1));
	}
	for(int i = 1; i <= q; ++i) cout << Ans[i] << endl;
	return 0;
}