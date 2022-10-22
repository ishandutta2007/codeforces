//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm(x,mod - 2)
#define lowbit(x) (x & (-x))

const int MAXN = 310;
const int INF = 2e9;
const int G = 3;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;

int n,k,ans;
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

int C(int x,int y) {
	return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int f(int n,int k) {
	int res = 0;
	for(int i = 1;i <= n; ++i) 
		(res += C(n,i) * qpow(k - 1,n - i) % mod) %= mod;
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(k);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i <= n; ++i)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = qpow(fac[n],mod - 2);
	for(int i = n - 1;i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	ans = qpow(f(n,k),n);
	for(int i = 1,opt = 1;i <= n; ++i) {
		opt *= -1;
		(ans += opt * C(n,i) * qpow(f(n - i,k),n) % mod * qpow(qpow(k - 1,n),i) % mod) %= mod;
	} 
	printf("%lld\n",(ans % mod + mod) % mod);
	return 0;
}