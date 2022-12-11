#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const long long inf=1ll<<50;
vector<pair<int,int> >son[500050];
vector<pair<int,pair<int,int> > >query[500050];
int n,q,id[500050],idnum,siz[500050];
long long ans[500050],dis[500050],mini[2000020],ad[2000020];
void pushdown(int k)
{
	ad[k<<1]+=ad[k];
	ad[k<<1|1]+=ad[k];
	mini[k<<1]+=ad[k];
	mini[k<<1|1]+=ad[k];
	ad[k]=0;
}
void upd(int k,int l,int r,int ll,int rr,long long w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)
	{
		mini[k]+=w;
		ad[k]+=w;
		return ;
	}
	if(ad[k])pushdown(k);
	upd(k<<1,l,l+r>>1,ll,rr,w);
	upd(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
	mini[k]=min(mini[k<<1],mini[k<<1|1]);
}
long long qmin(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)return inf;
	if(l>=ll&&r<=rr)return mini[k];
	if(ad[k])pushdown(k);
	return min(qmin(k<<1,l,l+r>>1,ll,rr),qmin(k<<1|1,(l+r>>1)+1,r,ll,rr));
}
void dfs1(int v)
{
	id[v]=++idnum;siz[v]=1;
	if(!son[v].size())upd(1,1,n,idnum,idnum,dis[v]);
	else upd(1,1,n,idnum,idnum,inf);
	for(auto u:son[v])
	{
		dis[u.first]=dis[v]+u.second;
		dfs1(u.first);
		siz[v]+=siz[u.first];
	}
}
void dfs2(int v)
{
	for(auto u:query[v])
		ans[u.first]=qmin(1,1,n,u.second.first,u.second.second);
	for(auto u:son[v])
	{
		upd(1,1,n,id[u.first],id[u.first]+siz[u.first]-1,-u.second);
		if(id[u.first]>1)upd(1,1,n,1,id[u.first]-1,u.second);
		if(id[u.first]+siz[u.first]<=n)upd(1,1,n,id[u.first]+siz[u.first],n,u.second);
		dfs2(u.first);
		upd(1,1,n,id[u.first],id[u.first]+siz[u.first]-1,u.second);
		if(id[u.first]>1)upd(1,1,n,1,id[u.first]-1,-u.second);
		if(id[u.first]+siz[u.first]<=n)upd(1,1,n,id[u.first]+siz[u.first],n,-u.second);	
	}
}
int main()
{
	scanf("%d %d",&n,&q);
	int x,y,v,w;
	for(int i=2;i<=n;++i)
	{
		scanf("%d %d",&x,&w);
		son[x].push_back(make_pair(i,w));
	}
	for(int i=1;i<=q;++i)
	{
		scanf("%d %d %d",&v,&x,&y);
		query[v].push_back(make_pair(i,make_pair(x,y)));
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=q;++i)
		printf("%I64d\n",ans[i]);
	return 0;
}