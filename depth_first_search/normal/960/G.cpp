#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define X 998244353
using namespace std;
int n,A,B;I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
namespace Poly
{
	#define PR 3
	int P,L,A[N<<1],B[N<<1],R[N<<1];I void T(int* s,CI op)
	{
		RI i,j,k,x,y,U,S;for(i=0;i^P;++i) i<R[i]&&(swap(s[i],s[R[i]]),0);
		for(i=1;i^P;i<<=1) for(U=QP(QP(PR,op),(X-1)/(i<<1)),j=0;j^P;j+=i<<1) for(S=1,
			k=0;k^i;++k,S=1LL*S*U%X) s[j+k]=((x=s[j+k])+(y=1LL*S*s[i+j+k]%X))%X,s[i+j+k]=(x-y+X)%X;
	}
	int ct,f[50][N+5];I void Solve(CI l,CI r,CI rt)
	{
		if(l==r) return (void)(f[rt][0]=l-1,f[rt][1]=1);
		RI i,mid=l+r>>1,lc=++ct,rc=++ct;Solve(l,mid,lc),Solve(mid+1,r,rc);
		P=1,L=0;W(P<=2*(r-l+1)) P<<=1,++L;for(i=0;i^P;++i) A[i]=B[i]=0,R[i]=(R[i>>1]>>1)|((i&1)<<L-1);
		for(i=0;i<=mid-l+1;++i) A[i]=f[lc][i];for(i=0;i<=r-mid;++i) B[i]=f[rc][i];
		for(T(A,1),T(B,1),i=0;i^P;++i) A[i]=1LL*A[i]*B[i]%X;
		RI t=QP(P,X-2);for(T(A,X-2),i=0;i<=r-l+1;++i) f[rt][i]=1LL*A[i]*t%X;ct-=2;
	}
}
I int S1(CI n,CI m) {return n>m?(Poly::Solve(1,n,0),Poly::f[0][m]):n==m;}
I int C(CI n,CI m) {RI i,t=1;for(i=m+1;i<=n;++i) t=1LL*t*i%X*QP(i-m,X-2)%X;return t;}
int main()
{
	if(scanf("%d%d%d",&n,&A,&B),!A||!B) return puts("0"),0;
	return printf("%lld\n",1LL*S1(n-1,A+B-2)*C(A+B-2,A-1)%X),0;
}