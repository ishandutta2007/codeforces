#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 5000
using namespace std;
int n,a[N+5],dc,dv[N+5],s[N+5],vis[N+5];
int main()
{
	RI i,j;for(scanf("%d",&n),i=1;i<=n;dv[i]=a[i],++i)
		for(scanf("%d",a+i),j=2;j*j<=abs(a[i]);++j) W(!(a[i]%(j*j))) a[i]/=j*j;
	sort(dv+1,dv+n+1),dc=unique(dv+1,dv+n+1)-dv-1;
	for(i=1;i<=n;++i) a[i]=lower_bound(dv+1,dv+dc+1,a[i])-dv; 
	RI t;for(i=1;i<=n;++i) for(t=0,j=i;j<=n;++j)
		dv[a[j]]&&vis[a[j]]^i&&(vis[a[j]]=i,++t),++s[max(t,1)];
	for(i=1;i<=n;++i) printf("%d%c",s[i]," \n"[i==n]);return 0;
}