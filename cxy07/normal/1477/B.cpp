//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, q;
int L[MAXN], R[MAXN];
int sum[MAXN << 2], tag[MAXN << 2];
char s[MAXN], t[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void build(int x, int l, int r) {
	sum[x] = 0, tag[x] = -1;
	if(l == r) {
		sum[x] = t[l] - '0';
		tag[x] = -1;
		return;
	}
	sum[x << 1] = sum[x << 1 | 1] = 0;
	int mid = (l + r) >> 1;
	build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
}

void pushdown(int x, int l, int r) {
	if(tag[x] == -1) return;
	int mid = (l + r) >> 1;
	tag[x << 1] = tag[x << 1 | 1] = tag[x];
	sum[x << 1] = tag[x] * (mid - l + 1);
	sum[x << 1 | 1] = tag[x] * (r - mid);
	tag[x] = -1;
}

void update(int x, int l, int r, int L, int R, int v) {
	if(L <= l && r <= R) {
		sum[x] = (r - l + 1) * v;
		tag[x] = v;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x, l, r);
	if(L <= mid) update(x << 1, l, mid, L, R, v);
	if(R > mid) update(x << 1 | 1, mid + 1, r, L, R, v);
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
}

int query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return sum[x];
	int mid = (l + r) >> 1, res = 0;
	pushdown(x, l, r);
	if(L <= mid) res += query(x << 1, l, mid, L, R);
	if(R > mid) res += query(x << 1 | 1, mid + 1, r, L, R);
	return res;
}

void solve() {
	read(n), read(q);
	scanf("%s", s + 1), scanf("%s", t + 1);
	n = strlen(s + 1);
	build(1, 1, n);
	for(int i = 1; i <= q; ++i) read(L[i], R[i]);
	for(int i = q; i >= 1; --i) {
		int s = query(1, 1, n, L[i], R[i]);
		int len = R[i] - L[i] + 1;
		if(s * 2 == len) return puts("NO"), void();
		if(s * 2 < len) update(1, 1, n, L[i], R[i], 0);
		else update(1, 1, n, L[i], R[i], 1);
	}
	for(int i = 1; i <= n; ++i)
		if(query(1, 1, n, i, i) != s[i] - '0') return puts("NO"), void();
	puts("YES");
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}