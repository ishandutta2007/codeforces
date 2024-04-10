#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define NM 250
#define M 15
#define X 1000000007
using namespace std;
int n,m,f[NM+1][1<<M][2][2];char s[NM+5][NM+5];
int main()
{
	RI i,j;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%s",s[i]+1);
	if(n<m) for(swap(n,m),i=1;i<=m;++i) for(j=i+1;j<=n;++j) swap(s[i][j],s[j][i]);
	RI l=(1<<m)-1,p,q,w,o;for(f[0][0][0][0]=i=1;i<=n;++i) for(j=1;j<=m;++j)
	{
		#define T(x) (x=(x+f[o-1][w][p][q])%X)
		if(o=(i-1)*m+j,s[i][j]=='x') {for(w=0;w<=l;++w) for(p=0;p<=1;++p) for(q=0;q<=1;++q) T(f[o][(w<<1)&l][0][q]);continue;}
		for(w=0;w<=l;++w) for(p=0;p<=1;++p) for(q=0;q<=1;++q)
		{
			if(j^1&&p||(w>>m-1&1)) T(f[o][(w<<1|(w>>m-1&1))&l][j^1?p:0][q]);else if(!q) T(f[o][(w<<1)&l][0][1]);T(f[o][(w<<1|1)&l][1][q]);
		}
	}
	RI t=0;for(w=0;w<=l;++w) for(p=0;p<=1;++p) for(q=0;q<=1;++q) t=(t+f[n*m][w][p][q])%X;return printf("%d\n",t),0;
}