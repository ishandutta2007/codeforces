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
int l,r;LL m;
int main()
{
	RI Tt,i;LL n,t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%d%lld",&l,&r,&m),i=l;i<=r;++i)
		{
			if(n=m/i,!n&&++n,(n+1)*i-m<m-n*i&&++n,abs(t=m-n*i)>r-l) continue;
			if(t<0) printf("%d %d %d\n",i,l,l-t);else printf("%d %d %d\n",i,r,r-t);break;
		}
	}return 0;
}