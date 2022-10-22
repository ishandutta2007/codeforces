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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-10;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, t, q;
int l[MAXN], c[MAXN], p[MAXN];
double Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

double calc(int i, int c) {
	if(c < 0) return INF;
	if(c >= l[i]) return 0;
	return 1. * p[i] * l[i] / (1. * (l[i] + c + 1)) / (1. * (l[i] + c));
}

double v(int i) {
	return 1. * p[i] * min(c[i], l[i]) / (1. * (min(c[i], l[i]) + l[i]));
}

struct NODE {
	double v; int x, c;
	NODE(int _x = 0, int _c = -1) {x = _x, c = _c, v = calc(_x, _c);}
	bool operator < (const NODE &b) const {
		return fabs(v - b.v) < eps ? x < b.x : v < b.v;
	}
};

multiset<NODE> nxt, now;

void add() {
	auto it = --nxt.end();
	Ans += it->v; int x = it->x;
	now.erase(NODE(x, c[x] - 1)); now.insert(*it);
	nxt.erase(it); nxt.insert(NODE(x, ++c[x]));
}

void del() {
	auto it = now.begin();
	Ans -= it->v; int x = it->x;
	nxt.erase(NODE(x, c[x])); nxt.insert(*it);
	now.erase(it); now.insert(NODE(x, (--c[x]) - 1));
}

void solve() {
	int i, opt;
	read(opt), read(i); opt = opt == 1 ? 1 : -1;
	nxt.erase(NODE(i, c[i])), now.erase(NODE(i, c[i] - 1)); Ans -= v(i); 
	l[i] += opt;
	nxt.insert(NODE(i, c[i])); now.insert(NODE(i, c[i] - 1)); Ans += v(i);
	while((--nxt.end())->v > (now.begin())->v + eps) del(), add();
	printf("%.10lf\n", Ans);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(t), read(q);
	for(int i = 1; i <= n; ++i) read(p[i]);
	for(int i = 1; i <= n; ++i) read(l[i]);
	for(int i = 1; i <= n; ++i) 
		nxt.insert(NODE(i, 0)), now.insert(NODE(i, -1));
	while(t--) add();
	while(q--) solve();
	return 0;
}