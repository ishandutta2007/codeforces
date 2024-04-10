#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define LN 20
#define DB double
#define eps 1e-10
using namespace std;
const double S=acos(-1)*2;
int n,m,cnt,a[N+5],b[N+5],fa[4*N+5][LN+5];
struct Il
{
	DB l,r;int op;I Il(Con DB& x=0,Con DB& y=0,CI f=0):l(x),r(y),op(f){}
	I bool operator < (Con Il& o) Con {return op^o.op?op<o.op:l<o.l;}
}s[4*N+5],w[4*N+5];
I bool Check(Con DB& x)
{
	RI i,j,p;DB d,t;for(i=1;i<=n;++i) d=atan2(b[i],a[i]),
		t=acos(x/sqrt(1.0*a[i]*a[i]+1.0*b[i]*b[i])),s[i]=Il(d-t,d+t,0),s[n+i]=Il(d-t+S,d+t+S,1);
	for(cnt=0,sort(s+1,s+2*n+1),i=2*n;i;--i) (!cnt||s[i].r<w[cnt].r)&&(w[++cnt]=s[i],0);
	for(i=1;i<=cnt&&!w[cnt-i+1].op;++i) s[i]=w[cnt-i+1];cnt=i-1;
	for(i=1;i<=cnt;++i) s[i+cnt]=Il(s[i].l+S,s[i].r+S,1);
	for(p=i=1;i<=2*cnt;++i) {W(p<=2*cnt&&s[p].l<=s[i].r) ++p;fa[i][0]=p;}
	for(j=1;j<=LN;++j) for(i=1;i<=2*cnt;++i) fa[i][j]=fa[fa[i][j-1]][j-1];
	for(i=1;i<=cnt;++i)
	{
		for(p=i,j=0;j<=LN;++j) m>>j&1&&(p=fa[p][j]);
		if(p>=i+cnt||!p) return true;
	}return false;
}
int main()
{
	RI i;DB l=0,r=1e9,mid;scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i) scanf("%d%d",a+i,b+i),r=min(r,sqrt(1.0*a[i]*a[i]+1.0*b[i]*b[i]));
	W(r-l>eps) Check(mid=(l+r)/2)?l=mid:r=mid;return printf("%.10lf",l),0;
}