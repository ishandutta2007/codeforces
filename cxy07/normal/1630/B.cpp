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

int T, n, k, L, R;
int a[MAXN], b[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n), read(k);
	for(int i = 1; i <= n; ++i) read(a[i]), b[i] = a[i];
	sort(b + 1, b + n + 1); 
	L = R = -1;
	for(int l = 1, r = 1; l <= n; ++l) {
		while(r <= n && (r - l + 1) * 2 - n < k) ++r;
		if(r > n) break;
		if((L == -1) || (R - L) > (b[r] - b[l])) L = b[l], R = b[r];
	}
	printf("%d %d\n", L, R);
	for(int i = 1; i <= n; ++i) a[i] = ((L <= a[i] && a[i] <= R) ? 1 : -1);
	for(int l = 1, r, sum; l <= n; l = r + 1) {
		r = l, sum = a[l];
		while(r < n && sum <= 0) sum += a[++r];
		assert(sum > 0);
		if(--k) printf("%d %d\n", l, r);
		else { printf("%d %d\n", l, n); break; }
	}
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