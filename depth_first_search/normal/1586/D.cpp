#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100
using namespace std;
int n,a[N+5],s[N+5],pre[N+5],nxt[N+5];
int main()
{
	RI i,j,x;for(scanf("%d",&n),i=1;i<=n;++i)
	{
		for(printf("? "),j=1;j<=n;++j) printf("%d%c",1+(i==j)," \n"[j==n]);fflush(stdout);
		scanf("%d",&x),x&&x^i&&(pre[nxt[i]=x]=i);
	}
	for(i=1;i<=n;++i) if(!pre[i])
	{
		for(printf("? "),j=1;j<=n;++j) printf("%d%c",2-(i==j)," \n"[j==n]);fflush(stdout);
		scanf("%d",&x),x&&x^i&&(nxt[pre[i]=x]=i);
	}
	RI t;for(i=1;i<=n;++i) !pre[i]&&(t=i);for(i=1;i<=n;++i) s[t]=i,t=nxt[t];
	for(printf("! "),i=1;i<=n;++i) printf("%d%c",s[i]," \n"[i==n]);return fflush(stdout),0;
}