#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<cstdio>
#include<algorithm>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
#define V 400000000
#define X 998244353
using namespace std;
int n,a[N+5];I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;} 
int main()
{
	scanf("%d",&n);RI A=0;for(RI i=1;i<=n;++i) scanf("%d",a+i),A+=a[i];if(sort(a+1,a+n+1),n==1) return puts("0"),0;
	RI t=0,p=1,v,X0=0,Y0=1,X1=2,Y1=1,X2,Y2;W(a[p]==1) t+=2,++p;for(RI i=1;i^A;++i)
	{
		Y2=1LL*(A-i)*Y1%X*Y0%X,X2=((3LL*A-2*i)*X1%X*Y0-(2LL*A-i)*X0%X*Y1%X+X)%X;
		if(a[p]==i+1) {v=QP(Y2,X-2);W(a[p]==i+1) t=(t+1LL*X2*v)%X,++p;}X0=X1,Y0=Y1,X1=X2,Y1=Y2;
	}return printf("%d\n",(1LL*X2*QP(Y2,X-2)-t+X)%X),0;
}