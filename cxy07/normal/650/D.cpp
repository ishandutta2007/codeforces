//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 8e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Len;
int a[MAXN], Ans[MAXN];
int A[MAXN], B[MAXN], top, tp[MAXN], cnt[MAXN];
int suf[MAXN], pre[MAXN], pbit[MAXN], sbit[MAXN];
vec<int> v;
vec<pii> p[MAXN];
pair<int*, int> stk[MAXN * 10];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void addp(int x, int v) {
	for(; x < MAXN; x += lowbit(x)) 
		pbit[x] = max(pbit[x], v);
}

int askp(int x) {
	int res = 0;
	for(; x; x -= lowbit(x)) res = max(res, pbit[x]);
	return res;
}

void adds(int x, int v) {
	for(; x < MAXN; x += lowbit(x)) {
		if(sbit[x] >= v) continue;
		stk[++top] = mp(&sbit[x], sbit[x]);
		sbit[x] = v;
	}
}

int asks(int x) {
	int res = 0;
	for(; x; x -= lowbit(x)) res = max(res, sbit[x]);
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1; i <= n; ++i) read(a[i]), v.pb(a[i]);
	for(int i = 1; i <= m; ++i)
		read(A[i]), read(B[i]), v.pb(B[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1; i <= n; ++i)
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	for(int i = 1; i <= m; ++i) {
		B[i] = lower_bound(v.begin(), v.end(), B[i]) - v.begin() + 1;
		p[A[i]].pb(mp(B[i], i));
	}
	for(int i = n; i >= 1; --i) {
		suf[i] = asks(MAXN - a[i] - 1) + 1;
		Len = max(Len, suf[i]);
		adds(MAXN - a[i], suf[i]);
		tp[i] = top;
	}
	for(int i = 1; i <= n; ++i) {
		pre[i] = askp(a[i] - 1) + 1;
		if(pre[i] + suf[i] - 1 == Len) cnt[pre[i]]++;
		while(top > tp[i + 1]) {
			*(stk[top].fst) = stk[top].scd;
			top--;
		}
		for(int j = 0, val; j < p[i].size(); ++j) {
			val = p[i][j].fst;
			Ans[p[i][j].scd] = askp(val - 1) + asks(MAXN - val - 1) + 1;
		}
		addp(a[i], pre[i]);
	}
	for(int i = 1; i <= m; ++i) {
		int d = 0;
		if(pre[A[i]] + suf[A[i]] - 1 == Len && cnt[pre[A[i]]] == 1) d = 1;
		Ans[i] = max(Ans[i], Len - d);
		printf("%d\n", Ans[i]);
	}
	return 0;
}