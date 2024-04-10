#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
using namespace std;
int n,p,k,x,y,c[N+5];char s[N+5];
int main()
{
	RI Tt,i,j,ans;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%d%d%s",&n,&p,&k,s+1),i=0;i^k;++i) c[i]=0;for(i=p;i<=n;++i) c[i%k]+=s[i]&1;
		for(scanf("%d%d",&x,&y),ans=n*x,i=0;i<=n-p;++i)
			ans=min(ans,((n-i-p)/k+1-c[(p+i)%k])*x+i*y),c[(p+i)%k]-=s[p+i]&1;
		printf("%d\n",ans);
	}return 0;
}