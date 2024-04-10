#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
long long p,q;
int cnt,tot,par[400010][22],f[400010][22],last,opt,Q;
struct Tree
{
	int par[400010][22],len[400010];
	long long deep[400010];
	void init(int p,int x)
	{
		deep[p]=x;
		len[p]=1;
		for(int i=0;i<=20;i++)
		{
			par[p][i]=p;
		}
	}
	void add(int fa,int p,int x)
	{
		par[p][0]=fa;
		len[p]=len[fa]+1;
		deep[p]=deep[fa]+x;
		for(int i=1;i<=20;i++)
		{
			par[p][i]=par[par[p][i-1]][i-1];
		}
	}
	int query(int p,long long X)
	{
		if(deep[p]<=X)
		{
			return len[p];
		}
		int x=p;
		for(int i=20;i>=0;i--)
		{
			if(deep[p]-deep[par[x][i]]<=X)
			{
				x=par[x][i];
			}
		}
		return len[p]-len[x];
	}
}TT;
void add(int p,int W)
{
	int u=++cnt;
	//printf("%d %d %d\n",p,u,W);
	par[u][0]=p;
	f[u][0]=W;
	for(int i=1;i<=20;i++)
	{
		par[u][i]=par[par[u][i-1]][i-1];
		f[u][i]=max(f[u][i-1],f[par[u][i-1]][i-1]);
	}
	int x=p;
	for(int i=20;i>=0;i--)
	{
		if(f[x][i]<W)
		{
			x=par[x][i];
		}
	}
	//printf("%d %d\n",u,x);
	if(x==1&&W)
	{
		TT.init(u,W);
	}
	else
	{
		TT.add(x,u,W);
	}
}
int main()
{
	cnt=1;
	for(int i=0;i<=20;i++)
	{
		par[1][i]=1;
	}
	TT.init(1,0);
	scanf("%d",&Q);
	last=0;
	for(;Q--;)
	{
		scanf("%d%lld%lld",&opt,&p,&q);
		if(opt==1)
		{
			int R=p^last,W=q^last;
			add(R,W);
		}
		else
		{
			int R=p^last;
			long long X=q^last;
			printf("%d\n",last=TT.query(R,X));
		}
	}
	return 0;
}