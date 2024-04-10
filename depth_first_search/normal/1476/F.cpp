#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 300000
#define LN 19
using namespace std;
int n,p[N+5],f[N+5],g[N+5],w[N+5],LG[N+5],Mx[N+5][LN+1];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
I int MX(CI l,CI r) {if(l>r) return 0;RI k=LG[r-l+1];return max(Mx[l][k],Mx[r-(1<<k)+1][k]);}
I void P(CI x) {if(!x) return;if(!~g[x]) return (void)(P(x-1),putchar('R'));P(g[x]);for(RI i=g[x]+1;i<x;++i) putchar('R');putchar('L');}
int main()
{
	RI Tt,i,j,x,t,s;read(Tt);W(Tt--)
	{
		for(read(n),i=1;i<=n;++i) read(p[i]),f[i]=0,g[i]=w[i]=-1;
		for(LG[0]=-1,i=1;i<=n;++i) LG[i]=LG[i>>1]+1,Mx[i][0]=min(i+p[i],n);
		for(j=1;(1<<j)<=n;++j) for(i=1;i+(1<<j)-1<=n;++i) Mx[i][j]=max(Mx[i][j-1],Mx[i+(1<<j-1)][j-1]);
		for(s=0,i=1;i<=n;++i) {(f[i]=f[i-1])>=i&&(f[i]=max(f[i-1],Mx[i][0]));
			~(x=w[max(i-p[i]-1,0)])&&(t=max(f[x],max(MX(x+1,i-1),i-1)))>f[i]&&(f[i]=t,g[i]=x);W(s<f[i]) w[++s]=i;}
		s==n?(puts("YES"),P(n),putchar('\n')):puts("NO");
	}return 0;
}