#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define V (int)1e6
#define DB double
#define eps 1e-8
using namespace std;
int n,m,t1,t2;struct S {int x,v;bool operator < (Cn S& o) Cn {return x<o.x;}}s1[N+5],s2[N+5];
struct Il {int l,r;bool operator < (Cn Il& o) Cn {return l^o.l?l<o.l:r>o.r;}}g1[N+5],g2[N+5];
I bool Chk(Cn DB& w)
{
	RI i,c1=0;for(i=1;i<=t1;++i)
	{
		if(s1[i].x<=w*s1[i].v) {g1[++c1]=(Il){0,V};break;}
		if(s1[i].v<=m) g1[++c1]=(Il){s1[i].x,(int)min(floor(s1[i].x+(m-s1[i].v)*(w-(s1[i].x-w*s1[i].v)/m)),1e6)};
		g1[c1].l>g1[c1].r&&--c1;
	}
	RI c,c2=0;for(i=1;i<=t2;++i)
	{
		if(s2[i].x<=w*s2[i].v) {g2[++c2]=(Il){0,V};break;}
		if(s2[i].v<=m) g2[++c2]=(Il){(int)max(ceil(V-(s2[i].x+(m-s2[i].v)*(w-(s2[i].x-w*s2[i].v)/m))),0.0),V-s2[i].x};
		g2[c2].l>g2[c2].r&&--c2;
	}
	for(c=0,i=1;i<=c1;++i) (!c||g1[c].r<g1[i].r)&&(g1[++c]=g1[i],0);c1=c;
	for(c=0,i=1;i<=c2;++i) (!c||g2[c].l>g2[i].l)&&(g2[++c]=g2[i],0);c2=c;reverse(g2+1,g2+c+1);
	RI j;for(i=j=1;i<=c1;++i)
	{
		W(j<=c2&&g2[j].r<g1[i].l) ++j;if(j>c2) break;
		if(max(g1[i].l,g2[j].l)<=min(g1[i].r,g2[j].r)) return 1;
	}return 0;
}
int main()
{
	RI i,x,d,v;for(scanf("%d%d",&n,&m),i=1;i<=n;++i)
		scanf("%d%d%d",&x,&v,&d),d==1?s1[++t1]=(S){x,v}:s2[++t2]=(S){V-x,v};sort(s1+1,s1+t1+1),sort(s2,s2+t2+1);
	DB l=0,r=1e6,mid;W(r-l>eps) Chk(mid=(l+r)/2)?r=mid:l=mid;return printf("%.8lf\n",r),0;
}