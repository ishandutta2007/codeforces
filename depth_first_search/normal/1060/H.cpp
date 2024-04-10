#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 10
using namespace std;
int o,d,X,tot=2,C[N+5][N+5];
I int A(CI x,CI y) {return ++tot,printf("+ %d %d %d\n",x,y,tot),tot;}
I int M(CI x,RI v) {RI u=x,t=o?o:0;W(v) v&1&&(t=t?A(t,u):u),u=A(u,u),v>>=1;return t;}
I int D(CI x,CI y) {RI z=M(y,X-1);return A(x,z);}
namespace G
{
	I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
	int a[N+5][N+5],v[N+5];I void Gauss()
	{
		RI i,j,k,t;for(i=0;i<=d;++i)
		{
			if(!a[i][i]) {for(j=i;j<=d&&!a[j][i];++j);for(swap(v[i],v[j]),k=i;k<=d;++k) swap(a[i][k],a[j][k]);}
			for(j=i+1;j<=d;++j) for(t=1LL*(X-a[j][i])*QP(a[i][i],X-2)%X,v[j]=(v[j]+1LL*t*v[i])%X,k=i;k<=d;++k) a[j][k]=(a[j][k]+1LL*t*a[i][k])%X;
		}
		for(i=d;~i;--i) for(v[i]=1LL*v[i]*QP(a[i][i],X-2)%X,j=i-1;~j;--j) v[j]=(v[j]-1LL*v[i]*a[j][i]%X+X)%X;
	}
}
I int Sqr(CI x) {RI t;for(RI i=0,p,s;i<=d;++i) p=i?A(p,5000):x,++tot,printf("^ %d %d\n",p,tot),s=M(tot,G::v[i]),t=i?A(t,s):s;return t;}
int main()
{
	RI i,j;scanf("%d%d",&d,&X),o=D(1,1);
	for(C[0][0]=i=1;i<=d;++i) for(C[i][0]=j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%X;
	RI p;for(i=0;i<=d;++i) for(j=0;j<=d;++j) G::a[j][i]=1LL*C[d][j]*G::QP(i,d-j)%X;G::v[2]=1,G::Gauss();
	return printf("f %d\n",M(D(Sqr(A(1,2)),A(Sqr(1),Sqr(2))),X+1>>1)),0;
}