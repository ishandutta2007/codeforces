#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
struct edge{int to,c,t,id;};
struct bian{int nxt,to;}bi[500050];
vector<edge>E[50050];
map<int,int>mp[50050];
int n,m,cnt[50050],p[50050][2],b[50050][4],head[300030],num,tot,res,ans[50050];
int dfn[300030],low[300030],dfnum,bl[300030],bcnt;
bool used[50050];
void add(int from,int to){/*printf("%d %d\n",from,to);*/bi[++num]=bian{head[from],to};head[from]=num;}
void tarjan(int v)
{
	static int st[300030],tp;
	st[++tp]=v;dfn[v]=low[v]=++dfnum;
//	printf("%d\n",v);
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(!dfn[u])
		{
			tarjan(u);
			low[v]=min(low[v],low[u]);
		}
		else if(!bl[u])low[v]=min(low[v],dfn[u]);
	}
	if(dfn[v]==low[v])
	{
		bl[v]=++bcnt;
		while(st[tp]!=v)bl[st[tp]]=bcnt,--tp;
		--tp;
	}
}
bool check(int mid)
{
	memset(used,0,sizeof(used));
	memset(head,0,sizeof(head));num=0;
	for(int i=1;i<=m;++i)if(b[i][3]>mid)used[i]=1;
	for(int i=1;i<=n;++i)if(cnt[i])for(auto j:E[i])if(j.id!=p[i][0]&&j.id!=p[i][1])used[j.id]=1;
	static int st[50050],tp;tot=2*m;
	for(int i=1;i<=n;++i)
		if(cnt[i])
		{
			if(used[p[i][0]]&&used[p[i][1]])return 0;
			if(used[p[i][0]]){add(p[i][1],p[i][1]+m);continue;}
			if(used[p[i][1]]){add(p[i][0],p[i][0]+m);continue;}
			add(p[i][1],p[i][0]+m);add(p[i][0],p[i][1]+m);
			add(p[i][1]+m,p[i][0]);add(p[i][0]+m,p[i][1]);
		}
		else
		{
			tp=0;
			for(auto j:E[i])if(!used[j.id])st[++tp]=j.id;
			for(int j=1;j<=tp;++j)
			{
				if(j>1)add(st[j]+m,tot);
				++tot;add(tot,st[j]);
				if(j>1)add(tot,tot-1);
			}
			for(int j=tp;j;--j)
			{
				if(j<tp)add(st[j]+m,tot);
				++tot;add(tot,st[j]);
				if(j<tp)add(tot,tot-1);
			}
		}
	memset(bl,0,sizeof(bl));bcnt=0;
	memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=tot;++i)if(!dfn[i])tarjan(i);
//	for(int i=1;i<=tot;++i)printf("%d ",bl[i]);printf("\n");
	for(int i=1;i<=m;++i)if(bl[i]==bl[i+m])return 0;
	return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y,c,t;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d %d",&x,&y,&c,&t);
		b[i][0]=x,b[i][1]=y,b[i][2]=c,b[i][3]=t;
		E[x].push_back(edge{y,c,t,i});
		E[y].push_back(edge{x,c,t,i});
		if(mp[x].count(c))p[x][0]=mp[x][c],p[x][1]=i,++cnt[x];mp[x][c]=i;
		if(mp[y].count(c))p[y][0]=mp[y][c],p[y][1]=i,++cnt[y];mp[y][c]=i;
	}
	for(int i=1;i<=n;++i)if(cnt[i]>1)return printf("No"),0;
//	check(641991574);
//	return 0;
	int l=0,r=1000000010,mid;
	while(l<r)
	{
		mid=l+r>>1;
	//	printf("%d\n",mid);
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(l==1000000010)return printf("No"),0;
	printf("Yes\n");
	check(l);
	int res=0;
	for(int i=1;i<=m;++i)if(bl[i]>bl[i+m])ans[++res]=i;
	printf("%d %d\n",l,res);
	for(int i=1;i<=res;++i)printf("%d ",ans[i]);
	return 0;
}