#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100
#define K 1000
#define T (N+1)*(N+1)
#define P(x,y) ((x)*(m+1)+(y)+1)
using namespace std;
int n,m,X,tot,id[T+5];char s[N+5][N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
namespace UnionFindSet
{
	int f[T+5];I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
	I void U(RI x,RI y) {(x=fa(x))^(y=fa(y))?f[x]=y:(puts("0"),exit(0),0);}
}
class Gauss
{
	private:
		int op,a[K+5][K+5];I bool Find(CI x)
		{
			RI i=x+1,j;W(i<=n&&!a[i][x]) ++i;if(i>n) return 0;
			for(j=x;j^n;++j) swap(a[i][j],a[x][j]);return 1;
		}
	public:
		int n;I void A(CI x,CI y) {++a[x][x],++a[y][y],--a[x][y],--a[y][x];}
		I int Det()
		{
			RI i,j,k,t;for(i=1;i^n;++i) for(j=1;j^n;++j) a[i][j]=(a[i][j]%X+X)%X;
			for(i=1;i^n;++i) if(!a[i][i]&&(op^=1,!Find(i))) break;else for(j=i+1;j^n;++j)
				for(t=X-1LL*a[j][i]*QP(a[i][i],X-2)%X,k=i;k^n;++k) a[j][k]=(1LL*a[i][k]*t+a[j][k])%X;
			for(t=op?X-1:1,i=1;i^n;++i) t=1LL*t*a[i][i]%X;return t;
		}
}G1,G2;
int main()
{
	using namespace UnionFindSet;RI i,j;scanf("%d%d%d",&n,&m,&X);
	for(i=1;i<=n;++i) for(scanf("%s",s[i]+1),j=1;j<=m;++j)
		s[i][j]=='/'&&(U(P(i,j-1),P(i-1,j)),0),s[i][j]=='\\'&&(U(P(i-1,j-1),P(i,j)),0);
	for(i=0;i<=n;++i) for(j=0;j<=m;++j) (i^j)&1&&
		(!id[fa(P(i,j))]&&(id[fa(P(i,j))]=++G1.n),id[P(i,j)]=id[fa(P(i,j))]);
	for(i=0;i<=n;++i) for(j=0;j<=m;++j) (i^j)&1^1&&
		(!id[fa(P(i,j))]&&(id[fa(P(i,j))]=++G2.n),id[P(i,j)]=id[fa(P(i,j))]);
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) if(s[i][j]=='*') (i^j)&1
		?(G2.A(id[P(i,j-1)],id[P(i-1,j)]),G1.A(id[P(i-1,j-1)],id[P(i,j)]))
		:(G1.A(id[P(i,j-1)],id[P(i-1,j)]),G2.A(id[P(i-1,j-1)],id[P(i,j)]));
	return printf("%d\n",(G1.Det()+G2.Det())%X),0;
}