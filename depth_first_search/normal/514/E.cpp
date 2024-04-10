#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define V 100
#define X 1000000007
using namespace std;
int n,m,c[V+5];struct M
{
	int a[V+5][V+5];I M() {memset(a,0,sizeof(a));}
	I int* operator [] (CI x) {return a[x];}I Cn int* operator [] (CI x) Cn {return a[x];}
	I M operator * (Cn M& o) Cn {M t;for(RI i=0;i<=V;++i)
		for(RI j=0;j<=V;++j) for(RI k=0;k<=V;++k) t[i][j]=(t[i][j]+1LL*a[i][k]*o[k][j])%X;return t;}
}U,S;
I void QP(RI y) {W(y) y&1&&(S=S*U,0),U=U*U,y>>=1;}
int main()
{
	RI i,j,x;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d",&x),++c[x];
	for(U[0][0]=j=1;j<=V;++j) U[j][0]=U[j][1]=c[j];for(j=2;j<=V;++j) U[j-1][j]=1;
	return S[0][0]=S[0][1]=1,QP(m),printf("%d\n",S[0][0]),0;
}