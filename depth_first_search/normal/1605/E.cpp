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
#define V 1000000
#define LL long long
using namespace std;
int n;LL sv[V+5],sx[V+5];struct S
{
	int v,x;I S(CI a=0,CI b=0):v(a),x(b){}I bool operator < (Cn S& o) Cn {return 1LL*x*o.v>1LL*v*o.x;}
	I S operator + (Cn S& o) Cn {return S(v+o.v,x+o.x);}I S operator - (Cn S& o) Cn {return S(v-o.v,x-o.x);}
}a[N+5],b[N+5],d[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int main()
{
	RI Qt,i,j,x;for(read(n),i=1;i<=n;++i) read(a[i].v);for(i=1;i<=n;++i) read(b[i].v);b[1]=S(0,1);
	for(i=1;i<=n;++i) for(d[i]=b[i]-a[i],j=i;j<=n;j+=i) a[j]=a[j]+d[i];
	for(i=1;i<=n;++i) !d[i].x?sv[1]+=abs(d[i].v):(d[i].x<0&&(d[i].x*=-1,d[i].v*=-1),
		sx[1]-=d[i].x,sv[1]-=d[i].v,(x=max((int)floor(-1.0*d[i].v/d[i].x),0)+1)<=V&&(sx[x]+=2*d[i].x,sv[x]+=2*d[i].v));
	for(i=1;i<=V;++i) sv[i]+=sv[i-1],sx[i]+=sx[i-1];read(Qt);W(Qt--) read(x),writeln(sx[x]*x+sv[x]);return clear(),0;
}