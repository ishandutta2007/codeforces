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
#define S 450
#define LL long long
#define INF (LL)1e18
using namespace std;
int n,sz,a[N+5];LL s[N+5],f[N+5][S+1];
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
	RI Tt,i,j,t=0;read(Tt);W(Tt--)
	{
		for(read(n),sz=sqrt(2*n),i=1;i<=n;++i) read(a[i]),s[i]=s[i-1]+a[i];
		for(i=1;i<=n+1;++i) for(f[i][0]=INF,j=1;j<=S;++j) f[i][j]=-INF;
		for(i=n;i;--i) for(j=1;j<=min(S,n-i+1);++j) f[i][j]=max(f[i+1][j],s[i+j-1]-s[i-1]<f[i+j][j-1]?s[i+j-1]-s[i-1]:-INF);
		for(i=1;f[1][i+1]!=-INF;++i);writeln(i);
	}return clear(),0;
}