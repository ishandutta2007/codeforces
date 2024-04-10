#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=1e9+7;
inline int MOD(int x){return x>=mod?x-mod:x;}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,D,head[3010],tot,g[3010][3010];
struct node
{
	int to,nextn;
}a[3010];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void fun(int u,int fa)
{
	for(int i=1;i<=n+1;++i) g[u][i]=1;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		fun(v,u);
		for(int j=1;j<=n+1;++j) g[u][j]=1ll*g[u][j]*g[v][j]%mod;
	}
	for(int i=2;i<=n+1;++i) g[u][i]=MOD(g[u][i]+g[u][i-1]);
}
int inv[3010];
int calc(int x)
{
	if(x<=n+1) return g[1][x];
	int bck=0;
	inv[1]=1;
	for(int i=2;i<=n+1;++i) inv[i]=1ll*MOD(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n+1;++i)
	{
		int mem=g[1][i];
		for(int j=1;j<=n+1;++j)
			if(i!=j)
				mem=1ll*mem*(x-j)%mod*inv[abs(i-j)]%mod;
		if((n+1-i)%2) mem=MOD(mod-mem);
		bck=MOD(bck+mem);
	}
	return bck;
}
int main()
{
	n=read(),D=read();
	for(int i=2;i<=n;++i)
	{
		int fa=read();
		ADD(fa,i);
	}
	fun(1,0);
	printf("%d\n",calc(D));
	return 0;
}