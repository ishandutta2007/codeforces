#include<cstdio>
#include<cstring> 
#include<algorithm>
using namespace std;
#define MN 1000000
char s[MN+5];
int nxp[MN+5],nxd[MN+5],lsp[MN+5],t[MN+5],f[MN+5];
int main()
{
	int n,i,sd=0,sp=0,l,r,mid,ans;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;++i)
	{
		lsp[i]=lsp[i-1];
		if(s[i]=='P')++sp,lsp[i]=i;
		if(s[i]=='*')++sd;
	}
	nxp[n+1]=nxd[n+1]=t[n+1]=n+1;
	for(i=n;i;--i)
	{
		nxp[i]=s[i]=='P'?i:nxp[i+1];
		nxd[i]=s[i]=='*'?i:nxd[i+1];
	}
	if(sp==1)
	{
		int ls=0,rs=0,lp,rp;
		for(i=1;s[i]!='P';++i)if(s[i]=='*'&&!ls++)lp=i;
		for(i=n;s[i]!='P';--i)if(s[i]=='*'&&!rs++)rp=i;
		printf("%d %d",max(ls,rs),ls>rs?i-lp:rs>ls?rp-i:min(i-lp,rp-i));
		return 0;
	}
	for(l=1,r=n;l<=r;)
	{
		mid=l+r>>1;
		memset(f,0,sizeof(f));f[1]=1;
		for(i=1;i<=n;++i)if(f[i])
		{
			if(s[i]=='.')f[i+1]=1;
			if(s[i]=='P')f[min(nxp[i+1],min(i+mid+1,n+1))]=1;
			if(s[i]=='*')
			{
				if(nxp[i]>n||nxp[i]-i>mid)continue;
				f[nxp[i]+1]=1;
				if(nxp[nxp[i]+1]<=n&&nxp[nxp[i]+1]-i<=mid)
					f[lsp[min(nxp[i]+mid,n)]>nxp[nxp[i]+1]?lsp[min(nxp[i]+mid,n)]:min(nxp[i]+mid+1,n+1)]=1;
			}
		}
		if(f[n+1])ans=mid,r=mid-1;else l=mid+1;
	}
	printf("%d %d",sd,ans);
}