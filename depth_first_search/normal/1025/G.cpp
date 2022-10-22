#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500
#define X 1000000007
using namespace std;
int n,a[N+5],p[N+5];
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) p[i]=1;for(i=1;i<=n;++i) scanf("%d",a+i),~a[i]&&(p[a[i]]=2LL*p[a[i]]%X);
	RI t=1;for(i=1;i^n;++i) t=2LL*t%X;for(--t,i=1;i<=n;++i) !~a[i]&&(t=(t-(p[i]-1)+X)%X);return printf("%d\n",t),0;
}