#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
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
int main()
{
	RI i,j;for(scanf("%d%d",&n,&p),i=1;i<=n;++i) scanf("%d",a+i),s[i]=(s[i-1]+a[i])%p;
	RI t=0;for(i=1;i^n;++i) t=max(t,s[i]+(s[n]-s[i]+p)%p);return printf("%d\n",t),0;
}