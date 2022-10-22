#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1500
#define X 998244353
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
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
int n,a[N+5][N+5],F[2*N+5][N+5],F_[N+5],sz[2*N+5];set<int> g[N+5],G[2*N+5];
struct line {int x,y,v;bool operator < (Cn line& o) Cn {return v<o.v;}}w[N*N+5];
int f[N+5],s[N+5],h[N+5];int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
I void Mg(RI x,RI y)
{
	if((x=fa(x))==(y=fa(y))) return;s[f[y]=x]+=s[y],h[x]+=h[y];
	W(!g[y].empty()) g[x].insert(*g[y].begin()),g[y].erase(g[y].begin());
}
int main()
{
	RI i,j;for(read(n),i=1;i<=n;++i) for(j=1;j<=n;++j) read(a[i][j]);
	RI c=0;for(i=1;i<=n;++i) for(g[i].insert(i),s[i]=1,j=i+1;j<=n;++j) w[++c]=(line){i,j,a[i][j]};
	RI t=n,x;for(sort(w+1,w+c+1),i=1;i<=c;++i) Mg(w[i].x,w[i].y),
		x=fa(w[i].x),++h[x]==s[x]*(s[x]-1)/2&&(G[++t]=g[x],g[x].clear(),g[x].insert(t),0);
	RI p,q;set<int>::iterator it;for(i=1;i<=t;++i)
	{
		for(F[i][0]=1,it=G[i].begin();it!=G[i].end();++it)
		{
			for(p=0;p<=sz[i];++p) for(q=1;q<=sz[*it];++q) F_[p+q]=(F_[p+q]+1LL*F[i][p]*F[*it][q])%X;
			for(sz[i]+=sz[*it],p=0;p<=sz[i];++p) F[i][p]=F_[p],F_[p]=0;
		}
		!sz[i]&&++sz[i],++F[i][1];
	}
	for(i=1;i<=n;++i) write(F[t][i]);return clear(),0;
}