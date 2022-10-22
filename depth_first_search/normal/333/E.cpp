#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 3000
using namespace std;
int n,x[N+5],y[N+5];bitset<N+5> g[N+5];struct S {int i,j,d;I bool operator < (Cn S& o) Cn {return d<o.d;}}s[N*N+5];
int main()
{
	RI i,j;for(scanf("%d",&n),i=1;i<=n;++i) for(scanf("%d%d",x+i,y+i),j=1;j<=n;++j) i^j&&(g[i].set(j),0);
	RI c=0;for(i=1;i<=n;++i) for(j=i+1;j<=n;++j) s[++c]=(S){i,j,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])};
	RI t=0;for(sort(s+1,s+c+1),i=1;i<=c;++i) g[s[i].i].reset(s[i].j),g[s[i].j].reset(s[i].i),(g[s[i].i]&g[s[i].j]).any()&&(t=s[i].d);
	return printf("%.10lf\n",sqrt(t)/2),0;
}