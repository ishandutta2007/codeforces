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
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,a[N+5],b[N+5],p[N+5],vis[N+5];
int main()
{
	RI Tt,i,x,c,t;long long ans;read(Tt);W(Tt--)
	{
		for(read(n),i=1;i<=n;++i) read(a[i]);for(i=1;i<=n;++i) read(b[i]),p[a[i]]=b[i],vis[i]=0;
		for(t=0,i=1;i<=n;++i) if(!vis[i]) {c=0,x=i;W(++c,vis[x]=1,!vis[x=p[x]]);t+=c>>1;}
		for(ans=0,i=1;i<=t;++i) ans+=n-i+1-i;printf("%lld\n",ans<<1);
	}return 0;
}