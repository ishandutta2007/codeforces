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
#define ui unsigned int 
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 210;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, p, q;
ui binom[MAXN], Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

ui Gcd(ui x, ui y) {
	if(!y) return x;
	return Gcd(y, x % y);
}

void calc(ui x, ui y) {
	static vec<ui> up, dn; up.clear(), dn.clear();
	for(ui i = x; i > x - y; --i) up.pb(i);
	for(ui i = 2; i <= y; ++i) dn.pb(i);
	for(auto &a : up) {
		for(auto &b : dn) {
			int g = Gcd(a, b);
			a /= g, b /= g;
		}
	}
	binom[y] = 1;
	for(auto a : up) binom[y] *= a;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(p), read(q);
	for(ui i = 0; i <= min(p, n - 1); ++i) calc(n, i);
	for(int t = 1; t <= q; ++t) {
		ui now = 0, pw = 1;
		for(ui i = 0; i <= min(p, n - 1); ++i, pw *= t) now += binom[i] * pw;
		Ans ^= now * t;
	}
	printf("%u\n", Ans);
	return 0;
}