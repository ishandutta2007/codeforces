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
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,lim[MAXN],rim[MAXN];
struct node
{
	int head[MAXN],tot;
	int to[MAXN*2],nextn[MAXN*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
	void init()
	{
		for(int i=1;i<=n;++i) head[i]=0;
		tot=0;
	}
}Ed;
int ans;
ll fun(int u,int fa)
{
	ll maxn=0;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		maxn+=fun(v,u);
	}
	if(maxn>=lim[u]) return min((ll)rim[u],maxn);
	++ans;
	return rim[u];
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=2;i<=n;++i)
		{
			int fa=read();
			Ed.ADD(fa,i);
		}
		for(int i=1;i<=n;++i) lim[i]=read(),rim[i]=read();
		ans=0;
		fun(1,0);
		printf("%d\n",ans);
		Ed.init();
	}
	return 0;
}
//tetu no isi to hagane no tuyosa