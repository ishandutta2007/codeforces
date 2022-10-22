#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
using namespace std;
int x,y;
int main()
{
	RI Tt;scanf("%d",&Tt);W(Tt--) scanf("%d%d",&x,&y),printf("%d\n",y<x?x+y:(y==x?x:y-(x+y>>1)%x));return 0;
}