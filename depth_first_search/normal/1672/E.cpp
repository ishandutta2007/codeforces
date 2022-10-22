#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 2001
using namespace std;
int n,f[N*N+5],lim[N*N+5];
I int Q(CI x)
{
	if(~f[x]) return f[x];printf("? %d\n",x),fflush(stdout);
	scanf("%d",f+x);for(RI i=x;i;--i) lim[i]=max(lim[i],f[x]);return f[x];
}
int main()
{
	scanf("%d",&n);
	RI l=1,r=n*N-1,u;memset(f,-1,sizeof(f));W(l^r) Q(u=l+r-1>>1)==1?r=u:l=u+1;
	RI t=r,ans=t;for(RI i=2;i<=n;++i) lim[t/i]<=i&&Q(t/i)&&(ans=min(ans,Q(t/i)*(t/i)));
	return printf("! %d\n",ans),fflush(stdout),0;
}