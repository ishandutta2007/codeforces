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

const int MAXN = (1 << 18) + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, tcnt, L, R;
int a[MAXN], l[MAXN], r[MAXN], v[MAXN];
LL Ans;
vec<int> idx[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void add(int x) { for(; x <= n; x += lowbit(x)) v[x]++; }
int ask(int x) { int r = 0; for(; x; x -= lowbit(x)) r += v[x]; return r; }

signed main () {
#ifdef FILE
	freopen("CF1693E.in", "r", stdin);
	freopen("CF1693E.out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) {
		read(a[i]); idx[a[i]].pb(i);
		r[a[i]] = i; if(!l[a[i]]) l[a[i]] = i;
	}
	L = 0, R = n + 1;
	for(int i = n, nl, nr; i >= 1; --i) {
		if(!idx[i].size()) continue;
		nl = min(l[i], R + 1), nr = max(r[i], L - 1);
		for(auto p : idx[i]) add(p);
		L = nl, R = nr; Ans += ask(R) - ask(L - 1);
	}
	printf("%lld\n", Ans);
	return 0;
}