#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int S=2001,T=2002,inf=0x3f3f3f3f;
struct bian
{
	int nxt,to;
}bi[1000000];
int n,bg[1010],len[1010],ch[10000010][2],up[10000010],fail[10000010],tot=1,p[10000010];
int head[1010],num,ans,match[1010];
char s[10000010];
bool vis[1010],visl[1010],visr[1010];
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
void ins(int id)
{
	int u=1,c;
	for(int i=1;i<=len[id];++i)
	{
		c=s[bg[id]+i]-'a';
		if(!ch[u][c])ch[u][c]=++tot;
		u=ch[u][c];
	}
	up[u]=u;p[u]=id;
}
void build()
{
	queue<int>q;
	q.push(1);ch[0][0]=ch[0][1]=1;
	int x;
	while(!q.empty())
	{
		x=q.front();q.pop();
		if(!up[x])up[x]=up[fail[x]];
		for(int i=0;i<=1;++i)
			if(ch[x][i])fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
			else ch[x][i]=ch[fail[x]][i];
	}
}
void work(int id)
{
	memset(vis,0,sizeof(vis));
	int u=1,c,x;
	for(int i=1;i<=len[id];++i)
	{
		c=s[bg[id]+i]-'a';
		u=ch[u][c];
		x=up[u];
		while(p[x]&&!vis[p[x]])
		{
			if(p[x]!=id)add(p[x],id);
			vis[p[x]]=1,x=up[fail[x]];
		}
	}
}
int dfs(int v)
{
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(vis[u])continue;
		vis[u]=1;
		if(!match[u]||dfs(match[u]))
		{
			match[u]=v;
			return 1;
		}
	}
	return 0;
}
void dfs1(int v)
{
	visl[v]=1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(match[u]!=v)
		{
			visr[u]=1;
			if(!visl[match[u]])dfs1(match[u]);
		}
	}
}
int main()
{
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+sum+1);
		bg[i]=sum,len[i]=strlen(s+sum+1);
		ins(i);
		sum+=len[i];
	}
	build();
	for(int i=1;i<=n;++i)work(i);
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))++ans;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)if(match[i])vis[match[i]]=1;
	for(int i=1;i<=n;++i)if(!vis[i])dfs1(i);
//	for(int i=1;i<=n;++i)printf("%d ",visl[i]);printf("\n");
//	for(int i=1;i<=n;++i)printf("%d ",visr[i]);printf("\n");
	printf("%d\n",n-ans);
	for(int i=1;i<=n;++i)if(visl[i]&&!visr[i])printf("%d ",i);
	return 0;
}