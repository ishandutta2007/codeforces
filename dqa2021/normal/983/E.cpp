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

int n,m,q;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt,last[200010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int fat[200010],siz[200010],son[200010],dep[200010];
int top[200010],id[200010];
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=dep; siz[cur]=1;
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		dfs1(edge[i].to,cur,dep+1);
		siz[cur]+=siz[edge[i].to];
		if (!son[cur]||siz[son[cur]]<siz[edge[i].to]) son[cur]=edge[i].to;
	}
}
void dfs2(int cur,int top)
{
	::top[cur]=top; id[cur]=++*id;
	if (siz[cur]==1) return;
	dfs2(son[cur],top);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to^son[cur])
			dfs2(edge[i].to,edge[i].to);
}
int getlca(int x,int y)
{
	while (top[x]^top[y])
		if (dep[top[x]]<dep[top[y]]) y=fat[top[y]];
		else x=fat[top[x]];
	if (dep[x]<dep[y]) return x; return y;
}
namespace B  //Bus
{
	struct Edge{
		int to,nxt;
	}edge[400010];
	int cnt,last[200010];
	inline void addedge(int x,int y)
	{
		edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	}
	int gnd[200010][18],maxdep[200010];
	void dfs3(int cur)
	{
		maxdep[cur]=cur;
		for (int i=last[cur];i;i=edge[i].nxt)
			if (dep[edge[i].to]<dep[maxdep[cur]]) maxdep[cur]=edge[i].to;
		for (int i=::last[cur];i;i=::edge[i].nxt)
		{
			dfs3(::edge[i].to);
			if (dep[maxdep[::edge[i].to]]<dep[maxdep[cur]]) maxdep[cur]=maxdep[::edge[i].to];
		}
	}
	void dfs4(int cur)
	{
		//printf("maxdep %d: %d\n",cur,maxdep[cur]);
		if (maxdep[cur]^cur)
		{
			gnd[cur][0]=maxdep[cur];
			for (int i=1;i<18&&gnd[cur][i-1];i++)
				gnd[cur][i]=gnd[gnd[cur][i-1]][i-1];
		}
		for (int i=::last[cur];i;i=::edge[i].nxt) dfs4(::edge[i].to);
	}
}
using B::gnd;
using B::maxdep;

int ans[200010];
int subans[200010];
bool mrk[200010];
namespace R  //Rectangle
{
	struct Edge{
		int pos,opt,l,r,nxt;
	}edge[800010];
	int cnt,last1[200010],last2[200010];
	inline void addedge(int *last,int x,int pos,int opt,int l,int r)
	{
		edge[++cnt]=(Edge){pos,opt,l,r,last[x]},last[x]=cnt;
	}
	int tri[200010];
	void add(int x)
	{
		for (;x<=n;x+=x&-x) tri[x]++;
	}
	int query(int x)
	{
		int res=0;
		for (;x;x-=x&-x) res+=tri[x];
		return res;
	}
	
	void solve()
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=last2[i];j;j=edge[j].nxt)
				add(edge[j].pos);
			for (int j=last1[i];j;j=edge[j].nxt)
				subans[edge[j].pos]+=edge[j].opt*(query(edge[j].r)-query(edge[j].l-1));
		}
	}
}
using R::last1;
using R::last2;

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	n=read();
	for (int i=2;i<=n;i++) addedge(read(),i);
	dfs1(1,0,1); dfs2(1,1);
	m=read();
	for (int i=1,x,y,z;i<=m;i++)
	{
		x=read(),y=read(),z=getlca(x,y);
		B::addedge(x,z); B::addedge(y,z);
		R::addedge(last2,id[x],id[y],0,0,0); R::addedge(last2,id[y],id[x],0,0,0);
	}
	B::dfs3(1); B::dfs4(1);
	q=read();
	for (int i=1,x,y,z,a,b;i<=q;i++)
	{
		x=read(),y=read(); z=getlca(x,y);
		if (dep[x]>dep[y]) swap(x,y);
		if (x==z)
		{
			for (int j=17;j>=0;j--)
			{
				if (!gnd[y][j]) continue;
				if (dep[gnd[y][j]]>dep[x]) y=gnd[y][j],ans[i]+=(1<<j);
			}
			//printf("y %d\n",y);
			if (!gnd[y][0]){ans[i]=-1;continue;}
			y=gnd[y][0],ans[i]++; if (dep[y]>dep[x]){ans[i]=-1;continue;}
			continue;
		}
		
		a=x,b=y;
		bool flg1=false,flg2=false;
		for (int j=17;j>=0;j--)
		{
			if (!gnd[a][j]) continue;
			if (dep[gnd[a][j]]<=dep[z]) flg1=true;
			if (dep[gnd[a][j]]>dep[z]) a=gnd[a][j],ans[i]+=(1<<j);
		}
		if (!flg1){ans[i]=-1;continue;}
		for (int j=17;j>=0;j--)
		{
			if (!gnd[b][j]) continue;
			if (dep[gnd[b][j]]<=dep[z]) flg2=true;
			if (dep[gnd[b][j]]>dep[z]) b=gnd[b][j],ans[i]+=(1<<j);
		}
		if (!flg2){ans[i]=-1;continue;}
		//rec[++rectop]=(Rec){id[b],id[b]+siz[b]-1,-1,id[a]-1};
		//rec[++rectop]=(Rec){id[b],id[b]+siz[b]-1,1,id[a]+siz[a]-1};
		R::addedge(last1,id[a]-1,i,-1,id[b],id[b]+siz[b]-1);
		R::addedge(last1,id[a]+siz[a]-1,i,1,id[b],id[b]+siz[b]-1);
		mrk[i]=true; ans[i]+=2;
	}
	R::solve();
	for (int i=1;i<=q;i++)
	{
		if (mrk[i]&&subans[i]) ans[i]--;
		printf("%d\n",ans[i]);
	}
	return 0;
}