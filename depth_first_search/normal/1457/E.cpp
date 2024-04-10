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
#define int long long 
using namespace std;
int n,k,a[N+5],b[N+5];
signed main()
{
	RI i,j;for(scanf("%lld%lld",&n,&k),i=1;i<=n;++i) scanf("%lld",a+i);
	RI t=0,cur=0;sort(a+1,a+n+1);W(n&&a[n]>0) t+=cur,cur+=a[n--];
	RI g=-1;for(i=1;i<=n;i+=k+1) for(++g,j=i;j<=i+k&&j<=n;++j) t+=a[j]*(b[j]=g);
	if(!n) return printf("%lld\n",t),0;
	RI m=n,r,ans;for(ans=t+cur*(r=(n-1)/(k+1)+1),i=r+1;i<=n;++i)
	{
		if(m%(k+1)==1) t-=a[m]*b[m],t+=cur,cur+=a[m],--r,--m;
		t-=a[m]*b[m],t+=cur,cur+=a[m],--m,ans=max(ans,t+cur*r);
	}return printf("%lld\n",ans),0;
}