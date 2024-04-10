#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 100
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char FO[FS],OS[FS],*FC=FO,*FE=FO+FS;
	void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}struct IO_Cl {~IO_Cl() {clear();}}CL;
	Tp void write(Ty x,char y) {while(OS[++OT]=x%10+48,x/=10);while(OT) pc(OS[OT--]);pc(y);}
}using namespace FastIO;
int n,s[N*N+5][N+5],c[N+5][N+5];
#define Dis(x,y) ((x)<(y)?(y)-(x):n-(x)+(y)) 
int o;bool cmp(int x,int y) {return Dis(o,x)>Dis(o,y);}
int main()
{
	int i,j,p,q,x;for(scanf("%d",&n),i=1;i<=n;++i) for(j=1;j<=n;++j) scanf("%d",&x),++c[i][x];
	int T;for(T=1;;++T)
	{
		for(i=1;i<=n;++i) for(j=1;j<=n;++j) if(c[i][j]>1) goto G;--T;break;
		G:for(--c[i][s[T][i]=j],p=i+1;p^i;p=p%n+1) {for(++c[p][j],q=1;q<=n&&c[p][q]<=1;++q);--c[p][j=s[T][p]=q];}++c[i][j];
	}
	for(i=1;i<=n-1;++i) for(j=i;j;--j) for(++T,p=1;p<=n;++p) s[T][p]=(p+j-1)%n+1;
	for(write(T,'\n'),i=1;i<=T;++i) for(j=1;j<=n;++j) write(s[i][j]," \n"[j==n]);return 0;
}