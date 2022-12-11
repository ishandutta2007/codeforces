#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int kpow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=1ll*x*x%mod)
		if(y&1)s=1ll*s*x%mod;
	return s;
}
int n,m,d[30][50050],p[30];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&d[i][j]);
	int fac=1;
	for(int i=2;i<=n;++i)fac=1ll*fac*i%mod;
	int ifac=kpow(fac,mod-2),ans=0;
	for(int j=1;j<=m;++j)
	{
		for(int i=1;i<=n;++i)p[i]=d[i][j]-1;
		sort(p+1,p+1+n);
		int tmp=1;
		for(int i=1;i<=n;++i)tmp=1ll*tmp*(p[i]-i+1)%mod;
		ans=(1ll*ans+fac+mod-tmp)%mod;
	}
	ans=1ll*ans*ifac%mod;
	printf("%d",ans);
	return 0;
}