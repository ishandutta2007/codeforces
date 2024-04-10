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
#define SZ 20000000
#define LL long long
using namespace std;
int n,X,a[N+5];set<int> S;set<int>::iterator it,jt;
I int QP(RI x,LL y,CI p) {RI t=1;W(y) y&1&&(t=1LL*t*x%p),x=1LL*x*x%p,y>>=1;return t;}
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
int Pt,P[SZ+5],phi[SZ+5];I void Sieve()
{
	phi[1]=1;for(RI i=2,j;i<=SZ;++i) for(!P[i]&&(phi[P[++Pt]=i]=i-1),j=1;i*P[j]<=SZ;++j)
		if(P[i*P[j]]=1,i%P[j]) phi[i*P[j]]=phi[i]*(P[j]-1);else {phi[i*P[j]]=phi[i]*P[j];break;}
}
I int Phi(RI x)
{
	if(x<=SZ) return phi[x];RI i,t=1;for(i=1;P[i]*P[i]<=x&&x>SZ;++i) if(!(x%P[i])) {t*=P[i]-1;W(x/=P[i],!(x%P[i])) t*=P[i];}
	return t*(x>SZ?x-1:phi[x]);
}
I int Q(CI l,CI r,CI p)
{
	RI v=a[l]%p;if(!v) return 0;if(l==r) return v;RI m=min(l+5,r),t=Phi(p);LL o,x=a[m],y;
	for(RI i=m-1;i^l;--i) {y=x,x=1;W(y--) if(1.0L*x*a[i]>t) return QP(v,Q(l+1,r,t)+t,p);else x*=a[i];}return QP(v,x,p);
}
int main()
{
	RI Qt,i;for(read(n,X),Sieve(),i=1;i<=n;++i) read(a[i]),a[i]==1&&(S.insert(i),0);
	RI x,y;read(Qt);W(Qt--) read(x,y),S.lower_bound(x)!=S.end()&&(y=min(y,*S.lower_bound(x))),writeln(Q(x,y,X)%X);return clear(),0;
}