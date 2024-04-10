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

const int Mod=1000000007;
char D[1020];
int dc,T,K;

void Read()
{
	scanf("%s",D+1);
	dc=strlen(D+1);
	reverse(D+1,D+dc+1);
	Fr(i,1,dc)D[i]-='0';
}

int Check()
{
	int las=-Mod;
	Fr(i,1,dc)if(D[i]==4||D[i]==7)
	{
		if(i-las<=K)return 1;
		las=i;
	}
	return 0;
}

int dp[1020][1020];
int dfs(int n,int u,int a)
{
	if(!n)return !a;
	if(!u&&dp[n][a]!=-1)return dp[n][a];
	int h=u?D[n]:9;
	ll v=0;
	Fr(i,0,h)
	{
		int b=a==0?0:
			i==4||i==7?a>K:
			min(a+1,K+1);
		v+=dfs(n-1,u&&i==h,b);
	}
	v%=Mod;
	if(!u)dp[n][a]=v;
	return v;
}


int main()
{
	scanf("%d%d",&T,&K);
	memset(dp,0xff,sizeof(dp));
	Fr(i,1,T)
	{
		Read();
		int a=(Check()-dfs(dc,1,K+1)+Mod)%Mod;
		Read();
		a=(a+dfs(dc,1,K+1))%Mod;
		printf("%d\n",a);
	}
	return 0;
}