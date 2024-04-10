#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
}

int n,m,fat[100010];
struct Edge{
	int to,nxt;
}edge[100010];
int cnt,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int siz[100010],dep[100010],son[100010],gnd[100010][17];
void dfs1(int cur,int dep)
{
	gnd[cur][0]=fat[cur];
	for (int i=1;i<17&&gnd[cur][i-1];gnd[cur][i]=gnd[gnd[cur][i-1]][i-1],i++);
	::dep[cur]=dep; siz[cur]=1;
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		dfs1(edge[i].to,dep+1);
		siz[cur]+=siz[edge[i].to];
		if (!son[cur]||siz[son[cur]]<siz[edge[i].to]) son[cur]=edge[i].to;
	}
}
int getnode(int cur,int dep)
{
	int tmp=(::dep[cur]-dep);
	for (int i=16;~i;i--)
		if ((tmp>>i)&1) cur=gnd[cur][i];
	return cur;
}
namespace Q
{
	int ans[100010];
	int lst[100010],nxt[100010],rec[100010];
}
int dp[100010],rec[100010];   //::rec and Q::rec
void dfs3(int cur)
{
	rec[++*rec]=dep[cur]; dp[dep[cur]]++;
	for (int i=last[cur];i;i=edge[i].nxt)
		dfs3(edge[i].to);
}
void dfs2(int cur)
{
	if (siz[cur]==1)
	{
		for (int i=1;i<=(*rec);i++) dp[rec[i]]=0; (*rec)=0;
		rec[++*rec]=dep[cur]; dp[dep[cur]]++;
		for (int i=Q::lst[cur];i;i=Q::nxt[i]) Q::ans[i]=dp[Q::rec[i]]-1;
		return;
	}
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=son[cur])
			dfs2(edge[i].to);
	dfs2(son[cur]); rec[++*rec]=dep[cur]; dp[dep[cur]]++;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=son[cur])
			dfs3(edge[i].to);
	for (int i=Q::lst[cur];i;i=Q::nxt[i]) Q::ans[i]=dp[Q::rec[i]]-1;
}

int main()
{
	read(n);
	for (int i=1;i<=n;i++)
	{
		read(fat[i]); if (fat[i]) addedge(fat[i],i);
	}
	for (int i=1;i<=n;i++) if (!fat[i]) dfs1(i,1);
	read(m);
	for (int i=1,x,y,z;i<=m;i++)
	{
		read(x);read(y);
		if (y+1>dep[x]) continue;
		z=dep[x];
		x=getnode(x,dep[x]-y);
		Q::nxt[i]=Q::lst[x];
		Q::lst[x]=i;
		Q::rec[i]=z;
	}
	for (int i=1;i<=n;i++) if (!fat[i]) dfs2(i);
	for (int i=1;i<m;i++) printf("%d ",Q::ans[i]); printf("%d\n",Q::ans[m]);
	return 0;
}