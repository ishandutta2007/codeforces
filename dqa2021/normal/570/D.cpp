#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}

int n,m;
char s[500010];
struct Edge{
	int to,nxt;
}edge[500010];
int cnt,last[500010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int son[500010],dep[500010],maxdep[500010];
void dfs1(int cur,int dep)
{
	maxdep[cur]=::dep[cur]=dep;
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		dfs1(edge[i].to,dep+1);
		maxdep[cur]=max(maxdep[cur],maxdep[edge[i].to]);
		if (!son[cur]||maxdep[son[cur]]<maxdep[edge[i].to]) son[cur]=edge[i].to;
	}
}
int pos[500010],top[500010];
void dfs2(int cur,int top)
{
	::top[cur]=top; if (cur==top) pos[cur]=(*pos)+1,(*pos)+=maxdep[cur]-dep[cur]+1;
	if (!last[cur]) return;
	dfs2(son[cur],top);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=son[cur])
			dfs2(edge[i].to,edge[i].to);
}
namespace Q
{
	int lst[500010],nxt[500010],rec[500010];
}
bool ans[500010];
int dp[500010];
bool bt[(1<<26)+10];
void dfs3(int cur)
{
	if (!last[cur])
	{
		dp[pos[top[cur]]+dep[cur]-dep[top[cur]]]=(1<<(s[cur]-'a'));
		for (int i=Q::lst[cur];i;i=Q::nxt[i])
			ans[i]=(Q::rec[i]>maxdep[cur]||Q::rec[i]<dep[cur]||bt[dp[pos[top[cur]]+Q::rec[i]-dep[top[cur]]]]);
		return;
	}
	dfs3(son[cur]);
	dp[pos[top[cur]]+dep[cur]-dep[top[cur]]]=(1<<(s[cur]-'a'));
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=son[cur])
		{
			dfs3(edge[i].to);
			for (int j=dep[cur]+1;j<=maxdep[edge[i].to];j++)
				dp[pos[top[cur]]+j-dep[top[cur]]]^=dp[pos[edge[i].to]+j-dep[edge[i].to]];
		}
	for (int i=Q::lst[cur];i;i=Q::nxt[i])
		ans[i]=(Q::rec[i]>maxdep[cur]||Q::rec[i]<dep[cur]||bt[dp[pos[top[cur]]+Q::rec[i]-dep[top[cur]]]]);
}

int main()
{
	bt[0]=true;
	for (int i=0;i<26;i++) bt[1<<i]=true;
	read(n);read(m);
	for (int i=2,x;i<=n;i++)
	{
		read(x); addedge(x,i);
	}
	scanf("%s",s+1);
	dfs1(1,1); dfs2(1,1);
	for (int i=1,x,y;i<=m;i++)
	{
		read(x);read(y);
		Q::nxt[i]=Q::lst[x]; Q::lst[x]=i; Q::rec[i]=y;
	}
	dfs3(1);
	for (int i=1;i<=m;i++)
		if (ans[i]) puts("Yes");
		else puts("No");
	return 0;
}