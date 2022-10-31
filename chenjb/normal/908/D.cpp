#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MOD=1E9+7;
bool vis[1010][1010];
int f[1010][1010],p1,p2,p2_inv,pa,pb,k;
int mypow(int x,int n){int s=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)s=1ll*s*x%MOD;return s;}
int DP(int a,int b)
{
	if(b>=k)
	{
		return b;
	}
	if(a+b>=k)
	{
		return (a+b+1ll*p1*p2_inv)%MOD;
	}
	if(vis[a][b])
	{
		return f[a][b];
	}
	vis[a][b]=1;
	if(a==0)
	{
		return f[a][b]=1ll*DP(a+1,b)%MOD;
	}
	else
	{
		return f[a][b]=(1ll*p1*DP(a+1,b)+1ll*p2*DP(a,a+b))%MOD;
	}
}
int main()
{
	scanf("%d%d%d",&k,&pa,&pb);
	p1=1ll*pa*mypow(pa+pb,MOD-2)%MOD;
	p2=1ll*pb*mypow(pa+pb,MOD-2)%MOD;
	p2_inv=mypow(p2,MOD-2);
	printf("%d\n",DP(0,0));
	return 0;
}