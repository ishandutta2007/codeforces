#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define SN 320
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
int n,a[N+5],idt,dv[2*N+5];map<int,int> id;I int ID(CI x) {return !id.count(x)&&(dv[id[x]=++idt]=x),id[x];}
namespace B
{
	int sz,bl[N+5],c[SN+5][2*N+5],g[SN+5][N+5];
	I void Init() {sz=sqrt(n);for(RI i=1;i<=n;++i) bl[i]=(i-1)/sz+1;}
	I void Build()
	{
		for(RI i=1,j;i<=bl[n];++i)
		{
			for(j=1;j<=2*N;++j) c[i][j]=c[i-1][j];for(j=1;j<=n;++j) g[i][j]=g[i-1][j];
			for(j=(i-1)*sz+1;j<=min(i*sz,n);++j) ++g[i][++c[i][a[j]]];
		}
	}
	I void A(CI x) {for(RI i=bl[x];i<=bl[n];++i) ++g[i][++c[i][a[x]]];}
	I void D(CI x) {for(RI i=bl[x];i<=bl[n];++i) --g[i][c[i][a[x]]--];}
	I int M(CI x,CI p) {RI t=0;for(RI i=(bl[x]-1)*sz+1;i<=x;++i) ++c[bl[x]-1][a[i]]==p&&++t;return t;}
	I void M(CI x) {for(RI i=(bl[x]-1)*sz+1;i<=x;++i) --c[bl[x]-1][a[i]];}
	I int Q1(CI x) {RI t=c[bl[x]-1][a[x]];for(RI i=(bl[x]-1)*sz+1;i<=x;++i) a[i]==a[x]&&++t;return t;}
	I int Q2(CI x) {RI p=Q1(x),t=g[bl[x]-1][p];return t+=M(x,p),M(x),t;}
}using namespace B;
int main()
{
	RI i;for(read(n),Init(),i=1;i<=n;++i) read(a[i]),a[i]=ID(a[i]);Build();
	RI Qt,op,x,y;read(Qt);W(Qt--) read(op,x,y),op==1?(D(y),a[y]=ID(x),A(y)):writeln(x^1?(x&1?Q2(y):Q1(y)):dv[a[y]]);
	return clear(),0;
}