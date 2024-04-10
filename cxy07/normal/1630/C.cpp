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

int n, m, Ans;
int a[MAXN], pre[MAXN], suf[MAXN];
vec<pii> v, _v;

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
	for(int i = 1; i <= n; ++i) {
		if(!pre[a[i]]) pre[a[i]] = i;
		suf[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i)
		if(pre[i] && pre[i] < suf[i]) v.pb(mp(pre[i], suf[i]));
	sort(v.begin(), v.end());
	for(int i = 0, mx = 0; i < (int)v.size(); ++i) {
		if(v[i].scd < mx) continue;
		_v.pb(v[i]); mx = v[i].scd;
	}
	v = _v;
	for(int i = 0, pre = 0, R = 0; i < (int)v.size(); ++i) {
		if(R < v[i].fst) {
			R = v[i].scd; Ans += v[i].scd - v[i].fst - 1, pre = 0;
			continue;
		}
		assert(R < v[i].scd);
		if(v[i].fst <= pre) Ans += v[i].scd - R;
		else Ans += v[i].scd - R - 1, pre = R;
		R = v[i].scd;
	}
	printf("%d\n", Ans);
	return 0;
}