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
int n,a[N+5];map<int,int> p;
int main()
{
	RI i,t=0,f=0;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	for(sort(a+1,a+n+1),i=1;i<=n;++i)
		if(++p[a[i]]==2) {if(f||!a[i]||p[a[i]-1]) return puts("cslnb"),0;f=1;}
		else if(p[a[i]]==3) return puts("cslnb"),0;
	for(i=1;i<=n;++i) t^=(a[i]-i+1)&1;return puts(t?"sjfnb":"cslnb"),0;
}