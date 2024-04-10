#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 150000
#define M 300
#define LL long long
using namespace std;
int n,m,d,a[M+5],ti[M+5],q[N+5];LL f[2][N+5];
int main()
{
	RI i,o;LL s=0;for(scanf("%d%d%d",&n,&m,&d),i=1;i<=m;++i) scanf("%d%d%d",a+i,&o,ti+i),s+=o;
	RI j,H,T;for(i=1;i<=m;++i)
	{
		for(H=1,T=0,j=1;j<=n;++j)
		{
			W(H<=T&&q[H]<j-1LL*(ti[i]-ti[i-1])*d) ++H;W(H<=T&&f[i&1^1][q[T]]<f[i&1^1][j]) --T;
			q[++T]=j,f[i&1][j]=f[i&1^1][q[H]];
		}
		for(H=1,T=0,j=n;j>=1;--j)
		{
			W(H<=T&&q[H]>j+1LL*(ti[i]-ti[i-1])*d) ++H;W(H<=T&&f[i&1^1][q[T]]<f[i&1^1][j]) --T;
			q[++T]=j,f[i&1][j]=max(f[i&1][j],f[i&1^1][q[H]]);
		}
		for(j=1;j<=n;++j) f[i&1][j]-=abs(a[i]-j);
	}
	LL t=-1e18;for(i=1;i<=n;++i) t=max(t,f[m&1][i]);return printf("%lld\n",t+s),0;
}