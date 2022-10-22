#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 1000000
#define LL long long
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,c[N+5];LL ans,a[N+5];
int Cnt(LL x) {int t=0;while(x) ++t,x&=x-1;return t;}
int ct[80],p[N+5];LL w[N+5];void Solve(int l,int r)
{
	if(l==r) return (void)(++ans);int u=l+r>>1;Solve(l,u),Solve(u+1,r);
	int i,j,k,o,cn,cx;LL v,mn,mx;
	for(mn=1e18+1,mx=-1,i=j=u;i>=l;--i)
	{
		a[i]<mn&&(mn=a[i],cn=c[i]),a[i]>mx&&(mx=a[i],cx=c[i]);
		while(j^r&&mn<=a[j+1]&&a[j+1]<=mx) ++j;cn==cx&&(ans+=j-u);
	}
	for(mn=1e18+1,mx=-1,i=j=u+1;i<=r;++i)
	{
		a[i]<mn&&(mn=a[i],cn=c[i]),a[i]>mx&&(mx=a[i],cx=c[i]);
		while(j^l&&mn<a[j-1]&&a[j-1]<mx) --j;cn==cx&&(ans+=u-j+1);
	}
	for(v=mn=1e18+1,mx=-1,i=j=u,k=u+1;i>=l;--i)
	{
		a[i]<mn&&(mn=a[i],cn=c[i]),a[i]>mx&&(mx=a[i],cx=c[i]);
		while(j^r&&a[j+1]<=mx) a[++j]<v&&(v=a[j],o=c[j]),w[j]=v,++ct[p[j]=o];
		while(k<=j&&w[k]>=mn) --ct[p[k++]];ans+=ct[cx];
	}
	while(k<=j) --ct[p[k++]];
	for(mn=1e18+1,v=mx=-1,i=j=u,k=u+1;i>=l;--i)
	{
		a[i]<mn&&(mn=a[i],cn=c[i]),a[i]>mx&&(mx=a[i],cx=c[i]);
		while(j^r&&a[j+1]>=mn) a[++j]>v&&(v=a[j],o=c[j]),w[j]=v,++ct[p[j]=o];
		while(k<=j&&w[k]<=mx) --ct[p[k++]];ans+=ct[cn];
	}
	while(k<=j) --ct[p[k++]];
}
int main()
{
	int i;for(read(n),i=1;i<=n;++i) read(a[i]),c[i]=Cnt(a[i]);return Solve(1,n),printf("%lld\n",ans),0;
}