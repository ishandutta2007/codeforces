#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define X 1000000007
using namespace std;
int n,Pt,P[N+5],mu[N+5],s[N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
I void Sieve()
{
	RI i,j;for(mu[1]=1,i=2;i<=n;++i)
		for(!P[i]&&(mu[P[++Pt]=i]=X-1),j=1;j<=Pt&&i*P[j]<=n;++j)
			if(P[i*P[j]]=1,i%P[j]) mu[i*P[j]]=X-mu[i];else break;
	for(i=1;i<=n;++i) s[i]=(s[i-1]+mu[i])%X;
}
int main()
{
	RI l,r,t=1;for(scanf("%d",&n),Sieve(),l=2;l<=n;l=r+1)
		r=n/(n/l),t=(1LL*(X-1)*(s[r]-s[l-1]+X)%X*(n/l)%X*QP(n-n/l,X-2)+t)%X;
	return printf("%d\n",t),0;
}