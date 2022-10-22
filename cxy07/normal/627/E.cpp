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

const int MAXN = 3010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct NODE {
	int x, y;
	NODE(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	bool operator < (const NODE &b) const {return y < b.y || (y == b.y && x < b.x);}
} s[MAXN], t[MAXN];

struct List {
	int _pre[MAXN], _nxt[MAXN];
	void del(int x) {
		_pre[_nxt[x]] = _pre[x];
		_nxt[_pre[x]] = _nxt[x];
	}
	int pre(int x) {return _pre[x];}
	int nxt(int x) {return _nxt[x];}
} L;

int n, m, c, k, tot, add;
int Ans, sum[MAXN];
vec<int> opt[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void modify(int x, int k) {
	add -= t[x].y * sum[x];
	add += t[L.pre(x)].y * sum[x];
	if(L.pre(x) && k > 1) modify(L.pre(x), k - 1);
	if(L.pre(x)) sum[L.pre(x)] += sum[x];
	sum[x] = 0;
}

void calc(int p) {
	tot = 0;
	for(int i = 1; i <= n; ++i) opt[i].clear();
	for(int i = 1; i <= c; ++i) {
		if(s[i].x < p) continue;
		t[++tot] = s[i];
		L._pre[tot] = tot - 1, L._nxt[tot] = tot + 1;
		sum[tot] = 0; opt[s[i].x].pb(tot);
	}
	int pos = 0; add = 0;
	for(int i = 1; i <= m; ++i) {
		while(pos + 1 <= tot && t[pos + 1].y <= i) pos++;
		if(pos - k + 1 >= 1) sum[pos - k + 1]++, add += t[pos - k + 1].y;
	}
	Ans += add;
	for(int i = n; i > p; --i) {
		for(auto x : opt[i])
			modify(x, k), L.del(x);
		Ans += add;
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m), read(c), read(k);
	for(int i = 1; i <= c; ++i) read(s[i].x), read(s[i].y);
	sort(s + 1, s + c + 1);
	for(int i = 1; i <= n; ++i) calc(i);
	printf("%lld\n", Ans);
	return 0;
}