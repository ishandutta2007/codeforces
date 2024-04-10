#include <cstdio>
#include <algorithm>
#define rinc(x, y) x=(x+(y))%MOD
const int N=405;
int MOD;
int n, f[N][N], g[N], inv[N], fac[N], ans;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int main()
{
	scanf("%d%d", &n, &MOD);
	inv[0]=inv[1]=fac[0]=1;
	for(int i=2; i<=n; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	for(int i=1; i<=n; ++i) inv[i]=1ll*inv[i-1]*inv[i]%MOD, fac[i]=1ll*i*fac[i-1]%MOD;
	for(int i=1; i<=n; ++i) for(int j=1; j<=i; ++j) inc(g[i], C(i-1, j-1));
	for(int i=1; i<=n; ++i) g[i]=1ll*g[i]*inv[i]%MOD;
	for(int i=1; i<=n; ++i) f[i][i]=g[i];
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; i+j+1<=n; ++j) for(int k=1; k<=i; ++k)
		{
			rinc(f[i+j+1][k+j], 1ll*f[i][k]*g[j]);
		}
	}
	for(int i=1; i<=n; ++i) rinc(ans, 1ll*fac[i]*f[n][i]);
	printf("%d\n", ans);
	return 0;
}