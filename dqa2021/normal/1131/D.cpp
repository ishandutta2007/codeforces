#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

int n,m;
int fat[2010];
int find(int x)
{
	return x==fat[x]?x:fat[x]=find(fat[x]);
}
struct Edge{
	int to,nxt;
}edge[1000010];
int cnt,last[2010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
bool vis[2010],mrk[2010];
void dfs(int cur)
{
	vis[cur]=true; mrk[cur]=true;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (!vis[edge[i].to])
			dfs(edge[i].to);
		else if (mrk[edge[i].to])
			{
				puts("No"); exit(0);
			}
	mrk[cur]=false;
}
int dp[2010];
bool exst[2010];
int getdp(int x)
{
	if (exst[x]) return dp[x];
	exst[x]=true; dp[x]=1;
	for (int i=last[x];i;i=edge[i].nxt)
		dp[x]=max(dp[x],getdp(edge[i].to)+1);
	return dp[x];
}
char s[1010][1010];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n+m;i++) fat[i]=i;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++)
		{
			int x=find(i),y=find(n+j);
			if (s[i][j]=='=')
			{
				fat[y]=x;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			if (s[i][j]!='='&&find(i)==find(n+j))
			{
				puts("No"); return 0;
			}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			int x=find(i),y=find(n+j);
			if (s[i][j]=='<') addedge(y,x);
			else if (s[i][j]=='>') addedge(x,y);
		}
	for (int i=1;i<=n+m;i++) if (!vis[find(i)]) dfs(find(i));
	puts("Yes");
	for (int i=1;i<n;i++) printf("%d ",getdp(find(i))); printf("%d\n",getdp(find(n)));
	for (int i=1;i<m;i++) printf("%d ",getdp(find(i+n))); printf("%d\n",getdp(find(n+m)));
	return 0;
}