#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
#define X 1000000007
using namespace std;
int n,A,B,f[N+5][N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,j,iA,iB,iS;scanf("%d%d%d",&n,&A,&B),iA=QP(A,X-2),iB=QP(B,X-2),iS=QP(A+B,X-2);
	RI c,x,y;for(i=n;i;--i) for(j=n-1;~j;--j)
	{
		if(i==n) {f[i][j]=(j+i+1LL*(A+B)*iB-1)%X;continue;}
		f[i][j]=(1LL*A*iS%X*f[i+1][j]+1LL*B*iS%X*(j+i>=n?j+i:f[i][min(j+i,n)]))%X;
	}return printf("%d\n",f[1][0]),0;
}