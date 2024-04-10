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
int n,c[N+5];map<int,int> F;I bool cmp(CI x,CI y) {return x>y;}
int main()
{
	RI i,j,x;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",&x),++F[x];
	RI m=0;for(map<int,int>::iterator it=F.end();it!=F.begin();) --it,c[++m]=it->second;sort(c+1,c+m+1,cmp),m=min(m,20);
	RI g,t=0;for(i=1;i<=m;++i) {for(g=1e9,j=1;j<=i;++j) g=min(g,c[j]>>i-j);t=max(t,g*((1<<i)-1));}return printf("%d\n",t),0;
}