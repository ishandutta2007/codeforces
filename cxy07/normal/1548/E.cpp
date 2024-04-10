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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct NODE {
	int x, y, o;
	NODE(int _x = 0, int _y = 0, int _o = 0) : x(_x), y(_y), o(_o) {}
	bool operator < (const NODE &b) const { return (x < b.x) || (x == b.x && abs(o) < abs(b.o)); }
} s[MAXN << 1];

int n, m, x, cnt, Ans;
int a[MAXN], b[MAXN], lima[MAXN], limb[MAXN];
int stk[MAXN], mx[MAXN], top;
int FT[MAXN << 1];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void GetLim(int *a, int *l, int n) {
	top = 0; mx[0] = (int)2e5 + 10;
	for(int i = 1; i <= n; ++i) {
		while(top && a[stk[top]] > a[i]) { mx[top - 1] = max(mx[top - 1], mx[top]); top--; }
		l[i] = mx[top]; stk[++top] = i; mx[top] = a[i];
	}
	top = 0;
	for(int i = n; i >= 1; --i) {
		while(top && a[stk[top]] >= a[i]) { mx[top - 1] = max(mx[top - 1], mx[top]); top--; }
		l[i] = min(mx[top], l[i]); stk[++top] = i; mx[top] = a[i];
	}
	for(int i = 1; i <= n; ++i) l[i] = max(l[i], a[i]);
}

void Add(int x, int v) { 
	x += MAXN;
	for(; x; x -= lowbit(x)) FT[x] += v; 
}

int Ask(int x) {
	x += MAXN; int res = 0;
	for(; x < (MAXN << 1); x += lowbit(x)) res += FT[x];
	return res;
}

signed main () {
#ifdef FILE
	freopen("CF1548E.in", "r", stdin);
	freopen("CF1548E.out", "w", stdout);
#endif
	read(n), read(m), read(x);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= m; ++i) read(b[i]);
	GetLim(a, lima, n); GetLim(b, limb, m);
	for(int i = 1; i <= m; ++i)
		s[++cnt] = NODE(b[i], limb[i], 0);
	for(int i = 1, L, R, pos; i <= n; ++i) {
		L = x - lima[i], R = x - a[i];
		pos = x - a[i] + 1;
		if(L > 0) s[++cnt] = NODE(L, pos, -1);
		if(R > 0) s[++cnt] = NODE(R, pos, 1);
	}
	sort(s + 1, s + cnt + 1);
	for(int i = 1; i <= cnt; ++i) {
		if(!s[i].o) Add(s[i].y, 1);
		else Ans += Ask(s[i].y) * s[i].o;
	}
	printf("%lld\n", Ans);
	return 0;
}