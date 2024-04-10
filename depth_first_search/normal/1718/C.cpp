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
int n,a[N+5],ct,d[10];LL c[10][N+5];multiset<LL> G[10];
LL Q() {LL t=0;for(int i=1;i<=ct;++i) t=max(t,*--G[i].end()*d[i]);return t;}
int main()
{
	int Tt,Qt,i,j,p,x;read(Tt);while(Tt--)
	{
		for(read(n,Qt),i=1;i<=n;++i) read(a[i]);
		for(ct=0,x=n,i=2;i*i<=x;++i) if(!(x%i)) {d[++ct]=n/i;while(!(x%i)) x/=i;}x^1&&(d[++ct]=n/x);
		for(i=1;i<=ct;++i) {for(G[i].clear(),j=0;j^d[i];++j) c[i][j]=0;
		for(j=1;j<=n;++j) c[i][j%d[i]]+=a[j];for(j=0;j^d[i];++j) G[i].insert(c[i][j]);}
		while(writeln(Q()),Qt--) {for(read(p,x),i=1;i<=ct;++i) G[i].erase(G[i].find(c[i][p%d[i]])),G[i].insert(c[i][p%d[i]]+=x-a[p]);a[p]=x;}
	}return 0;
}