#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 100000
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
int n,a[N+5],f[N+5];map<int,int> P;
int main()
{
	int Tt,i,mn,d;read(Tt);while(Tt--)
	{
		for(read(n),i=1;i<=n;++i) read(a[i]);P.clear();
		for(P[d=0]=-1,i=1;i<=n;++i) f[i]=f[i-1]+1,P.count(d^=a[i])?(f[i]=min(f[i],P[d]+i),P[d]=min(P[d],f[i]-i-1)):P[d]=f[i]-i-1;
		printf("%d\n",f[n]);
	}return 0;
}