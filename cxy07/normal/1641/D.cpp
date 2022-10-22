#pragma GCC optimize("Ofast")
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

const int MAXN = 1e5 + 10;
const int INF = 2e9 + 10;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
const int B = (1 << 20) - 1;
//const int G = 3;
const int base = 1234;

int n, m, idc, Ans = INF;
int a1[MAXN][6], w1[MAXN], p[MAXN], p1[MAXN];
int a[MAXN][6], w[MAXN], pos[MAXN][33];
int buk[MAXN * 33];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

struct HashTable {
	int head[B + 10], siz, tmp[5], tlen;
	int id[MAXN * 32][5], len[MAXN * 32], nxt[MAXN * 32];
	int getK() {
		int t = 0;
		for(int i = 0; i < 5; ++i) t = (1ll * t * base + tmp[i]) & B;
		return (t & B);
	}
	int Insert() {
		int x = getK();
		nxt[++siz] = head[x];
		len[siz] = tlen, memcpy(id[siz], tmp, sizeof tmp); head[x] = siz;
		return siz;
	}
	int find() {
		int x = getK();
		for(int i = head[x]; i; i = nxt[i]) {
			if(len[i] != tlen) continue;
			bool flag = true;
			for(int j = 0; j < tlen; ++j) if(id[i][j] != tmp[j]) { flag = false; break; }
			if(flag) return i;
		}
		return -1;
	}
} T;

bool valid(int p, int q) {
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j)
			if(a[p][i] == a[q][j]) return false;
	return true;
}

int calc(int p) {
	int res = 0;
	for(int i = 1; i <= (1 << m); ++i)
		res += buk[abs(pos[p][i])] * (pos[p][i] < 0 ? -1 : 1);
	return res;
}

void solve(int l, int r, int L, int R) {
	if(l > r || L > R) return;
	if(L == R) {
		for(int i = l; i <= r; ++i)
			if(valid(p[i], L)) Ans = min(Ans, w[p[i]] + w[L]);
		return;
	}
	int mid = (L + R) >> 1, pl = l - 1, pr = r + 1;
	for(int i = L; i <= mid; ++i)
		for(int j = 1; j <= (1 << m); ++j) buk[abs(pos[i][j])]++;
	for(int i = l; i <= r; ++i) {
		if(calc(p[i])) p1[++pl] = p[i];
		else p1[--pr] = p[i];
	}
	for(int i = l; i <= r; ++i) p[i] = p1[i];
	assert(pl + 1 == pr);
	solve(pr, r, mid + 1, R);
	for(int i = L; i <= mid; ++i)
		for(int j = 1; j <= (1 << m); ++j) buk[abs(pos[i][j])]--;
	solve(l, pl, L, mid);
}

signed main () {
#ifdef FILE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	read(n), read(m);
	int tmp = 0;
	for(int i = 1; i <= n; ++i) {
		++tmp; p[tmp] = tmp;
		for(int j = 1; j <= m; ++j) read(a1[tmp][j]); 
		read(w1[tmp]); 
		for(int j = 1; j <= m; ++j) {
			int flag = false;
			for(int k = j + 1; k <= m; ++k)
				if(a1[tmp][j] == a1[tmp][k]) { tmp--; flag = true; break; }
			if(flag) break;
		}
	}
	n = tmp;
	sort(p + 1, p + n + 1, [&](int a, int b) { return w1[a] < w1[b]; });
	for(int i = 1; i <= n; ++i) {
		memcpy(a[i], a1[p[i]], sizeof a[i]);
		w[i] = w1[p[i]];
	}
	for(int i = 1, c, t; i <= n; ++i) {
		sort(a[i] + 1, a[i] + m + 1); 
		c = t = 0;
		for(int S = 0, loc; S < (1 << m); ++S) {
			memset(T.tmp, 0, sizeof T.tmp); T.tlen = 0;
			for(int j = 0; j < m; ++j)
				if((S >> j) & 1) T.tmp[T.tlen++] = a[i][j + 1];
			loc = T.find(); 
			if(loc == -1) loc = T.Insert();
			pos[i][++c] = loc * ((popc(S) & 1) ? -1 : 1);
		}
	}
	for(int i = 1; i <= n; ++i) p[i] = i;
	solve(1, n, 1, n);
	if(Ans == INF) puts("-1");
	else printf("%d\n", Ans);
	return 0;
}