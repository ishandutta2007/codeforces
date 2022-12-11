#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int mod=1000000007;
struct linear
{
	int p[5];
	friend bool operator < (linear a,linear b)
	{
		for(int i=0;i<5;++i)if(a.p[i]!=b.p[i])return a.p[i]<b.p[i];
		return 0;
	}
	bool ins(int w)
	{
		for(int i=4;~i;--i)
			if(w>>i&1)
			{
				if(p[i])w^=p[i];
				else
				{
					p[i]=w;
					for(int j=i-1;~j;--j)if((p[i]>>j&1)&&p[j])p[i]^=p[j];
					for(int j=i+1;j<5;++j)if(p[j]>>i&1)p[j]^=p[i];
					return 1;
				}
			}
		return 0;
	}
	int CNT()
	{
		int res=0;
		for(int i=0;i<5;++i)res+=p[i]!=0;
		return res;
	}
}s[410];
bool cmp(linear a,linear b)
{
	int cnta=0,cntb=0;
	for(int i=0;i<5;++i)cnta+=a.p[i]!=0;
	for(int i=0;i<5;++i)cntb+=b.p[i]!=0;
	return cnta<cntb;
}
map<linear,int>mp;
int tot,cur[5],trans[410][410];
void pdfs(int w,int hv)
{
	if(w==5)
	{
		++tot;
		for(int i=0;i<5;++i)s[tot].p[i]=cur[i];
		return ;
	}
	for(int j=0;j<1<<w;++j)
		if((j&hv)==0)
		{
			cur[w]=(1<<w)|j;
			pdfs(w+1,hv|1<<w);
		}
	cur[w]=0;
	pdfs(w+1,hv);
}
struct bian
{
	int nxt,to,w;
}bi[200020];
int n,m,head[100010],num,dis[100010],dep[100010];
inline void add(int from,int to,int w){bi[++num]=bian{head[from],to,w};head[from]=num;}
bool vis[100010],flag;
int cnt[410];
linear now;
int dp[2][410],t;
int hv,h,ans;
void dfs(int v,int fa)
{
	vis[v]=1;dep[v]=dep[fa]+1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(vis[u]&&dep[u]>dep[v]&&!now.ins(dis[u]^dis[v]^bi[i].w))flag=1;
		if(dep[v]>1&&u==1)hv=1,h=dis[v]^bi[i].w;
		if(vis[u])continue;
		dis[u]=dis[v]^bi[i].w;
		dfs(u,v);
	}
}
int main()
{
	pdfs(0,0);
	sort(s+1,s+1+tot,cmp);
//	for(int i=0;i<5;++i)printf("%d ",s[370].p[i]);
	for(int i=1;i<=tot;++i)mp[s[i]]=i;
	for(int i=1;i<=tot;++i)
		for(int j=1;j<=tot;++j)
		{
			linear a=s[i];
			flag=0;
			for(int k=0;k<5;++k)
				if(s[j].p[k]&&!a.ins(s[j].p[k]))
				{
					trans[i][j]=0;
					flag=1;
					break;
				}
			if(!flag)trans[i][j]=mp[a];
		}
	scanf("%d %d",&n,&m);
	for(int i=1,x,y,w;i<=m;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		add(x,y,w),add(y,x,w);
	}
	vis[1]=1;
	t=0;dp[t][1]=1;
	for(int i=head[1],x,a;i;i=bi[i].nxt)
	{
		x=bi[i].to;
		if(!vis[x])
		{
			t^=1;
			memcpy(dp[t],dp[t^1],sizeof(dp[t]));
			memset(now.p,0,sizeof(now.p));
			flag=0;hv=0;
			dis[x]=bi[i].w,dfs(x,1);
			if(!flag)
			{
				a=hv+1;
				int c=mp[now];
				for(int j=1;j<=tot;++j)dp[t][trans[j][c]]=(dp[t][trans[j][c]]+1ll*a*dp[t^1][j])%mod;
			}
			if(hv)
			{
				flag|=!now.ins(h);
				if(!flag)
				{
					int c=mp[now];
					for(int j=1;j<=tot;++j)dp[t][trans[j][c]]=(dp[t][trans[j][c]]+dp[t^1][j])%mod;
				}
			}
		}
	}
	for(int i=1;i<=tot;++i)(ans+=dp[t][i])>=mod?ans-=mod:0;
	printf("%d",ans);
	return 0;
}