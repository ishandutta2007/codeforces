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

const int MAXN = 1010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, tot = 1, maxc;
int col[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve(int l, int r, int c) {
	maxc = max(maxc, c);
	if(r - l + 1 <= k) {
		for(int i = l; i <= r; ++i)
			for(int j = i + 1; j <= r; ++j) col[i][j] = c;
		return;
	} 
	int len = (r - l + 1) / k, cnt = (r - l + 1) % k;
	for(int i = 1, d, cur = l; i <= k; ++i) {
		d = len + (i <= cnt); solve(cur, cur + d - 1, c + 1);
		for(int a = l; a < cur; ++a)
			for(int b = cur; b <= cur + d - 1; ++b) col[a][b] = c;
		cur += d;
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k);
	solve(1, n, 1); printf("%d\n", maxc);
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) printf("%d ", col[i][j]);
	return 0;
}