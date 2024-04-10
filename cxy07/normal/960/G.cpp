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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
const int mod = 998244353;
const int G = 3;
//const int base = 131;

int n,m,a,b,Gi;
int fac[MAXN],ifac[MAXN];
int rev[MAXN],lim,l;
int f[MAXN],g[MAXN],A[MAXN],B[MAXN];

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

void Init(int n) {
	lim = 1,l = 0;
	while(n >= lim) lim <<= 1,l++;
	for(int i = 0;i < lim; ++i)
		rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (l - 1)));
}

void NTT(int *A,int opt) {
	for(int i = 0;i < lim; ++i)
		if(i > rev[i]) swap(A[i],A[rev[i]]);
	for(int mid = 1,w;mid < lim; mid <<= 1) {
		w = qpow(opt == 1 ? G : Gi,(mod - 1) / (mid << 1));
		for(int i = 0,now,x,y;i < lim; i += (mid << 1)) {
			now = 1;
			for(int j = 0;j < mid; ++j,(now *= w) %= mod) {
				x = A[i + j],y = A[i + j + mid] * now % mod;
				A[i + j] = (x + y) % mod;
				A[i + j + mid] = ((x - y) % mod + mod) % mod;
			}
		}
	}
	if(opt == -1) {
		int ilim = inv(lim);
		for(int i = 0;i < lim; ++i) A[i] = A[i] * ilim % mod;
	} 
}

void GetG(int n,int c) {
	Init(n << 1);
	for(int i = 0,powc = 1;i < n; ++i) {
		A[i] = f[n - i - 1] * fac[n - i - 1] % mod;
		B[i] = powc * ifac[i] % mod;
		(powc *= c) %= mod;
	}
	for(int i = n;i < lim; ++i) A[i] = B[i] = 0;
	NTT(A,1); NTT(B,1);
	for(int i = 0;i < lim; ++i) (A[i] *= B[i]) %= mod;
	NTT(A,-1);
	for(int i = 0;i < n; ++i) g[i] = A[n - i - 1] * ifac[i] % mod;
}

void solve(int n) {
	if(!n) return (void)(f[0] = 1);
	int m = n / 2;
	solve(m);
	Init(n << 1);
	GetG(m + 1,m);
	for(int i = 0;i <= m; ++i) A[i] = f[i],B[i] = g[i];
	for(int i = m + 1;i < lim; ++i) A[i] = B[i] = 0;
	NTT(A,1); NTT(B,1);
	for(int i = 0;i < lim; ++i) (A[i] *= B[i]) %= mod;
	NTT(A,-1);	
	if(n & 1) {
		for(int i = 0;i <= n; ++i)
			f[i] = ((i ? A[i - 1] : 0) + (n - 1) * A[i] % mod) % mod;
	} else for(int i = 0;i <= n; ++i) f[i] = A[i];
}

int C(int x,int y) {
	if(x < y) return 0;
	return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(a); read(b);
	Gi = inv(G);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i <= 1e6; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[(int)1e6] = inv(fac[(int)1e6]);
	for(int i = 1e6 - 1;i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	solve(n - 1);
	printf("%lld\n",(f[a + b - 2] * C(a + b - 2,a - 1) % mod + mod) % mod);
	return 0;
}