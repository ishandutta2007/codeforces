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
int n,m,a[N+5],b[N+5],dc,dv[2*N+5];long long ans;
struct BIT1
{
	int a[2*N+5];I void Cl() {for(RI i=1;i<=dc;++i) a[i]=0;}
	I void U(RI x,RI v) {W(x) a[x]+=v,x-=x&-x;}I int Q(RI x) {RI t=0;W(x<=dc) t+=a[x],x+=x&-x;return t;}
}T1;
struct BIT2
{
	int a[2*N+5];I void Cl() {for(RI i=1;i<=dc;++i) a[i]=0;}
	I void U(RI x,RI v) {W(x<=dc) a[x]+=v,x+=x&-x;}I int Q(RI x) {RI t=0;W(x) t+=a[x],x-=x&-x;return t;}
}T2;
int k;void Solve(CI l,CI r,CI L,CI R)
{
	RI i,u=l+r>>1,w=L,t=T1.Q(b[u]+1)+T2.Q(b[u]-1),s=t;
	for(i=L+1;i<=R;++i) a[i]<b[u]&&--s,a[i]>b[u]&&++s,s<t&&(w=i,t=s);ans+=t;
	l^u&&(Solve(l,u-1,L,w),0);W(k^w) ++k,T1.U(a[k],1),T2.U(a[k],-1);r^u&&(Solve(u+1,r,w,R),0); 
}
int main()
{
	RI Tt,i;read(Tt);W(Tt--)
	{
		for(read(n,m),i=1;i<=n;++i) read(a[i]),dv[i]=a[i];for(i=1;i<=m;++i) read(b[i]),dv[n+i]=b[i];
		#define GV(x) (lower_bound(dv+1,dv+dc+1,x)-dv)
		for(sort(dv+1,dv+n+m+1),dc=unique(dv+1,dv+n+m+1)-dv-1,i=1;i<=n;++i) a[i]=GV(a[i]);for(i=1;i<=m;++i) b[i]=GV(b[i]);
		for(ans=0,T1.Cl(),T2.Cl(),i=n;i;--i) ans+=T2.Q(a[i]-1),T2.U(a[i],1);
		sort(b+1,b+m+1),k=0,Solve(1,m,0,n),writeln(ans);
	}return clear(),0;
}