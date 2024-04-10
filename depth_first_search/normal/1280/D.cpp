#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 3000
#define LL long long
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y) 
using namespace std;
int n,m,a[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
struct V
{
	int x;LL y;V(RI a=0,LL b=-1e18):x(a),y(b){}
	I V operator + (Cn V& o) Cn {return V(x+o.x,y+o.y);}
	I bool operator < (Cn V& o) Cn {return x^o.x?x<o.x:y<o.y;}
}f[N+5][N+5],f_[N+5];
int g[N+5];void dfs(CI x,CI lst=0)
{
	RI i,y,p,q;for(f[x][0]=V(0,a[x]),g[x]=0,i=lnk[x];i;i=e[i].nxt) if((y=e[i].to)^lst)
	{
		for(dfs(y,x),p=g[x];~p;--p) for(q=g[y];~q;--q) f_[p+q]=max(f_[p+q],f[x][p]+f[y][q]);
		for(g[x]+=g[y],p=0;p<=g[x];++p) f[x][p]=f_[p],f_[p]=V();
	}
	if(lst) for(f[x][g[x]+1]=V(),i=g[x];~i;--i) f[x][i+1]=max(f[x][i+1],V(f[x][i].x+(f[x][i].y>0),0));++g[x];
}
int main()
{
	RI Tt,i,x,y;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d",a+i);for(i=1;i<=n;++i) scanf("%d",&x),a[i]=x-a[i];
		for(ee=0,i=1;i<=n;++i) lnk[i]=0;for(i=1;i^n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);
		dfs(1),printf("%d\n",f[1][m-1].x+(f[1][m-1].y>0));
	}return 0;
}