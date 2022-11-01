#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define travel(i,x) for(int i=h[x];i;i=pre[i])
const int N = 1000005, P = 1000000007;
int n, k, sum, fac[N], ans[N], f[N], g[N];
inline int Pow(ll x, int y=P-2){
	int ass=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ass=ass*x%P;
	return ass;
}
int main() {
	scanf("%d%d", &n, &k);
	fac[0]=1;
	rep(i, 1, k+1) fac[i]=(ll)fac[i-1]*i%P, ans[i]=(ans[i-1]+Pow(i, k))%P;
	f[0]=n;
	rep(i, 1, k+1) f[i]=(ll)f[i-1]*(n-i)%P;
	g[k+2]=1;
	for(int i=k+1; i; --i) g[i]=(ll)g[i+1]*(n-i)%P;
	// printf(">>%d\n", f[1]);
	rep(i, 1, k+1) sum=(sum+((k+1-i)&1?-1ll:1ll)*ans[i]*f[i-1]%P*g[i+1]%P*Pow((ll)fac[i]*fac[k+1-i]%P))%P;
	return printf("%d", (sum+P)%P), 0;
}