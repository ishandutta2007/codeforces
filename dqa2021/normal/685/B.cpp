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

int n,m;
struct Edge{
	int to,nxt;
}edge[300010];
int cnt,last[300010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int fat[300010],maxsiz[300010],siz[300010],son[300010],/*id[300010],*/dfn[300010],ans[300010];
void dfs1(int cur)
{
	siz[cur]=1;
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		dfs1(edge[i].to);
		siz[cur]+=siz[edge[i].to];
		if (maxsiz[cur]<siz[edge[i].to]) maxsiz[cur]=siz[edge[i].to],son[cur]=edge[i].to;
	}
}
void dfs2(int cur)
{
	dfn[++*dfn]=cur;// id[cur]=(*dfn);
	if (siz[cur]==1) return;
	dfs2(son[cur]);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=son[cur])
			dfs2(edge[i].to);
}

int main()
{
	read(n);read(m);
	for (int i=2;i<=n;i++)
	{
		read(fat[i]);
		addedge(fat[i],i);
	}
	dfs1(1); dfs2(1);
	for (int i=n;i;i--)
	{
		if (siz[dfn[i]]==1){ans[dfn[i]]=dfn[i];continue;}
		int pos=ans[son[dfn[i]]];
		while (pos!=dfn[i]&&max(siz[dfn[i]]-siz[pos],maxsiz[pos])>max(siz[dfn[i]]-siz[fat[pos]],maxsiz[fat[pos]])) pos=fat[pos];
		ans[dfn[i]]=pos;
	}
	while (m--)
	{
		int x; read(x); printf("%d\n",ans[x]);
	}
	return 0;
}