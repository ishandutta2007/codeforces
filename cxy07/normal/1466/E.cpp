//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 5e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, ans = 0;
int x[MAXN], a, b;
int buk[70], p2[70];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n); a = b = ans = 0;
		memset(buk, 0, sizeof buk);
		for(int i = 1; i <= n; ++i) {
			read(x[i]);
			for(int j = 0; j < 60; ++j)
				buk[j] += ((x[i] & (1ll << j)) ? 1 : 0);
		}
		for(int i = 1; i <= n; ++i) {
			a = 0, b = 0;
			for(int j = 0; j < 60; ++j) {
				if(x[i] & (1ll << j)) (a += buk[j] * ((1ll << j) % mod) % mod) %= mod;
				if(x[i] & (1ll << j)) (b += n * ((1ll << j) % mod) % mod) %= mod;
				else (b += buk[j] * ((1ll << j) % mod) % mod) %= mod;
			}
			(ans += a * b % mod) %= mod;
		}
		cout << (ans % mod + mod) % mod << endl;
	}
	return 0;
}