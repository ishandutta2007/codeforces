#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
using namespace std;
int n,m,X,g[N+5],f[N+5];I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
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
	RI i,x,y;for(read(n,m,X),i=1;i<=m;++i) read(x,y),(x=fa(x))^(y=fa(y))&&(f[y]=x);
	RI t=1,c=0;for(i=1;i<=n;++i) ++g[fa(i)];for(i=1;i<=n;++i) fa(i)==i&&(t=1LL*t*g[i]%X,++c);
	if(c==1) return printf("%d\n",1%X),0;
	for(i=1;i<=c-2;++i) t=1LL*t*n%X;return printf("%d\n",t),0;
}