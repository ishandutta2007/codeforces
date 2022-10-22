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
#define V 1000000
#define LL long long
using namespace std;
int n;LL a[N+5],p[N*30];set<LL> vis;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int Pt,P[V+5];I void Sieve() {for(RI i=2,j;i<=V;++i)
	for(!P[i]&&(P[++Pt]=i),j=1;j<=Pt&&i*P[j]<=V;++j) if(P[i*P[j]]=1,!(i%P[j])) break;}
int ans;I void Check(Con LL& x)
{
	if(vis.find(x)!=vis.end()) return;vis.insert(x);
	LL res=0;for(RI i=1;i<=n&&res<ans;++i) res+=a[i]<x?x-a[i]:min(a[i]%x,x-a[i]%x);
	ans>res&&(ans=res);
}
I void Work(LL x)
{
	for(RI i=1;i<=Pt&&P[i]<=x;++i) if(!(x%P[i])) {Check(P[i]);W(!(x%P[i])) x/=P[i];}
	x^1&&(Check(x),0);
}
int main()
{
	RI T,i;LL x;for(srand(20050521),Sieve(),read(n),i=1;i<=n;++i) read(a[i]);
	for(ans=n,T=1;T<=30;++T) x=a[1ull*rand()*rand()*rand()%n+1],Work(x),Work(x+1),x^1&&(Work(x-1),0);
	return printf("%d\n",ans),0;
}