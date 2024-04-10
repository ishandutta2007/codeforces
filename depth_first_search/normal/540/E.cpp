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
#define G(x) (lower_bound(dv+1,dv+dc+1,x)-dv)
using namespace std;
int n,s[2*N+5],a[N+5],b[N+5],dc,dv[2*N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
struct TreeArray
{
	int a[2*N+5];I void U(RI x,CI v) {W(x) a[x]+=v,x-=x&-x;}I int Q(RI x,RI t=0) {W(x<=dc) t+=a[x],x+=x&-x;return t;}
}T;
I int Calc(CI l,CI r) {return l<=r?r-l+1-(G(r+1)-G(l)):0;}
int main()
{
	RI i;for(read(n),i=1;i<=n;++i) read(a[i],b[i]),dv[i]=a[i],dv[n+i]=b[i];
	for(sort(dv+1,dv+2*n+1),dc=unique(dv+1,dv+2*n+1)-dv-1,i=1;i<=dc;++i) s[i]=dv[i];
	for(i=1;i<=n;++i) a[i]=G(a[i]),b[i]=G(b[i]),swap(s[a[i]],s[b[i]]);
	long long t=0;for(i=1;i<=dc;++i) t+=T.Q(G(s[i])),T.U(G(s[i]),1),t+=Calc(s[i]+1,dv[i]-1)+Calc(dv[i]+1,s[i]-1);
	return printf("%lld\n",t),0;
}