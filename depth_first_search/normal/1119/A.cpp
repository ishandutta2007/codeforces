#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 300000
using namespace std;
int n,a[N+5];
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	if(a[1]^a[n]) return printf("%d",n-1),0;
	RI l=1,r=n;W(l<=n&&a[l]==a[1]) ++l;if(l>n) return puts("0"),0;
	W(a[r]==a[1]) --r;return printf("%d",max(r-1,n-l)),0;
}