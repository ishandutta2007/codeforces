#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,d[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
int op[N+5];void dfs(CI x,CI lst=0) {for(RI i=lnk[x],y;i;i=e[i].nxt) (y=e[i].to)^lst&&(op[y]=-op[x],dfs(y,x),0);}
int main()
{
	RI Tt,i,x,y;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),ee=0,i=1;i<=n;++i) lnk[i]=d[i]=0;
		for(i=1;i^n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x),++d[x],++d[y];
		for(op[1]=1,dfs(1),i=1;i<=n;++i) printf("%d ",op[i]*d[i]);putchar('\n');
	}return 0;
}