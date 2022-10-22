#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define M 5
#define SZ 3300000
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,m,id[N+5],w[N+5],a[N+5][M+1];bool cmp(CI x,CI y) {return w[x]<w[y];}
int f[SZ];struct Trie {int Nt;map<int,int> g[SZ];I int S(CI x,CI y) {return !g[x].count(y)&&(g[x][y]=++Nt),g[x][y];}}T;
I void A(CI i,RI v,RI x=1,RI o=0) {if(x>m) return (void)(f[o]+=v);A(i,v,x+1,o),A(i,v,x+1,T.S(o,a[i][x]));}
I int Q(CI i,RI x=1,RI o=0) {if(x>m) return f[o];return Q(i,x+1,o)-Q(i,x+1,T.S(o,a[i][x]));}
int main()
{
	RI i,j;for(read(n,m),i=1;i<=n;sort(a[i]+1,a[i]+m+1),id[i]=i,read(w[i++])) for(j=1;j<=m;++j) read(a[i][j]);
	for(sort(id+1,id+n+1,cmp),i=1;i<=n&&!Q(id[i]);++i) A(id[i],1);if(i>n) return puts("-1"),0;
	RI t=w[id[i]]+w[id[i-1]];for(A(id[i-1],-1),j=i-2;i<=n;++i) W(j&&Q(id[i])) t=min(t,w[id[i]]+w[id[j]]),A(id[j--],-1);
	return printf("%d\n",t),0;
}