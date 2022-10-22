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
int n;vector<int> G[N+5];
namespace T
{
	#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
	int ee,lnk[N+5];struct edge {int to,nxt;}e[N+5];
	I void Bd(CI x,CI lst=0)
	{
		for(vector<int>::iterator it=G[x].begin();it!=G[x].end();++it) *it^lst&&(Bd(*it,x),add(x,*it));
	}
	int ct,f[N+5],g[N+5];I void dfs(CI x,CI m)
	{
		f[x]=g[x]=0;for(RI i=lnk[x],y;i;i=e[i].nxt) dfs(y=e[i].to,m),f[y]+1>f[x]?(g[x]=f[x],f[x]=f[y]+1):g[x]=max(g[x],f[y]+1);
		f[x]+g[x]+1>=m&&(++ct,f[x]=-1);
	}
	I int Q(CI m) {return ct=0,dfs(1,m),ct;}
}
int main()
{
	RI i,x,y;for(read(n),i=1;i^n;++i) read(x,y),G[x].push_back(y),G[y].push_back(x);
	RI l,r,mid;for(x=sqrt(n*log2(n)),T::Bd(1),i=1;i<=x;++i) writeln(T::Q(i));
	for(i=n/x;~i;--i) {l=x,r=n;W(l^r) T::Q(mid=l+r+1>>1)>=i?l=mid:r=mid-1;W(x^l) ++x,writeln(i);}return clear(),0;
}