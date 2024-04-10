#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 25
#define V 50000
#define LL long long
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
int n,a[2*N+5];
class DpSolver
{
	private:
		bitset<2*N*V+5> f[2*N+5];
	public:
		I int GetAns()
		{
			RI i,j,s=0,ans=s;for(i=1;i<=2*n;++i) s+=a[i];
			for(f[0].set(0),i=3;i<=2*n;++i) for(j=min(n-1,i-2);j;--j) f[j]|=f[j-1]<<a[i];
			for(s-=a[1]+a[2],i=0;i<=s;++i) f[n-1].test(i)&&max(ans,s-ans)>max(i,s-i)&&(ans=i);
			return min(ans,s-ans);
		}
}DP;
class DfsSolver
{
	private:
		#define pb push_back
		LL w[N+5][N*V+5];
		I void dfs1(CI p,CI x,CI y,CI t,CI v,Con LL& s)
		{
			if(x>y) return (void)(!~w[t][v]&&(w[t][v]=s));
			dfs1(p,x+1,y,t,v,s),v+a[x]<=p&&(dfs1(p,x+1,y,t+1,v+a[x],s|(1LL<<x)),0);return;
		}
		I void dfs2(CI p,CI x,CI y,CI t,CI v,Con LL& s)
		{
			if(x>y)
			{
				if(!~w[n-1-t][p-v]) return;RI i;LL g=w[n-1-t][p-v]|s;
				printf("%d ",a[1]);for(i=3;i<=2*n;++i) g>>i&1&&printf("%d ",a[i]);putchar('\n');
				for(i=2*n;i>=3;--i) !(g>>i&1)&&printf("%d ",a[i]);printf("%d\n",a[2]);exit(0);
			}
			dfs2(p,x+1,y,t,v,s),v+a[x]<=p&&(dfs2(p,x+1,y,t+1,v+a[x],s|(1LL<<x)),0);
		}
	public:
		I void Solve(CI x) {memset(w,-1,sizeof(w)),dfs1(x,3,n+1,0,0,0),dfs2(x,n+2,2*n,0,0,0);}
}DFS;
int main()
{
	RI i,j;for(scanf("%d",&n),i=1;i<=2*n;++i) scanf("%d",a+i);
	return sort(a+1,a+2*n+1),DFS.Solve(DP.GetAns()),0;
}