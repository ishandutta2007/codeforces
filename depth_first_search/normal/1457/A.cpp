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
int n,m,r,c;
int main()
{
	RI Tt;scanf("%d",&Tt);W(Tt--)
		scanf("%d%d%d%d",&n,&m,&r,&c),printf("%d\n",max(r-1,n-r)+max(c-1,m-c));
	return 0;
}