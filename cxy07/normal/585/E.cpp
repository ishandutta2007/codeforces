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

const int MAXN = 5e5 + 10;
const int MAXW = 1e7 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, w, Ans;
int a[MAXN], mu[MAXW], c[MAXW], p2[MAXN];
int g[MAXW], f[MAXW], s[MAXW];
int pr[MAXW / 10], cnt;
bool np[MAXW];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Modadd(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

void sieve(int siz) {
	mu[1] = 1;
	for(int i = 2; i <= siz; ++i) {
		if(!np[i]) pr[++cnt] = i, mu[i] = -1;
		for(int j = 1; j <= cnt && i * pr[j] <= siz; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) break;
			mu[i * pr[j]] = -mu[i];
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); p2[0] = 1;
	for(int i = 1; i < MAXN; ++i) p2[i] = p2[i - 1] * 2 % mod;
	for(int i = 1; i <= n; ++i) 
		read(a[i]), c[a[i]]++, w = max(w, a[i]);
	sieve(w);
	for(int i = 1; i <= w; ++i) g[i] = c[i];
	for(int i = 1; i <= cnt; ++i)
		for(int j = w / pr[i]; j; --j) 
			Modadd(g[j], g[j * pr[i]]);
	for(int i = 1; i <= w; ++i) s[i] = (mu[i] * g[i] + mod) % mod;
	for(int i = 1; i <= cnt; ++i)
		for(int j = 1; j <= w / pr[i]; ++j)
			Modadd(s[j * pr[i]], s[j]);
	for(int i = 1; i <= w; ++i) f[i] = p2[g[i]] - 1;
	for(int i = 1; i <= cnt; ++i)
		for(int j = 1; j <= w / pr[i]; ++j)
			Modadd(f[j], mod - f[j * pr[i]]);
	for(int i = 2; i <= w; ++i) Modadd(Ans, 1ll * s[i] * f[i] % mod);
	printf("%d\n", Ans);
	return 0;
}