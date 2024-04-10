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
const int MAXN=2e5+10;
const int MAXM=5e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,A,B,ansA,ansB,vis[MAXN];
struct node
{
	int head[MAXN],tot;
	int to[MAXM*2],nextn[MAXM*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed;
void fun(int u,int fbd,int &ans)
{
	vis[u]=1;
	++ans;
	if(u==fbd) return;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(vis[v]) continue;
		fun(v,fbd,ans);
	}
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read(),A=read(),B=read();
		for(int i=1;i<=n;++i) Ed.head[i]=0;
		Ed.tot=0;
		for(int i=1;i<=m;++i)
		{
			int u=read(),v=read();
			Ed.ADD(u,v);
			Ed.ADD(v,u);
		}
		ansA=ansB=0;
		for(int i=1;i<=n;++i) vis[i]=0;
		fun(A,B,ansA);
		for(int i=1;i<=n;++i) vis[i]=0;
		fun(B,A,ansB);
		printf("%lld\n",(ll)(n-ansA)*(n-ansB));
	}
	return 0;
}
//ore no turn,draw!