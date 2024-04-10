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
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct vec {
	int x, y;
	vec(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	vec operator + (const vec &b) const {return vec(x + b.x, y + b.y);}
	vec operator - (const vec &b) const {return vec(x - b.x, y - b.y);}
	vec operator % (const vec &b) const {return vec((x % mod + mod) % mod, (y % mod + mod) % mod);}
	int operator ^ (const vec &b) const {return (x % mod * b.y % mod - y % mod * b.x % mod + mod) % mod;}
	int operator * (const vec &b) const {return x * b.y - y * b.x;}
} p[MAXN], sum[MAXN];

int n, m, b, X, Y;
int Ans, marea;
int pro[MAXN], pro2[MAXN];
ull area, cur;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void modadd(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

int count(int a, int b) {
	int res = 0, tmp;
	res = ((p[a] * (sum[b] - sum[a])) % mod + mod) % mod;
	tmp = (pro2[b - 1] % mod - pro2[a - 1] % mod - (b - a) * (pro[a - 1] % mod) % mod);
	tmp = (tmp % mod + mod) % mod;
	return res + tmp;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) {
		read(p[i].x), read(p[i].y);
		X = min(X, p[i].y), Y = min(Y, p[i].y);
		p[i + n] = p[i];
	}
	for(int i = 1; i <= (n << 1); ++i) {
		sum[i] = (sum[i - 1] + p[i]) % mod;
		pro[i] = (pro[i - 1] + p[i + 1] * p[i]) % mod;
		pro2[i] = (pro2[i - 1] + pro[i]) % mod;
	}
	for(int i = 1; i <= n; ++i) {
		area += p[i + 1] * p[i];
		modadd(marea, p[i + 1] ^ p[i]);
	}
	b = 3;
	cur = p[2] * p[1] + p[3] * p[2] + p[1] * p[3];
	for(int a = 1; a <= n; ++a) {
		while(b < (n << 1) && (cur + p[b + 1] * p[b] + p[a] * p[b + 1] - p[a] * p[b]) * 2ull <= area) {
			cur += p[b + 1] * p[b] + p[a] * p[b + 1] - p[a] * p[b];
			b++;
		}
		if(cur * 2ull <= area)
			(Ans += ((b - a - 1) * marea % mod - count(a, b) * 2 % mod + mod) % mod) %= mod;
		cur += p[a + 1] * p[b] - p[a] * p[b] - p[a + 1] * p[a];
	}
	printf("%lld\n", Ans);
	return 0;
}