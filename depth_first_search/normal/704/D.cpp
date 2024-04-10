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
#define INF (int)1e9 
#define NA() (puts("-1"),exit(0),0)
using namespace std;
int n,m,r,b,op,xx[N+5],yy[N+5],cx[N+5],cy[N+5],sx[N+5],sy[N+5],d[2*N+5];
int tx;map<int,int> wx;I int px(CI x) {return wx.count(x)?wx[x]:wx[x]=++tx;}
int ty;map<int,int> wy;I int py(CI y) {return wy.count(y)?wy[y]:wy[y]=++ty;}
namespace D
{
	#define PS (2*N+2)
	#define ES (3*N)
	#define s0 (tx+ty+1)
	#define t0 (tx+ty+2)
	#define ss (tx+ty+3)
	#define tt (tx+ty+4)
	#define adde(x,y,f) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].F=f)
	int ee=1,lnk[PS+5],cur[PS+5];struct edge {int to,nxt,F;}e[2*ES+5];
	I void Add(CI x,CI y,CI f) {adde(x,y,f),adde(y,x,0);}
	int q[PS+5],d[PS+5];I bool BFS(CI s,CI t)
	{
		RI i,k,H,T;for(i=1;i<=tt;++i) d[i]=0;d[q[H=T=1]=s]=1;W(H<=T&&!d[t])
			for(i=lnk[k=q[H++]];i;i=e[i].nxt) !d[e[i].to]&&e[i].F&&(d[q[++T]=e[i].to]=d[k]+1);
		return memcpy(cur,lnk,sizeof(lnk)),d[t];
	}
	I int DFS(CI x,CI t,RI f=INF)
	{
		if(x==t||!f) return f;RI i,o,g=0;for(i=cur[x];i;i=e[i].nxt)
		{
			if((d[x]+1)^d[e[i].to]||!e[i].F||!(o=DFS(e[i].to,t,min(f,e[i].F)))) continue;
			if(e[i].F-=o,e[i^1].F+=o,g+=o,!(f-=o)) break;
		}return cur[x]=i,g;
	}
	I bool Try() {W(BFS(ss,tt)) DFS(ss,tt);for(RI i=lnk[ss];i;i=e[i].nxt) if(e[i].F) return 0;return 1;}
	I int MaxFlow() {RI g=0;W(BFS(s0,t0)) g+=DFS(s0,t0);return g;}
	I void Print() {for(RI i=1;i<=n;++i) putchar(e[i<<1].F^op?'b':'r');}
}
int main()
{
	RI i,x,y;scanf("%d%d%d%d",&n,&m,&r,&b),r>b&&(swap(r,b),op=1);
	for(i=1;i<=n;++i) scanf("%d%d",xx+i,yy+i),++cx[xx[i]=px(xx[i])],++cy[yy[i]=py(yy[i])];
	for(i=1;i<=tx;++i) sx[i]=cx[i];for(i=1;i<=ty;++i) sy[i]=cy[i];for(i=1;i<=n;++i) D::Add(xx[i],tx+yy[i],1);
	RI op;for(i=1;i<=m;++i) scanf("%d%d%d",&op,&x,&y),
		op==1?wx.count(x)&&(sx[wx[x]]=min(sx[wx[x]],y)):wy.count(x)&&(sy[wy[x]]=min(sy[wy[x]],y));
	for(i=1;i<=tx;++i) (x=cx[i]-sx[i]+1>>1)>(y=cx[i]+sx[i]>>1)?NA():(D::Add(s0,i,y-x),d[s0]-=x,d[i]+=x);
	for(i=1;i<=ty;++i) (x=cy[i]-sy[i]+1>>1)>(y=cy[i]+sy[i]>>1)?NA():(D::Add(tx+i,t0,y-x),d[tx+i]-=x,d[t0]+=x);
	for(i=1;i<=t0;++i) d[i]>0&&(D::Add(ss,i,d[i]),0),d[i]<0&&(D::Add(i,tt,-d[i]),0);D::Add(t0,s0,INF);
	return D::Try()?(printf("%lld\n",1LL*D::MaxFlow()*(r-b)+1LL*n*b),D::Print(),0):puts("-1"),0;
}