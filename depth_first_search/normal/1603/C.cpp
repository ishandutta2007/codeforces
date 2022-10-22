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
#define SN 320
#define X 998244353
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
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,a[N+5],w[N+5],f[N+5];
int dfs(CI i,CI lst)
{
	if(!i) return 0;if(w[i]==lst) return f[i];w[i]=lst;
	RI o=(a[i]-1)/lst+1;return f[i]=(dfs(i-1,a[i]/o)+1LL*i*(o-1))%X;
}
int main()
{
	RI Tt,i,j,t;read(Tt);W(Tt--)
	{
		for(read(n),i=1;i<=n;++i) read(a[i]),w[i]=0;for(t=0,i=n;i;--i) t=(t+dfs(i,N))%X;writeln(t);
	}
	return clear(),0;
}