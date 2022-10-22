#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=2e4+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,K;
struct node
{
	int head[MAXN*22],tot;
	int to[MAXN*70],nextn[MAXN*70];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
	void init(int N)
	{
		for(int i=1;i<=N;++i) head[i]=0;
		tot=0;
	}
}Ed;
int dfn[MAXN*22],low[MAXN*22],tim,z[MAXN*22],top,pd[MAXN*22],point[MAXN*22],cnt;
void tarjan(int u)
{
	dfn[u]=low[u]=++tim;
	z[++top]=u,pd[u]=1;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(pd[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		++cnt;
		int x;
		do
		{
			x=z[top--];
			pd[x]=0;
			point[x]=cnt;
		}while(x!=u);
	}
}
int calc(int x,int y) {return (x-1)*(K+1)+y;}
int main()
{
	//cerr<<(double)sizeof(Ed)/1024/1024<<endl;
	T=read();
	while(T--)
	{
		n=read(),m=read(),K=read();
		Ed.init(2*n*(K+1));
		tim=cnt=0;
		for(int i=1;i<=2*n*(K+1);++i) dfn[i]=0;
		for(int i=1;i<=n;++i)
		{
			Ed.ADD(2*calc(i,1),2*calc(i,1)-1);
			Ed.ADD(2*calc(i,K+1)-1,2*calc(i,K+1));
			for(int j=K+1;j>1;--j) Ed.ADD(2*calc(i,j)-1,2*calc(i,j-1)-1);
			for(int j=1;j<=K;++j) Ed.ADD(2*calc(i,j),2*calc(i,j+1));
		}
		for(int i=1;i<n;++i)
			for(int j=1;j<=K+1;++j)
			{
				Ed.ADD(2*calc(i,j)-1,2*calc(i+1,j)-1);
				Ed.ADD(2*calc(i+1,j),2*calc(i,j));
			}
		for(int i=1;i<=m;++i)
		{
			int type=read();
			if(type==1)
			{
				int x=read(),v=read();
				Ed.ADD(2*calc(x,v)-1,2*calc(x,v+1)-1);
				Ed.ADD(2*calc(x,v+1),2*calc(x,v));
			}
			if(type==2)
			{
				int x=read(),y=read(),v=read();
				for(int j=1;j<=K+1;++j)
				{
					int oth=min(K+1,max(1,v-j+1));
					Ed.ADD(2*calc(x,j)-1,2*calc(y,oth));
					Ed.ADD(2*calc(y,j)-1,2*calc(x,oth));
				}
			}
			if(type==3)
			{
				int x=read(),y=read(),v=read();
				for(int j=1;j<=K+1;++j)
				{
					int oth=min(K+1,max(1,v-j+1));
					Ed.ADD(2*calc(x,j),2*calc(y,oth)-1);
					Ed.ADD(2*calc(y,j),2*calc(x,oth)-1);
				}
			}
		}
		for(int i=1;i<=2*n*(K+1);++i) if(!dfn[i]) tarjan(i);
		int flag=1;
		for(int i=1;i<=n*(K+1);++i) if(point[2*i-1]==point[2*i]) flag=0;
		if(!flag) {puts("-1");continue;}
		//cout<<"ans ";
		for(int i=1;i<=n;++i)
		{
			int ans=K; while(point[2*calc(i,ans)]<point[2*calc(i,ans)-1]) --ans;
			printf("%d ",ans);
		}
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw!