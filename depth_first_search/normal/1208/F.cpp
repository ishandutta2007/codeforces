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
#define V 2097151
using namespace std;
int n,a[N+5],f[V+5],g[V+5];vector<int> v[N+5];vector<int>::iterator it;
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
struct Trie
{
	int Nt,S[N*21][2];I void Ins(int& rt,CI x,CI d=20) {if(!rt&&(rt=++Nt),!~d) return;Ins(S[rt][x>>d&1],x,d-1);}
	I int Q(CI rt,CI x,CI d=20) {if(!~d) return 0;return S[rt][x>>d&1^1]?Q(S[rt][x>>d&1^1],x,d-1)|(1<<d):Q(S[rt][x>>d&1],x,d-1);}
}T;
int main()
{
	#define F5(x,v) (f[x]<v?(g[x]=f[x],f[x]=v):g[x]=max(g[x],v))
	RI i,j,rt=0;for(read(n),i=1;i<=n;++i) read(a[i]),F5(a[i],i);
	for(j=0;j<=20;++j) for(i=0;i<=V;++i) i>>j&1&&(F5(i^(1<<j),f[i]),F5(i^(1<<j),g[i]));for(i=0;i<=V;++i) v[g[i]].push_back(i);
	RI ans=0;for(i=n;i;--i) for(ans=max(ans,T.Q(rt,a[i])),it=v[i].begin();it!=v[i].end();++it) T.Ins(rt,*it);return printf("%d\n",ans),0;
}