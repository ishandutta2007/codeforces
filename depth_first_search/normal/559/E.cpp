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
#define Gmax(x,y) (x<(y)&&(x=(y)))
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
int n,dc,dv[3*N+5],f[N+5][3*N+5],Mx[N+5][N+5];
struct Data {int x,l;I bool operator < (Con Data& o) Con {return x<o.x;}}s[N+5];
int main()
{
	RI i,j,k,x,y,z;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d%d",&s[i].x,&s[i].l),
		dv[++dc]=s[i].x,dv[++dc]=s[i].x-s[i].l,dv[++dc]=s[i].x+s[i].l;sort(s+1,s+n+1);
	#define GV(x) (lower_bound(dv+1,dv+dc+1,x)-dv)
	for(sort(dv+1,dv+dc+1),dc=unique(dv+1,dv+dc+1)-dv-1,i=1;i<=n;++i)
		for(Mx[i][i]=GV(s[i].x+s[i].l),j=i+1;j<=n;++j) Mx[i][j]=max(Mx[i][j-1],GV(s[j].x+s[j].l));
	for(i=1;i<=n;++i)
	{
		#define T(j,l,r) for(k=r;k>=l;--k) Gmax(f[i][k],f[j][l]+dv[k]-dv[l])
		x=GV(s[i].x);T(i-1,x,GV(s[i].x+s[i].l));
		for(y=GV(s[i].x-s[i].l),j=1;j<=i;++j) T(j-1,y,max(x,Mx[j][i-1]));
		for(j=1;j<=dc;++j) Gmax(f[i][j],f[i-1][j]),Gmax(f[i][j],f[i][j-1]);
	}return printf("%d\n",f[n][dc]),0;
}