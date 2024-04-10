#include<cstdio>
#include<vector>
using namespace std;
const int MOD=1E9+7;
vector<int> g[100010];
int n,x,y,ans,f[100010][2][2];
int quick_pow(int x,int n)
{
	int tmp=x,tans=1;
	for(;n;n>>=1)
	{
		if(n&1)tans=1ll*tans*tmp%MOD;
		tmp=1ll*tmp*tmp%MOD;
	}
	return tans;
}
void dfs1(int p,int fa)
{
	int tans1=1,tans2=1,cnt=g[p].size();
	bool flag=0;
	for(int i=0;i<cnt;i++)
	if(g[p][i]!=fa)
	{
		flag=1;
		dfs1(g[p][i],p);
		tans1=1ll*tans1*(f[g[p][i]][0][0]+f[g[p][i]][1][0])%MOD;
		tans2=1ll*tans2*(f[g[p][i]][0][1]+f[g[p][i]][1][1])%MOD;
	}
	if(!flag)
	{
		f[p][0][0]=f[p][1][1]=1;
		f[p][0][1]=f[p][1][0]=0;
		return;
	}
	f[p][0][0]=tans1;
	f[p][1][0]=tans2;
	f[p][0][1]=tans2;
	f[p][1][1]=tans1;
}
void dfs2(int p,int fa)
{
	ans=(0ll+ans+f[p][0][0]+f[p][1][0])%MOD;
	int cnt=g[p].size();
	for(int i=0;i<cnt;i++)
	if(g[p][i]!=fa)
	{
		int ff1,ff2,ff3,ff4;
		ff1=f[g[p][i]][0][0];
		ff2=f[g[p][i]][0][1];
		ff3=f[g[p][i]][1][0];
		ff4=f[g[p][i]][1][1];
		f[g[p][i]][0][0]=1ll*max(1,ff1)*((1ll*f[p][0][0]*quick_pow((ff1+ff3)%MOD,MOD-2)+(p==1&&cnt==1?0:1)*1ll*f[p][1][0]*quick_pow((ff2+ff4)%MOD,MOD-2))%MOD)%MOD;
		f[g[p][i]][0][1]=1ll*max(1,ff2)*((1ll*f[p][1][1]*quick_pow((ff1+ff3)%MOD,MOD-2)+(p==1&&cnt==1?0:1)*1ll*f[p][0][1]*quick_pow((ff2+ff4)%MOD,MOD-2))%MOD)%MOD;
		f[g[p][i]][1][0]=1ll*max(1,ff3)*((1ll*f[p][1][1]*quick_pow((ff1+ff3)%MOD,MOD-2)+(p==1&&cnt==1?0:1)*1ll*f[p][0][1]*quick_pow((ff2+ff4)%MOD,MOD-2))%MOD)%MOD;
		f[g[p][i]][1][1]=1ll*max(1,ff4)*((1ll*f[p][0][0]*quick_pow((ff1+ff3)%MOD,MOD-2)+(p==1&&cnt==1?0:1)*1ll*f[p][1][0]*quick_pow((ff2+ff4)%MOD,MOD-2))%MOD)%MOD;
		dfs2(g[p][i],p);
		f[g[p][i]][0][0]=ff1;
		f[g[p][i]][0][1]=ff2;
		f[g[p][i]][1][0]=ff3;
		f[g[p][i]][1][1]=ff4;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%d\n",ans);
	return 0;
}