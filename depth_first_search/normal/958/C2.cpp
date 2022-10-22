#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 20000
#define M 100
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,k,p,a[N+5],s[N+5];
int f[2][N+5],g[M+5];I void BF()
{
	RI i,j,o,INF;memset(f,163,sizeof(f));for(INF=f[0][0],f[0][0]=0,o=1;o<=k;++o)
	{
		for(j=0;j^p;++j) g[j]=INF;for(i=0;i<=n;++i)
		{
			for(f[o&1][i]=INF,j=0;j^p;++j) f[o&1][i]=max(f[o&1][i],g[j]+(s[i]-j+p)%p);
			g[s[i]]=max(g[s[i]],f[o&1^1][i]);
		}
	}printf("%d\n",f[k&1][n]);
}
int main()
{
	RI i,j;for(scanf("%d%d%d",&n,&k,&p),i=1;i<=n;++i) scanf("%d",a+i),s[i]=(s[i-1]+a[i])%p;return BF(),0;
}