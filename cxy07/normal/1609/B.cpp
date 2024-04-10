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

int n, q, cnt = 0;
char s[MAXN], t[10];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool ok(int x) {
	if(x + 2 > n || x < 1) return false;
	return (s[x] == 'a' && s[x + 1] == 'b' && s[x + 2] == 'c');
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(q);
	scanf("%s", s + 1);
	for(int i = 1; i + 2 <= n; ++i) cnt += ok(i);
	while(q--) {
		int x; read(x), scanf("%s", t + 1);
		cnt -= ok(x - 2) + ok(x - 1) + ok(x) + ok(x + 1) + ok(x + 2);
		s[x] = t[1];
		cnt += ok(x - 2) + ok(x - 1) + ok(x) + ok(x + 1) + ok(x + 2);
		printf("%d\n", cnt);
	}
	return 0;
}