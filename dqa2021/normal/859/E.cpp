#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}

int n;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt,last[200010],deg[200010],totnode,totdeg;
bool toself;
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}

int dp[200010][2];
bool vis[200010];
void dfs1(int cur)
{
	vis[cur]=true; totnode++,totdeg+=deg[cur];
	for (int i=last[cur];i;i=edge[i].nxt)
		if (!vis[edge[i].to]) dfs1(edge[i].to);
		else if (edge[i].to==cur) toself=true;
}
int inv(int x)
{
	int y=Mod-2,res=1;
	while (y)
	{
		if (y&1) res=(ll)res*x%Mod;
		x=(ll)x*x%Mod;
		y>>=1;
	}
	return res;
}
int dfs2(int cur,int id,int fat=0)   //single node??
{
	if (~dp[cur][id]) return dp[cur][id];
	if (!id)
	{
		dp[cur][id]=1;
		for (int i=last[cur];i;i=edge[i].nxt)
			if (edge[i].to!=fat)
				dp[cur][id]=(ll)dp[cur][id]*dfs2(edge[i].to,0,cur)%Mod;
		return dp[cur][id];
	}
	dp[cur][id]=0;
	int zr=0,sum=1;
	for (int i=last[cur],tmp;i;i=edge[i].nxt)
		if (edge[i].to!=fat)
		{
			tmp=dfs2(edge[i].to,0,cur);
			if (!tmp) zr++;
			else sum=(ll)sum*tmp%Mod;
		}
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat)
		{
			int tzr=zr,tsum=sum;
			if (!dp[edge[i].to][0]) tzr--;
			else tsum=(ll)tsum*inv(dp[edge[i].to][0])%Mod;
			if (tzr) continue;
			else dp[cur][id]=(dp[cur][id]+(ll)tsum*(dp[edge[i].to][0]+dfs2(edge[i].to,1,cur))%Mod)%Mod;
		}
	return dp[cur][id];
}
int ans=1;
int main()
{
	memset(dp,-1,sizeof dp);
	read(n);
	for (int i=1,x,y;i<=n;i++)
	{
		read(x),read(y); deg[x]++,deg[y]++;
		addedge(x,y);
	}
	n<<=1;
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
//			printf("stop at %d\n",i);
			totnode=totdeg=0,toself=false; dfs1(i);
//			printf("tot %d %d\n",totnode,totdeg);
			if ((totdeg>>1)==totnode) if (!toself) ans=ans*2%Mod; else ;
			else ans=(ll)ans*(dfs2(i,0)+dfs2(i,1))%Mod/*,printf("debug %d %d\n",dfs2(i,0),dfs2(i,1))*/;
		}
	printf("%d\n",ans);
	return 0;
}