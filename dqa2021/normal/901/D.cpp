#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;

int n,m;
ll w[100010],cw[100010];
struct Rec{
	int u,v; bool mrk;
	ll ans;
}rec[100010];
struct Edge{
	int to,nxt,id;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y,int id)
{
	edge[++cnt]=(Edge){y,last[x],id},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],id},last[y]=cnt;
}
namespace B
{
	int f[100010];
	int find(int x)
	{
		return f[x]?f[x]=find(f[x]):x;
	}
}
int fat[100010],son[100010],dep[100010],siz[100010];
int top[100010];
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=dep; siz[cur]=1;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to^fat)
		{
			dfs1(edge[i].to,cur,dep+1);
			rec[edge[i].id].ans=w[edge[i].to]-cw[edge[i].to];
			cw[cur]+=rec[edge[i].id].ans;
			siz[cur]+=siz[edge[i].to];
			if (!son[cur]||siz[edge[i].to]>siz[son[cur]]) son[cur]=edge[i].to;
		}
}
void dfs2(int cur,int top)
{
	::top[cur]=top;
	if (siz[cur]==1) return;
	dfs2(son[cur],top);
	for (int i=last[cur];i;i=edge[i].nxt)
		if ((edge[i].to^fat[cur])&&(edge[i].to^son[cur]))
			dfs2(edge[i].to,edge[i].to);
}
void dfs3(int cur)
{
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to^fat[cur])
		{
			dfs3(edge[i].to);
			rec[edge[i].id].ans=w[edge[i].to]-cw[edge[i].to];
			cw[cur]+=rec[edge[i].id].ans;
		}
}
int getlca(int x,int y)
{
	while (top[x]^top[y])
		if (dep[top[x]]<dep[top[y]]) y=fat[top[y]];
		else x=fat[top[x]];
	if (dep[x]<dep[y]) return x; return y;
}
int getdis(int x,int y)
{
	return dep[x]+dep[y]-(dep[getlca(x,y)]<<1);
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=1,x,y;i<=m;i++)
	{
		rec[i].u=read(),rec[i].v=read();
		x=B::find(rec[i].u),y=B::find(rec[i].v);
		if (x^y) rec[i].mrk=true,addedge(rec[i].u,rec[i].v,i),B::f[y]=x;
	}
	dfs1(1,0,1);
	if (w[1]==cw[1])
	{
		puts("YES");
		for (int i=1;i<=m;i++) printf("%lld\n",rec[i].ans);
		return 0;
	}
	dfs2(1,1);
	ll tmp=w[1]-cw[1];
	for (int i=1;i<=m;i++) rec[i].ans=0;
	for (int i=1;i<=n;i++) cw[i]=0;
	bool flg=false;
	for (int i=1;i<=m;i++)
	{
		if (rec[i].mrk) continue;
		if (!(getdis(rec[i].u,rec[i].v)&1))
		{
			if (dep[rec[i].u]&1) cw[rec[i].u]=cw[rec[i].v]=rec[i].ans=tmp/2;
			else cw[rec[i].u]=cw[rec[i].v]=rec[i].ans=-tmp/2;
			flg=true;
			break;
		}
	}
	if (!flg) return puts("NO"),0;
	puts("YES");
	dfs3(1);
	for (int i=1;i<=m;i++) printf("%lld\n",rec[i].ans);
	return 0;
}