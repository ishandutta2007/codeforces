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
#define BS 182
#define BT N/BS
#define INF (int)1e9
using namespace std;
int n,a[N+5],bl[N+5],id[N+5],c[BT+5],p[BT+5][BS+5],g[N+5][BT+5],f[BT+5][BT+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
I bool cmp(CI x,CI y) {return a[x]<a[y];}
#define A(x,l,r) l<=x&&x<=r&&(res=min(res,a[x]-t),t=a[x])
I int BF(CI l,CI r)
{
	RI i,o=bl[l],t=-INF,res=INF;for(i=1;i<=c[o];++i) A(p[o][i],l,r);return res;
}
I int Mg(CI l1,CI r1,CI l2,CI r2)
{
	RI i=1,j=1,L=bl[l1],R=bl[l2],t=-INF,res=INF;
	W(i<=c[L]&&j<=c[R]) a[p[L][i]]<=a[p[R][j]]?(A(p[L][i],l1,r1),++i):(A(p[R][j],l2,r2),++j);
	W(i<=c[L]) A(p[L][i],l1,r1),++i;W(j<=c[R]) A(p[R][j],l2,r2),++j;return res;
}
I void Build()
{
	RI i,j,k;for(i=1;i<=n;++i) for(j=1;j<=bl[n];++j) g[i][j]=INF;
	for(i=1;i<=n;++i) id[i]=i;sort(id+1,id+n+1,cmp);for(a[0]=-INF,a[n+1]=2*INF,i=1;i<=bl[n];++i)
	{
		for(j=(i-1)*BS+1;j<=min(i*BS,n);++j) p[i][++c[i]]=j;sort(p[i]+1,p[i]+c[i]+1,cmp),p[i][0]=0,p[i][c[i]+1]=n+1;
		for(k=1,j=0;j<=c[i];++j) W(k<=n&&a[id[k]]<=a[p[i][j+1]]) g[id[k]][i]=min(a[id[k]]-a[p[i][j]],a[p[i][j+1]]-a[id[k]]),++k;
	}
	for(i=1;i<=n;++i) {for(j=bl[i]-2;j>=1;--j) g[i][j]=min(g[i][j],g[i][j+1]);for(j=bl[i]+2;j<=bl[n];++j) g[i][j]=min(g[i][j],g[i][j-1]);}
	for(i=1;i<=bl[n];++i) f[i][i]=BF((i-1)*BS+1,min(i*BS,n));
	for(i=1;i<=bl[n];++i) for(j=i+1;j<=bl[n];++j) for(f[i][j]=min(f[i][j-1],f[j][j]),k=(j-1)*BS+1;k<=min(j*BS,n);++k) f[i][j]=min(f[i][j],g[k][i]);
}
I int Q(CI l,CI r)
{
	RI L=bl[l],R=bl[r];if(L==R) return BF(l,r);RI t=INF;
	if(R-L>1) {RI i;for(t=f[L+1][R-1],i=l;i<=L*BS;++i) t=min(t,g[i][R-1]);for(i=(R-1)*BS+1;i<=r;++i) t=min(t,g[i][L+1]);}
	return min(t,Mg(l,L*BS,(R-1)*BS+1,r));
}
int main()
{
	RI Qt,i;for(read(n),i=1;i<=n;++i) read(a[i]),bl[i]=(i-1)/BS+1;Build();
	RI l,r;read(Qt);W(Qt--) read(l,r),writeln(Q(l,r));return clear(),0;
}