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
#define V 2750131
using namespace std;
int n,a[N+5],c[V+5],Pt,P[V+5],id[V+5],Mx[V+5];I void Sieve()
{
	RI i,j;for(i=2;i<=V;++i) for(!Mx[i]&&(P[id[i]=++Pt]=i),j=1;j<=Pt&&i*P[j]<=V;++j) if(Mx[i*P[j]]=i,!(i%P[j])) break;
}
int main()
{
	RI i,x;for(Sieve(),scanf("%d",&n),i=1;i<=2*n;++i) scanf("%d",&x),++c[x];
	RI t=0;for(i=V;i;--i) W(c[i]--) Mx[i]?--c[Mx[a[++t]=i]]:--c[a[++t]=id[i]];
	for(i=1;i<=n;++i) printf("%d ",a[i]);return 0;
}