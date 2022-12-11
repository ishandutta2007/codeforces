#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian{int nxt,to;}bi[1000010];
int n,head[500050],num,dis[500050],dis2[500050],f[500050];
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
int ans[500050];
void dfs1(int v,int fa)
{
	f[v]=fa;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs1(u,v);
		if(dis[u]+1>dis[v])dis2[v]=dis[v],dis[v]=dis[u]+1;
		else if(dis[u]+1>dis2[v])dis2[v]=dis[u]+1;
	}
}
int ad[2000020],mxad[2000020];
void pushdown(int k)
{
	mxad[k<<1]=max(mxad[k<<1],ad[k<<1]+mxad[k]);
	mxad[k<<1|1]=max(mxad[k<<1|1],ad[k<<1|1]+mxad[k]);
	ad[k<<1]+=ad[k],ad[k<<1|1]+=ad[k];
	ad[k]=mxad[k]=0;
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return;
	if(l>=ll&&r<=rr)
	{
		ad[k]+=w;
		mxad[k]=max(mxad[k],ad[k]);
		return;
	}
	pushdown(k);
	add(k<<1,l,l+r>>1,ll,rr,w);
	add(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
}
void dfs2(int v,int udis)
{
	static int d[500050],cnt;
	d[cnt=1]=udis;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==f[v])continue;
		d[++cnt]=dis[u]+1;
	}
	sort(d+1,d+1+cnt);d[cnt+1]=0;
	for(int i=cnt;i;--i)
	{
		if(d[i]!=d[i+1])ans[d[i]*2+1]=max(ans[d[i]*2+1],cnt-i+1);
		else ans[d[i]*2]=max(ans[d[i]*2],cnt-i+1);
	}
	ans[1]=max(ans[1],cnt+(v!=1));
	if(udis)add(1,1,n/2,1,udis,1)/*,printf("%d %d\n",udis,1)*/;
	cnt=0;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==f[v])continue;
		d[++cnt]=dis[u]+1;
	}
	for(int i=2;i<=cnt;++i)add(1,1,n/2,1,d[i],1)/*,printf("%d %d\n",d[i],1)*/;
	for(int i=head[v],u,p=1;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==f[v])continue;
		for(int j=head[u],w;j;j=bi[j].nxt)
		{
			w=bi[j].to;
			if(w==v)continue;
			add(1,1,n/2,1,dis[w]+1,1);
		//	printf("%d %d\n",dis[w]+1,1);
		}
		for(int j=head[u],w;j;j=bi[j].nxt)
		{
			w=bi[j].to;
			if(w==v)continue;
			add(1,1,n/2,1,dis[w]+1,-1);
		//	printf("%d %d\n",dis[w]+1,-1);
		}
		if(p<cnt)add(1,1,n/2,1,d[p+1],-1)/*,printf("%d %d\n",d[p+1],-1)*/,add(1,1,n/2,1,d[p],1)/*,printf("%d %d\n",d[p],1)*/;
		++p;
	}
	for(int i=1;i<cnt;++i)add(1,1,n/2,1,d[i],-1)/*,printf("%d %d\n",d[i],-1)*/;
	if(udis)add(1,1,n/2,1,udis,-1)/*,printf("%d %d\n",udis,-1)*/;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==f[v])continue;
		if(dis[u]+1==dis[v])dfs2(u,max(udis,dis2[v])+1);
		else dfs2(u,max(udis,dis[v])+1);
	}
}
void work(int k,int l,int r)
{
	if(l==r)
	{
	//	printf("%d ",mxad[k]);
		ans[2*l]=max(ans[2*l],mxad[k]);
		return;
	}
	pushdown(k);
	work(k<<1,l,l+r>>1);
	work(k<<1|1,(l+r>>1)+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	ans[n]=1;
	for(int i=n-1;i;--i)ans[i]=max(ans[i],ans[i+1]);
	work(1,1,n/2);//printf("\n");
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}