#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define LL long long
#define DB double
using namespace std;
int n,p[N+5];LL a[2*N+5],b[N+5];char s[N+5];
namespace Poly
{
	int P,L,R[N<<2];DB Pi=acos(-1);
	struct node
	{
		DB x,y;I node(Con DB& a=0,Con DB& b=0):x(a),y(b){}
		I node operator + (Con node& o) Con {return node(x+o.x,y+o.y);}
		I node operator - (Con node& o) Con {return node(x-o.x,y-o.y);}
		I node operator * (Con node& o) Con {return node(x*o.x-y*o.y,x*o.y+y*o.x);}
	}A[N<<2],B[N<<2];
	I void FFT(node* s,CI op)
	{
		RI i,j,k;node U,S,x,y;for(i=0;i^P;++i) i<R[i]&&(x=s[i],s[i]=s[R[i]],s[R[i]]=x,0);
		for(i=1;i^P;i<<=1) for(U=node(cos(Pi/i),op*sin(Pi/i)),j=0;j^P;j+=i<<1)
			for(S=1,k=0;k^i;++k,S=S*U) s[j+k]=(x=s[j+k])+(y=S*s[i+j+k]),s[i+j+k]=x-y;
	}
	I void Mul(LL* a,LL* b)
	{
		RI i;P=1,L=0;W(P<=(n<<1)) P<<=1,++L;for(i=0;i^P;++i) R[i]=(R[i>>1]>>1)|((i&1)<<L-1);
		for(i=1;i<=n;++i) A[i]=a[i],B[i]=b[i];FFT(A,1),FFT(B,1);
		for(i=0;i^P;++i) A[i]=A[i]*B[i];for(FFT(A,-1),i=1;i<=2*n;++i) a[i]=A[i].x/P+0.5;
		for(i=0;i^P;++i) A[i]=B[i]=0,R[i]=0;
	}
}
int main()
{
	RI Tt,i,j,t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%s",&n,s+1),i=1;i<=n;++i) a[i]=s[i]=='V',b[n-i+1]=s[i]=='K';
		for(Poly::Mul(a,b),i=n;i;--i)
			for(p[i]=!a[n-i+1]&&!a[n+i+1],j=i<<1;p[i]&&j<=n;j+=i) p[i]&=p[j];
		for(t=0,i=1;i<=n;++i) p[i]&&++t;printf("%d\n",t);
		for(i=1;i<=n;++i) p[i]&&printf("%d ",i);putchar('\n');for(i=1;i<=2*n;++i) a[i]=0;
	}return 0;
}