#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 2000
#define M 100000
#define LL long long
#define Pr pair<LL,int>
#define Gmax(x,y) (x<(y)&&(x=(y)))
#define Gmin(x,y) (x>(y)&&(x=(y)))
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
using namespace std;
int n,m,A,B,a[N+5],ee,lnk[N+5];struct edge {int to,nxt,v;}e[2*M+5];
int dA[N+5],dB[N+5],c[N+5][N+5];LL s[N+5][N+5];
namespace Dij
{
	int dc,vis[N+5];LL dis[N+5],dv[N+5];priority_queue<Pr,vector<Pr>,greater<Pr> > q;
	I void Solve(CI s,int* d)
	{
		RI i,k;for(i=1;i<=n;++i) dis[i]=1e18,vis[i]=0;q.push(make_pair(dis[s]=0,s));
		W(!q.empty()) if(k=q.top().second,q.pop(),!vis[k]) for(vis[k]=1,i=lnk[k];i;i=e[i].nxt)
			dis[k]+e[i].v<dis[e[i].to]&&(q.push(make_pair(dis[e[i].to]=dis[k]+e[i].v,e[i].to)),0);
		for(i=1;i<=n;++i) dv[i]=dis[i];sort(dv+1,dv+n+1),dc=unique(dv+1,dv+n+1)-dv-1;
		for(i=1;i<=n;++i) d[i]=lower_bound(dv+1,dv+dc+1,dis[i])-dv;
	}
}
namespace DP
{
	int p[N+5],q[N+5];LL u[N+5],v[N+5],f[2][N+5][N+5];
	I void Solve()
	{
		RI i,j;for(i=0;i<=n;++i) p[i]=q[i]=n,u[i]=-1e18,v[i]=1e18;
		for(i=n;~i;--i) for(j=n;~j;--j)
		{
			W(c[p[j]+1][j+1]^c[i+1][j+1]) Gmax(u[j],f[1][p[j]][j]-s[p[j]+1][j+1]),--p[j];
			W(c[i+1][q[i]+1]^c[i+1][j+1]) Gmin(v[i],f[0][i][q[i]]+s[i+1][q[i]+1]),--q[i];
			f[0][i][j]=p[j]^n?u[j]+s[i+1][j+1]:0,f[1][i][j]=q[i]^n?v[i]-s[i+1][j+1]:0;
		}
		puts(f[0][0][0]?(f[0][0][0]>0?"Break a heart":"Cry"):"Flowers");
	}
}
int main()
{
	RI i,j,x,y,z;for(scanf("%d%d%d%d",&n,&m,&A,&B),i=1;i<=n;++i) scanf("%d",a+i);
	for(i=1;i<=m;++i) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	for(Dij::Solve(A,dA),Dij::Solve(B,dB),i=1;i<=n;++i) ++c[dA[i]][dB[i]],s[dA[i]][dB[i]]+=a[i];
	for(i=n;~i;--i) for(j=n;~j;--j) c[i][j]+=c[i+1][j],s[i][j]+=s[i+1][j];
	for(i=n;~i;--i) for(j=n;~j;--j) c[i][j]+=c[i][j+1],s[i][j]+=s[i][j+1];return DP::Solve(),0; 
}