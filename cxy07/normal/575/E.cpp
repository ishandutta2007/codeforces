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
#define fst first
#define endl '\n'

const int MAXN = 1e6 + 10;
const int lim = 1e5;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct vec {
	int x, y;
	vec(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	int operator * (const vec &b) const {return x * b.y - y * b.x;}
	vec operator + (const vec &b) const {return vec(x + b.x, y + b.y);}
	vec operator - (const vec &b) const {return vec(x - b.x, y - b.y);}
	double len() {return sqrt(1. * (x * x) + 1. * (y * y));}
	bool operator < (const vec &b) const {return x < b.x || (x == b.x && y < b.y);}
	bool operator == (const vec &b) const {return x == b.x && y == b.y;}
	void print() {printf("%lld %lld\n", x, y);}
} p[MAXN], stk[MAXN];

int n, m, cnt;
int x[MAXN], y[MAXN], v[MAXN];
int top, pos;
double Max;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Add(int x, int y) {p[++cnt] = vec(x, y);}

int dis2(vec a) {return a.x * a.x + a.y * a.y;}

bool cmp(vec a, vec b) {
	static int d; d = (a - p[1]) * (b - p[1]);
	if(d > 0) return true;
	if(!d) return (a - p[1]).len() < (b - p[1]).len();
	return false;
}

double calc(int x) {
	static vec a, b, c;
	a = stk[x + 1] - stk[x], b = stk[x + 2] - stk[x + 1], c = stk[x + 2] - stk[x];
	return (a.len() * b.len() * c.len()) / (2. * abs(a * c));
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) {
		read(x[i]), read(y[i]), read(v[i]);
		if(x[i] - v[i] >= 0) Add(x[i] - v[i], y[i]);
		else {
			Add(0, min(y[i] + (v[i] - x[i]), lim));
			Add(0, max(y[i] - (v[i] - x[i]), 0ll));
		}
		if(x[i] + v[i] <= lim) Add(x[i] + v[i], y[i]);
		else {
			Add(lim, min(y[i] + (x[i] + v[i] - lim), lim));
			Add(lim, max(y[i] - (x[i] + v[i] - lim), 0ll));
		}
		if(y[i] - v[i] >= 0) Add(x[i], y[i] - v[i]);
		else {
			Add(min(x[i] + (v[i] - y[i]), lim), 0);
			Add(max(x[i] - (v[i] - y[i]), 0ll), 0);
		}
		if(y[i] + v[i] <= lim) Add(x[i], y[i] + v[i]);
		else {
			Add(min(x[i] + (y[i] + v[i] - lim), lim), lim);
			Add(max(x[i] - (y[i] + v[i] - lim), 0ll), lim);
		}
	}
	sort(p + 1, p + cnt + 1);
	cnt = unique(p + 1, p + cnt + 1) - p - 1;
	for(int i = 2; i <= cnt; ++i)
		if(p[1].y > p[i].y) swap(p[1], p[i]);
	sort(p + 2, p + cnt + 1, cmp);
	stk[++top] = p[1];
	for(int i = 2; i <= cnt; ++i) {
		while(top > 1 && (stk[top] - stk[top - 1]) * (p[i] - stk[top - 1]) <= 0) top--;
		stk[++top] = p[i];
		if(top >= 3) assert((stk[top] - stk[top - 2]) * (stk[top - 1] - stk[top - 2]));
	}
	stk[++top] = stk[1]; stk[++top] = stk[2];
	for(int i = 1; i <= top - 2; ++i) {
		double len = calc(i);
		if(!pos || len > Max) Max = len, pos = i;
	}
	for(int i = pos; i <= pos + 2; ++i)
		printf("%lld %lld\n", stk[i].x, stk[i].y);
	return 0;
}