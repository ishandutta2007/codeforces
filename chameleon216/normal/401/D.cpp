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

int N,U,Mod,D[20],cnt[10];
ll F[20],dp[1<<18][100];

int main()
{
	ll x;
	scanf("%lld%d",&x,&Mod);
	while(x)D[N++]=x%10,x/=10;
	Fr(i,0,N-1)++cnt[D[i]];
	F[0]=1;
	Fr(i,1,N)F[i]=F[i-1]*i;
	ll p=1;
	Fr(i,0,9)p*=F[cnt[i]];
	U=(1<<N)-1,dp[0][0]=1;
	Fr(b,1,U)Fr(i,0,N-1)if((b>>i&1)&&(D[i]||b!=U))Fr(j,0,Mod-1)
		dp[b][j]+=dp[b&~(1<<i)][(j*10+D[i])%Mod];
	printf("%lld\n",dp[U][0]/p);
	return 0;
}