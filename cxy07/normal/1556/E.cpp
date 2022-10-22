//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, q;
int a[MAXN], b[MAXN], sum[MAXN];
int mn[MAXN][21], mx[MAXN][21];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int qmax(int l, int r) {
	int len = log2(r - l + 1);
	return max(mx[l][len], mx[r - (1 << len) + 1][len]);
}

int qmin(int l, int r) {
	int len = log2(r - l + 1);
	return min(mn[l][len], mn[r - (1 << len) + 1][len]);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(q);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= n; ++i) {
		read(b[i]), a[i] = b[i] - a[i];
		sum[i] = sum[i - 1] + a[i];
		mn[i][0] = mx[i][0] = sum[i];
	}
	for(int i = 1; i <= 20; ++i)
		for(int j = 1; j + (1 << i) - 1 <= n; ++j) {
			mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
			mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
		}
	while(q--) {
		int l, r; read(l), read(r);
		if(sum[l - 1] != sum[r] || qmin(l, r) < sum[l - 1]) puts("-1");
		else cout << qmax(l, r) - sum[l - 1] << endl;
	}
	return 0;
}