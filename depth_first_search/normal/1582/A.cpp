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
int a,b,c;
int main()
{
	RI Tt;scanf("%d",&Tt);W(Tt--) switch(scanf("%d%d%d",&a,&b,&c),(c&1)<<2|(b&1)<<1|(a&1))
	{
		case 0:puts("0");break;case 1:puts("1");break;case 2:puts(a||b>=3&&c>=2?"0":"2");break;
		case 3:puts("1");break;case 4:puts(a||b?"1":"3");break;case 5:puts(a>1||b?"0":"2");break;
		case 6:puts("1");break;case 7:puts("0");break;
	}return 0;
}