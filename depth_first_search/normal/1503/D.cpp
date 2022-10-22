#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
using namespace std;
int n,p[2*N+5],w[2*N+5],suf[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
}using namespace FastIO;
int ans;I void Solve(CI l,CI r)
{
	RI tx[2]={0,0},ty[2]={0,0};for(RI i=l,x=1e9,y=1e9;i<=r;++i)
		p[i]<x?(x=p[i],++tx[w[i]]):(p[i]<y?(y=p[i],++ty[w[i]]):(puts("-1"),exit(0),0));
	ans+=min(tx[0]+ty[1],tx[1]+ty[0]);
}
int main()
{
	RI i,x,y;for(read(n),i=1;i<=n;++i) if(read(x),read(y),
		x<y?p[x]=y:(swap(x,y),p[x]=y,w[x]=1),x>n||y<=n) return puts("-1"),0;
	for(i=n;i;--i) suf[i]=max(suf[i+1],p[i]);
	RI j=1,t=p[1];for(i=2;i<=n;++i) t>suf[i]?(Solve(j,i-1),t=p[j=i]):t=min(t,p[i]);
	return Solve(j,n),printf("%d\n",ans),0;
}