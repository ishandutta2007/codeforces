#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 2000
#define LL long long
using namespace std;
int n,a[N+5];
int main()
{
	RI Tt,i,j,t;LL k;scanf("%d",&Tt);W(Tt--)
	{
		if(scanf("%lld",&k),k&1) {puts("-1");continue;}
		for(t=0,i=62;i;--i) k&(1LL<<i)&&(i^1&&(a[++t]=i-1),a[++t]=1);
		for(n=1,i=1;i^t;++i) n+=a[i];printf("%d\n",n);
		for(putchar('1'),putchar(' '),i=1;i^t;++i)
			{for(j=1;j^a[i];++j) putchar('0'),putchar(' ');putchar('1'),putchar(' ');}
		putchar('\n');
	}return 0;
}