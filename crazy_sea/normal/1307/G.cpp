#include<cstdio>
#include<algorithm>
#define M 100010
#define N 10010
using namespace std;
struct edge{
	int next,to,flow,cost;
}e[M];
const int inf=0x3f3f3f3f;
int first[N],len=1,n;
struct my_queue{
	int head,tail,q[N<<5],p[N];
	void clear()
	{
		for(int i=head;i<=tail;i++) p[q[i]]=0;
		head=tail=0;
	}
	int size(){return tail-head;}
	void push(int x)
	{
		if(p[x]) return;
		p[q[tail++]=x]=1;
	}
	int top()
	{
		p[q[head]]=0;
		return q[head++];
	}
}q;
void add(int a,int b,int c,int d)
{
	e[++len]=(edge){first[a],b,c,d};
	first[a]=len;
}
int dis[N],f[N],s,t,x,y,k[N],lst[N];
int spfa()
{
	for(int i=1;i<=n;i++) dis[i]=inf,f[i]=0;
	dis[s]=0,f[s]=inf;
	q.clear();
	q.push(s);
	while(q.size())
	{
		x=q.top();
		for(int i=first[x];i;i=e[i].next)
		{
			if(e[i].flow==0) continue;
			if(dis[e[i].to]>dis[x]+e[i].cost)
			{
				dis[e[i].to]=dis[x]+e[i].cost;
				lst[e[i].to]=x,k[e[i].to]=i;
				f[e[i].to]=min(e[i].flow,f[x]);
				q.push(e[i].to);
			}
		}
	}
	return f[t];
}
int ss[N],l,p;
void mcmf()
{
	int mx;
	while(mx=spfa())
	{
		for(int x=t,y;x!=s;x=lst[x])
		{
			y=k[x];
			e[y].flow-=mx;
			e[y^1].flow+=mx;
			p+=e[y].cost;
		}
		ss[++l]=p;
	}
}
int m,z,c,Q;
double ans;
int main()
{
	scanf("%d%d",&n,&m);
	s=1,t=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		add(x,y,1,c), add(y,x,0,-c);
	}
	mcmf();
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&x);
		ans=1e18;
		for(int i=1;i<=l;i++)
			ans=min(ans,(ss[i]+x)*1.0/i);
		printf("%lf\n",ans);
	}
}