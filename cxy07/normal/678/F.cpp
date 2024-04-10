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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, pcnt;
int opt[MAXN];
int ed[MAXN], p[MAXN], q[MAXN << 2], h, t;
double cc[MAXN];
LL Ans[MAXN];
LL x[MAXN], y[MAXN];
vec<int> D[MAXN << 2], Q[MAXN << 2];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool cmp1(int a, int b) {
	return (x[a] < x[b]) || (x[a] == x[b] && y[a] < y[b]);
}

bool cmp3(int a, int b) { return x[a] * y[b] < x[b] * y[a]; }

void update(int x, int l, int r, int L, int R, int i) {
	if(L <= l && r <= R) return D[x].pb(i), void();
	int mid = (l + r) >> 1;
	if(L <= mid) update(x << 1, l, mid, L, R, i);
	if(R > mid) update(x << 1 | 1, mid + 1, r, L, R, i);
}

void addq(int x, int l, int r, int p, int i) {
	Q[x].pb(i);
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(p <= mid) addq(x << 1, l, mid, p, i);
	else addq(x << 1 | 1, mid + 1, r, p, i);
}

bool slope(int i, int j, int k) {
	return ((y[j] - y[i]) * (x[k] - x[j]) < (y[k] - y[j]) * (x[j] - x[i]));
}

LL val(int id, LL a, LL b) {
	return a * x[id] + b * y[id];
}

void calc(int pos) {
	if(!D[pos].size() || !Q[pos].size()) return;
	h = 1, t = 0;
	for(auto a : D[pos]) {
		while(h <= t && x[q[t]] == x[a]) t--;
		while(h < t && slope(q[t - 1], q[t], a)) t--;
		q[++t] = a;
	}
	if(h > t) return;
	int p = h;
	for(auto a : Q[pos]) {
		while(p < t && val(q[p + 1], x[a], y[a]) > val(q[p], x[a], y[a])) p++;
		Ans[a] = max(Ans[a], val(q[p], x[a], y[a]));
	}
}

void solve(int x, int l, int r) {
	calc(x);
	if(l == r) return;
	int mid = (l + r) >> 1;
	solve(x << 1, l, mid), solve(x << 1 | 1, mid + 1, r);
}

signed main () {
#ifdef FILE
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	read(n); memset(Ans, -0x3f, sizeof Ans);
	for(int i = 1, xx; i <= n; ++i) { 
		read(opt[i]);
		if(opt[i] == 1) read(x[i]), read(y[i]);
		if(opt[i] == 2) read(xx), ed[xx] = i;
		if(opt[i] == 3) read(x[i]), y[i] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		if(opt[i] == 1 && !ed[i]) ed[i] = n;
		if(opt[i] == 1) p[++pcnt] = i;
	}
	sort(p + 1, p + pcnt + 1, cmp1);
	for(int i = 1; i <= pcnt; ++i) update(1, 1, n, p[i], ed[p[i]], p[i]);
	pcnt = 0;
	for(int i = 1; i <= n; ++i)
		if(opt[i] == 3) p[++pcnt] = i;
	sort(p + 1, p + pcnt + 1, cmp3);
	for(int i = 1; i <= pcnt; ++i) addq(1, 1, n, p[i], p[i]);
	solve(1, 1, n);
	for(int i = 1; i <= n; ++i)
		if(opt[i] == 3) {
			if(Ans[i] == Ans[0]) puts("EMPTY SET");
			else printf("%lld\n", Ans[i]);
		}
	return 0;
}