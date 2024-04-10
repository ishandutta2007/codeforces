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

int n, m, k, p;
int h[MAXN], a[MAXN], f[MAXN];
int L, R, mid;
priority_queue<pii> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool chk(int val) {
	while(Q.size()) Q.pop();
	for(int i = 1; i <= n; ++i) {
		f[i] = val;
		if(val - a[i] * m >= h[i]) continue;
		Q.push(mp(-(val / a[i]), i));
	}
	for(int i = 1; i <= m; ++i) {
		if(!Q.size()) break;
		for(int j = 1, x; j <= k; ++j) {
			if(!Q.size()) break;
			pii now = Q.top(); Q.pop();
			x = now.scd;
			if(f[x] - a[x] * i < 0) return false;
			f[x] += p;
			if(f[x] - a[x] * m < h[x])
				Q.push(mp(-(f[x] / a[x]), x));
		}
	}
	for(int i = 1; i <= n; ++i)
		if(f[i] - a[i] * m < h[i]) return false;
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m), read(k), read(p);
	for(int i = 1; i <= n; ++i) {
		read(h[i]), read(a[i]);
		R = max(R, m * a[i] + h[i]);
	}
	while(L < R) {
		mid = (L + R) >> 1;
		if(chk(mid)) R = mid;
		else L = mid + 1;
	}
	printf("%lld\n", L);
	return 0;
}