#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 50 
using namespace std;
int n,m,a[N+5],b[N+5];
int main()
{
	RI Tt,i;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d",a+i);
		for(i=1;i<=n;++i) scanf("%d",b+i);sort(a+1,a+n+1),sort(b+1,b+n+1);
		for(i=1;i<=n;++i) if(a[i]+b[n-i+1]>m) goto Wrong;
		puts("Yes");continue;Wrong:puts("No");
	}return 0;
}