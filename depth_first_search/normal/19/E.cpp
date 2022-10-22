#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 10000
#define LN 20
#define swap(x,y) (x^=y^=x^=y)
#define pb push_back
using namespace std;
int n,m,cnt;vector<int> ans;struct line {int x,y,p;}s[N+5];
namespace UnionFindSet
{
	int fa[N+5];I int getfa(CI x) {return fa[x]?fa[x]=getfa(fa[x]):x;}
	I void Union(CI x,CI y) {fa[getfa(x)]=getfa(y);}
	I bool Identify(CI x,CI y) {return getfa(x)==getfa(y);}
}
namespace Tree
{
	int tot,ee,lnk[N+5],dep[N+5],fa[N+5][LN+5],v[N+5],p[N+5];struct edge {int to,nxt,pos;}e[N<<1];
	I void Add(CI x,CI y,CI z) {e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].pos=z;}
	I void Init(CI x,CI lst=0)
	{
		RI i;for(i=1;i<=LN;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
		for(i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
			(dep[e[i].to]=dep[fa[e[i].to][0]=x]+1,Init(e[i].to,x),0);
	}
	I int LCA(RI x,RI y)
	{
		RI i;dep[x]<dep[y]&&swap(x,y);
		for(i=0;dep[x]^dep[y];++i) ((dep[x]^dep[y])>>i)&1&&(x=fa[x][i]);if(x==y) return x;
		for(i=LN;~i;--i) fa[x][i]^fa[y][i]&&(x=fa[x][i],y=fa[y][i]);return fa[x][0];
	}
	I bool Check(CI x,CI y)
	{
		#define Upt(t) (x==z?(v[y]+=t,v[x]-=t):(y==z?(v[x]+=t,v[y]-=t):(v[x]+=t,v[y]+=t,v[z]-=2*t)))
		RI z=LCA(x,y);return (dep[x]+dep[y]-(dep[z]<<1)+1)&1?(++tot,Upt(1),true):(Upt(-1),false);
	}
	I void Calc(vector<int>& V,CI x,CI lst=0,CI pre=0)
	{
		for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(Calc(V,e[i].to,x,e[i].pos),v[x]+=v[e[i].to]);
		pre&&v[x]==tot&&(V.pb(pre),0);
	}
	I void GetDep() {for(RI i=1;i<=n;++i) !dep[i]&&(Init(i),0);}
	I void GetAns(vector<int>& V) {for(RI i=1;i<=n;++i) !dep[i]&&(Calc(V,i),0);}
}
int main()
{
	RI i,x,y,t;using namespace UnionFindSet;
	for(scanf("%d%d",&n,&m),i=1;i<=m;++i) scanf("%d%d",&x,&y),
		Identify(x,y)?(s[++cnt]=(line){x,y,i},0):(Tree::Add(x,y,i),Tree::Add(y,x,i),Union(x,y),0);
	for(Tree::GetDep(),i=1;i<=cnt;++i) Tree::Check(s[i].x,s[i].y)&&(t=s[i].p);
	if(!Tree::tot) {for(printf("%d\n",m),i=1;i<=m;++i) printf("%d ",i);return 0;}
	Tree::GetAns(ans),Tree::tot==1&&(ans.pb(t),0);
	printf("%d\n",ans.size()),sort(ans.begin(),ans.end());vector<int>::iterator it;
	for(it=ans.begin();it!=ans.end();++it) printf("%d ",*it);return 0;
}