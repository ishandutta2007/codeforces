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
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, p, q;
int b[MAXN];
vec<int> a[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n), read(m); p = q = 0;
	bool flag = true;
	for(int i = 1; i <= n; ++i) {
		int x = 0, y = 0; 
		a[i].resize(m + 1);
		for(int j = 1; j <= m; ++j) read(a[i][j]), b[j] = a[i][j];
		sort(b + 1, b + m + 1);
		for(int j = 1; j <= m; ++j) {
			if(a[i][j] == b[j]) continue;
			if(!x) x = j;
			else if(!y) y = j;
			else flag = false;
		}
		if(x) assert(y);
		else continue;
		if(!p) assert(!q), p = x, q = y;
		else if(p != x || q != y) flag = false;
	}
	if(!flag) return puts("-1"), void();
	if(!p) p = q = 1;
	for(int i = 1; i <= n; ++i) {
		swap(a[i][p], a[i][q]);
		for(int j = 2; j <= m; ++j)
			if(a[i][j] < a[i][j - 1]) return puts("-1"), void();
	}
	printf("%d %d\n", p, q);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}