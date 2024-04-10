#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 300000
#define LL long long
using namespace std;
int n,w,a[N+5],b[N+5],c[N+5];
struct Data
{
	int p,x,c;I Data(CI i=0,CI a=0,CI b=0):p(i),x(a),c(b){}
	I bool operator < (Con Data& o) Con {return x*o.c<o.x*c;}
}s[2*N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int main()
{
	RI i,t=0;for(read(n,w),i=1;i<=n;++i) read(a[i],b[i]),
		2*a[i]<=b[i]?(s[++t]=Data(i,a[i],1),s[++t]=Data(i,b[i]-a[i],1)):s[++t]=Data(i,b[i],2);
	RI g=0;LL ans=0;for(sort(s+1,s+t+1),i=1;i<=t;++i) if((g+=s[i].c)>=w) break;else c[s[i].p]+=s[i].c,ans+=s[i].x;
	RI tp=s[i].p,tx=a[s[i].p],pp=s[i].p,xx=s[i].x;if(g==w) {c[pp]+=s[i].c,ans+=xx;goto End;}
	#define F5(p,x) (tx>x&&(tp=p,tx=x))
	for(i=1;i<=n;++i) !c[i]&&F5(i,a[i]),c[i]==1&&(F5(i,b[i]-a[i]),F5(-i,xx-a[i])),c[i]==2&&F5(-i,xx-(b[i]-a[i]));
	if(tp>0) {++c[tp],ans+=tx;goto End;}c[pp]+=2,--c[-tp],ans+=tx;
	End:for(printf("%lld\n",ans),i=1;i<=n;++i) putchar(48|c[i]);return 0;
}