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
#define V 58
using namespace std;
Cn int Pt=16,P[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n,a[N+5],g[V+5],f[N+5][1<<Pt],w[N+5][1<<Pt];
I void Print(CI x,CI y) {if(!x) return;Print(x-1,y^g[w[x][y]]),printf("%d ",w[x][y]);}
int main()
{
	RI i,j;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	for(i=0;i^Pt;++i) for(j=P[i];j<=V;j+=P[i]) g[j]|=1<<i;
	RI l=1<<Pt,k,v;for(i=1;i<=n;++i) for(j=0;j^l;++j)
		for(f[i][j]=1e9,k=1;k<=V;++k) (j&g[k])==g[k]&&(v=f[i-1][j^g[k]]+abs(a[i]-k))<f[i][j]&&(f[i][j]=v,w[i][j]=k);
	return Print(n,l-1),0; 
}