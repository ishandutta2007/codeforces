#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007,inv3=(mod+1)/3;
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
inline int pl(int x,int y){return (x+=y)>=mod?x-=mod:x;}
int n,q,ans[3000010][3],fac[3000010],ifac[3000010];
int C(int a,int b)
{
	return 1ll*fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<=3000001;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[3000001]=kpow(fac[3000001],mod-2);
	for(int i=3000001;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	scanf("%d %d",&n,&q);
	ans[0][0]=ans[0][1]=ans[0][2]=n;
	for(int i=1;i<=3*n;++i)
	{
		ans[i][1]=(1ll*C(3*n+1,i+1)+2*(mod-ans[i-1][1])+mod-ans[i-1][2])*inv3%mod;
		ans[i][2]=pl(ans[i][1],ans[i-1][1]);
		ans[i][0]=pl(ans[i][2],ans[i-1][2]);
	//	printf("%d %d %d\n",ans[i][1],ans[i][2],ans[i][0]);
	}
	while(q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",ans[x][0]);
	}
	return 0;
}