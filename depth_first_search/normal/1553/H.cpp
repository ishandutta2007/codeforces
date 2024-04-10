#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N (1<<K)
#define K 19
#define INF (int)1e9
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
int n,k,a[N+5],f[K+1][N+5],Mn[K+1][N+5],Mx[K+1][N+5];
int main()
{
	RI i,j,l;for(read(n,k),l=1<<k,i=0;i^l;++i) f[0][i]=Mn[0][i]=INF,Mx[0][i]=-INF;
	for(i=1;i<=n;++i) read(a[i]),Mn[0][a[i]]=Mx[0][a[i]]=0;
	RI p;for(j=1;j<=k;++j) for(i=0;i^l;++i)
		f[j][i]=min(min(f[j-1][i],f[j-1][i^(1<<j-1)]),Mn[j-1][i^(1<<j-1)]-Mx[j-1][i]+(1<<j-1)),
		Mn[j][i]=min(Mn[j-1][i],Mn[j-1][i^(1<<j-1)]+(1<<j-1)),Mx[j][i]=max(Mx[j-1][i],Mx[j-1][i^(1<<j-1)]+(1<<j-1));
	for(i=0;i^l;++i) write(f[k][i]);return clear(),0;
}