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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int a[MAXN], pre[MAXN], suf[MAXN], nxt[MAXN];
int pos[MAXN];
bool vis[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void del(int l, int r) { pre[suf[r]] = pre[l], suf[pre[l]] = suf[r]; }

int unused() {
	static int p = 1;
	while(vis[p]) ++p;
	if(p > n) { puts("no"); exit(0); }
	vis[p] = true; return p;
}

void solve(int l, int r) {
	if((r - l) & 1) { puts("no"); exit(0); }
	for(int i = l; i <= r; i = suf[i]) {
		while(nxt[i]) {
			if(nxt[i] > r) { puts("no"); exit(0); }
			solve(suf[i], pre[nxt[i]]); del(suf[i], nxt[i]);
			nxt[i] = nxt[nxt[i]];
		}
	} int s = 0, c = 0, rt = a[pre[l]];
	for(int i = l; i <= r; i = suf[i]) c++, s += (a[i] != 0);
	c = (c + 1) >> 1;
	if(s > c) { puts("no"); exit(0); }
	for(int i = suf[l]; i <= r; i = suf[i]) {
		if(s == c) break;
		if(a[i]) continue;
		a[i] = unused(); ++s;
	} if(s == 0 && c == 1) a[l] = unused();
	for(int i = l; suf[i] <= r; i = suf[i]) {
		while(l < i && suf[i] <= r && !a[pre[i]] && a[i] && a[suf[i]]) {
			assert(a[i] != a[suf[i]]);
			a[pre[i]] = a[suf[i]]; del(i, suf[i]); i = pre[pre[i]];
		}
		while(l <= i && suf[suf[i]] <= r && a[i] && a[suf[i]] && !a[suf[suf[i]]]) {
			assert(a[suf[i]] != a[i]);
			a[suf[suf[i]]] = a[i]; del(suf[i], suf[suf[i]]); i = pre[i];
		}
	} for(int i = l; i <= r; i = suf[i]) if(!a[i]) a[i] = rt;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); m = (n << 1) - 1;
	for(int i = 1; i <= m; ++i) read(a[i]), vis[a[i]] = true;
	if(a[1] && a[m] && (a[1] ^ a[m])) return puts("no"), 0;
	a[1] = a[m] = a[1] | a[m];
	for(int i = 0; i <= m + 1; ++i) pre[i] = i - 1, suf[i] = i + 1;
	for(int i = m; i >= 1; --i) {
		if(!a[i]) continue;
		nxt[i] = pos[a[i]]; pos[a[i]] = i;
	} solve(1, m); puts("yes");
	for(int i = 1; i <= m; ++i) printf("%d ", a[i]);
	return 0;
}