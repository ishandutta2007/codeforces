#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<map>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}

int n,m,w[100010],fat[100010];
struct Edge{
	int to,nxt;
}edge[100010];
int cnt,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
struct Str{
	char s[22];
};
bool operator<(const Str x,const Str y)
{
	return strcmp(x.s+1,y.s+1)<0;
}
map<Str,int> st;
int stidtot;
int dep[100010],son[100010],siz[1000010];
void dfs1(int cur,int dep)
{
	::dep[cur]=dep; siz[cur]=1;
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		dfs1(edge[i].to,dep+1);
		siz[cur]+=siz[edge[i].to];
		if (!son[cur]||siz[son[cur]]<siz[edge[i].to]) son[cur]=edge[i].to;
	}
}
namespace Q
{
	int ans[100010];
	int lst[100010],nxt[100010],rec[100010];
}
int dp[100010];
map<int,bool> rt[100010];
int rec[100010];
void dfs3(int cur)
{
	rec[++*rec]=dep[cur];
	if (!rt[dep[cur]].count(w[cur])) rt[dep[cur]][w[cur]]=true,dp[dep[cur]]++;
	for (int i=last[cur];i;i=edge[i].nxt)
		dfs3(edge[i].to);
}
void dfs2(int cur)
{
	if (siz[cur]==1)
	{
		for (int i=1;i<=(*rec);i++)
			dp[rec[i]]=0,rt[rec[i]].clear();
		(*rec)=0;
		rec[++*rec]=dep[cur]; rt[dep[cur]][w[cur]]=true; dp[dep[cur]]=1;
		for (int i=Q::lst[cur];i;i=Q::nxt[i]) Q::ans[i]=dp[min(Q::rec[i]+dep[cur],n+1)];
		return;
	}
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=son[cur])
			dfs2(edge[i].to);
	dfs2(son[cur]);
	rec[++*rec]=dep[cur];
	if (!rt[dep[cur]].count(w[cur])) rt[dep[cur]][w[cur]]=true,dp[dep[cur]]++;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=son[cur])
			dfs3(edge[i].to);
	for (int i=Q::lst[cur];i;i=Q::nxt[i]) Q::ans[i]=dp[min(Q::rec[i]+dep[cur],n+1)];
}

int main()
{
	read(n);
	Str tmp;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",tmp.s+1); read(fat[i]);
		if (fat[i]) addedge(fat[i],i);
		if (st.count(tmp)) w[i]=st[tmp];
		else w[i]=st[tmp]=++stidtot;
	}
	read(m);
	for (int i=1,x;i<=m;i++)
	{
		read(x); read(Q::rec[i]);
		Q::nxt[i]=Q::lst[x]; Q::lst[x]=i;
	}
	for (int i=1;i<=n;i++)
		if (!fat[i])
		{
			dfs1(i,1); dfs2(i);
		}
	for (int i=1;i<=m;i++) printf("%d\n",Q::ans[i]);
	return 0;
}