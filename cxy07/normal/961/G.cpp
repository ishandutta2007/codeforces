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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,k,w,ans;
int fac[MAXN],ifac[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int qpow(int x,int b) {
	int res = 1;
	for(;b;b >>= 1,(x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

int C(int x,int k) {
	if(x < k) return 0;
	return fac[x] * ifac[k] % mod * ifac[x - k] % mod;
}

int S(int n,int x) {
	int res = 0;
	for(int k = 0,opt = 1;k <= x; ++k) {
		(res += C(x,k) * opt * qpow(x - k,n) % mod) %= mod;
		opt *= -1;
	}
	(res *= ifac[x]) %= mod;
	return (res % mod + mod) % mod;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(k);
	for(int i = 1,tmp;i <= n; ++i) {
		read(tmp);
		(w += tmp) %= mod;
	}
	fac[0] = ifac[0] = 1;
	for(int i = 1;i <= 2e5; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[(int)2e5] = inv(fac[(int)2e5]);
	for(int i = 2e5 - 1;i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	ans += S(n - 1,k - 1) * w % mod;
	(ans += S(n - 1,k) * (n - 1 + k) % mod * w % mod) %= mod;
	printf("%lld\n",(ans % mod + mod) % mod);
	return 0;
}