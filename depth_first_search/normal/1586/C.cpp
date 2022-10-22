#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000000
using namespace std;
int n,m,p[N+5];string s[N+5];
int main()
{
	RI i,j;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) cin>>s[i],s[i]="#"+s[i];
	for(i=2;i<=n;++i) for(j=2;j<=m;++j) s[i][j-1]=='X'&&s[i-1][j]=='X'&&(p[j]=1);for(i=1;i<=m;++i) p[i]+=p[i-1];
	RI Qt,x,y;scanf("%d",&Qt);W(Qt--) scanf("%d%d",&x,&y),puts(p[x]^p[y]?"NO":"YES");return 0;
}