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
using namespace std;
int n,m,g[N+5],c[N+5],dp[2][N+5];deque<int> q[N+5];
int f[N+5];I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
I bool pd(RI x) {W(x) if((x%10)^4&&(x%10)^7) return 0;else x/=10;return 1;}
int main()
{
	RI i,j,x,y;for(scanf("%d%d",&n,&m),i=1;i<=m;++i) scanf("%d%d",&x,&y),(x=fa(x))^(y=fa(y))&&(f[x]=y);
	for(i=1;i<=n;++i) ++g[fa(i)];for(i=1;i<=n;++i) ++c[g[i]];
	RI op=0;for(i=1;i<=n;++i) dp[0][i]=1e9;for(i=1;i<=n;++i) if(c[i])
	{
		for(op^=1,j=0;j^i;++j) q[j].clear();for(j=0;j<=n;++j)
		{
			x=j%i;W(!q[x].empty()&&dp[op^1][q[x].back()]-q[x].back()/i>dp[op^1][j]-j/i) q[x].pop_back();q[x].push_back(j);
			(j-q[x].front())/i>c[i]&&(q[x].pop_front(),0),dp[op][j]=dp[op^1][q[x].front()]+(j-q[x].front())/i;
		}
	}
	RI t=1e9;for(i=1;i<=n;++i) pd(i)&&(t=min(t,dp[op][i]));return t==1e9?puts("-1"):printf("%d\n",t-1),0;
}