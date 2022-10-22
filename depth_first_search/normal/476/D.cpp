#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
using namespace std;
int n,k;
int main()
{
	RI i,x;scanf("%d%d",&n,&k),printf("%d\n",(6*n-1)*k);
	for(i=x=1;i<=n;++i,x+=6) printf("%d %d %d %d\n",x*k,(x+1)*k,(x+2)*k,(x+4)*k);return 0;
}