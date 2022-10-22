#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define LL long long
using namespace std;
int n,a[N+5],s[N+5];
int main()
{
	RI Tt,i,Mx;LL t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),t=0,i=1;i<=n;++i) scanf("%d",a+i),i^1&&(t+=abs(a[i]-a[i-1]));
		for(Mx=max(abs(a[1]-a[2]),abs(a[n-1]-a[n])),i=2;i<n;++i)
			Mx=max(Mx,abs(a[i]-a[i-1])+abs(a[i]-a[i+1])-abs(a[i-1]-a[i+1]));
		printf("%lld\n",t-Mx);
	}return 0;
}