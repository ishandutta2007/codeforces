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
int n,m,a[N+5];
int main()
{
	RI Tt,i,x,t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%d",&n,&m),i=1;i<=N;++i) a[i]=0;
		for(i=1;i<=n;++i) scanf("%d",&x),a[x]=1;
		for(t=0,i=1;i<=m;++i) scanf("%d",&x),t+=a[x];printf("%d\n",t);
	}return 0;
}