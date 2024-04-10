#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500
#define X 1000000007
#define I2 500000004
#define LL long long
using namespace std;
Cn int dx[8]={1,1,-1,-1,2,2,-2,-2},dy[8]={2,-2,2,-2,1,-1,1,-1};
LL k;int n,vis[4*N+5][4*N+5],qx[17*N*N+5],qy[17*N*N+5],qk[17*N*N+5];
int ans,ct[N+5];I void BFS(CI k)
{
	RI i,tx,ty,nx,ny,nk,H=1,T=1;vis[qx[1]=2*N][qy[1]=2*N]=ct[0]=1;W(H<=T&&qk[H]^k)
		for(tx=qx[H],ty=qy[H],nk=qk[H++]+1,i=0;i^8;++i) !vis[nx=tx+dx[i]][ny=ty+dy[i]]&&(++ct[qk[++T]=nk],vis[qx[T]=nx][qy[T]=ny]=1);
	for(i=0;i<=k;++i) ans+=ct[i];
}
int main()
{
	RI i,x,y;for(scanf("%lld%d",&k,&n),i=1;i<=n;++i) scanf("%d%d",&x,&y),vis[2*N+x][2*N+y]=1;
	if(BFS(min(k,(LL)N)),k<=N) return printf("%d\n",ans),0;
	RI d=ct[N]-ct[N-1];printf("%d\n",(int)((ans+1LL*(ct[N]+d+ct[N]+1LL*(k-N)%X*d%X)*((k-N)%X)%X*I2)%X)),0;
}