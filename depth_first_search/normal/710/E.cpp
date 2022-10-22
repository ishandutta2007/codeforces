#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 10000000
#define LL long long
using namespace std;
int n,a,b;LL f[N+5];
int main()
{
	RI i;for(scanf("%d%d%d",&n,&a,&b),i=1;i<=n;++i) f[i]=min(f[i-1]+a,i&1?f[i+1>>1]+b+a:f[i>>1]+b);
	return printf("%lld\n",f[n]),0;
}