#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 40
#define LL long long
using namespace std;
int n,m,a[N+5][N+5];
namespace S0
{
	I LL Solve() {RI i,j;LL t=1;for(i=1;i<=n;++i) {for(j=1;j<=n&&!a[i][j];++j);j>n&&(t<<=1);}return t;}
}
namespace S1
{
	int c[N+5];bool Col(CI x)
	{
		for(RI i=1;i<=n;++i) if(a[x][i]&&(~c[i]?c[i]==c[x]:(c[i]=c[x]^1,!Col(i)))) return 0;return 1;
	}
	I LL Solve()
	{
		RI i;LL t=1;for(i=1;i<=n;++i) c[i]=-1;
		for(i=1;i<=n;++i) if(!~c[i]) if(c[i]=0,Col(i)) t<<=1;else return 0;return t;
	}
}
namespace S01
{
	LL w[N+5];
	int A[1<<N/2];void dfs1(CI x,LL s=0)
	{
		if(x>n/2) return (void)++A[s>>(n/2)];dfs1(x+1,s),!(s>>x-1&1)&&(dfs1(x+1,s|w[x]),0);
	}
	int B[1<<N/2];void dfs2(CI x,RI o=0,LL s=0)
	{
		if(x>n) return (void)++B[o];dfs2(x+1,o,s),!(s>>x-1&1)&&(dfs2(x+1,o|(1<<x-1-n/2),s|w[x]),0);
	}
	I LL Solve()
	{
		RI i,j;for(i=1;i<=n;++i) for(j=1;j<=n;++j) a[i][j]&&(w[i]|=1LL<<j-1);dfs1(1),dfs2(n/2+1);
		RI l=1<<n-n/2;for(j=0;j<n-n/2;++j) for(i=0;i^l;++i) i>>j&1&&(A[i]+=A[i^(1<<j)]);
		LL t=0;for(i=0;i^l;++i) t+=1LL*A[i^(l-1)]*B[i];return t;
	}
}
namespace S02
{
	int ct,vis[N+5];void dfs(CI x) {vis[x]=1;for(RI i=1;i<=n;++i) a[x][i]&&!vis[i]&&(dfs(i),0);}
	I LL Solve() {RI i;LL t=1;for(i=1;i<=n;++i) !vis[i]&&(dfs(i),t<<=1);return t;}
}
int main()
{
	if(scanf("%d%d",&n,&m),!m) return puts("0"),0;
	RI i,x,y;for(i=1;i<=m;++i) scanf("%d%d",&x,&y),a[x][y]=a[y][x]=1;
	return printf("%lld\n",(1LL<<n)-S02::Solve()-2*S01::Solve()+S1::Solve()+2*S0::Solve()),0;
}