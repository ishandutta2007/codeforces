#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 50
using namespace std;
int n,a[N+5];
int main()
{
	RI Tt,i,x,t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),t=0,i=1;i<=n;++i) scanf("%d",&x),t^=x-1&1;
		puts(t?"errorgorn":"maomao90");
	}return 0;
}