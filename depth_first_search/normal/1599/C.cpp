#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
#define DB double
#define C2(x) ((x)*(x-1)/2)
#define C3(x) ((x)*(x-1)*(x-2)/6)
using namespace std;
int n;DB p;
DB Calc(CI x) {return (C3(x)+C2(x)*(n-x)+x*C2(n-x)/2.0)/C3(n);}
int main()
{
	scanf("%d%lf",&n,&p);for(RI i=0;i<=n;++i) if(Calc(i)>=p) return printf("%d\n",i),0;
}