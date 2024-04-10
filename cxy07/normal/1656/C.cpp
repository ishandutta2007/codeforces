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
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int a[MAXN];
set<int> S;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n); S.clear();
	for(int i = 1; i <= n; ++i) read(a[i]), S.insert(a[i]);
	bool eq = true;
	for(int i = 1; i <= n; ++i)
		if(a[i] != a[1]) { eq = false; break; }
	if(eq) return puts("YES"), void();
	int z = 0, o = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] == 0) z = 1;
		if(a[i] == 1) o = 1;
	}
	if(z && o) return puts("NO"), void();
	if(!o) return puts("YES"), void();
	for(int i = 1; i <= n; ++i)
		if(a[i] >= 2 && S.count(a[i] - 1)) return puts("NO"), void();
	puts("YES");
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