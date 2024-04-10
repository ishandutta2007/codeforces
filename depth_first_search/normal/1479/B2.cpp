#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
using namespace std;
int n,a[N+5],f[N+5];
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i),f[i]=1e9;
	RI t,tg=0,Mn=0;for(i=1;i<=n;++i) t=min(Mn+tg+1,f[a[i]]+tg),
		a[i-1]^a[i]&&++tg,f[a[i-1]]+tg>t&&(Mn=min(Mn,f[a[i-1]]=t-tg));
	return printf("%d\n",Mn+tg),0;
}