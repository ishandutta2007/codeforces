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
#define X 1000000007
#define I2 500000004
#define LL long long
#define INF (LL)1e18
using namespace std;
int n,a[N+5],ans[N+5];struct Q {int p,l,r;I bool operator < (Cn Q& o) Cn {return r<o.r;}}q[N+5];
int pw[N+5],ipw[N+5],S[N+5],V[N+5],St[N+5],F[N+5];LL G[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int ff,OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0,ff=1;W(!isdigit(oc=tc())) ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));x*=ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int main()
{
	RI Qt,i;for(read(n,Qt),i=1;i<=n;++i) read(a[i]);for(i=1;i<=Qt;++i) read(q[i].l,q[i].r),q[i].p=i;sort(q+1,q+Qt+1);
	for(pw[0]=ipw[0]=i=1;i<=n;++i) pw[i]=2LL*pw[i-1]%X,ipw[i]=1LL*I2*ipw[i-1]%X,S[i]=(S[i-1]+1LL*pw[i]*(a[i]+X))%X;
	RI x,j=1,T=0;for(sort(q+1,q+Qt+1),i=1;i<=n;++i)
	{
		St[++T]=i,F[T]=(a[i]+X)%X,G[T]=a[i];
		W(T>1&&G[T]>=0) x=St[T]-St[T-1],F[T-1]=(F[T-1]+1LL*F[T]*pw[x])%X,G[T-1]=G[T-1]+1.0*G[T]*pw[x]>=INF?INF:G[T-1]+G[T]*pw[x],--T;
		V[T]=(V[T-1]+F[T])%X,St[T+1]=i+1;
		W(j<=Qt&&q[j].r==i) x=upper_bound(St+1,St+T+1,q[j].l)-St,ans[q[j].p]=(1LL*ipw[q[j].l]*(S[St[x]-1]-S[q[j].l-1]+X)+2LL*(V[T]-V[x-1]+X))%X,++j;
	}
	for(i=1;i<=Qt;++i) writeln(ans[i]);return clear(),0;
}