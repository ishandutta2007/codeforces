#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
int rt[300030],ch[6000000][2],tot;
long long mi[6000000],ad[6000000];
inline void pushdown(int k)
{
	if(ch[k][0])ad[ch[k][0]]+=ad[k],mi[ch[k][0]]+=ad[k];
	if(ch[k][1])ad[ch[k][1]]+=ad[k],mi[ch[k][1]]+=ad[k];
	ad[k]=0;
}
long long query(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll||!k)return inf;
	if(l>=ll&&r<=rr)return mi[k];
	if(ad[k])pushdown(k);
	return min(query(ch[k][0],l,l+r>>1,ll,rr),query(ch[k][1],(l+r>>1)+1,r,ll,rr));
}
void upd(int &k,int l,int r,int p,long long w)
{
	if(!k)k=++tot,mi[k]=inf;
	if(w<mi[k])mi[k]=w;
	if(l==r)return ;
	if(ad[k])pushdown(k);
	if(p<=l+r>>1)upd(ch[k][0],l,l+r>>1,p,w);
	else upd(ch[k][1],(l+r>>1)+1,r,p,w);
}
void merge(int &x,int y,int l,int r)
{
	if(!x||!y)
	{
		x=x+y;
		return ;
	}
	if(l==r)
	{
		mi[x]=min(mi[x],mi[y]);
		return ;
	}
	if(ad[x])pushdown(x);
	if(ad[y])pushdown(y);
	merge(ch[x][0],ch[y][0],l,l+r>>1);
	merge(ch[x][1],ch[y][1],(l+r>>1)+1,r);
	mi[x]=inf;
	if(ch[x][0]&&mi[ch[x][0]]<mi[x])mi[x]=mi[ch[x][0]];
	if(ch[x][1]&&mi[ch[x][1]]<mi[x])mi[x]=mi[ch[x][1]];
}
void print(int k,int l,int r)
{
	if(l==r)
	{
		printf("%lld ",k?mi[k]:-1);
		return ;
	}
	print(ch[k][0],l,l+r>>1);
	print(ch[k][1],(l+r>>1)+1,r);
}
struct bian
{
	int nxt,to;
}bi[600060];
int n,m,head[300030],num,dep[300030];
long long cost[300030];
vector<pair<int,int> >c[300030];
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs(u,v);
	}
}
void dfs1(int v,int fa)
{
	long long sum=0;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs1(u,v);
		cost[u]=query(rt[u],1,n,1,dep[v]);
		if(cost[u]==inf){printf("-1"),exit(0);}
		sum+=cost[u];
	}
	for(auto p:c[v])upd(rt[v],1,n,p.first,p.second+sum);
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		ad[rt[u]]+=sum-cost[u];
		mi[rt[u]]+=sum-cost[u];
		merge(rt[v],rt[u],1,n);
	}
//	printf("%d\n",v);
//	print(rt[v],1,n);printf("\n");
}
int main()
{
	scanf("%d %d",&n,&m);
	if(n==1)return printf("0"),0;
	int x,y,w;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		if(x==y)continue;
		c[x].push_back(make_pair(dep[y],w));
	}
	dfs1(1,0);
	printf("%lld",query(rt[1],1,n,1,1));
	return 0;
}