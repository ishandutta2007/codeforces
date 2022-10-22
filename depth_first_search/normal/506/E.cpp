#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define L 200
#define X 10007
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
using namespace std;
int n,l,f[L+5][L+5][L+5],g[L+5];char s[L+5];
namespace Mat
{
	int tot;struct M
	{
		#define SZ 300
		int a[SZ+5][SZ+5];I M() {memset(a,0,sizeof(a));}
		I int* operator [] (CI x) {return a[x];}I Con int* operator [] (CI x) Con {return a[x];}
		I M operator * (Con M& o) Con
		{
			M t;for(RI i=0,j,k;i<=tot;++i) for(j=i;j<=tot;++j)
				for(k=i;k<=j;++k) t[i][j]=(a[i][k]*o[k][j]+t[i][j])%X;return t;
		}
	}S,U;
	I M Pow(RI y) {W(y) y&1&&(S=S*U,0),U=U*U,y>>=1;return S;}
	I int Solve(CI tg)
	{
		S=U=M(),S[0][1]=1,S[0][tot-(l+1>>1)]=g[0],tg&&(U[tot][tot]=26);
		RI i;for(i=1;i<=l;++i) U[i][i]=24,U[i][tot-(l-i+1>>1)]=g[i],i^l&&(U[i][i+1]=1);
		for(i=l+1;i^tot;++i) U[i][i]=25,U[i][i+1]=1;return Pow(n+l+1>>1),S[0][tot];
	}
}
int main()
{
	RI i,j,k,t;scanf("%s%d",s+1,&n),l=strlen(s+1);
	for(f[1][l][0]=1,t=l;t;--t) for(i=1,j=t;j<=l;++i,++j) for(k=0;k<=l;++k)
		s[i]^s[j]?(Inc(f[i+1][j][k+1],f[i][j][k]),Inc(f[i][j-1][k+1],f[i][j][k]))
		:(i+1<j?Inc(f[i+1][j-1][k],f[i][j][k]):Inc(g[k],f[i][j][k]));
	if(Mat::tot=l+(l+1>>1)+1,t=Mat::Solve(1),!((n+l)&1)) return printf("%d\n",t),0;
	for(memset(g,0,sizeof(g)),i=1;i^l;++i) if(s[i]==s[i+1]) for(k=0;k<=l;++k) Inc(g[k],f[i][i+1][k]);
	return printf("%d\n",(t-Mat::Solve(0)+X)%X),0;
}