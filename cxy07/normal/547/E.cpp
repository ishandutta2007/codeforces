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
const int MAXQ = 5e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, q, cnt, Ans[MAXQ];
int loc[MAXN], fa[MAXN], dfn[MAXN], dfnc, siz[MAXN];
int ch[MAXN][26], fail[MAXN], FT[MAXN];
char s[MAXN];
vec<int> G[MAXN];
vec<pii> qs[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void Insert(int id) {
	int len = strlen(s + 1), cur = 0;
	for(int i = 1; i <= len; ++i) {
		int &to = ch[cur][s[i] - 'a'];
		if(!to) to = ++cnt;
		fa[to] = cur; cur = to;
	}
	loc[id] = cur;
}

void build() {
	queue<int> Q;
	for(int i = 0; i < 26; ++i)
		if(ch[0][i]) Q.push(ch[0][i]);
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(int i = 0; i < 26; ++i) {
			if(ch[x][i]) fail[ch[x][i]] = ch[fail[x]][i], Q.push(ch[x][i]);
			else ch[x][i] = ch[fail[x]][i];
		}
	}
}

void DFS(int x) {
	dfn[x] = ++dfnc, siz[x] = 1;
	for(auto to : G[x]) DFS(to), siz[x] += siz[to];
}

void add(int x, int v) {
	for(; x < MAXN; x += lowbit(x)) FT[x] += v;
}

int ask(int x) {
	int res = 0;
	for(; x; x -= lowbit(x)) res = res + FT[x];
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(q);
	for(int i = 1; i <= n; ++i) scanf("%s", s + 1), Insert(i);
	build();
	for(int i = 1; i <= cnt; ++i) G[fail[i]].pb(i);
	DFS(0);
	for(int i = 1, l, r, x; i <= q; ++i) {
		read(l), read(r), read(x);
		if(l > 1) qs[l - 1].pb(mp(x, -i));
		qs[r].pb(mp(x, i));
	}
	for(int i = 1, cur, x; i <= n; ++i) {
		cur = loc[i];
		while(cur) add(dfn[cur], 1), cur = fa[cur];
		for(auto q : qs[i]) {
			x = loc[q.fst];
			Ans[abs(q.scd)] += (q.scd > 0 ? 1 : -1) * (ask(dfn[x] + siz[x] - 1) - ask(dfn[x] - 1));
		}
	}
	for(int i = 1; i <= q; ++i) printf("%d\n", Ans[i]);
	return 0;
}