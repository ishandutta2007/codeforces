#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define RL Reg LL
#define Con const
#define CI Con int&
#define CL Con LL&
#define I inline
#define W while
#define N 25
#define LL long long
using namespace std;
int n,m,k,a[N+5];LL s,ans,Fac[N+5];map<LL,int> p[N+5];
I void dfs1(CI x,CI u,CL v)
{
	if(x>n/2) {for(RI i=u;i<=k;++i) ++p[i][v];return;}
	dfs1(x+1,u,v),a[x]+v<=s&&(dfs1(x+1,u,a[x]+v),0),
	a[x]<=m&&Fac[a[x]]+v<=s&&u<k&&(dfs1(x+1,u+1,Fac[a[x]]+v),0);
}
I void dfs2(CI x,CI u,CL v)
{
	if(x>n) return (void)(ans+=p[k-u][s-v]);
	dfs2(x+1,u,v),a[x]+v<=s&&(dfs2(x+1,u,a[x]+v),0),
	a[x]<=m&&Fac[a[x]]+v<=s&&u<k&&(dfs2(x+1,u+1,Fac[a[x]]+v),0);
}
int main()
{
	RI i;for(scanf("%d%d%lld",&n,&k,&s),i=1;i<=n;++i) scanf("%d",a+i);
	for(Fac[0]=i=1;Fac[i-1]<=s;++i) Fac[i]=Fac[i-1]*i;m=i-1;
	return dfs1(1,0,0),dfs2(n/2+1,0,0),printf("%lld",ans),0;
}