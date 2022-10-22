#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000000
#define V 1048575
#define X 1000000007
using namespace std;
int n,c[V+5],g[V+5],pw[N+5];
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
	RI i,j,x;for(read(n),pw[0]=i=1;i<=n;++i) read(x),++c[x],pw[i]=(pw[i-1]<<1)%X;
	for(j=0;j<=20;++j) for(i=V;~i;--i) i>>j&1&&(c[i^(1<<j)]+=c[i]);
	RI t=0;for(i=0;i<=V;++i) g[i]=i?X-g[i^(i&-i)]:1,t=(t+1LL*g[i]*(pw[c[i]]-1))%X;return printf("%d\n",t),0;
}