#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1000
using namespace std;
int n,vis[N+5];double s[N+5],p[N+5],a[N+5][N+5];
int main()
{
	#define E(x) ((s[x]+p[x])/(1-p[x]))
	#define F5(x) vis[x]=1;for(RI i=1;i<=n;++i)\
		!vis[i]&&(s[i]+=(E(x)+1)*p[i]*a[i][x],p[i]*=1-a[i][x]);
	RI i,j,t;for(scanf("%d",&n),i=1;i<=n;++i)
		for(j=1;j<=n;++j) scanf("%lf",a[i]+j),a[i][j]/=100;
	for(i=1;i^n;++i) p[i]=1;F5(n);for(i=1;i<=n&&!vis[1];++i)
		{for(t=0,j=1;j<=n;++j) !vis[j]&&(!t||E(t)>E(j))&&(t=j);F5(t);}
	return printf("%.10lf\n",E(1)),0;
}