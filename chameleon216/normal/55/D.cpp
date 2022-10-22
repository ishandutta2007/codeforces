#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=20,Mod=2520;

int D[MX],Len;
ll dp[MX][Mod][512];

ll dfs(int n,int u,int m,int s)
{
	if(n==0)
	{
		Fr(i,1,9)if(((s>>i)&1)&&m%i)return 0;
		return 1;
	}
	if(!u&&dp[n][m][s>>1]!=-1)return dp[n][m][s>>1];
	ll res=0;
	int h=u?D[n]:9;
	Fr(i,0,h)res+=dfs(n-1,u&&i==h,(m*10+i)%Mod,s|(1<<i));
	if(!u)dp[n][m][s>>1]=res;
	return res;
}

ll Solve(ll x)
{
	Len=0;
	for(ll y=x;y;y/=10)D[++Len]=y%10;
	return dfs(Len,1,0,0);
}


int main()
{
//	printf("%d\n",lcm(1,2,3,4,5,6,7,8,9));
	int t;
	scanf("%d",&t);
	Fill(dp,0xff);
	while(t --> 0)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",Solve(r)-Solve(l-1));
	}
	return 0;
}