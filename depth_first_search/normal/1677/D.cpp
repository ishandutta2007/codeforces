#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000000
#define X 998244353
using namespace std;
int n,k,a[N+5];
int main()
{
	RI Tt,i,x,t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%d",&n,&k),i=1;i<=n;++i) scanf("%d",a+i);
		for(t=i=1;i<=k;++i) t=1LL*t*i%X,~a[n-k+i]&&a[n-k+i]&&(t=0);
		for(i=1;i<=n-k;++i) !~a[i]?t=1LL*t*(k+i)%X:(!a[i]?t=1LL*t*(k+1)%X:a[i]>=i&&(t=0));
		printf("%d\n",t);
	}return 0;
}