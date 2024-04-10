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
#define LL long long
using namespace std;
int n,s,e,nxt[N+5],x[N+5],a[N+5],b[N+5],c[N+5],d[N+5];
I LL F(CI i,CI j) {return i>j?0LL+x[i]-x[j]+c[i]+b[j]:0LL+x[j]-x[i]+d[i]+a[j];}
int main()
{
	RI i;for(scanf("%d%d%d",&n,&s,&e),i=1;i<=n;++i) scanf("%d",x+i);for(i=1;i<=n;++i) scanf("%d",a+i);
	for(i=1;i<=n;++i) scanf("%d",b+i);for(i=1;i<=n;++i) scanf("%d",c+i);for(i=1;i<=n;++i) scanf("%d",d+i);
	RI k,t;LL g=F(s,e);for(nxt[s]=e,i=1;i<=n;++i) if(i^s&&i^e)
	{
		for(t=s,k=nxt[s];k^e;k=nxt[k]) F(t,i)+F(i,nxt[t])-F(t,nxt[t])>F(k,i)+F(i,nxt[k])-F(k,nxt[k])&&(t=k);
		g+=F(t,i)+F(i,nxt[t])-F(t,nxt[t]),nxt[i]=nxt[t],nxt[t]=i;
	}return printf("%lld\n",g),0;
}