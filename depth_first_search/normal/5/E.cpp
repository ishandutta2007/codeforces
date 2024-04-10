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
using namespace std;
int n,a[2*N+5],S[N+5],V[N+5];
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
	RI i,T=1;long long t=0;for(read(n),i=1;i<=n;++i) read(a[i]),a[n+i]=a[i],a[i]>a[T]&&(T=i);for(i=1;i<=n;++i) a[i]=a[i+T];
	for(--n,T=0,i=1;i<=n;++i) {W(T&&S[T]<a[i]) t+=V[T--];S[T]^a[i]?(S[++T]=a[i],V[T]=1):++V[T],t+=V[T];}
	W(T>1) t+=V[T--];return printf("%lld\n",t),0;
}