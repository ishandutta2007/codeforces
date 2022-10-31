#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
const int N=200005, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, a[N];
int fac[N*2], inv[N*2];
inline void init(int n)
{
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD;
	inv[n]=qpow(fac[n], MOD-2);
	for(int i=n-1; ~i; --i) inv[i]=1ll*(i+1)*inv[i+1]%MOD;
}
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int main()
{
	scanf("%d", &n);
	for(int i=0; i<=n; ++i) scanf("%d", a+i);
	if(!a[0]) return puts("0"), 0;
	init(n+a[0]);
	int ans=0;
	for(int i=0; i<=n; ++i) if(a[i])
	{
		inc(ans, C(i+a[i], i+1));
	}
	printf("%d\n", ans);
	return 0;
}