#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 100
#define LL long long
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,a[N+5],mn[N+5],c[100];LL Fib[100];
void U(int x,int v) {c[x]-=v;while(x>2) c[x-1]+=v,x-=2;c[x]+=v;}
bool Chk()
{
	int i;if(c[1]^2) {if(c[1]^1) return 0;i=2;}else for(i=2;c[i]==1;++i);
	for(;i<=59;++i) if(c[i]) return 0;return 1;
}
int main()
{
	int i;for(Fib[0]=Fib[1]=1,i=2;Fib[i-1]<=1e12;++i) Fib[i]=Fib[i-2]+Fib[i-1];
	int Tt,j;read(Tt);while(Tt--)
	{
		memset(c,0,sizeof(c));
		for(read(n),i=1;i<=n;++i) for(read(a[i]),j=59;j;--j) a[i]>=Fib[j]&&(a[i]-=Fib[j],++c[mn[i]=j]);
		if(Chk()) {puts("YES");continue;}
		for(i=1;i<=n;++i) if(mn[i]>2&&mn[i]&1) {if(U(mn[i],1),Chk()) {puts("YES");goto E;}else U(mn[i],-1);}
		puts("NO");continue;E:; 
	}return 0;
}