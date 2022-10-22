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
#define double long double
#define endl '\n'

const int MAXN = 1e5 + 10;
const int SIZ = 410;
const int INF = 2e17;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, siz, cnt, Ans;
int a[MAXN];
int v[MAXN], pos[MAXN], L[MAXN], R[MAXN], per[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool cmp(int x, int y) {return a[x] < a[y];}

struct BLOCK {
	int k, b;
	int stk[SIZ], top, p;
	int f(int x) {return v[x] + a[x] * k + b;}
	double at(int i, int j) {
		if(a[i] == a[j]) return v[i] < v[j] ? -INF : INF;
		return 1.0L * (v[i] - v[j]) / (a[i] - a[j]);
	}
	void build(int x) {
		for(int i = L[x]; i <= R[x]; ++i) v[i] = v[i] + a[i] * k + b;
		k = b = top = 0, p = 1;
		for(int i = L[x]; i <= R[x]; ++i) {
			while(top >= 2 && at(per[i], stk[top]) > at(stk[top], stk[top - 1])) top--;
			stk[++top] = per[i];
		}
	}
	pii query() {
		while(p < top && f(stk[p + 1]) >= f(stk[p])) p++;
		return mp(f(stk[p]), stk[p]);
	}
} B[SIZ];

bool Add() {
	pii now = mp(0, 0);
	for(int i = 1; i <= cnt; ++i) now = max(now, B[i].query());
	if(now.fst <= 0) return false;
	Ans += now.fst, v[now.scd] = -INF;
	for(int i = 1; i < pos[now.scd]; ++i) B[i].b += a[now.scd];
	for(int i = L[pos[now.scd]]; i < now.scd; ++i) v[i] += a[now.scd];
	for(int i = now.scd + 1; i <= R[pos[now.scd]]; ++i) v[i] += a[i];
	for(int i = pos[now.scd] + 1; i <= cnt; ++i) B[i].k++;
	B[pos[now.scd]].build(pos[now.scd]);
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); siz = 400; cnt = (n + siz - 1) / siz;
	for(int i = 1; i <= n; ++i) read(a[i]), per[i] = i, v[i] = a[i];
	for(int i = 1; i <= cnt; ++i) {
		L[i] = (i - 1) * siz + 1, R[i] = min(n, i * siz);
		for(int j = L[i]; j <= R[i]; ++j) pos[j] = i;
		sort(per + L[i], per + R[i] + 1, cmp);
		B[i].build(i);
	}
	while(Add());
	printf("%lld\n", Ans);
	return 0;
}