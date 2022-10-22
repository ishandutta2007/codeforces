#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,t,T,l[N+5],r[N+5],c[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[2*N+5];
I void Col(CI x)
{
	for(RI i=lnk[x];i;i=e[i].nxt) c[e[i].to]==c[x]?
		(puts("IMPOSSIBLE"),exit(0),0):!c[e[i].to]&&(c[e[i].to]=3-c[x],Col(e[i].to),0);
}
int main()
{
	RI i,x,y,L=0,R=1e9;scanf("%d%d%d%d",&t,&T,&n,&m);
	for(i=1;i<=n;++i) scanf("%d%d",l+i,r+i),L=max(L,l[i]),R=min(R,r[i]);
	for(i=1;i<=m;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	#define In(x,l,r) ((l)<=(x)&&(x)<=(r))
	if(L+R>T&&(R=T-L),L+R<t&&(L=t-R),L<0||L>T||R<0||R>T) return puts("IMPOSSIBLE"),0;
	for(i=1;i<=n;++i) if(!In(L,l[i],r[i])&&!In(R,l[i],r[i])) return puts("IMPOSSIBLE"),0;
		else if(!In(R,l[i],r[i])) {if(c[i]==2) return puts("IMPOSSIBLE"),0;c[i]=1,Col(i);}
		else if(!In(L,l[i],r[i])) {if(c[i]==1) return puts("IMPOSSIBLE"),0;c[i]=2,Col(i);}
	for(i=1;i<=n;++i) !c[i]&&(c[i]=2,Col(i),0);
	for(puts("POSSIBLE"),printf("%d %d\n",L,R),i=1;i<=n;++i) putchar(c[i]+48);return 0;
}