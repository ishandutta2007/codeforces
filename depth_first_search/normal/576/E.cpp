#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define K 50
using namespace std;
int n,m,k,Qt,lst[N+5];struct line {int x,y;}s[N+5];struct Q {int x,c;}q[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define D isdigit(c=tc())
		char c,*A,*B,FI[FS];
	public:
		I FastIO() {A=B=FI;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=(x<<3)+(x<<1)+(c&15),D);}
		Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}F;
class UnionFindSet
{
	private:
		int f[N+5],g[N+5],T,Sx[N+5],Sy[N+5];bool tg[N+5],Sg[N+5];
	public:
		I int fa(CI x) {return f[x]?fa(f[x]):x;}
		I int V(CI x) {return (f[x]?V(f[x]):0)^tg[x];}
		I void U(RI x,RI y)
		{
			RI fx=fa(x),fy=fa(y);if(++T,fx==fy) return (void)(Sx[T]=-1);
			g[fx]<g[fy]&&(swap(x,y),swap(fx,fy),0),Sx[T]=fx,Sy[T]=fy,
			g[fx]+=(Sg[T]=g[fx]==g[fy]),f[fy]=fx,tg[fy]=V(x)^V(y)^1;
		}
		I void Back() {~Sx[T]&&(g[Sx[T]]-=Sg[T],f[Sy[T]]=tg[Sy[T]]=0),--T;}
}U[K+5];
class SegmentTreeSolver
{
	private:
		#define PT CI l=1,CI r=Qt,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		int o[N+5];vector<int> P[N<<2];vector<int>::iterator it;
	public:
		I void T(CI L,CI R,CI p,PT)
		{
			if(L<=l&&r<=R) return P[rt].push_back(p);RI mid=l+r>>1;
			L<=mid&&(T(L,R,p,LT),0),R>mid&&(T(L,R,p,RT),0);
		}
		I void Solve(PT)
		{
			for(it=P[rt].begin();it!=P[rt].end();++it) U[q[*it].c].U(s[q[*it].x].x,s[q[*it].x].y);
			RI p,x,y,c;if(l==r) x=s[p=q[l].x].x,y=s[p].y,c=q[l].c,
				puts(U[c].fa(x)^U[c].fa(y)||U[c].V(x)^U[c].V(y)?(o[p]=c,"YES"):(q[l].c=o[p],"NO"));
			else {RI mid=l+r>>1;Solve(LT),Solve(RT);}
			for(it=P[rt].begin();it!=P[rt].end();++it) U[q[*it].c].Back();
		}
}S;
int main()
{
	RI i;for(F.read(n,m,k,Qt),i=1;i<=m;++i) F.read(s[i].x,s[i].y);
	for(i=1;i<=Qt;++i) F.read(q[i].x,q[i].c),
		lst[q[i].x]&&(S.T(lst[q[i].x]+1,i,lst[q[i].x]),0),lst[q[i].x]=i;
	for(i=1;i<=m;++i) lst[i]&&(S.T(lst[i]+1,Qt,lst[i]),0);return S.Solve(),0;
}