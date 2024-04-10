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
using namespace std;
int n,ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C^FS?FO[C++]=c:(fwrite(FO,1,C,stdout),FO[(C=0)++]=c))
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		int T,C;char c,*A,*B,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=tn+(c&15),D);}
		Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void writeln(Con Ty& x) {write(x),pc('\n');}
		I void clear() {fwrite(FO,1,C,stdout),C=0;}
		#undef D
}F;
class LongChainDissection
{
	private:
		#define Assign(x) (f[x]=p,p+=len[x])
		#define F5(x,v) ((f[x][ans[x]]<f[x][v]||(f[x][ans[x]]==f[x][v]&&ans[x]>v))&&(ans[x]=v))
		int son[N+5],len[N+5],ans[N+5],*p,*f[N+5],_f[N+5];
		I void dfs(CI x,CI lst)
		{
			for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
				(dfs(e[i].to,x),len[e[i].to]>len[son[x]]&&(son[x]=e[i].to));
			len[x]=len[son[x]]+1;
		}
		I void DP(CI x,CI lst)
		{
			RI i,j;son[x]&&(f[son[x]]=f[x]+1,DP(son[x],x),ans[x]=ans[son[x]]+1);
			for(i=lnk[x];i;i=e[i].nxt) if(e[i].to^lst&&e[i].to^son[x])
				for(Assign(e[i].to),DP(e[i].to,x),j=1;j<=len[e[i].to];++j)
					f[x][j]+=f[e[i].to][j-1],F5(x,j);f[x][0]=1,F5(x,0);
		}
	public:
		I LongChainDissection() {p=_f;}I void Init() {dfs(1,0);}
		I void Solve() {Assign(1),DP(1,0);for(RI i=1;i<=n;++i) F.writeln(ans[i]);}
}D; 
int main()
{
	RI i,x,y;for(F.read(n),i=1;i^n;++i) F.read(x,y),add(x,y),add(y,x);
	return D.Init(),D.Solve(),F.clear(),0;
}