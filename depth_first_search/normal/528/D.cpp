#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
#define DB double
using namespace std;
int n,m,k,c[N+5];char a[N+5],b[N+5];
namespace Poly
{
	int P,L,R[N<<2];DB Pi=acos(-1);struct node
	{
		DB x,y;I node(Cn DB& a=0,Cn DB& b=0):x(a),y(b){}
		I node operator + (Cn node& o) Cn {return node(x+o.x,y+o.y);}
		I node operator - (Cn node& o) Cn {return node(x-o.x,y-o.y);}
		I node operator * (Cn node& o) Cn {return node(x*o.x-y*o.y,x*o.y+y*o.x);}
	}A[N<<2],B[N<<2];
	I void FFT(node* s,CI op)
	{
		RI i,j,k;node U,S,x,y;for(i=0;i^P;++i) i<R[i]&&(x=s[i],s[i]=s[R[i]],s[R[i]]=x,0);
		for(i=1;i^P;i<<=1) for(U=node(cos(Pi/i),op*sin(Pi/i)),j=0;j^P;j+=i<<1)
			for(S=1,k=0;k^i;++k,S=S*U) s[j+k]=(x=s[j+k])+(y=S*s[i+j+k]),s[i+j+k]=x-y;
		if(op==-1) for(i=0;i^P;++i) s[i].x/=P;
	}
	I void Mul(int* a,int* b)
	{
		RI i;P=1,L=0;W(P<=(n<<1)) P<<=1,++L;for(i=0;i^P;++i) R[i]=(R[i>>1]>>1)|((i&1)<<L-1),A[i]=B[i]=0;
		for(i=0;i<=n;++i) A[i]=a[i],B[i]=b[i];FFT(A,1),FFT(B,1);
		for(i=0;i^P;++i) A[i]=A[i]*B[i];for(FFT(A,-1),i=0;i<=n;++i) a[i]=A[i].x+0.5;
	}
}
int f[N+5],g[N+5];I void Solve(char o)
{
	RI i,t=-1e9;for(i=1;i<=n;++i) a[i]==o&&(t=i),f[i]=i-t<=k;for(t=1e9,i=n;i;--i) a[i]==o&&(t=i),f[i]|=t-i<=k;
	for(i=1;i<=m;++i) g[m-i]=b[i]==o;for(Poly::Mul(f,g),i=m;i<=n;++i) c[i]+=f[i];
}
int main()
{
	scanf("%d%d%d%s%s",&n,&m,&k,a+1,b+1),Solve('A'),Solve('C'),Solve('T'),Solve('G');
	RI i,t=0;for(i=m;i<=n;++i) c[i]==m&&++t;return printf("%d\n",t),0;
}