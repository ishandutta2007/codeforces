#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,k,h[200020],cnt,ans,jc[200020],jcv[200020];
void init()
{
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mod;
	jcv[n]=kpow(jc[n],mod-2);
	for(int i=n;i;--i)jcv[i-1]=1ll*jcv[i]*i%mod;
}
int C(int a,int b){return 1ll*jc[a]*jcv[b]%mod*jcv[a-b]%mod;}
int main()
{
	scanf("%d %d",&n,&k);
	init();
	for(int i=1;i<=n;++i)scanf("%d",&h[i]);
	for(int i=1;i<=n;++i)cnt+=h[i]==h[i%n+1];
	int res=0;
	for(int i=0;2*i<=n-cnt;++i)res=(res+1ll*C(n-cnt,2*i)*C(2*i,i)%mod*kpow(k-2,n-cnt-2*i))%mod;
	(ans=kpow(k,n-cnt)+mod-res)>=mod?ans-=mod:0;
	ans=1ll*ans*jcv[2]%mod;
	ans=1ll*ans*kpow(k,cnt)%mod;
	printf("%d",ans);
	return 0;
}