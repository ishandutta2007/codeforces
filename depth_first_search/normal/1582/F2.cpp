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
#define V 8192
using namespace std;
int n,a[N+5],f[N+5];vector<int> g[V+5];vector<int>::iterator it;
struct S {int p,v;I bool operator < (Cn S& o) Cn {return v<o.v;}}A[V+5],B[V+5],C[V+5];
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
I int Mg(CI p,CI q)
{
	RI i=1,j=1,k=0;W(i<=p&&j<=q) f[A[i].v]<A[i].p?++i:(C[++k]=A[i].p<B[j].p?A[i++]:B[j++],0);
	W(i<=p) f[A[i].v]==A[i].p&&(C[++k]=A[i],0),++i;W(j<=q) C[++k]=B[j++];return k;
}
int main()
{
	RI i,j;for(read(n),i=1;i<=n;++i) read(a[i]),g[a[i]].push_back(i);
	RI p,q;for(i=1;i<=V;++i) f[i]=n+1;A[p=1]=(S){0,0};
	for(i=1;i<=V;++i) if(!g[i].empty())
	{
		for(j=1,q=0,it=g[i].begin();it!=g[i].end();++it)
			for(;j<=p&&A[j].p<*it;++j) f[A[j].v^i]>*it&&(B[++q]=(S){f[A[j].v^i]=*it,A[j].v^i},0);
		for(p=Mg(p,q),j=1;j<=p;++j) A[j]=C[j];
	}
	for(sort(A+1,A+p+1),printf("%d\n",p),i=1;i<=p;++i) printf("%d%c",A[i].v," \n"[i==p]);return 0;
}