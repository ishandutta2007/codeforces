#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define LV 64
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
#define Gmin(x,y) (void)(x>(y)&&(x=(y)))
using namespace std;
int n,ee,tot,ans,p[LV+5],q[LV+5],lnk[2*LV+5],used[2*LV+5],vis[2*LV+5][2*LV+5];
struct data {int x,lst,dis;I data(CI a=0,CI b=0,CI c=0):x(a),lst(b),dis(c){}};queue<data> que;
struct edge {int to,nxt;}e[2*LV+5];
I void BFS(CI x)
{
	RI i;data k;W(!que.empty()) que.pop();que.push(data(x,0,1));W(!que.empty())
	{
		if(k=que.front(),que.pop(),k.lst^x)
			for(i=lnk[k.x];i;i=e[i].nxt) if(e[i].to==x) return Gmin(ans,k.dis);
		for(i=lnk[k.x];i;i=e[i].nxt) e[i].to^k.lst&&(que.push(data(e[i].to,k.x,k.dis+1)),0);
	}
}
int main()
{
	RI i,j,t;long long x;for(scanf("%d",&n),ans=n+1,i=1;i<=n;++i)
	{
		if(scanf("%lld",&x),!x) continue;for(++tot,j=0;j<=64;++j)
		{
			if(!(x>>j&1)) continue;if(p[j]==2) return puts("3"),0;
			if(!p[j]) {p[j]=1,q[j]=tot;continue;}
			p[j]=2,!vis[q[j]][tot]&&(add(q[j],tot),add(tot,q[j]),vis[q[j]][tot]=1);
		}
	}
	for(i=1;i<=tot;++i) BFS(i);return printf("%d",ans>n?-1:ans),0;
}