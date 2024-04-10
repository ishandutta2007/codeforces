#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=330000,Mod=1000000007;
struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int N,M;
int V[MX];

int B[MX],Dfn[MX],Low[MX],dc;
int C[MX],cc,stk[MX],tp;
void Tarjan(int x)
{
	B[x]=1,Dfn[x]=Low[x]=++dc,stk[++tp]=x;
	Fe(i,x)
	{
		int y=E[i].y;
		if(B[y]==0)Tarjan(y),Low[x]=min(Low[x],Low[y]);
		else if(B[y]==1)Low[x]=min(Low[x],Dfn[y]);
	}
	if(Dfn[x]==Low[x])
	{
		++cc; int z=-1;
		while(z!=x)z=stk[tp--],C[z]=cc,B[z]=2;
	}
}

int A[MX],W[MX];

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",V+i);
	scanf("%d",&M);
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y);
	}
	Fr(i,1,N)if(B[i]==0)Tarjan(i);
	Fill(W,0x3f);
	Fr(i,1,N)
	{
		int x=C[i],v=V[i];
		W[x]=min(W[x],v);
	}
	Fr(i,1,N)
	{
		int x=C[i],v=V[i];
		if(W[x]==v)++A[x];
	}
	ll ans=1,sum=0;
	Fr(i,1,cc)sum+=W[i],ans*=A[i],ans%=Mod;
	printf("%lld %lld\n",sum,ans);
	return 0;
}