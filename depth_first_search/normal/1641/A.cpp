#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
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
int n,m,a[N+5];map<int,int> F;
int main()
{
	RI Tt,i,t;read(Tt);W(Tt--)
	{
		for(read(n,m),i=1;i<=n;++i) read(a[i]);sort(a+1,a+n+1);
		for(i=1;i<=n;++i) !(a[i]%m)&&F[a[i]/m]?--F[a[i]/m]:++F[a[i]];
		t=0;for(map<int,int>::iterator it=F.begin();it!=F.end();++it) t+=it->second;
		writeln(t),F.clear();
	}return clear(),0;
}