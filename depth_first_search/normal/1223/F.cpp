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
using namespace std;
int n,S[N+5];struct H
{
	#define ull unsigned long long
	#define CU Cn ull&
	ull x,y;I H() {x=y=0;}I H(CU a) {x=y=a;}I H(CU a,CU b):x(a),y(b){}
	I H operator + (Cn H& o) Cn {return H(x+o.x,y+o.y);}
	I H operator - (Cn H& o) Cn {return H(x-o.x,y-o.y);}
	I H operator * (Cn H& o) Cn {return H(x*o.x,y*o.y);}
	I bool operator < (Cn H& o) Cn {return x^o.x?x<o.x:y<o.y;}
}sd(324682339,456789001),pw[N+5];map<H,int> G;
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
	RI Tt,i,x,T;long long t;H h;for(pw[0]=i=1;i<=N;++i) pw[i]=pw[i-1]*sd;read(Tt);W(Tt--)
	{
		for(G.clear(),G[h=H()]=1,read(n),t=T=0,i=1;i<=n;++i) read(x),T&&S[T]==x?h=h-pw[T--]*x:(S[++T]=x,h=h+pw[T]*x),t+=G[h]++;
		printf("%lld\n",t);
	}return 0;
}