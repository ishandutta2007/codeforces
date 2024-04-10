
 #include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#define ri register
#define inf 0x7fffffff
#define E (1)
#define mk make_pair
//#define int long long
using namespace std; const int N=3004, M=9000005;
inline int read()
{
	int s=0, w=1; ri char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar(); return s*w;
}
int n,m,a,b,que[N],hd,tl;
int f[N][N],dp[N][N];
long long g[M],res;
signed main()
{
	n=read(), m=read(), a=read(), b=read();
	long long x,y,z;scanf("%lld%lld%lld%lld",&g[0],&x,&y,&z);
	for(ri int i=1;i<M;i++) g[i]=(g[i-1]*x+y)%z;
	for(ri int i=1;i<=n;i++)for(ri int j=1;j<=m;j++)f[i][j]=g[(i-1)*m+j-1];
	for(ri int i=1;i<=n;i++)
	{
		que[hd=tl=0]=0;
		for(ri int j=1;j<=m;j++)
		{
			while(hd<=tl&&f[i][j]<f[i][que[tl]]) tl--;
			que[++tl]=j;
			while(hd<tl&&j-b>=que[hd]) hd++;
			dp[i][j]=f[i][que[hd]];
		}
	}
	for(ri int i=1;i<=m;i++)
	{
		que[hd=tl=0]=0;
		for(ri int j=1;j<=n;j++)
		{
			while(hd<=tl&&dp[j][i]<dp[que[tl]][i]) tl--;
			que[++tl]=j;
			while(hd<tl&&j-a>=que[hd]) hd++;
			if(i>=b&&j>=a) res+=1ll*dp[que[hd]][i];
		}
	}
	printf("%lld\n",res);
	return 0;
}