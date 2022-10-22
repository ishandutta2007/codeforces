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
#define X 1000000007
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
using namespace std;
int n,m,ee,ct,lnk[N+5];struct edge {int to,nxt,v;}e[2*N+5];struct line {int x,y,v;}s[N+5];
int f[N+5];I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
int v[N+5];I void dfs(CI x) {f[x]=-1;for(RI i=lnk[x];i;i=e[i].nxt) ~f[e[i].to]&&(v[e[i].to]=v[x]^e[i].v,dfs(e[i].to),0);}
int main()
{
	RI i,x,y,z,fx,fy;for(scanf("%d%d",&n,&m),i=1;i<=m;++i) scanf("%d%d%d",&x,&y,&z),
		z^=1,(fx=fa(x))^(fy=fa(y))?(add(x,y,z),add(y,x,z),f[fx]=fy):(s[++ct]=(line){x,y,z},0);
	RI t=1;for(i=1;i<=n;++i) if(!f[i]) dfs(i),t=2LL*t%X;
	for(i=1;i<=ct;++i) if(v[s[i].x]^v[s[i].y]^s[i].v) return puts("0"),0;
	return printf("%d\n",(int)(1LL*t*(X+1>>1)%X)),0;
}