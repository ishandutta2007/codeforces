#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100
using namespace std;
int n,m,a,b,c;char s[N+5][N+5];
int main()
{
	RI i,j;if(scanf("%d%d%d%d%d",&n,&m,&a,&b,&c),n&1&&m&1) return puts("IMPOSSIBLE"),0;
	if(n&1) {if(a<(m>>1)) return puts("IMPOSSIBLE"),0;for(i=1;i<=m;++i) s[n][i]="yz"[(i-1>>1)&1];a-=m>>1;}
	if(m&1) {if(b<(n>>1)) return puts("IMPOSSIBLE"),0;for(i=1;i<=n;++i) s[i][m]="yz"[(i-1>>1)&1];b-=n>>1;}
	if((a>>1)+(b>>1)+c<(n>>1)*(m>>1)) return puts("IMPOSSIBLE"),0;
	char o=100;for(i=1;i<=(n>>1);++i,!((m>>1)&1)&&(o^=2)) for(j=1;j<=(m>>1);++j)
	{
		if(o^=2,c) {s[2*i-1][2*j-1]=s[2*i-1][2*j]=s[2*i][2*j-1]=s[2*i][2*j]=o,--c;continue;}
		if(a>1) {s[2*i-1][2*j-1]=s[2*i-1][2*j]=o,s[2*i][2*j-1]=s[2*i][2*j]=o+1,a-=2;continue;}
		if(b>1) {s[2*i-1][2*j-1]=s[2*i][2*j-1]=o,s[2*i-1][2*j]=s[2*i][2*j]=o+1,b-=2;continue;}
	}
	for(i=1;i<=n;++i) puts(s[i]+1);return 0;
}