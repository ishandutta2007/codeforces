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
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
int a,b,c,d;I LL gcd(Con LL& a,Con LL& b) {return b?gcd(b,a%b):a;}
int main()
{
	#define P(x) {printf("%d\n",x);continue;}
	RI Tt;scanf("%d",&Tt);W(Tt--)
	{
		if(scanf("%d%d%d%d",&a,&b,&c,&d),c<=d) P(a>1LL*b*c?-1:a);
		if(a<=1LL*b*d) P(a);if(a>1LL*b*c) P(-1);
		LL g=a/(b*d),t=min(c/d,g);
		printf("%lld\n",max(a,a*(t+1)-t*(t+1)/2*(1LL*b*d)));
	}return 0;
}