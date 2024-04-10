#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100
using namespace std;
int n,a[N+5];
int main()
{
	RI Tt,i;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
		for(i=1;i<=n;++i) printf("%d%c",(i&1?1:-1)*a[((i-1)^1)+1]," \n"[i==n]);
	}return 0;
}