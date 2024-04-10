#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define V 10000000
#define X 1000000007
using namespace std;
int n,a[N+5],pw[N+5],f[V+5],g[V+5],c[V+5],S[N+5];
int main()
{
	RI i,j;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i),++c[a[i]];
	for(i=1;i<=V;++i) for(j=i<<1;j<=V;j+=i) c[i]+=c[j];
	for(pw[0]=i=1;i<=n;++i) pw[i]=(pw[i-1]<<1)%X;for(i=V;i;--i)
	{
		f[i]=1LL*c[i]*(pw[c[i]-1]-1)%X,g[i]=(1LL*n*(pw[c[i]]-1)-1LL*c[i]*pw[c[i]-1]%X+X)%X;
		for(j=i<<1;j<=V;j+=i) f[i]=(f[i]-f[j]+X)%X,g[i]=(g[i]-g[j]+X)%X;
	}return printf("%d\n",(f[1]-g[1]+X)%X),0;
}