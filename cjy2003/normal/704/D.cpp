#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;
const int S=200001,T=200002,SS=200003,TT=200004;
map<int,int>idx,idy;
queue<int>q;
struct bian
{
	int to,nxt,va,id;
}bi[1000010];
int n,m,a,b,p[100010][2],totx,toty,limx[100010],limy[100010],cntx[100010],cnty[100010],sumx,sumy;
int head[200020],num=1,depth[200020],cur[200020];
int delt[200020];
int bj[200020];
long long ans;
void add(int from,int to,int va,int id)
{
	if(va<0)
	{
		printf("-1");
		exit(0);
	}
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
	bi[num].va=va;
	bi[num].id=id;
}
bool bfs(int st,int ed)
{
	memset(depth,0,sizeof(depth));
	memcpy(cur,head,sizeof(cur));
	depth[st]=1;
	q.push(st);
	int x,y;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(int i=head[x];i;i=bi[i].nxt)
			if(bi[i].va)
			{
				y=bi[i].to;
				if(!depth[y])
				{
					depth[y]=depth[x]+1;
					q.push(y);
				}
			}
	}
	return depth[ed]!=0;
}
int dfs(int v,int last,int ed)
{
	if(v==ed)return last;
	int now=0,u;
	for(int i=cur[v];i;i=bi[i].nxt,cur[v]=i)
		if(bi[i].va)
		{
			u=bi[i].to;
			if(depth[u]!=depth[v]+1)continue;
			int dmin=dfs(u,min(last,bi[i].va),ed);
			if(dmin)
			{
				bi[i].va-=dmin;
				bi[i^1].va+=dmin;
				now+=dmin,last-=dmin;
				if(!last)return now;
			}
		}
	return now;
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d",&a,&b);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&x,&y);
		if(!idx[x])idx[x]=++totx;x=idx[x];++cntx[x];
		if(!idy[y])idy[y]=++toty;y=idy[y];++cnty[y];
		p[i][0]=x,p[i][1]=y;
	}
	int t,l,d;
	memset(limx,0x3f,sizeof(limx));
	memset(limy,0x3f,sizeof(limy));
	while(m--)
	{
		scanf("%d %d %d",&t,&l,&d);
		if(t==1)
		{
			l=idx[l];
			if(!l)continue;
			limx[l]=min(limx[l],d);
		}
		else
		{
			l=idy[l];
			if(!l)continue;
			limy[l]=min(limy[l],d);
		}
	}
	for(int i=1;i<=totx;++i)
	{
		sumx+=max(0,(cntx[i]-limx[i]+1)/2);
		add(S,i,min((cntx[i]+limx[i])/2,cntx[i])-max(0,(cntx[i]-limx[i]+1)/2),0);
		add(i,S,0,0);
		if(max(0,(cntx[i]-limx[i]+1)/2))
		{
			add(SS,i,max(0,(cntx[i]-limx[i]+1)/2),0);
			add(i,SS,0,0);
		}
	}
	for(int i=1;i<=toty;++i)
	{
		sumy+=max(0,(cnty[i]-limy[i]+1)/2);
		add(i+totx,T,min((cnty[i]+limy[i])/2,cnty[i])-max(0,(cnty[i]-limy[i]+1)/2),0);
		add(T,i+totx,0,0);
		if(max(0,(cnty[i]-limy[i]+1)/2))
		{
			add(i+totx,TT,max(0,(cnty[i]-limy[i]+1)/2),0);
			add(TT,i+totx,0,0);
		}
	}
	for(int i=1;i<=n;++i)
		add(p[i][0],p[i][1]+totx,1,i),add(p[i][1]+totx,p[i][0],0,0);
	add(S,TT,sumx,0),add(TT,S,0,0);
	add(SS,T,sumy,0),add(T,SS,0,0);	
	add(T,S,0x3f3f3f3f,0),add(S,T,0,0);
	while(bfs(SS,TT))
	{
		while(dfs(SS,0x7fffffff,TT));
	}
	for(int i=head[SS];i;i=bi[i].nxt)
		if(bi[i].va!=0)
		{
			printf("-1");
			return 0;
		}
	while(bfs(S,T))
	{
		while(dfs(S,0x7fffffff,T));
	}
	for(int i=1;i<=totx;++i)
		for(int j=head[i];j;j=bi[j].nxt)
			if(bi[j].id)bj[bi[j].id]=bi[j].va^1;
	for(int i=1;i<=n;++i)
		if(bj[i])ans+=min(a,b);
		else ans+=max(a,b);
	printf("%I64d\n",ans);
	for(int i=1;i<=n;++i)
	{
		if(bj[i])
		{
			if(a<b)printf("r");
			else printf("b");
		}
		else
		{
			if(a<b)printf("b");
			else printf("r");
		}
	}
	return 0;
}