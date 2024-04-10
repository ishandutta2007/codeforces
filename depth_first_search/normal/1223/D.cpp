#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 300000 
using namespace std;
int n,f[N+5],fir[N+5],lst[N+5];pair<int,int> p[N+5];
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
int main()
{
	RI Tt,i,j,m,x,t=0;read(Tt);W(Tt--)
	{
		for(read(n),i=1;i<=n;++i) fir[i]=lst[i]=0;for(i=1;i<=n;++i) read(x),!fir[x]&&(fir[x]=i),lst[x]=i;
		for(m=0,i=1;i<=n;++i) fir[i]&&(p[++m]=make_pair(fir[i],lst[i]),0);
		for(t=0,i=1;i<=m;i=j+1) {j=i;W(j<m&&p[j].second<p[j+1].first) ++j;t=max(t,j-i+1);}writeln(m-t);
	}return clear(),0;
}