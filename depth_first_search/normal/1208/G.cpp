#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000000
using namespace std;
int n,k,Pt,P[N+5],phi[N+5];I void Sieve(CI n)
{
	phi[1]=1;for(RI i=2,j;i<=n;++i) for(!P[i]&&(phi[P[++Pt]=i]=i-1),j=1;j<=Pt&&i*P[j]<=n;++j)
		if(P[i*P[j]]=1,i%P[j]) phi[i*P[j]]=phi[i]*(P[j]-1);else {phi[i*P[j]]=phi[i]*P[j];break;} 
}
int main()
{
	RI i;long long t=1;for(scanf("%d%d",&n,&k),Sieve(n),sort(phi+3,phi+n+1),i=3;i<=2+k;++i) t+=phi[i];
	return k>=2&&++t,printf("%lld\n",t),0;
}