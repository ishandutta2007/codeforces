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
#define X 1000000007
using namespace std;
int n,m,lim,k,a[N+5];struct M
{
	int a[N+5][N+5];I M() {memset(a,0,sizeof(a));}
	I int* operator [] (CI x) {return a[x];}I Cn int* operator [] (CI x) Cn {return a[x];}
	I M operator * (Cn M& o) Cn {M t;for(RI i=0;i<=lim;++i)
		for(RI j=0;j<=lim;++j) for(RI k=0;k<=lim;++k) t[i][j]=(t[i][j]+1LL*a[i][k]*o[k][j])%X;return t;}
	I M operator ^ (RI y) {M x=*this,t;for(RI i=0;i<=lim;++i) t[i][i]=1;W(y) y&1&&(t=t*x,0),x=x*x,y>>=1;return t;}
}S,U;
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,j;for(scanf("%d%d",&n,&k),i=1;i<=n;++i) scanf("%d",a+i),m+=!a[i];
	RI Inv=QP(1LL*n*(n-1)/2%X,X-2);for(lim=min(m,n-m),i=0;i<=lim;++i)
		i&&(U[i][i-1]=1LL*i*i%X*Inv%X),U[i][i+1]=1LL*(m-i)*(n-m-i)%X*Inv%X,U[i][i]=(1LL-(i?U[i][i-1]:0)-U[i][i+1]+2*X)%X;
	RI t=0;for(i=1;i<=m;++i) a[i]&&++t;return S[t][t]=1,printf("%d\n",(S*(U^k))[t][0]),0;
}