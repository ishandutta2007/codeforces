#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define V 100000
#define X 998244353
using namespace std;
int n,m,g[V<<2],s[V<<2];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
class Poly
{
	private:
		int P,L,R[V<<2],t[V<<2],k[V<<2],PR,IPR,I2;
		I void T(int *s,CI p)
		{
			RI i,j,k,U,S,x,y;for(i=0;i^P;++i) i<R[i]&&(x=s[i],s[i]=s[R[i]],s[R[i]]=x);
			for(i=1;i^P;i<<=1) for(U=QP(p,(X-1)/(i<<1)),j=0;j^P;j+=i<<1) for(S=1,k=0;k^i;
				S=1LL*S*U%X,++k) s[j+k]=((x=s[j+k])+(y=1LL*S*s[i+j+k]%X))%X,s[i+j+k]=(x-y+X)%X;
		}
	public:
		I Poly() {PR=3,IPR=QP(3,X-2),I2=X+1>>1;}
		I void Inv(CI n,int *a,int *b)
		{
			if(!n) return (void)(b[0]=QP(a[0],X-2));Inv(n>>1,a,b);
			RI i;P=1,L=0;W(P<=(n<<1)) P<<=1,++L;for(i=0;i^P;++i) R[i]=(R[i>>1]>>1)|((i&1)<<L-1);
			for(i=0;i<=n;++i) t[i]=a[i];W(i^P) t[i++]=0;
			for(T(b,PR),T(t,PR),i=0;i^P;++i) b[i]=(2LL*b[i]-1LL*t[i]*b[i]%X*b[i]%X+X)%X;
			RI t=QP(P,X-2);for(T(b,IPR),i=0;i<=n;++i) b[i]=1LL*b[i]*t%X;W(i^P) b[i++]=0;
		}
		I void Sqrt(CI n,int *a,int *b)
		{
			if(!n) return (void)(b[0]=1);Sqrt(n>>1,a,b);
			RI i;P=1,L=0;W(P<=(n<<1)) P<<=1,++L;for(i=0;i^P;++i) R[i]=(R[i>>1]>>1)|((i&1)<<L-1);
			for(i=0;i^P;++i) k[i]=0;for(Inv(n,b,k),i=0;i<=n;++i) t[i]=a[i];W(i^P) t[i++]=0;
			for(T(t,PR),T(b,PR),T(k,PR),i=0;i^P;++i) b[i]=(1LL*b[i]*b[i]+t[i])%X*k[i]%X*I2%X;
			RI t=QP(P,X-2);for(T(b,IPR),i=0;i<=n;++i) b[i]=1LL*b[i]*t%X;W(i^P) b[i++]=0;
		}
}P;
int main()
{
	RI i,x;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d",&x),g[x]=1;
	for(g[0]=i=1;i<=V;++i) g[i]=X-4LL*g[i]%X;P.Sqrt(V,g,s),++s[0]==X&&(s[0]=0);
	for(memset(g,0,sizeof(g)),P.Inv(V,s,g),i=1;i<=m;++i) printf("%d\n",2LL*g[i]%X);
	return 0;
}