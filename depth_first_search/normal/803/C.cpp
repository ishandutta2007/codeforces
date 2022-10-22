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
LL n,k;
int main()
{
	if(scanf("%lld%lld",&n,&k),k>=1e6||k*(k+1)/2>n) return puts("-1"),0;
	LL d=n/(k*(k+1)/2),p=0,t=0;for(RI i=1;1LL*i*i<=n&&i<=d;++i) if(!(n%i)) {if(n/i<=d) {p=n/i;break;}p=i;}
	for(RI i=1;i^k;++i) printf("%lld ",p*i),t+=p*i;return printf("%lld\n",n-t),0;
}