#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 2000000
#define X 1000000007
using namespace std;
int n,k,s[2*N+5],G[N+5],Pt,P[N+5],mu[N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,j;for(scanf("%d%d",&n,&k),i=1;i<=k;++i) G[i]=QP(i,n);
	for(mu[1]=1,i=2;i<=k;++i) for(!P[i]&&(mu[P[++Pt]=i]=X-1),
		j=1;i*P[j]<=k;++j) if(P[i*P[j]]=1,i%P[j]) mu[i]&&(mu[i*P[j]]=X-mu[i]);else break;
	for(i=1;i<=k;++i) for(j=1;j<=k/i;++j) s[i*j]=(s[i*j]+1LL*mu[i]*G[j])%X,s[i*(j+1)]=(s[i*(j+1)]-1LL*mu[i]*G[j]%X+X)%X;
	RI t=0;for(i=1;i<=k;++i) s[i]=(s[i]+s[i-1])%X,t=(t+(s[i]^i))%X;return printf("%d\n",t),0;
}