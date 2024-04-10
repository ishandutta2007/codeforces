#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000000
#define X 1000000007
using namespace std;
int n,k,f[N+5],Inv[N+5];
int main()
{
	RI i;for(scanf("%d%d",&n,&k),Inv[1]=1,i=2;i<=n;++i) Inv[i]=1LL*(X-X/i)*Inv[X%i]%X;
	RI t=1;for(f[0]=i=1;i^n;++i) i>k&&(t=(t-f[i-k-1]+X)%X),f[i]=1LL*t*Inv[i]%X,t=(t+f[i])%X;
	for(t=i=0;i^n;++i) t=(t+f[i])%X;for(t=(n-t+X)%X,i=1;i^n;++i) t=1LL*t*i%X;return printf("%d\n",t),0;
}