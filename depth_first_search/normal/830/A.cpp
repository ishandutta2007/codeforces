// luogu-judger-enable-o2
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
#define K 2000
#define INF 2e9
#define abs(x) ((x)<0?-(x):(x))
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
int n,m,p,a[N+5],b[K+5];
class DpSolver
{
	private:
		int f[N+5][K+5];
	public:
		I void Solve()
		{
			RI i,j,ans=INF;sort(a+1,a+n+1),sort(b+1,b+m+1);
			for(i=1;i<=n;++i) for(j=0;j<=m;++j) f[i][j]=INF;
			for(i=1;i<=n;++i) for(j=i;j<=m;++j)
				f[i][j]=min(max(f[i-1][j-1],abs(a[i]-b[j])+abs(p-b[j])),f[i][j-1]);
			printf("%d",f[n][m]);
		}
}D;
int main()
{
	RI i;for(scanf("%d%d%d",&n,&m,&p),i=1;i<=n;++i) scanf("%d",a+i);
	for(i=1;i<=m;++i) scanf("%d",b+i);return D.Solve(),0;
}