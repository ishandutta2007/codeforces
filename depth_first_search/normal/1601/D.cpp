#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500000
using namespace std;
int n,m;struct S {int a,b;I bool operator < (Cn S& o) Cn {return max(a,b)^max(o.a,o.b)?max(a,b)<max(o.a,o.b):a<o.a;}}s[N+5];
int main()
{
	RI i;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d%d",&s[i].a,&s[i].b);
	RI o=m,t=0;for(sort(s+1,s+n+1),i=1;i<=n;++i) s[i].a>=o&&(++t,o=max(o,s[i].b));return printf("%d\n",t),0;
}