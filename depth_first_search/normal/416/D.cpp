#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
using namespace std;
int n,a[N+5],f[N+5],q[N+5];
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	RI d=0,H=1,T=0;for(i=1;i<=n;++i)
	{
		if(!~a[i]) {f[i]=i==1?1:(!T||a[q[T]]+1LL*(i-q[T])*d>0?f[i-1]:(H=T,d=0,f[q[T-1]]+1));continue;}
		if(!T) {f[q[++T]=i]=1;continue;}
		(a[i]-a[q[T]])%(i-q[T])?(d=0,H=T+1):(d=(a[i]-a[q[T]])/(i-q[T]),H^T&&a[q[T]]-a[q[T-1]]!=1LL*d*(q[T]-q[T-1])&&(H=T));
		f[q[++T]=i]=f[max(q[H-1],d>0?q[H]-(a[q[H]]-1)/d-1:0)]+1;
	}return printf("%d\n",f[n]),0;
}