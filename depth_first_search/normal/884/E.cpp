#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N (1<<12)
#define M (1<<14)
#define U(i,j) ((x=fa(i))^(y=fa(j))&&(f[x]=f[y]=max(x,y),--t))
using namespace std;
int n,m,f[2*M+5];bool s[2][M+5];I int fa(CI x) {return f[x]^x?f[x]=fa(f[x]):x;}
I void gc(char& c) {W(isspace(c=getchar()));} 
int main()
{
	RI i,j,x,y,t=0;char c;for(scanf("%d%d",&n,&m),i=1;i<=n;++i)
	{
		for(j=1;j<=m/4;++j) gc(c),x=isdigit(c)?(c&15):(c-'A'+10),
			s[i&1][4*j-3]=x>>3,s[i&1][4*j-2]=x>>2&1,s[i&1][4*j-1]=x>>1&1,s[i&1][4*j]=x&1;
		for(j=1;j<=m;++j) f[j]=s[i&1^1][j]?f[m+j]-m:0,f[m+j]=s[i&1][j]?(++t,m+j):0;
		for(j=1;j<=m;++j) s[i&1][j]&&(i^1&&s[i&1^1][j]&&U(m+j,j),j^m&&s[i&1][j+1]&&U(m+j,m+j+1));
	}return printf("%d\n",t),0;
}