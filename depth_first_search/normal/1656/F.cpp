#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
#define LL long long
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define D isdigit(oc=tc())
	int ff;char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0,ff=1;W(!D) ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),D);x*=ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,a[N+5];
int main()
{
	RI Tt,i;LL t,A,B,ans;read(Tt);W(Tt--)
	{
		for(read(n),i=1;i<=n;++i) read(a[i]);sort(a+1,a+n+1);
		for(t=0,i=2;i<=n;++i) t+=a[1]+a[i];if(t>0) {puts("INF");continue;}
		for(t=0,i=1;i<n;++i) t+=a[i]+a[n];if(t<0) {puts("INF");continue;}
		for(A=B=0,i=1;i^n;++i) A+=1LL*a[1]*a[i],B+=a[1]+a[i];
		for(ans=-1e18,i=1;i^n;++i) A+=1LL*(a[n]-a[1])*a[i],B+=a[n]-a[1],ans=max(ans,max(A-1LL*B*a[i],A-1LL*B*a[i+1]));
		printf("%lld\n",ans);
	}return 0;
}