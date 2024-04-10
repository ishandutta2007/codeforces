#include<bits/stdc++.h>
#define CI const int&
#define N 100000
#define X 998244353
#define I2 499122177
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
using namespace std;
int n,m,a[N+5],p[2*N+5],pw[N+5],ipw[N+5],c[2*N+5],g1[3*N+5],g2[3*N+5],f[5*N+5];
int QP(int x,int y=X-2) {int t=1;while(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
namespace Poly
{
	#define PR 3
	#define IPR 332748118
	int P,L,R[6*N+5],A[6*N+5],B[6*N+5];
	void NTT(int* s)
	{
		int i,j,k,x,y,U,S;for(i=0;i^P;++i) i<R[i]&&(swap(s[i],s[R[i]]),0);
		for(i=1;i^P;i<<=1) for(U=QP(PR,X/(i<<1)),j=0;j^P;j+=i<<1)
			for(S=1,k=0;k^i;++k,S=1LL*S*U%X) s[j+k]=((x=s[j+k])+(y=1LL*S*s[i+j+k]%X))%X,s[i+j+k]=(x-y+X)%X;
	}
	void INTT(int* s)
	{
		int i,j,k,x,y,U,S;for(i=0;i^P;++i) i<R[i]&&(swap(s[i],s[R[i]]),0);
		for(i=1;i^P;i<<=1) for(U=QP(IPR,X/(i<<1)),j=0;j^P;j+=i<<1)
			for(S=1,k=0;k^i;++k,S=1LL*S*U%X) s[j+k]=((x=s[j+k])+(y=1LL*S*s[i+j+k]%X))%X,s[i+j+k]=(x-y+X)%X;
		for(x=QP(P),i=0;i^P;++i) s[i]=1LL*s[i]*x%X;
	}
	void Work(int l,int r)
	{
		if(l==r) return;int i,u=l+r>>1;Work(l,u),Work(u+1,r);
		int l1=l,r1=min(2*n,u),l2=max(n,u)+1,r2=r;if(l1>r1||l2>r2) return;
		P=1,L=0;while(P<=r2-l2+r1-l1) P<<=1,++L;for(i=0;i^P;++i) A[i]=B[i]=0,R[i]=(R[i>>1]>>1)|((i&1)<<L-1);
		for(i=l1;i<=r1;++i) A[i-l1]=g2[i];for(i=l2;i<=r2;++i) B[i-l2]=g1[i];
		for(NTT(A),NTT(B),i=0;i^P;++i) A[i]=1LL*A[i]*B[i]%X;INTT(A);
		for(i=0;i<=r1-l1+r2-l2;++i) Inc(f[i+l1+l2],A[i]);
	}
	void Solve() {memset(f,0,sizeof(f)),Work(0,3*n);}
}
int main()
{
	int i,x;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d",a+i);
	for(i=1;i<=m;++i) scanf("%d",&x),p[x]=1;
	for(pw[0]=ipw[0]=i=1;i<=n;++i) pw[i]=(pw[i-1]<<1)%X,ipw[i]=1LL*ipw[i-1]*I2%X;
	#define Ex(x) (x>=0?p[x]:0)
	int t=0;for(i=1;i<=2*n;++i) c[i]=c[i-1]+p[i];
	for(i=0;i<=n;++i) g2[i]=1;
	for(i=0;i<=2*n;++i) g1[n+i]=1LL*i*(ipw[c[i]]<<p[i])%X,g2[n+i]=(pw[c[i]]<<p[i+1])%X;
	for(Poly::Solve(),i=1;i<=n;++i) t=(t+1LL*a[i]*f[2*(n+i)-1])%X;
	for(i=0;i<=2*n;++i) g1[n+i]=(ipw[c[i]]<<p[i])%X,g2[n+i]=(pw[c[i]]<<p[i+1])%X;
	for(Poly::Solve(),i=1;i<=n;++i) t=(t-1LL*a[i]*i%X*f[2*(n+i)-1]%X+X)%X;
	for(i=0;i<=2*n;++i) g1[n+i]=1LL*i*ipw[c[i]]%X,g2[n+i]=pw[c[i]];
	for(Poly::Solve(),i=1;i<=n;++i) t=(t-1LL*a[i]*f[2*(n+i)-1]%X+X)%X;
	for(i=0;i<=2*n;++i) g1[n+i]=ipw[c[i]],g2[n+i]=pw[c[i]];
	for(Poly::Solve(),i=1;i<=n;++i) t=(t+1LL*a[i]*i%X*f[2*(n+i)-1])%X;
	return printf("%d\n",(int)(1LL*t*pw[m]%X*QP(pw[m]-1)%X)),0;
}