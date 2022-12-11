#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}

int n,k,m;
bool vis[1000100]; int prm[1000100],idk[1000100],ifac[1000100],fac=1;
int pre[1000100],suf[1000100];
int main()
{
	scanf("%d%d",&n,&k),m=k+2;
	idk[1]=1;
	for (int i=2;i<=m;i++)
	{
		fac=1LL*fac*i%Mod;
		if (!vis[i]) prm[++*prm]=i,idk[i]=qpow(i,k);
		for (int j=1;j<=(*prm)&&i*prm[j]<=m;j++)
		{
			int tmp=i*prm[j];
			vis[tmp]=true; idk[tmp]=1LL*idk[i]*idk[prm[j]]%Mod;
			if (i%prm[j]==0) break;
		}
	}
	ifac[m]=qpow(fac,Mod-2);
	for (int i=m-1;i>=0;i--) ifac[i]=1LL*ifac[i+1]*(i+1)%Mod;
	for (int i=2;i<=m;i++) idk[i]=(idk[i]+idk[i-1])%Mod;
	
	pre[0]=1;
	for (int i=1;i<=m;i++)
	{
		pre[i]=1LL*pre[i-1]*(n-i)%Mod;  //negative
	}
	suf[m+1]=1;
	for (int i=m;i;i--)
	{
		suf[i]=1LL*suf[i+1]*(n-i)%Mod;
	}
	
	int ans=0;
	for (int i=1,flg=((m-1)&1?-1:1);i<=m;i++,flg=-flg)
	{
		//idk[i]*pre[i-1]*suf[i+1]*ifac[j-1]*ifac[m-i]*flg
		ans=(ans+1LL*idk[i]*pre[i-1]%Mod*suf[i+1]%Mod*ifac[i-1]%Mod*ifac[m-i]*flg)%Mod;
	}
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}