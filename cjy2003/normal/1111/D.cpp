#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
char s[100010];
int n,q,x,y,id[200],idnum,t[200],inv[100010],jc[100010],jcv[100010],tinv,dp[50050],ans[100][100];
void shai()
{
	inv[1]=1;
	jc[0]=jc[1]=jcv[0]=jcv[1]=1;
	for(int i=2;i<=n;++i)
	{
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		jc[i]=1ll*jc[i-1]*i%mod;
		jcv[i]=1ll*jcv[i-1]*inv[i]%mod;
	}
}
int C(int a,int b)
{
	if(a<b)return 0;
	return 1ll*jc[a]*jcv[b]%mod*jcv[a-b]%mod;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	shai();
	for(int i=1;i<=n;++i)
	{
		if(!id[s[i]])id[s[i]]=++idnum;
		++t[id[s[i]]];
	}
	tinv=1;
	for(int i=1;i<=idnum;++i)
		tinv=1ll*tinv*jcv[t[i]]%mod;	
	for(int i=1;i<=idnum;++i)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int j=1;j<=idnum;++j)
			if(j!=i)
				for(int k=n/2;k>=t[j];--k)
					(dp[k]+=dp[k-t[j]])>=mod?dp[k]-=mod:0;
	//	for(int j=0;j<=2;++j)
	//		printf("%d ",dp[j]);
	//	printf("\n");
		if(t[i]<=n/2)ans[i][i]=2ll*dp[n/2]*C(n/2,t[i])%mod*jc[n/2-t[i]]%mod*jc[n/2]%mod*tinv%mod*jc[t[i]]%mod;
		for(int j=i+1;j<=idnum;++j)
			if(t[i]+t[j]<=n/2)
			{
				int now=0;
				for(int k=0,p=n/2;p>=0;p-=t[j],++k)
				{
					if(k&1)(now+=mod-dp[p])>=mod?now-=mod:0;
					else (now+=dp[p])>=mod?now-=mod:0;
				}
				ans[i][j]=2ll*now*C(n/2,t[i]+t[j])%mod*jc[t[i]+t[j]]%mod*jc[n/2-t[i]-t[j]]%mod*jc[n/2]%mod*tinv%mod;
			}
				
	}
/*	for(int i=1;i<=idnum;++i)
	{
		for(int j=1;j<=idnum;++j)
			printf("%d ",ans[i][j]);
		printf("\n");
	}*/
	scanf("%d",&q);
	int x,y;
	while(q--)
	{
		scanf("%d %d",&x,&y);
		x=id[s[x]],y=id[s[y]];
		if(x>y)swap(x,y);
		printf("%d\n",ans[x][y]);
	}
	return 0;
}