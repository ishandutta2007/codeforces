//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define vec vector

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, lim = 1e6, ans;
int a[MAXN], cnt[MAXN], p2[MAXN];
int f[MAXN], g[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	p2[0] = 1;
	for(int i = 1; i <= n; ++i) 
		read(a[i]), f[a[i]]++, p2[i] = p2[i - 1] * 2 % mod;
	for(int i = 0; i <= 20; ++i) 
		for(int j = 0; j <= lim; ++j) 
			if(j & (1 << i)) f[j - (1 << i)] += f[j], cnt[j]++;
	for(int i = 0; i <= lim; ++i)
		g[i] = (p2[f[i]] - 1 + mod) % mod;
	for(int i = 0; i <= lim; ++i)
		(ans += (g[i] * ((cnt[i] & 1) ? -1 : 1)) % mod) %= mod;
	printf("%lld\n", (ans % mod + mod) % mod);
	return 0;
}