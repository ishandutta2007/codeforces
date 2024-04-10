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
#define LL long long
using namespace std;
int n,k,a[N+5],s[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
struct TreeArray
{
	int a[2*N+5];I void Cl() {for(RI i=1;i<=2*n+1;++i) a[i]=0;} 
	I void U(RI x) {x+=n+1;W(x<=2*n+1) ++a[x],x+=x&-x;}I int Q(RI x) {RI t=0;x+=n+1;W(x) t+=a[x],x-=x&-x;return t;}
}T;
I LL Solve()
{
	RI i,S=0;LL t=0;for(T.Cl(),T.U(0),i=1;i<=n;++i) S+=s[i],t+=T.Q(S-1),T.U(S);return t;
}
int main()
{
	RI i;for(read(n,k),i=1;i<=n;++i) read(a[i]),s[i]=a[i]>=k?1:-1;LL t=Solve();
	for(i=1;i<=n;++i) s[i]=a[i]>k?1:-1;return printf("%lld\n",t-Solve()),0;
}