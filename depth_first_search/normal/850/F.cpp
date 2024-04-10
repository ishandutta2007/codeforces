#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 2500
#define V 100000
#define X 1000000007
using namespace std;
int n,a[N+5],f[V+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,s=0,Mx=0;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i),s+=a[i],Mx=max(Mx,a[i]);
	for(f[1]=1LL*(s-1)*(s-1)%X*QP(s,X-2)%X,i=2;i<=Mx;++i) f[i]=(2LL*f[i-1]-f[i-2]-1LL*(s-1)*QP(s-(i-1),X-2)%X+2*X)%X;
	RI t=0;for(i=1;i<=n;++i) t=(t+f[a[i]])%X;return printf("%d\n",t),0;
}