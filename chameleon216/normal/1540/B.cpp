#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x],y=E[i].y;i;i=E[i].nx,y=E[i].y)
using namespace std;
typedef long long ll;
const int MX=550,Mod=1000000007;

ll Pow(ll a,ll p)
{
	ll r=1;
	a%=Mod;
	while(p)
	{
		if(p&1)r=r*a%Mod;
		a=a*a%Mod,p>>=1;
	}
	return r%Mod;
}
ll Inv(ll a){return Pow(a,Mod-2);}

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int N;
ll dp[MX][MX];

int F[MX],D[MX],sz[MX];

void dfs1(int x,int f,int d)
{
	F[x]=f,D[x]=d,sz[x]=1;
	Fe(i,x)if(y!=f)
		dfs1(y,x,d+1),sz[x]+=sz[y];
}

ll Calc(int rt,int z) //rt<z
{
	dfs1(rt,0,1);
	int x=z,w=0;
	ll ans=0;
	while(x)
	{
		ll sum=1;
		Fe(i,x)if(y!=w&&y!=F[x])
			sum+=sz[y];
		ans+=sum*dp[D[x]-D[rt]][D[z]-D[x]]%Mod;
		ans%=Mod;
		w=x,x=F[x];
	}
	return ans;
}


int main()
{
	scanf("%d",&N);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y),Add(y,x);
	}
	
	Fr(i,1,N)dp[i][0]=1;
	ll i2=Inv(2);
	Fr(i,1,N)Fr(j,1,N)
		dp[i][j]=(dp[i-1][j]+dp[i][j-1])%Mod*i2%Mod;
	
	ll ans=0;
	Fr(x,1,N)Fr(y,x+1,N)
	{
		ll tmp=Calc(x,y);
	//	printf("%d %d %lld\n",x,y,tmp);
		ans+=tmp;
		ans%=Mod;
	}
	printf("%lld\n",ans*Inv(N)%Mod);
	
	return 0;
}