#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<queue>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
typedef long long ll;

int n,m,q;
bool mrk[200010];  //edge mrk
struct Edge{
	int to,nxt,val;
}edge[400010];
int cnt=1,last[200010];
inline void addedge(int x,int y,int v)
{
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
}
ll dis1[200010],disn[200010];
typedef pair<ll,int> P;
priority_queue<P,vector<P>,greater<P> > que;
int pre[200010];   //pre edge
void dij(ll *dis,int x)
{
	memset(dis,0x7f,sizeof dis1);
	dis[x]=0; que.push((P){dis[x],x});
	while (!que.empty())
	{
		P cur=que.top(); que.pop();
		if (dis[cur.second]!=cur.first) continue;
		int u=cur.second,v;
//		printf("find %d\n",u);
		for (int i=last[u];i;i=edge[i].nxt)
			if (v=edge[i].to,dis[u]+edge[i].val<dis[v])
			{
				dis[v]=dis[u]+edge[i].val;
				pre[v]=i;
				que.push((P){dis[v],v});
			}
	}
}
int rec[200010],id[200010];
int L[200010],R[200010];
int dfsL(int cur)
{
	if (L[cur]) return L[cur];
	L[cur]=0x7fffffff;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (dis1[edge[i].to]+edge[i].val==dis1[cur])
			L[cur]=min(L[cur],dfsL(edge[i].to));
	return L[cur];
}
int dfsR(int cur)
{
	if (R[cur]) return R[cur];
	for (int i=last[cur];i;i=edge[i].nxt)
		if (disn[edge[i].to]+edge[i].val==disn[cur])
			R[cur]=max(R[cur],dfsR(edge[i].to));
	return R[cur];
}
#define mid (l+r>>1)
#define lson (cur<<1)
#define rson (cur<<1|1)
struct Node{
	ll val;
}node[800010];
void build(int cur,int l,int r)
{
	node[cur].val=0x7fffffffffffffffLL;
	if (l==r) return;
	build(lson,l,mid); build(rson,mid+1,r);
}
void update(int cur,int l,int r,int ql,int qr,ll val)
{
	if (l==ql&&r==qr) return node[cur].val=min(node[cur].val,val),void();
	if (qr<=mid) return update(lson,l,mid,ql,qr,val);
	if (ql>mid) return update(rson,mid+1,r,ql,qr,val);
	update(lson,l,mid,ql,mid,val); update(rson,mid+1,r,mid+1,qr,val);
}
ll subans[200010];
void segdfs(int cur,int l,int r,ll minval)
{
	minval=min(minval,node[cur].val);
	if (l==r) return subans[l]=minval,void();
	segdfs(lson,l,mid,minval); segdfs(rson,mid+1,r,minval);
}
#undef mid
#undef lson
#undef rson

int main()
{
	n=read(),m=read(),q=read();
	for (int i=1,x,y,z;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		addedge(x,y,z);
	}
	dij(disn,n);
//	for (int i=1;i<=n;i++) printf("dis %d from n is %lld\n",i,disn[i]);
	for (int i=1;i!=n;mrk[pre[i]>>1]=true,i=edge[pre[i]^1].to) rec[++*rec]=i,id[i]=L[i]=R[i]=*rec;
	rec[++*rec]=n,L[n]=R[n]=id[n]=*rec;
	
//	for (int i=1;i<=(*rec);i++) printf("%d ",rec[i]); puts("");
	
	for (int i=1;i<=n;i++) if (disn[i]!=0x7f7f7f7f7f7f7f7fLL) dfsR(i);
	dij(dis1,1);
	for (int i=1;i<=n;i++) if (dis1[i]!=0x7f7f7f7f7f7f7f7fLL) dfsL(i);
	build(1,1,(*rec)-1);
	for (int i=2;i<=cnt;i++)
		if (!mrk[i>>1]&&dis1[edge[i].to]!=0x7f7f7f7f7f7f7f7fLL)
		{
			int a=L[edge[i^1].to],b=R[edge[i].to];
			if (a<b) update(1,1,(*rec)-1,a,b-1,dis1[edge[i^1].to]+edge[i].val+disn[edge[i].to]);
		}
	segdfs(1,1,(*rec)-1,0x7fffffffffffffffLL);
	for (int i=1,x,y;i<=q;i++)
	{
		x=read(),y=read();
		if (dis1[edge[x<<1].to]==0x7f7f7f7f7f7f7f7fLL){printf("%I64d\n",dis1[n]);continue;}
		ll ans;
		if (!mrk[x])
		{
//			printf("A");
			ans=min(dis1[n],min(dis1[edge[x<<1].to]+disn[edge[x<<1|1].to],dis1[edge[x<<1|1].to]+disn[edge[x<<1].to])+y);
		}
		else
		{
//			printf("B");
			ans=dis1[n]-edge[x<<1].val+y;
			if (edge[x<<1].val<y) /*printf("C"),*/ans=min(ans,subans[min(id[edge[x<<1].to],id[edge[x<<1|1].to])]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}