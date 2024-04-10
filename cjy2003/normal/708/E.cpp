#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-=mod:x;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,m,p,k,l[1510],nl[1510],sl[1510],jc[200020],jcv[200020],po[1510],pov[1510];
inline int C(int a,int b)
{
	if(a<b||b<0)return 0;
	return 1ll*jc[a]*jcv[b]%mod*jcv[a-b]%mod;
}
void init()
{
	jc[0]=1;
	for(int i=1;i<=200000;++i)jc[i]=1ll*jc[i-1]*i%mod;
	jcv[200000]=kpow(jc[200000],mod-2);
	for(int i=200000;i;--i)jcv[i-1]=1ll*jcv[i]*i%mod;
	int tmp=1ll*(mod+1-p)*kpow(p,mod-2)%mod;
	po[0]=1;
	for(int i=1;i<=m;++i)po[i]=1ll*po[i-1]*tmp%mod;
	tmp=kpow(tmp,mod-2);
	pov[0]=1;
	for(int i=1;i<=m;++i)pov[i]=1ll*pov[i-1]*tmp%mod;
	
	tmp=0;
	for(int i=1;i<=m;++i)
	{
		tmp=(tmp+1ll*C(k,i-1)*pov[i-1])%mod;
		sl[i]=(sl[i-1]+1ll*tmp*C(k,m-i)%mod*po[i])%mod;
	}
}
int main()
{
	int a,b;
	scanf("%d %d %d %d %d",&n,&m,&a,&b,&k);
	if(2*k<m)return printf("1"),0;
	p=1ll*a*kpow(b,mod-2)%mod;
	init();
	int c=1ll*kpow(mod+1-p,2*k-m)*kpow(p,m)%mod;
	l[m]=1;
	for(int t=1;t<=n;++t)
	{
		memset(nl+1,0,m<<2);
		int tmp1=0,tmp2=0,sum=0;
		for(int i=1;i<=m;++i)
		{
			tmp1=(tmp1+1ll*l[i-1]*C(k,i-1)%mod*pov[i-1])%mod;
			tmp2=(tmp2+1ll*C(k,i-1)*pov[i-1])%mod;
			sum=(sum+1ll*(tmp1+1ll*tmp2*l[m-i])%mod*C(k,m-i)%mod*po[i])%mod;
			nl[i]=(1ll*l[m]*sl[i]+mod-sum)%mod;
		}
		for(int i=1;i<=m;++i)nl[i]=1ll*nl[i]*c%mod;
		memcpy(l+1,nl+1,m<<2);
	//	printf("%d:\n",t);
	//	for(int i=1;i<=m;++i)printf("%d ",l[i]);printf("\n");
	}
	printf("%d",l[m]);
	return 0;
}