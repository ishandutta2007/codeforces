#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define M 50
#define INF 2e9
using namespace std;
int n,m,xx[M+5],xy[M+5],yx[M+5],yy[M+5],v[2*M+5][2*M+5];
class Discretization
{
	private:
		int s[2*M+5];
	public:
		int n;I void Ins(CI x) {s[++n]=x;}I void Init() {sort(s+1,s+n+1),n=unique(s+1,s+n+1)-s-1;}
		I int GV(CI x) {return lower_bound(s+1,s+n+1,x)-s;}I int GF(CI x) {return s[x];}
}Dx,Dy;
template<int PS,int ES> class Dinic
{
	private:
		#define Else(x) ((((x)-1)^1)+1)
		#define add(x,y,f) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].F=f)
		int ee,lnk[PS+5],cur[PS+5],q[PS+5],dep[PS+5];struct edge {int to,nxt,F;}e[2*ES+5];
		I bool BFS(CI s,CI t)
		{
			RI i,k,H=1,T=0;for(i=1;i<=Dx.n+Dy.n+2;++i) dep[i]=0;dep[q[++T]=s]=1;
			W(H<=T&&!dep[t]) for(i=lnk[k=q[H++]];i;i=e[i].nxt)
				e[i].F&&!dep[e[i].to]&&(dep[q[++T]=e[i].to]=dep[k]+1);
			return dep[t];
		}
		I int DFS(CI x,RI f)
		{
			if(x==T||!f) return f;RI& i=cur[x];RI t,res=0;for(;i;i=e[i].nxt)
			{
				if((dep[x]+1)^dep[e[i].to]||!e[i].F||!(t=DFS(e[i].to,min(f,e[i].F)))) continue;
				if(e[i].F-=t,e[Else(i)].F+=t,res+=t,!(f-=t)) return res;
			}return dep[x]=-1,res;
		}
	public:
		int S,T;I Dinic() {S=1,T=2;}I int P1(CI x) {return x+2;}I int P2(CI x) {return x+Dx.n+2;}
		I void Add(CI x,CI y,CI f) {add(x,y,f),add(y,x,0);}
		I void Solve()
		{
			RI i,f=0;W(BFS(S,T)) {for(i=1;i<=Dx.n+Dy.n+2;++i) cur[i]=lnk[i];f+=DFS(S,INF);}
			printf("%d",f);
		}
};Dinic<4*M+2,4*M+4*M*M> D;
int main()
{
	RI i,j,k;scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i) scanf("%d%d%d%d",xx+i,yx+i,xy+i,yy+i),
		Dx.Ins(xx[i]),Dx.Ins(++xy[i]),Dy.Ins(yx[i]),Dy.Ins(++yy[i]);
	for(Dx.Ins(n+1),Dy.Ins(n+1),Dx.Init(),Dy.Init(),i=1;i<=m;++i)
	{
		xx[i]=Dx.GV(xx[i]),yx[i]=Dy.GV(yx[i]),xy[i]=Dx.GV(xy[i])-1,yy[i]=Dy.GV(yy[i])-1;
		for(j=xx[i];j<=xy[i];++j) for(k=yx[i];k<=yy[i];++k) ++v[j][k];
	}
	for(i=1;i^Dx.n;++i) for(j=1;j^Dy.n;++j) v[i][j]&&(D.Add(D.P1(i),D.P2(j),INF),0);
	for(i=1;i^Dx.n;++i) D.Add(D.S,D.P1(i),Dx.GF(i+1)-Dx.GF(i));
	for(i=1;i^Dy.n;++i) D.Add(D.P2(i),D.T,Dy.GF(i+1)-Dy.GF(i));return D.Solve(),0;
}