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
const int Mod=1000000007;

int N,M;
ll dp[70];

int Log(ll a)
{
	int r=0;
	while(a>>=1)++r;
	return r;
}

const int MX=300100;
const char Col[10]="wygbro";
int ch[MX][2],C[MX],tc=1;
int New(){C[++tc]=-1;return tc;}
void Ins(ll a,int c)
{
	int x=1;
	Fl(i,Log(a)-1,0)
	{
		int k=a>>i&1;
		if(!ch[x][k])ch[x][k]=New();
		x=ch[x][k];
	}
	C[x]=c;
}

ll ep[MX][6];
void dfs(int x,int h)
{
	if(!x)return;
	dfs(ch[x][0],h-1);
	dfs(ch[x][1],h-1);
	Fo(i,0,6)if(C[x]==-1||C[x]==i)
	{
		ep[x][i]=1;
		if(h==1)continue;
		Fr(k,0,1)
		{
			int y=ch[x][k];
			ll s=0;
			if(y)
			{
				Fo(j,0,6)if((i^j)>1)
					s+=ep[y][j],s%=Mod;
			}
			else s=4*dp[h-1]%Mod;
			ep[x][i]=ep[x][i]*s%Mod;
		}
	}
}


int main()
{
	scanf("%d%d",&N,&M);
	dp[1]=1;
	Fr(i,2,N)dp[i]=dp[i-1]*dp[i-1]%Mod*16%Mod;
//	printf("%lld\n",dp[N]*6%Mod);
	
	C[1]=-1;
	char s[10];
	Fr(i,1,M)
	{
		ll a;
		scanf("%lld%s",&a,s);
		int c=-1;
		while(*s!=Col[++c]);
//		printf("%d\n",c);
		Ins(a,c);
	}
//	printf("%d\n",tc);
	
	dfs(1,N);
	ll sum=0;
	Fo(i,0,6)sum+=ep[1][i],sum%=Mod;
	printf("%lld\n",sum);
	return 0;
}