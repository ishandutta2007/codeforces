#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define V 300000
#define X 998244353
using namespace std;
int n,a[N+5],f[V+5];I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;} 
int main()
{
	RI i,A=0;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i),A+=a[i];
	RI t;for(i=1;i^A;++i) t=1LL*(n-1)*QP(A-i,X-2)%X,f[i+1]=((1LL*A*t-(n-2)+X)%X*f[i]-1LL*i*t%X*f[i-1]%X+X+1LL*i*t)%X;
	for(t=f[A],i=1;i<=n;++i) t=(t-f[a[i]]+X)%X;return printf("%d\n",t),0;
}