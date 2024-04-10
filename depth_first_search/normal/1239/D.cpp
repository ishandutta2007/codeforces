#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1000000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
int n,m,ee,d,cnt,T,lnk[N+5],dfn[N+5],low[N+5],col[N+5],vis[N+5],S[N+5],Sz[N+5];
struct edge {int to,nxt;}e[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C==E&&(clear(),0),*C++=c)
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		int T;char c,*A,*B,*C,*E,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI,C=FO,E=FO+FS;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=tn+(c&15),D);}
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void write(Con Ty& x,Con char& y) {write(x),pc(y);}
		I void writes(Con string& x) {for(RI i=0,y=x.length();i^y;++i) pc(x[i]);}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
I void Tarjan(CI x,CI lst)
{
	dfn[x]=low[x]=++d,vis[S[++T]=x]=1;for(RI i=lnk[x];i;i=e[i].nxt) dfn[e[i].to]?
		vis[e[i].to]&&Gmin(low[x],dfn[e[i].to]):(Tarjan(e[i].to,x),Gmin(low[x],low[e[i].to]));
	if(dfn[x]^low[x]) return;Sz[col[x]=++cnt]=1,vis[x]=0;
	W(S[T]^x) ++Sz[col[S[T]]=cnt],vis[S[T--]]=0;--T;
}
int main()
{
	RI Tt,i,j,x,y;F.read(Tt);W(Tt--)
	{
		for(F.read(n),F.read(m),ee=d=cnt=0,i=1;i<=n;++i) lnk[i]=dfn[i]=vis[i]=0;
		for(i=1;i<=m;++i) F.read(x),F.read(y),x^y&&add(x,y);
		for(i=1;i<=n;++i) !dfn[i]&&(Tarjan(i,0),0);
		if(cnt==1) {F.writes("No\n");continue;}F.writes("Yes\n");
		F.write(Sz[1],' '),F.write(n-Sz[1],'\n');
		for(i=1;i<=n;++i) col[i]==1&&(F.write(i,' '),0);F.writes("\n");
		for(i=1;i<=n;++i) col[i]^1&&(F.write(i,' '),0);F.writes("\n");
	}return F.clear(),0;
}