//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, c2, c3, Ans;
int a[MAXN];
bool flag = true;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n); c2 = c3 = false, Ans = 0; int mx = 0;
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 2; i < n; ++i) mx = max(mx, a[i]);
	if(n == 3 && (a[2] & 1)) return puts("-1"), void();
	if(mx == 1) return puts("-1"), void();
	for(int i = 2; i < n; ++i) {
		if((a[i] & 1) && a[i] > 1) c3 = true;
		if(a[i] % 2 == 0) c2 = true;
	}
	for(int i = 2; i < n; ++i)
		Ans += (a[i] + 1) / 2;
	cout << Ans << endl;
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