#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 2000000
#define V 262144
#define LG 17
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,a[N+5];
struct S
{
	int mx,mp,sx,sp;S(RI a=0,RI b=0,RI c=0,RI d=0):mx(a),mp(b),sx(c),sp(d){}
	I S operator + (Cn S& o) Cn
	{
		if(mx==o.mx) {if(mp^o.mp) return S(mx,mp,o.mx,o.mp);return sx>=o.sx?S(mx,mp,sx,sp):S(mx,mp,o.sx,o.sp);}
		if(mx>o.mx) {RI x,y;o.mp^mp?(x=o.mx,y=o.mp):(x=o.sx,y=o.sp);return sx>=x?S(mx,mp,sx,sp):S(mx,mp,x,y);}
		RI x,y;mp^o.mp?(x=mx,y=mp):(x=sx,y=sp);return o.sx>=x?S(o.mx,o.mp,o.sx,o.sp):S(o.mx,o.mp,x,y);
	}
}s[V*10];
int f[N+5];I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
int ct,c[N+5],v[N+5],to[N+5],p[N+5];long long ans;void B()
{
	RI i,j;for(i=0;i^V;++i) s[i]=S(-1,-1,-1,-1);for(i=1;i<=ct;++i) v[i]=p[i]=-1;
	for(i=1;i<=n;++i) s[a[i]]=s[a[i]]+S(a[i],c[i],-1,-1),f[i]=0;
	for(j=0;j<=LG;++j) for(i=0;i^V;++i) i>>j&1&&(s[i]=s[i]+s[i^(1<<j)],0);
	RI o,x,y;for(i=1;i<=n;v[c[i]]<x&&(v[c[i]]=x,to[c[i]]=y),++i)
		s[o=a[i]^(V-1)].mp^c[i]?(x=~s[o].mx?a[i]+s[o].mx:-1,y=s[o].mp):(x=~s[o].sx?a[i]+s[o].sx:-1,y=s[o].sp);
	for(i=1;i<=ct;++i) (x=fa(i))^(y=fa(to[i]))&&(f[x]=y),ans+=v[i];
	for(i=1;i<=ct;++i) p[fa(i)]=max(p[fa(i)],v[i]);for(o=ct,ct=0,i=1;i<=o;++i) !f[i]&&(ans-=p[i],p[i]=++ct);
	if(ct==1) return;for(i=1;i<=n;++i) c[i]=p[fa(c[i])];B();
}
int main()
{
	RI i;for(read(n),i=1;i<=n;++i) read(a[i]),ans-=a[i];
	for(ct=++n,i=1;i<=n;++i) c[i]=i;return B(),printf("%lld\n",ans),0;
}