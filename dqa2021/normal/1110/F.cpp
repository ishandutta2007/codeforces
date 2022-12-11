#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
typedef long long ll;
const ll INF=0x7fffffffffffffffLL;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}

int n,m;
struct Edge{
	int to,nxt,val;
}edge[1000010];
int cnt,last[500010];
inline void addedge(int x,int y,int v)
{
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
}
//int rec[500010][2];

ll dis[500010];
int fat[500010],siz[500010],son[500010],dep[500010];
int top[500010];
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=dep; siz[cur]=1; int tmp=0;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat)
		{
			dis[edge[i].to]=dis[cur]+edge[i].val;
			dfs1(edge[i].to,cur,dep+1);
			siz[cur]+=siz[edge[i].to];
			if (siz[edge[i].to]>tmp) tmp=siz[edge[i].to],son[cur]=edge[i].to;
		}
}
void dfs2(int cur,int top)
{
	::top[cur]=top;
	if (siz[cur]==1) return;
	dfs2(son[cur],top);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat[cur]&&edge[i].to!=son[cur])
			dfs2(edge[i].to,edge[i].to);
}
int lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fat[top[x]];
	}
	if (dep[x]>dep[y]) return y; return x;
}
ll getdis(int x,int y)
{
	return dis[x]+dis[y]-dis[lca(x,y)]*2;
}

namespace R
{
	int fat[500010];  //R::fat
	bool vis[500010];
	int getsiz(int cur,int fat)
	{
		int res=1;
		for (int i=last[cur];i;i=edge[i].nxt)
			if (!vis[edge[i].to]&&edge[i].to!=fat)
				res+=getsiz(edge[i].to,cur);
		return res;
	}
	int Rt,Siz,siz[500010],maxsiz[500010];
	void getroot(int cur,int fat)
	{
		siz[cur]=1; maxsiz[cur]=0;
		for (int i=last[cur];i;i=edge[i].nxt)
			if (!vis[edge[i].to]&&edge[i].to!=fat)
			{
				getroot(edge[i].to,cur);
				siz[cur]+=siz[edge[i].to];
				maxsiz[cur]=max(maxsiz[cur],siz[edge[i].to]);
			}
		maxsiz[cur]=max(maxsiz[cur],Siz-siz[cur]);
		if (Rt==-1||maxsiz[Rt]>maxsiz[cur]) Rt=cur;
	}
	void dfs(int cur,int fat)
	{
		vis[cur]=true; R::fat[cur]=fat;
		for (int i=last[cur];i;i=edge[i].nxt)
			if (!vis[edge[i].to])
			{
				Rt=-1,Siz=getsiz(edge[i].to,0);
				getroot(edge[i].to,0);
				dfs(Rt,cur);
			}
	}
}

#define mid (l+r>>1)
struct Node{
	int lson,rson;
	ll val;
}node[25000010];
int idtot,rt[500010];
void update(int &cur,int l,int r,int pos,ll val)
{
	if (!cur) cur=++idtot,node[cur].val=INF;
	node[cur].val=min(node[cur].val,val);
	if (l==r) return;
	if (pos<=mid) update(node[cur].lson,l,mid,pos,val);
	else update(node[cur].rson,mid+1,r,pos,val);
}
ll query(int cur,int l,int r,int ql,int qr)
{
	if (!cur) return INF/2;
	if (l==ql&&r==qr) return node[cur].val;
	if (qr<=mid) return query(node[cur].lson,l,mid,ql,qr);
	if (ql>mid) return query(node[cur].rson,mid+1,r,ql,qr);
	return min(query(node[cur].lson,l,mid,ql,mid),query(node[cur].rson,mid+1,r,mid+1,qr));  //caution
}

int main()
{
	read(n);read(m);
	for (int i=2,x,y;i<=n;i++) read(x),read(y),addedge(i,x,y);
	dfs1(1,0,1); dfs2(1,1);
//	for (int i=1;i<=n;i++) printf("%d ",id[i]); puts("");
//	printf("%d %d\n",/*getdis(2,3)*//*,*//*getdis(5,2)*/lca(4,5),lca(5,2));
//	for (int i=1;i<=n;i++) printf("dis %d %lld\n",i,dis[i]);
	R::Rt=-1,R::Siz=n,R::getroot(1,0); R::dfs(R::Rt,0);
//	puts("R::fat:"); for (int i=1;i<=n;i++) printf("%d ",R::fat[i]); puts("");
	for (int i=1;i<=n;i++)
	{
		if (edge[last[i]].nxt) continue;
//		printf("remain %d\n",i);
		for (int j=i;j;j=R::fat[j])
			update(rt[j],1,n,i,getdis(i,j));
	}
	for (int i=1,x,y,z;i<=m;i++)
	{
		read(x);read(y);read(z);
		ll ans=INF;
		for (int j=x;j;j=R::fat[j]) ans=min(ans,query(rt[j],1,n,y,z)+getdis(x,j));  //caution INF+INF out of ll !!!
		printf("%I64d\n",ans);
	}
	return 0;
}