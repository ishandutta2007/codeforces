#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 2000
#define X 1000000007
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
using namespace std;
int n,m,f[2][N+5][N+5],g[2][N+5],p[2][N+5][N+5],q[2][N+5][N+5];char w[N+5],s[2][N+5];
struct Hash
{
	#define ull unsigned long long
	#define CU Con ull&
	ull x,y;I Hash() {x=y=0;}I Hash(CU a) {x=y=a;}I Hash (CU a,CU b):x(a),y(b){}
	I Hash operator + (Con Hash& o) Con {return Hash(x+o.x,y+o.y);}
	I Hash operator - (Con Hash& o) Con {return Hash(x-o.x,y-o.y);}
	I Hash operator * (Con Hash& o) Con {return Hash(x*o.x,y*o.y);}
	I bool operator == (Con Hash& o) Con {return x==o.x&&y==o.y;}
}seed(20050413,20201118),P[2*N+5],U[N+5],V[N+5],S[2][N+5];
#define G1(H,l,r) (H[r]-H[(l)-1])
#define G2(H,l,r) (H[l]-H[(r)+1])
int ans;I void Solve(CI tg)
{
	RI i,j,o;for(i=1;i<=m;++i) U[i]=U[i-1]+P[i]*w[i];for(i=m;i;--i) V[i]=V[i+1]+P[m-i+1]*w[i];
	for(o=0;o<=1;++o) for(i=1;i<=n;++i) for(j=1;2*j<=m&&j<=i;++j) p[o][i][j<<1]=
		G1(S[o^1],i-j+1,i)*P[m]==G2(V,1,j)*P[i]&&G1(S[o],i-j+1,i)*P[j<<1]==G1(U,j+1,j<<1)*P[i];
	for(o=0;o<=1;++o) for(i=1;i<=n;++i) for(j=1;2*j<=m&&j<=n-i+1;++j) q[o][i][j<<1]=
		G1(S[o^1],i,i+j-1)==G2(V,m-j+1,m)*P[i-1]&&G1(S[o],i,i+j-1)*P[m-j+1]==G1(U,m-2*j+1,m-j)*P[i+j];
	for(memset(f,0,sizeof(f)),i=1;i<=n;++i)
	{
		for(j=m;j^2;--j) for(o=0;o<=1;++o) s[o][i]==w[j]&&Inc(f[o][i][j],
			0LL+p[o][i][j]+f[o][i-1][j-1]+(s[o^1][i]==w[j-1]?f[o^1][i-1][j-2]:0));
		f[0][i][1]=s[0][i]==w[1],f[1][i][1]=s[1][i]==w[1],
		s[0][i]==w[2]&&(f[0][i][2]=p[0][i][2]+f[0][i-1][1]),
		s[1][i]==w[2]&&(f[1][i][2]=p[1][i][2]+f[1][i-1][1]);
	}
	for(o=0;o<=1;++o) for(i=1;i<=n;++i) for(j=1;j<=m;++j)
		s[o][i]==w[j]&&(q[o][i][m-j+1]||j==m)&&Inc(ans,j^1?f[o][i-1][j-1]:1);
	if(tg) for(o=0;o<=1;++o) for(i=1;i<=n;++i) p[o][i][m]&&++ans,q[o][i][m]&&--ans;
}
int main()
{
	RI i,o;scanf("%s%s%s",s[0]+1,s[1]+1,w+1),n=strlen(s[0]+1),m=strlen(w+1);
	if(m==1) {for(i=1;i<=n;++i) ans+=(s[0][i]==w[1])+(s[1][i]==w[1]);return printf("%d\n",ans),0;}
	if(m==2) {for(o=0;o<=1;++o) for(i=1;i<=n;++i) s[o][i]==w[1]&&
		(ans+=(s[o][i-1]==w[2])+(s[o][i+1]==w[2])+(s[o^1][i]==w[2]));return printf("%d\n",ans),0;}
	for(P[0]=i=1;i<=n+m;++i) P[i]=P[i-1]*seed;
	for(i=1;i<=n;++i) S[0][i]=S[0][i-1]+P[i]*s[0][i],S[1][i]=S[1][i-1]+P[i]*s[1][i];
	return Solve(0),reverse(w+1,w+m+1),Solve(1),printf("%d\n",ans),0;
}