#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 5000
using namespace std;
int n,p[N+5],s[N+5][N+5];
int main()
{
	RI Tt,i,j;long long t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),i=1;i<=n;++i) for(j=1;j<=n;++j) s[i][j]=0;
		for(i=1;i<=n;++i) scanf("%d",p+i),s[i][p[i]]=1;
		for(i=1;i<=n;++i) for(j=1;j<=n;++j) s[i][j]+=s[i][j-1];
		for(i=1;i<=n;++i) for(j=1;j<=n;++j) s[i][j]+=s[i-1][j];
		for(t=0,i=2;i<n;++i) for(j=i+1;j<n;++j) t+=1LL*s[i-1][p[j]]*(p[i]-s[j][p[i]]);
		printf("%lld\n",t);
	}return 0;
}