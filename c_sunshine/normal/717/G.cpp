#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define next next_
const int N=5555,maxm=1000000,L=131071,inf=0x3f000000;

int n,m,K;

int head[N],adj[maxm],f[maxm],c[maxm],next[maxm],tot=1;
int q[L+1],qh,qt,d[N],cost;
bool inq[N],vis[N];
int S,T,dn;

inline void addedge(const int &u,const int &v,const int &w,const int &p)
{tot++;adj[tot]=v;f[tot]=w;c[tot]=p;next[tot]=head[u];head[u]=tot;
tot++;adj[tot]=u;f[tot]=0;c[tot]=-p;next[tot]=head[v];head[v]=tot;}

bool spfa()
{
	memset(d,-20,dn+1<<2);
	d[S]=0,q[qh=0,qt=1]=S;
	for(int u,v,i;qh!=qt;)
	{
		u=q[qh=qh+1&L];
		inq[u]=0;
		for(i=head[u];i;i=next[i])
			if(f[i]>0&&d[v=adj[i]]<d[u]+c[i])
			{
				d[v]=d[u]+c[i];
				if(!inq[v])
				{
					inq[v]=1;
					q[qt=qt+1&L]=v;
				}
			}
	}
	return d[T]>0;
}

int aug(int u,int flow)
{
	if(u==T){cost+=flow*d[T];return flow;}
	vis[u]=1;
	int left=flow;
	for(int v,t,i=head[u];i&&left;i=next[i])
		if(!vis[v=adj[i]]&&f[i]>0&&d[v]==d[u]+c[i])
		{
			t=aug(v,min(f[i],left));
			left-=t;
			f[i]-=t,f[i^1]+=t;
		}
	return flow-left;
}

char s[N],str[N];


void init()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	S=n+2;T=n+1;dn=n+2;
	for(int i=1;i<=n;i++)
		addedge(i,i+1,inf,0);
	scanf("%d",&m);
	for(int i=1,p;i<=m;i++)
	{
		scanf("%s %d",str,&p);
		int l=strlen(str);
		for(int j=1;j+l-1<=n;j++)
		{
			int flag=1;
			for(int k=0;k<l&&flag;k++)
				flag&=str[k]==s[j+k];
			if(flag)
				addedge(j,j+l,1,p);
		}
	}
	scanf("%d",&K);
	addedge(S,1,K,0);
}

void solve()
{
	int mf=0;
	while(spfa())
	{
		memset(vis,0,dn+1);
		mf+=aug(S,inf);
	}
	printf("%d\n",cost);
}

int main()
{
	init();
	solve();
	return 0;
}