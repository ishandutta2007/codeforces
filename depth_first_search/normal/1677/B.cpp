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
	I int reaD() {W(!isdigit(oc=tc()));return oc&15;}
	I void writeln() {pc('\n');}
}using namespace FastIO;
int n,m,p[N+5],f[N+5],g[N+5];char s[N+5];
int main()
{
	RI Tt,i,t,lst;char c;read(Tt);W(Tt--)
	{
		for(read(n,m),i=0;i^m;++i) p[i]=f[i]=g[i]=0;
		for(lst=-1e9,t=0,i=1;i<=n*m;++i)
		{
			f[i%m]+=g[i%m],g[(i+1)%m]+=g[i%m],g[i%m]=0;
			if(reaD()==1) !p[i%m]&&(p[i%m]=1,++t),i-lst>=m?++t:(++g[lst%m],--g[i%m]),lst=i;write(t+f[i%m]);
		}writeln();
	}return clear(),0;
}