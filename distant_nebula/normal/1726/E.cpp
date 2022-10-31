#include <cstdio>
#include <numeric>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
#define pb push_back
using std::vector;
const int N=400005, MOD=998244353, iv2=MOD/2+1;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int T, n, fac[N], inv[N], pw[N], f[N], g[N];
inline void init(int n)
{
	pw[0]=fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD, pw[i]=1ll*pw[i-1]*iv2%MOD;
	inv[n]=qpow(fac[n], MOD-2);
	for(int i=n-1; ~i; --i) inv[i]=1ll*(i+1)*inv[i+1]%MOD;
}
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int main()
{
	scanf("%d", &T);
	f[0]=1, g[0]=1;
	n=300000;
	init(n);
	for(int i=1; i<=n; ++i)
	{
		f[i]=(1ll*(i>1?f[i-2]:0)*(i-1)+f[i-1])%MOD;
		g[i]=2ll*(2*i-1)*g[i-1]%MOD;
		// if(i>=4) inc(f[i], 2ll*(i-3)*f[i-4]%MOD);
	}
	while(T--)
	{
		scanf("%d", &n);
		int ans=0;
		for(int i=0; i*4<=n; ++i)
		{
			inc(ans, 1ll*f[n-i*4]*C(n-2*i, 2*i)%MOD*g[i]%MOD);
		}
		printf("%d\n", ans);
	}
	return 0;
}