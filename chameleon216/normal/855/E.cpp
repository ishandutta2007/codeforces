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

int B,D[70],dc;

ll dp[11][70][1024];
ll dfs(int n,int u,int z,int b)
{
	if(!n)return !b;
	if(!u&&!z&&dp[B][n][b]!=-1)return dp[B][n][b];
	int h=u?D[n]:B-1;
	ll res=0;
	Fr(i,0,h)
	{
		int z_=z&&!i;
		res+=dfs(n-1,u&&i==h,z_,b^!z_<<i);
	}
	if(!u&&!z)dp[B][n][b]=res;
	return res;
}

ll Query(ll x)
{
	dc=0;
	while(x)D[++dc]=x%B,x/=B;
	return dfs(dc,1,1,0);
}


int main()
{
	int t;
	scanf("%d",&t);
	memset(dp,0xff,sizeof(dp));
	while(t --> 0)
	{
		ll l,r;
		scanf("%d%lld%lld",&B,&l,&r);
		printf("%lld\n",Query(r)-Query(l-1));
	}
	return 0;
}