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
int a,b,c,d;
int main()
{
	RI Tt;scanf("%d",&Tt);W(Tt--) scanf("%d%d%d%d",&a,&b,&c,&d),printf("%d\n",max(a+b,c+d));
	return 0;
}