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
#define DB double
using namespace std;
int n,m,v[N+5];DB B=0.75;char o[N+5];
int main()
{
	RI i,j,x;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) v[i]=1;
	DB p,s[2];char c;for(srand(324682339),j=1;j<=m;++j)
	{
		for(s[0]=s[1]=0,i=1;i<=n;++i) cin>>o[i],s[o[i]&1]+=pow(B,v[i]);
		x=(p=1.0*rand()/RAND_MAX)>s[0]/(s[0]+s[1]),putchar(48|x),putchar('\n'),fflush(stdout);
		for(cin>>c,i=1;i<=n;++i) o[i]^c&&++v[i];
	}return 0;
}