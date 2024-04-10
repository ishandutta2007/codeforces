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
#define y1 _y1

const int MAXN = 5010;
const int MAXQ = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct Query {
	int opt, d, x, y, len, id;
} qs[MAXQ];

int n, q, Ans[MAXQ];
int FT[MAXN << 1], FT1[2][MAXN << 1][MAXN];
vec<Query> now;
vec<pair<int*, int>> stk;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Add(int x, int v) {
	for(; x < (MAXN << 1); x += lowbit(x))
		FT[x] += v;
}

int Ask(int x) {
	int res = 0;
	for(; x; x -= lowbit(x)) res += FT[x];
	return res;
}

void Add1(int id, int x, int y, int v) {
	for(; x < (MAXN << 1); x += lowbit(x))
		for(int i = y; i < MAXN; i += lowbit(i))
			FT1[id][x][i] += v;
}

int Ask1(int id, int x, int y) {
	int res = 0;
	for(; x; x -= lowbit(x))
		for(int i = y; i; i -= lowbit(i))
			res += FT1[id][x][i];
	return res;
}

void AddMatrix(int id, int x1, int x2, int y1, int y2) {
	if(x1 > x2 || y1 > y2) return;
	Add1(id, x1, y1, 1); Add1(id, x1, y2 + 1, -1);
	Add1(id, x2 + 1, y1, -1); Add1(id, x2 + 1, y2 + 1, 1);
}

void Insert(Query p) {
	int x = p.x, y = p.y, xy = p.x + p.y;
	Add(xy, 1); Add(xy + p.len + 1, -1);
	AddMatrix(0, xy, xy + p.len, 1, x - 1);
	AddMatrix(1, xy, xy + p.len, 1, y - 1);
}

int count(Query p) {
	int x = p.x, y = p.y;
	return Ask(x + y) - Ask1(0, x + y, x) - Ask1(1, x + y, y);
}

void roll() {
	while(stk.size()) {
		*(stk.back().fst) = stk.back().scd;
		stk.pop_back();
	}
}

void calc() {
	memset(FT, 0, sizeof FT);
	memset(FT1, 0, sizeof FT1);
	for(auto qs : now) {
		if(qs.opt == 1) Insert(qs);
		else Ans[qs.id] += count(qs);
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(q);
	for(int i = 1; i <= q; ++i) {
		read(qs[i].opt);
		if(qs[i].opt == 1)
			read(qs[i].d), read(qs[i].x), read(qs[i].y), read(qs[i].len);
		else read(qs[i].x), read(qs[i].y);
		qs[i].id = i;
	}
	now.clear();
	for(int i = 1; i <= q; ++i)
		if(qs[i].opt == 2 || qs[i].d == 1) now.pb(qs[i]);
	calc();
	now.clear();
	for(int i = 1; i <= q; ++i) {
		Query tmp = qs[i];
		if(qs[i].opt == 2 || qs[i].d == 2)
			tmp.y = n - tmp.y + 1, now.pb(tmp);
	}
	calc();
	now.clear();
	for(int i = 1; i <= q; ++i) {
		Query tmp = qs[i];
		if(qs[i].opt == 2 || qs[i].d == 3)
			tmp.x = n - tmp.x + 1, now.pb(tmp);
	}
	calc();
	now.clear();
	for(int i = 1; i <= q; ++i) {
		Query tmp = qs[i];
		if(qs[i].opt == 2 || qs[i].d == 4) {
			tmp.x = n - tmp.x + 1, tmp.y = n - tmp.y + 1;
			now.pb(tmp);
		}
	}
	calc();
	for(int i = 1; i <= q; ++i)
		if(qs[i].opt == 2) printf("%d\n", Ans[i]);
	return 0;
}