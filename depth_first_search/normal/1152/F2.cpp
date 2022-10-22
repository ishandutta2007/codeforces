#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define K 12
#define M 4
#define X 1000000007
using namespace std;
int n,k,m,l,tt,g[1<<M];
struct Mat
{
	int n,m,a[K+1<<M][K+1<<M];
	I void Init(CI _n,CI _m) {n=_n,m=_m;for(RI i=0;i^n;++i) for(RI j=0;j^m;++j) a[i][j]=0;}
	I int* operator [] (CI x) {return a[x];}I Cn int* operator [] (CI x) Cn {return a[x];}
	I Mat operator * (Cn Mat& o)
	{
		RI i,j,k;Mat t;t.Init(n,o.m);
		for(i=0;i^n;++i) for(j=0;j^o.n;++j) for(k=0;k^m;++k) t[i][j]=(t[i][j]+1LL*a[i][k]*o[k][j])%X;return t;
	}
}S,U;
int main()
{
	RI i,j,p,q;scanf("%d%d%d",&n,&k,&m),l=1<<m,tt=k+1<<m,S.Init(1,tt),U.Init(tt,tt);
	for(i=0;i^l;++i) g[i]=g[i>>1]+(i&1);
	for(i=0;i<=k;++i) for(j=0;j^l;++j) U[i<<m|j][i<<m|(j>>1)]=1,i^k&&(U[i<<m|j][i+1<<m|(j>>1|(1<<m-1))]=g[j]+1);
	S[0][0]=1;W(n) n&1&&(S=S*U,0),U=U*U,n>>=1;
	RI t=0;for(i=0;i^l;++i) t=(t+S[0][k<<m|i])%X;return printf("%d\n",t),0;
}