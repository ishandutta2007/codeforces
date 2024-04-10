#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define DB double
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
using namespace std;
int n,a[N+5],ee,lnk[N+5];struct edge {int to,nxt,v;}e[N<<1];
namespace DotSolver
{
	int ans,rt,Sz[N+5],Mx[N+5],used[N+5];DB cur,res,p[N+5];
	I void GetRt(CI x,CI lst,RI s)
	{
		Sz[x]=1,Mx[x]=0;for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
			!used[e[i].to]&&(GetRt(e[i].to,x,s),Sz[x]+=Sz[e[i].to],Mx[x]=max(Mx[x],Sz[e[i].to]));
		Mx[x]=max(Mx[x],s-Sz[x]),Mx[x]<Mx[rt]&&(rt=x);
	}
	I void Calc(CI x,CI lst,CI d,DB& p)
	{
		cur+=pow(d,1.5)*a[x],p+=1.5*pow(d,0.5)*a[x];
		for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(Calc(e[i].to,x,d+e[i].v,p),0);
	}
	I void Work(RI x)
	{
		RI i,y;DB s=cur=0;used[x]=1;
		for(i=lnk[x];i;i=e[i].nxt) p[y=e[i].to]=0,Calc(y,x,e[i].v,p[y]),s+=p[y];
		for((!ans||cur<res)&&(ans=x,res=cur),i=lnk[x];i;i=e[i].nxt)
			if(!used[e[i].to]&&s-2*p[y=e[i].to]<0) return GetRt(y,rt=0,Sz[y]),Work(rt);
	}
	I void Solve() {Mx[0]=1e9,GetRt(1,rt=0,n),Work(rt),printf("%d %.10lf\n",ans,res);}
}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	RI x,y,z;for(i=1;i^n;++i) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	return DotSolver::Solve(),0;
}