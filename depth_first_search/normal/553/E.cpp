#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 50
#define M 100
#define LIM 20000
#define DB double
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
int n,m,lim,ex,a[M+5],b[M+5],c[M+5],dis[N+5][N+5];DB p[M+5][2*LIM+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
namespace Poly
{
	int P,L,R[LIM<<3];const DB Pi=acos(-1);
	struct node
	{
		DB x,y;I node(Con DB& a=0,Con DB& b=0):x(a),y(b){}
		I node operator + (Con node& o) Con {return node(x+o.x,y+o.y);}
		I node operator - (Con node& o) Con {return node(x-o.x,y-o.y);}
		I node operator * (Con node& o) Con {return node(x*o.x-y*o.y,x*o.y+y*o.x);}
	}A[LIM<<3],B[LIM<<3];
	I void FFT(node* s,CI op)
	{
		RI i,j,k;node x,y,U,S;for(i=0;i^P;++i) i<R[i]&&(swap(s[i],s[R[i]]),0);
		for(i=1;i^P;i<<=1) for(U=node(cos(Pi/i),op*sin(Pi/i)),j=0;j^P;j+=i<<1)
			for(S=1,k=0;k^i;S=S*U,++k) s[j+k]=(x=s[j+k])+(y=S*s[i+j+k]),s[i+j+k]=x-y;
	}
	I void Mul(CI n,CI m)
	{
		RI i;P=1,L=0;W(P<=n+m) P<<=1,++L;for(i=0;i^P;++i) R[i]=(R[i>>1]>>1)|((i&1)<<L-1);
		for(i=n+1;i^P;++i) A[i]=0;for(i=m+1;i^P;++i) B[i]=0;
		for(FFT(A,1),FFT(B,1),i=0;i^P;++i) A[i]=A[i]*B[i];for(FFT(A,-1),i=0;i<=n+m;++i) A[i]=A[i].x/P;
	}
	DB f[N+5][2*LIM+5],g[M+5][LIM+5];I void CDQ(CI l,CI r)
	{
		RI i,j;if(l>lim) {for(i=1;i<=n;++i) for(j=l;j<=r;++j) f[i][j]=dis[i][n]+ex;return;}
		if(l==r) {for(i=1;i^n;++i) f[i][l]=1e9;for(i=1;i<=m;++i) a[i]^n&&Gmin(f[a[i]][l],c[i]+g[i][l]);return;}
		RI mid=l+r>>1;for(CDQ(mid+1,r),i=1;i<=m;++i) if(a[i]^n)
		{
			for(j=0;j<=r-l-1;++j) A[j]=p[i][j+1];for(j=0;j<=r-mid-1;++j) B[j]=f[b[i]][r-j];
			for(Mul(r-l-1,r-mid-1),j=l;j<=mid;++j) g[i][j]+=A[r-j-1].x;
		}CDQ(l,mid);
	}
}
int main()
{
	RI i,j,x;for(read(n,m,lim,ex),i=1;i<=n;++i) for(j=1;j<=n;++j) dis[i][j]=i^j?1e9:0;
	for(i=1;i<=m;++i) for(read(a[i],b[i],c[i]),Gmin(dis[a[i]][b[i]],c[i]),j=1;j<=lim;++j) read(x),p[i][j]=x/1e5;
	for(RI k=1;k<=n;++k) for(i=1;i<=n;++i) for(j=1;j<=n;++j) Gmin(dis[i][j],dis[i][k]+dis[k][j]);
	return Poly::CDQ(0,2*lim),printf("%.12lf\n",Poly::f[1][0]),0;
}