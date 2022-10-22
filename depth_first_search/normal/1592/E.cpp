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
using namespace std;
int n,a[N+5],s[N+5],g[V+5][2];
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
	RI i,j,k,t=0;for(read(n),i=1;i<=n;++i) read(a[i]);for(k=0;k<=20;++k)
	{
		for(i=0;i<=V;++i) g[i][0]=g[i][1]=0;for(i=1;i<=n;++i) s[i]=s[i-1]^(a[i]>>k);
		for(i=1,j=0;i<=n;++i) {if(j<i-1) j=i-1;W(j^n&&a[j+1]>>k&1) ++j,g[s[j]][j&1]=j;t=max(t,g[s[i-1]][i&1^1]-i+1);}
	}return printf("%d\n",t),0;
}