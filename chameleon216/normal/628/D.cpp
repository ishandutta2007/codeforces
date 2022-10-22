#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=2050,Mod=1000000007;

int M,A;
char S[MX];
int D[MX],dc;

ll dp[MX][MX][2];
ll dfs(int n,int u,int z,int a,int b)
{
	if(!n){return !a;}
	if(!u&&!z&&dp[n][a][b]!=-1)return dp[n][a][b];
	ll res=0;
	int h=u?D[n]:9;
	Fr(i,0,h)if((z&&!i)||(b^(i==A)))
		res+=dfs(n-1,u&&i==h,z&&!i,(a*10+i)%M,z&&!i?1:b^1);
	res%=Mod;
	if(!u&&!z)dp[n][a][b]=res;
	return res;
}

ll Count()
{
	memset(dp,0xff,sizeof(dp));
	return dfs(dc,1,1,0,1);
}

void Read(bool sub)
{
	scanf("%s",S+1);
	dc=strlen(S+1);
	Fr(i,1,dc)D[i]=S[dc+1-i]-'0';
	if(sub)
	{
		--D[1];
		Fr(i,1,dc)if(D[i]<0)
			D[i]+=10,--D[i+1];
	//	if(!D[dc])--dc;
	}
//	Fl(i,dc,1)printf("%d",D[i]);putchar('\n');
}

int main()
{
	scanf("%d%d",&M,&A);
	ll ans=0;
	Read(1),ans=(ans-Count()+Mod)%Mod;
	Read(0),ans=(ans+Count())%Mod;
	printf("%lld\n",ans);
	return 0;
}