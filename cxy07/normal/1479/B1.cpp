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

int n, m, Ans;
int a[MAXN], nxt[MAXN], pos[MAXN];

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
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= n; ++i) pos[i] = n + 1;
	for(int i = n; i >= 1; --i) {
		nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	nxt[0] = n + 1;
	int p0 = 0, p1 = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[p0] != a[i] && a[p1] != a[i]) { ++Ans, (nxt[p0] < nxt[p1] ? p0 : p1) = i; } 
		else if(a[p1] != a[i]) p1 = i, ++Ans;
		else if(a[p0] != a[i]) p0 = i, ++Ans;
		else p0 = p1 = i;
	}
	printf("%d\n", Ans);
	return 0;
}