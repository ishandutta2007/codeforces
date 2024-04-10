#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define LL long long
#define INF (LL)4e18
using namespace std;
int n;LL x[N+5],y[N+5],z[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define D isdigit(oc=tc())
	int ff;char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0,ff=1;W(!D) ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),D);x*=ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
I bool Check(Con LL& d,CI op=0)
{
	LL l=-INF,r=INF,la=-INF,ra=INF,lb=-INF,rb=INF,lc=-INF,rc=INF;
	RI i;for(i=1;i<=n;++i)
		l=max(l,x[i]+y[i]+z[i]-d),r=min(r,x[i]+y[i]+z[i]+d),
		la=max(la,x[i]+y[i]-z[i]-d),ra=min(ra,x[i]+y[i]-z[i]+d),
		lb=max(lb,x[i]+z[i]-y[i]-d),rb=min(rb,x[i]+z[i]-y[i]+d),
		lc=max(lc,y[i]+z[i]-x[i]-d),rc=min(rc,y[i]+z[i]-x[i]+d);
	LL A,B,C,L,R,LA,RA,LB,RB,LC,RC;for(i=0;i<=1;++i)
	{
		L=l-3*i+1>>1,R=r-3*i>>1,LA=la-i+1>>1,RA=ra-i>>1,LB=lb-i+1>>1,RB=rb-i>>1,LC=lc-i+1>>1,RC=rc-i>>1;
		if(L>R||LA>RA||LB>RB||LC>RC||LA+LB+LC>R||RA+RB+RC<L) continue;
		(A=LA)+(B=LB)+(C=LC)<L&&(A+=min(RA-LA,R-A-B-C))+B+C<L&&A+(B+=min(RB-LB,R-A-B-C))+C<L&&(C+=min(RC-LC,R-A-B-C));
		return op&&((A<<=1)|=i,(B<<=1)|=i,(C<<=1)|=i,printf("%lld %lld %lld\n",A+B>>1,A+C>>1,B+C>>1)),true;
	}return false;
}
int main()
{
	RI Tt,i;LL l,r,mid;read(Tt);W(Tt--)
	{
		for(read(n),i=1;i<=n;++i) read(x[i],y[i],z[i]);
		l=0,r=INF,mid;W(l^r) Check(mid=l+r-1>>1)?r=mid:l=mid+1;Check(r,1);
	}return 0;
}