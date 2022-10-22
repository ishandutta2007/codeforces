#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 250000
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
int n,a[N+5],q[N+5],d[N+5],L1[N+5],L2[N+5],R1[N+5],R2[N+5],S1[N+5],S2[N+5];
int f1[N+5];int F1(int x) {return f1[x]?f1[x]=F1(f1[x]):x;}
int f2[N+5];int F2(int x) {return f2[x]?f2[x]=F2(f2[x]):x;}
int g1[N+5];int G1(int x) {return g1[x]?g1[x]=G1(g1[x]):x;}
int g2[N+5];int G2(int x) {return g2[x]?g2[x]=G2(g2[x]):x;}
int main()
{
	int Tt,i,k,H,T,T1,T2;read(Tt);while(Tt--)
	{
		for(read(n),i=1;i<=n;++i) read(a[i]),d[i]=-1;
		for(i=0;i<=n+1;++i) f1[i]=f2[i]=g1[i]=g2[i]=0;
		for(T1=T2=0,S1[0]=S2[0]=0,i=1;i<=n;++i)
		{
			while(T1&&a[S1[T1]]<=a[i]) --T1;L1[i]=S1[T1],S1[++T1]=i;
			while(T2&&a[S2[T2]]>=a[i]) --T2;L2[i]=S2[T2],S2[++T2]=i;
		}
		for(T1=T2=0,S1[0]=S2[0]=n+1,i=n;i;--i)
		{
			while(T1&&a[S1[T1]]<=a[i]) --T1;R1[i]=S1[T1],S1[++T1]=i;
			while(T2&&a[S2[T2]]>=a[i]) --T2;R2[i]=S2[T2],S2[++T2]=i;
		}
		d[q[H=T=1]=1]=0;while(!~d[n])
		{
			k=q[H++];
			for(i=F1(L1[k]);i>L2[k];i=f1[i]=F1(L1[i])) !~d[i]&&(d[q[++T]=i]=d[k]+1);
			for(i=F2(L2[k]);i>L1[k];i=f2[i]=F2(L2[i])) !~d[i]&&(d[q[++T]=i]=d[k]+1);
			for(i=G1(R1[k]);i<R2[k];i=g1[i]=G1(R1[i])) !~d[i]&&(d[q[++T]=i]=d[k]+1);
			for(i=G2(R2[k]);i<R1[k];i=g2[i]=G2(R2[i])) !~d[i]&&(d[q[++T]=i]=d[k]+1);
		}
		printf("%d\n",d[n]);
	}return 0;
}