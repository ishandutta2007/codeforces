#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define K 100
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
int n,k,q[N+5],f[2*K+5][N+5][2];struct S {int l,r,op;}s[2*K+5];
int main()
{
	RI i,j,c=0,x,y,lst=0;for(scanf("%d%d",&n,&k),i=1;i<=k;++i) scanf("%d%d",&x,&y),
		!x&&++x,x<=y&&(x>lst+1&&(s[++c]=(S){lst+1,x-1,0},0),s[++c]=(S){x,lst=y,1},0);lst<2*n&&(s[++c]=(S){lst+1,2*n,0},0);
	RI H,T;for(i=0;i<=c;++i) for(j=0;j<=n;++j) f[i][j][0]=f[i][j][1]=1e9;for(f[0][0][0]=0,i=1;i<=c;++i)
	{
		for(j=0;j<=n;++j) j+s[i].r-s[i].l+1<=n&&Gmin(f[i][j+s[i].r-s[i].l+1][0],f[i-1][j][0]),Gmin(f[i][j][1],f[i-1][j][1]);
		if(!s[i].op) continue;
		for(H=1,T=0,j=0;j<=n;++j) {W(H<=T&&q[H]<=j-(s[i].r-s[i].l+1)) ++H;W(H<=T&&f[i-1][j][1]<f[i-1][q[T]][1]) --T;q[++T]=j,Gmin(f[i][j][0],f[i-1][q[H]][1]+1);}
		for(q[H=T=1]=0,j=1;j<=n;++j) {W(H<=T&&q[H]<j-(s[i].r-s[i].l+1)) ++H;W(H<=T&&f[i-1][j][0]<f[i-1][q[T]][0]) --T;Gmin(f[i][j][1],f[i-1][q[H]][0]+1),q[++T]=j;}
		if(s[i].l==s[i].r) continue;
		for(q[H=T=1]=0,j=1;j<=n;++j) {W(H<=T&&q[H]<=j-(s[i].r-s[i].l+1)) ++H;W(H<=T&&f[i-1][j][0]<f[i-1][q[T]][0]) --T;Gmin(f[i][j][0],f[i-1][q[H]][0]+2),q[++T]=j;}
		for(q[H=T=1]=0,j=1;j<=n;++j) {W(H<=T&&q[H]<=j-(s[i].r-s[i].l+1)) ++H;W(H<=T&&f[i-1][j][1]<f[i-1][q[T]][1]) --T;Gmin(f[i][j][1],f[i-1][q[H]][1]+2),q[++T]=j;}
	}return min(f[c][n][0],f[c][n][1])==1e9?puts("Hungry"):printf("Full\n%d\n",min(f[c][n][0],f[c][n][1])),0;
}