#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
int n,a[500050],f[10000010],po[500050],mu[10000010],su[10000010],sunum,ans;
bool bj[10000010];
void init()
{
	bj[1]=1;mu[1]=1;
	for(int i=2;i<=10000000;++i)
	{
		if(!bj[i])su[++sunum]=i,mu[i]=-1;
		for(int j=1;j<=sunum&&su[j]*i<=10000000;++j)
		{
			bj[su[j]*i]=1;
			if(i%su[j]==0)break;
			mu[su[j]*i]=-mu[i];
		}
	}
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)(po[i]=po[i-1]<<1|1)>=mod?po[i]-=mod:0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),++f[a[i]];
	for(int i=1;i<=5000000;++i)
		for(int j=2*i;j<=10000000;j+=i)f[i]+=f[j];
	int g1=0;
	for(int i=1;i<=10000000;++i)
		if(mu[i]==1)g1=(g1+po[f[i]])%mod;
		else if(mu[i]==-1)g1=(g1+mod-po[f[i]])%mod;
	ans=1ll*f[1]*(po[f[1]]+mod-g1)%mod;
//	printf("%d\n",ans);
	for(int i=2;i<=10000000;++i)
		if(mu[i]==1)ans=(ans+1ll*f[i]*po[f[i]])%mod;
		else if(mu[i]==-1)ans=(ans+1ll*(mod-f[i])*po[f[i]])%mod;
	printf("%d",ans);
	return 0;
}