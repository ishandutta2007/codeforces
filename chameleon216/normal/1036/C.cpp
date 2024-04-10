#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

int D[20],dc;

ll dp[20][4];
ll dfs(int n,int u,int c)
{
	if(c>3)return 0;
	if(!n)return 1;
	if(!u&&dp[n][c]!=-1)return dp[n][c];
	int h=u?D[n]:9;
	ll v=0;
	Fr(i,0,h)v+=dfs(n-1,u&&i==h,c+(i>0));
	if(!u)dp[n][c]=v;
	return v;
}

ll Query(ll x)
{
	dc=0;
	while(x)D[++dc]=x%10,x/=10;
	return dfs(dc,1,0);
}


int main()
{
	int t;
	scanf("%d",&t);
	memset(dp,0xff,sizeof(dp));
	while(t --> 0)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",Query(r)-Query(l-1));
	}
	return 0;
}