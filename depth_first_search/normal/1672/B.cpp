#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
using namespace std;
int n;char s[N+5];
int main()
{
	RI Tt,i,c;scanf("%d",&Tt);W(Tt--)
	{
		if(scanf("%s",s+1),n=strlen(s+1),s[n]=='A') {puts("NO");continue;}
		for(c=0,i=1;i<=n;++i) if(s[i]=='A') ++c;else if(!c--) break;puts(i>n?"YES":"NO");
	}return 0;
}