#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define LL long long
using namespace std;
int main()
{
	LL a;scanf("%lld",&a);LL x=(LL)1e18,y=x*9%a*9%a;return printf("%lld %lld\n",a-y,a-y-1+x),0;
}