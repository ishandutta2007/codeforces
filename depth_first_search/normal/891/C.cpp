#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500000
using namespace std;
int n,m,ans[N+5];vector<int> g[N+5];vector<pair<int,int> > q[N+5];struct line {int x,y,v;}s[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
namespace U
{
	int f[N+5],g[N+5];I int fa(CI x) {return f[x]?fa(f[x]):x;}
	int T,Sx[N+5],Sy[N+5],Sg[N+5];I bool Union(RI x,RI y,CI op=0)
	{
		if((x=fa(x))==(y=fa(y))) return false;g[x]<g[y]&&(swap(x,y),0);
		return op&&(Sx[++T]=x,Sy[T]=y,Sg[T]=g[x]),g[y]==g[f[y]=x]&&++g[x],true;
	}
	I void Bk() {W(T) f[Sy[T]]=0,g[Sx[T]]=Sg[T],--T;}
}
int main()
{
	RI i;for(read(n,m),i=1;i<=m;++i) read(s[i].x,s[i].y,s[i].v),g[s[i].v].push_back(i);
	RI Qt,x,y;for(read(Qt),i=1;i<=Qt;++i) for(ans[i]=1,read(x);x;--x) read(y),q[s[y].v].push_back(make_pair(y,i));
	vector<int>::iterator it;vector<pair<int,int> >::iterator qi,qj;for(i=1;i<=N;++i)
	{
		for(qi=q[i].begin();qi!=q[i].end();U::Bk(),qi=qj)
			for(qj=qi;qj!=q[i].end()&&qj->second==qi->second;++qj) ans[qi->second]&=U::Union(s[qj->first].x,s[qj->first].y,1);
		for(it=g[i].begin();it!=g[i].end();++it) U::Union(s[*it].x,s[*it].y);
	}
	for(i=1;i<=Qt;++i) puts(ans[i]?"YES":"NO");return 0;
}