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

const int MAXN = (1 << 19) + 10;
const int MAXK = 20;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, rt = 1, cnt = 1;
int mx[MAXN], mn[MAXN], Ans[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k);
	memset(Ans, 0x3f, sizeof Ans);
	memset(mx, -0x3f, sizeof mx), memset(mn, 0x3f, sizeof mn);
	for(int i = 1, x; i <= n; ++i) read(x), mx[x] = mn[x] = 0;
	for(int p = 0; p < k; ++p) {
		for(int x = 0, y, mxx, mnx, mxy, mny; x < (1 << k); ++x) {
			if((x >> p) & 1) continue;
			y = x ^ (1 << p);
			Ans[x] = Ans[y] = min(Ans[x], Ans[y]);
			Ans[x] = min(Ans[x], mn[y] - mx[x] + (1 << p));
			Ans[y] = min(Ans[y], mn[x] - mx[y] + (1 << p));
			mxx = mx[x], mnx = mn[x], mxy = mx[y], mny = mn[y];
			mx[x] = max(mxx, mxy + (1 << p));
			mn[x] = min(mnx, mny + (1 << p));
			mx[y] = max(mxy, mxx + (1 << p));
			mn[y] = min(mny, mnx + (1 << p));
		}
	}
	for(int i = 0; i < (1 << k); ++i) printf("%d ", Ans[i]);
	return 0;
}