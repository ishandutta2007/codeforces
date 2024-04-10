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

const int MAXN = 5e5 + 10;
const int INF = 2e17;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct NODE {
	int x, y, opt;
	NODE(int _x = 0, int _y = 0, int _o = 0) :
		x(_x), y(_y), opt(_o) {}
} s[MAXN];

int n, m, Ans;
int aa[MAXN], bb[MAXN];
int bit[MAXN];
vec<int> v;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int Getid(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void add(int x, int v) {
	for(; x < MAXN; x += lowbit(x))
		bit[x] = min(bit[x], v);
}

int ask(int x) {
	int res = INF;
	for(; x; x -= lowbit(x)) res = min(res, bit[x]);
	return res;
}

bool cmpy1(NODE a, NODE b) {
	if(a.y ^ b.y) return a.y > b.y;
	if(a.x ^ b.x) return a.x < b.x;
	return a.opt > b.opt;
}

bool cmpy2(NODE a, NODE b) {
	if(a.y ^ b.y) return a.y < b.y;
	if(a.x ^ b.x) return a.x < b.x;
	return a.opt > b.opt;
}

bool cmpy3(NODE a, NODE b) {
	if(a.y ^ b.y) return a.y > b.y;
	if(a.x ^ b.x) return a.x < b.x;
	return a.opt < b.opt;
}

bool cmpy4(NODE a, NODE b) {
	if(a.y ^ b.y) return a.y < b.y;
	if(a.x ^ b.x) return a.x < b.x;
	return a.opt < b.opt;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(aa[i]), v.pb(aa[i]);
	for(int i = 1; i <= n; ++i) {
		read(bb[i]); v.pb(bb[i]);
		s[i * 2 - 1] = NODE(aa[i], bb[i], 1);
		s[i * 2] = NODE(bb[i], aa[i], 0);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(s + 1, s + (n << 1) + 1, cmpy1);
	memset(bit, 0x3f, sizeof bit);
	for(int i = 1, p; i <= (n << 1); ++i) {
		p = Getid(s[i].x);
		if(s[i].opt) add(p, s[i].y - s[i].x - abs(s[i].y - s[i].x));
		else Ans = min(Ans, ask(p) + s[i].x - s[i].y - abs(s[i].x - s[i].y));
	}
	sort(s + 1, s + (n << 1) + 1, cmpy2);
	memset(bit, 0x3f, sizeof bit);
	for(int i = 1, p; i <= (n << 1); ++i) {
		p = Getid(s[i].x);
		if(s[i].opt) add(p, -s[i].y - s[i].x - abs(s[i].y - s[i].x));
		else Ans = min(Ans, ask(p) + s[i].x + s[i].y - abs(s[i].x - s[i].y));
	}
	sort(s + 1, s + (n << 1) + 1, cmpy3);
	memset(bit, 0x3f, sizeof bit);
	for(int i = 1, p; i <= (n << 1); ++i) {
		p = Getid(s[i].x);
		if(!s[i].opt) add(p, s[i].y - s[i].x - abs(s[i].y - s[i].x));
		else Ans = min(Ans, ask(p) + s[i].x - s[i].y - abs(s[i].x - s[i].y));
	}
	sort(s + 1, s + (n << 1) + 1, cmpy4);
	memset(bit, 0x3f, sizeof bit);
	for(int i = 1, p; i <= (n << 1); ++i) {
		p = Getid(s[i].x);
		if(!s[i].opt) add(p, -s[i].y - s[i].x - abs(s[i].y - s[i].x));
		else Ans = min(Ans, ask(p) + s[i].x + s[i].y - abs(s[i].x - s[i].y));
	}
	for(int i = 1; i <= n; ++i)
		Ans += abs(aa[i] - bb[i]);
	printf("%lld\n", Ans);
	return 0;
}