#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 150000
#define V 1000000
#define mp make_pair
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,a[N+5],Pt,P[V+5];set<pair<int,int> > G;
int f[N+V];I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}I void Union(RI x,RI y) {(x=fa(x))^(y=fa(y))&&(f[y]=x);}
int c,p[10];I void Resolve(RI x) {c=0;for(RI i=1;P[i]*P[i]<=x;++i) if(!(x%P[i])) {p[++c]=P[i];W(!(x%P[i])) x/=P[i];}x^1&&(p[++c]=x);}
int main()
{
	RI Qt,i,j,k;for(i=2;i<=V;++i) for(!P[i]&&(P[++Pt]=i),j=1;i*P[j]<=V;++j) if(P[i*P[j]]=1,!(i%P[j])) break;
	for(read(n,Qt),i=1;i<=n;++i) for(read(a[i]),Resolve(a[i]),j=1;j<=c;++j) Union(i,n+p[j]);
	RI fx;for(i=1;i<=n;++i)
	{
		for(fx=fa(i),Resolve(a[i]+1),j=1;j<=c;++j) G.insert(mp(fx,fa(n+p[j])));
		for(j=1;j<=c;++j) for(k=1;k<=c;++k) G.insert(mp(fa(n+p[j]),fa(n+p[k])));
	}
	RI x,y;W(Qt--) read(x,y),puts((x=fa(x))==(y=fa(y))?"0":(G.find(mp(x,y))!=G.end()||G.find(mp(y,x))!=G.end()?"1":"2"));return 0;
}