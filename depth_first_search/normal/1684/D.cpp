#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 200000
#define LL long long
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}struct IO_Cl {~IO_Cl() {clear();}}CL;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp void writeln(Ty x) {while(OS[++OT]=x%10+48,x/=10);while(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,k,a[N+5];
int main()
{
	int Tt,i;LL t;read(Tt);while(Tt--)
	{
		for(read(n,k),t=0,i=1;i<=n;++i) read(a[i]),t+=a[i],a[i]-=n-i;
		for(sort(a+1,a+n+1),i=n;i>n-k;--i) t-=a[i];t-=1LL*k*(k-1)/2,writeln(t);
	}return 0;
}