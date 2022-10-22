#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
int n,m,sz,ans[N+5],a[N+5],dc,dv[N+5],bl[N+5],Ex[N+5],L[N+5],R[N+5];
struct Q
{
	int p,l,r;I Q(CI i=0,CI x=0,CI y=0):p(i),l(x),r(y){}I bool operator < (Con Q& o) Con {return r<o.r;}
};vector<Q> q[N+5];vector<Q>::iterator it;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	#define D isdigit(oc=tc())
	int Ff,OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0,Ff=1;W(!D) Ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),D);x*=Ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
	I void NA() {pc('-'),pc('1'),pc('\n');}
	#undef D
}using namespace FastIO;
int res,T,S[N+5],V[N+5];I void A(CI x,CI op=0)
{
	if(!Ex[a[x]]) return (void)(Ex[a[x]]=1,L[a[x]]=R[a[x]]=x,op&&(S[++T]=a[x],V[T]=0));
	x<L[a[x]]?(Gmin(res,L[a[x]]-x),op&&(S[++T]=a[x],V[T]=-L[a[x]]),L[a[x]]=x)
	:(Gmin(res,x-R[a[x]]),op&&(S[++T]=a[x],V[T]=R[a[x]]),R[a[x]]=x);
}
I void D() {W(T) V[T]?(V[T]<0?L[S[T]]=-V[T]:R[S[T]]=V[T]):Ex[S[T]]=0,--T;}
int main()
{
	RI i,j,x,y;for(read(n,m),sz=sqrt(n),i=1;i<=n;++i) read(a[i]),dv[i]=a[i],bl[i]=(i-1)/sz+1;
	for(sort(dv+1,dv+n+1),dc=unique(dv+1,dv+n+1)-dv-1,i=1;i<=n;++i) a[i]=lower_bound(dv+1,dv+dc+1,a[i])-dv;
	for(i=1;i<=m;++i) if(read(x,y),bl[x]==bl[y])
		{for(res=1e9,j=x;j<=y;++j) A(j,1);ans[i]=res,D();}else q[bl[x]+1].push_back(Q(i,x,y));
	RI t,o;for(i=1;i<=bl[n];++i) {for(res=1e9,j=1;j<=dc;++j) Ex[j]=0;
		for(t=(i-1)*sz,sort(q[i].begin(),q[i].end()),it=q[i].begin();it!=q[i].end();++it)
			{W(t^it->r) ++t,A(t);for(o=res,j=(i-1)*sz;j>=it->l;--j) A(j,1);ans[it->p]=res,res=o,D();}}
	for(i=1;i<=m;++i) ans[i]==1e9?NA():writeln(ans[i]);return clear(),0;
}