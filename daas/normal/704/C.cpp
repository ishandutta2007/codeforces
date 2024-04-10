#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>//
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
const int mod=1e9+7;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,ans[2],pd[MAXN],deg[MAXN],dp[MAXN][2][2],val[MAXN][2];
struct node
{
	int head[MAXN],tot;
	int to[MAXN*2],nextn[MAXN*2],l1[MAXN*2],l2[MAXN*2];
	void ADD(int u,int v,int _l1,int _l2)
	{
		to[++tot]=v,nextn[tot]=head[u],l1[tot]=_l1,l2[tot]=_l2;
		head[u]=tot;
	}
}Ed;
int z[MAXN],pre[MAXN],top;
void Pick(int u)
{
	z[++top]=u;
	pd[u]=1;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(pd[v]) continue;
		pre[top]=i;
		Pick(v);
		break;
	}
}
int main()
{
	n=read(),m=read();
	Ed.tot=ans[0]=1;
	for(int i=1;i<=n;++i)
	{
		int p=read();
		if(p==1)
		{
			int x=read(),l=0;
			if(x<0) x=-x,l=1;
			if(l) val[x][0]^=1;
			else val[x][1]^=1;
		}
		else
		{
			int x=read(),y=read(),l1=0,l2=0;
			if(x<0) x=-x,l1=1;
			if(y<0) y=-y,l2=1;
			if(x==y)
			{
				if(l1 || l2) val[x][0]^=1;
				if(!l1 || !l2) val[x][1]^=1;
			}
			else
			{
				Ed.ADD(x,y,l1,l2);
				Ed.ADD(y,x,l2,l1);
				++deg[x];
				++deg[y];
			}
		}
	}
	for(int st=1;st<=m;++st) if(!pd[st] && deg[st]<=1)
	{
		top=0;
		Pick(st);
		dp[z[1]][0][val[z[1]][0]]=1;
		dp[z[1]][1][val[z[1]][1]]=1;
		for(int i=2;i<=top;++i)
		{
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					for(int w=0;w<2;++w)
					{
						int V=0;
						if((Ed.l1[pre[i-1]]^j) || (Ed.l2[pre[i-1]]^k)) V=1;
						dp[z[i]][k][w^V^val[z[i]][k]]=MOD(dp[z[i]][k][w^V^val[z[i]][k]]+dp[z[i-1]][j][w]-mod);
					}
		}
		int nans[2]={0,0};
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					nans[k^j]=MOD(nans[k^j]+(ll)ans[k]*dp[z[top]][i][j]%mod-mod);
		ans[0]=nans[0];
		ans[1]=nans[1];
	}
	for(int st=1;st<=m;++st) if(!pd[st])
	{
		top=0;
		Pick(st);
		for(int i=Ed.head[st];i!=0;i=Ed.nextn[i]) if(i!=pre[1]) pre[top]=i;
		//for(int i=1;i<=top;++i) cout<<"AD "<<z[i]<<" "<<Ed.l1[pre[i]]<<" "<<Ed.l2[pre[i]]<<endl;
		dp[z[1]][1][val[z[1]][1]]=1;
		for(int i=2;i<=top;++i)
		{
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					for(int w=0;w<2;++w)
					{
						int V=0;
						if((Ed.l1[pre[i-1]]^j) || (Ed.l2[pre[i-1]]^k)) V=1;
						dp[z[i]][k][w^V^val[z[i]][k]]=MOD(dp[z[i]][k][w^V^val[z[i]][k]]+dp[z[i-1]][j][w]-mod);
					}
		}
		int mem[2]={0,0};
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
			{
				int V=0;
				if((Ed.l1[pre[top]]^1) || (Ed.l2[pre[top]]^i)) V=1;
				mem[j^V]=MOD(mem[j^V]+dp[z[top]][i][j]-mod);
			}
		for(int i=1;i<=top;++i) memset(dp[z[i]],0,sizeof(dp[z[i]]));
		dp[z[1]][0][val[z[1]][0]]=1;
		for(int i=2;i<=top;++i)
		{
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					for(int w=0;w<2;++w)
					{
						int V=0;
						if((Ed.l1[pre[i-1]]^j) || (Ed.l2[pre[i-1]]^k)) V=1;
						dp[z[i]][k][w^V^val[z[i]][k]]=MOD(dp[z[i]][k][w^V^val[z[i]][k]]+dp[z[i-1]][j][w]-mod);
					}
		}
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
			{
				int V=0;
				if((Ed.l1[pre[top]]^0) || (Ed.l2[pre[top]]^i)) V=1;
				mem[j^V]=MOD(mem[j^V]+dp[z[top]][i][j]-mod);
			}
		//cout<<"?? "<<mem[0]<<" "<<mem[1]<<endl;
		int nans[2]={0,0};
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				nans[i^j]=MOD(nans[i^j]+(ll)ans[i]*mem[j]%mod-mod);
		ans[0]=nans[0];
		ans[1]=nans[1];
	}
	printf("%d\n",ans[1]);
	return 0;
}
//ore no turn,draw!