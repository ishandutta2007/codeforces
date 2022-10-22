#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define S 1000000 
#define LL long long
using namespace std;
int c[60];LL n,f[60],P3[S+5],P[60][32000];
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
I LL QP(LL x,RI y) {LL t=1;W(y) y&1&&(t*=x),x*=x,y>>=1;return t;}
I LL Rt(LL n,CI k) {if(k==1) return n;if(k==2) return (LL)sqrt(n);if(k==3) return upper_bound(P3,P3+S+1,n)-P3-1;return upper_bound(P[k],P[k]+c[k]+1,n)-P[k]-1;}
int main()
{
	RI Tt,i,j,l;for(P3[0]=j=1;j<=S;++j) P3[j]=1LL*j*j*j;for(i=4;i^60;++i) for(P[i][0]=j=1;pow(j,i)<=1e18;++j) P[i][++c[i]]=QP(j,i);
	read(Tt);W(Tt--) {for(read(n),i=1;QP(2,i)<=n;++i) f[i]=Rt(n,i)-1;for(l=--i;i;--i) for(j=i<<1;j<=l;j+=i) f[i]-=f[j];writeln(f[1]);}return clear(),0;
}