#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 5000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
int c,s[N+5],f[N+5][N+5][2],g[N+5][2];I void dfs(CI x,CI lst=0)
{
	for(RI i=lnk[x],j,k,y;i;i=e[i].nxt) if((y=e[i].to)^lst)
	{
		for(dfs(y,x),j=0;j<=s[x]+s[y];++j) g[j][0]=g[j][1]=1e9;
		for(j=0;j<=s[x];++j) for(k=0;k<=s[y];++k)
			g[j+k][0]=min(g[j+k][0],f[x][j][0]+min(f[y][k][0],f[y][k][1]+1)),
			g[j+k][1]=min(g[j+k][1],f[x][j][1]+min(f[y][k][0]+1,f[y][k][1]));
		for(s[x]+=s[e[i].to],k=0;k<=s[x];++k) f[x][k][0]=g[k][0],f[x][k][1]=g[k][1];
	}!s[x]&&(s[x]=1,f[x][0][1]=f[x][1][0]=1e9,++c);
}
int main()
{
	RI i,j,x,y;for(scanf("%d",&n),i=1;i^n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	if(n==2) return puts("1"),0;RI rt;for(i=1;i<=n;++i) e[lnk[i]].nxt&&(rt=i);
	return dfs(rt),printf("%d\n",min(f[rt][c>>1][0],f[rt][c>>1][1])),0;
}