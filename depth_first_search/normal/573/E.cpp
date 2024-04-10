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
#define BT 320
#define BS 320
#define LL long long
#define Pr pair<LL,int>
using namespace std;
int n,sz,a[N+5],bl[N+5];LL f[N+5];I bool cmp(CI x,CI y) {return a[x]<a[y];}
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define D isdigit(oc=tc())
	int Ff;char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0,Ff=1;W(!D) Ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));x*=Ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
struct Block
{
	#define V(x) (f[x]+a[x]*t+b)
	int H,T,q[BS+5],p[BS+5];LL t,b;
	I void Build(CI L,CI R)
	{
		RI i;for(i=L;i<=R;++i) f[p[i-L+1]=i]+=a[i]*t+b;t=b=0;sort(p+1,p+R-L+2,cmp);
		#define S(x,y) (a[x]^a[y]?1.0*(f[y]-f[x])/(a[y]-a[x]):(f[y]>f[x]?1e18:-1e18))
		for(H=1,T=0,i=1;i<=R-L+1;q[++T]=p[i++]) W(H<T&&S(q[T-1],q[T])<S(q[T],p[i])) --T;
	}
	I Pr Q() {W(H<T&&V(q[H])<V(q[H+1])) ++H;return make_pair(V(q[H]),q[H]);}
}B[BT+5];
int main()
{
	RI i,x;for(read(n),sz=sqrt(n),i=1;i<=n;++i) read(a[i]),bl[i]=(i-1)/sz+1,f[i]=a[i];
	for(i=1;i<=bl[n];++i) B[i].Build((i-1)*sz+1,min(i*sz,n));
	Pr k;LL ans=0;W(true)
	{
		for(k=make_pair(0LL,0),i=1;i<=bl[n];++i) k=max(k,B[i].Q());if(!k.first) break;ans+=k.first,x=k.second;
		for(i=1;i^bl[x];++i) B[i].b+=a[x];for(i=bl[x]+1;i<=bl[n];++i) ++B[i].t;
		for(i=(bl[x]-1)*sz+1;i^x;++i) f[i]+=a[x];for(i=x+1;i<=min(bl[x]*sz,n);++i) f[i]+=a[i];
		f[x]=-1e18,B[bl[x]].Build((bl[x]-1)*sz+1,min(bl[x]*sz,n));
	}return printf("%lld\n",ans),0;
}