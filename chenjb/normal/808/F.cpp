#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define inf 2147003647
using namespace std;
struct node
{
	int x,flow,next;
}data[800000];
struct node1
{
	int p,c,l;
	friend bool operator <(node1 x,node1 y)
	{
		return x.l<y.l;
	}
}a[110];
int prime[200][200];
int n,k;
int tot;
int g[200],nrl[200],q[200],d[200];

void addedge(int x,int y,int flow)
{
	data[tot].x=y; data[tot].flow=flow; data[tot].next=g[x]; g[x]=tot++;
	data[tot].x=x; data[tot].flow=0   ; data[tot].next=g[y]; g[y]=tot++;
}
void build(int now,int one)
{
	tot=0;
	memset(g,255,sizeof(g));
	for(int i=1;i<=now;i++)
		if (a[i].c%2==0)addedge(0,i,a[i].p);
		else if (a[i].c%2==1&&a[i].c!=1)addedge(i,n+1,a[i].p);
		else if (a[i].c%2==1&&a[i].c==1&&a[i].p==one)addedge(i,n+1,a[i].p);
	for(int i=1;i<now;i++)
		for(int j=i+1;j<=now;j++)
		{
			if (a[i].c==1&&a[i].p!=one)continue;
			if (a[j].c==1&&a[j].p!=one)continue;
			if (!prime[i][j])continue;
			if (a[i].c%2==1)addedge(j,i,inf);
			else addedge(i,j,inf);
		}
}

void bfs()
{
	memcpy(nrl,g,sizeof(g));

	int head=0;
	int tail=1;
	memset(d,255,sizeof(d));
	d[0]=0;
	q[1]=0;
	while (head<tail)
	{
		int x=q[++head];
		for(int p=g[x];p!=-1;p=data[p].next)
			if (d[data[p].x]==-1&&data[p].flow>0)
			{
				d[data[p].x]=d[x]+1;
				if (data[p].x==n+1)return;
				q[++tail]=data[p].x;
			}
	}

}

int get(int x,int flow)
{
	if (x==n+1)return flow;
	for(;nrl[x]!=-1;nrl[x]=data[nrl[x]].next)
		if (d[x]+1==d[data[nrl[x]].x]&&data[nrl[x]].flow>0)
		{
			int t=get(data[nrl[x]].x,min(flow,data[nrl[x]].flow));
			if (t>0)
			{
				data[nrl[x]].flow-=t;
				data[nrl[x]^1].flow+=t;
				return t;
			}
		}
	return 0;
}

int judge(int now)
{
	int sum=0;
	int one=0;
	for(int i=1;i<=now;i++)
	{
		if (a[i].c==1)one=max(one,a[i].p);
		else sum+=a[i].p;
	}
	sum+=one;

	build(now,one);

	bfs();
	while (d[n+1]!=-1)
	{
		int t=get(0,inf);
		while (t!=0)
		{
			sum-=t;
			t=get(0,inf);
		}
		bfs();
	}

	if (sum<k)return 0; 
	return 1;
}

int test(int x)
{
	if (x==0)return 0;
	if (x==1)return 0;
	if (x==2)return 1;
	for(int i=2;i<=floor(sqrt(x));i++)
		if (x%i==0)return 0;
	return 1;
}
int main()
{

	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i].p>>a[i].c>>a[i].l;
	sort(a+1,a+n+1);
	memset(prime,0,sizeof(prime));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (test(a[i].c+a[j].c))prime[i][j]=1;

	int ans=-1;
	for(int i=1;i<=n;i++)
		if (judge(i)){ ans=a[i].l; break; }
	cout<<ans<<endl;
}