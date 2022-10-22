#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 500000
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
int n,a[N+5],c[N+5],q[N+5],dc,dv[N+5];priority_queue<int,vector<int>,greater<int> > Q;
int main()
{
	int i;for(read(n),i=1;i<=n;++i) read(a[i]);n&1&&++n,sort(a+1,a+n+1);
	for(i=1;i<=n;++i) dv[i]=a[i];dc=unique(dv+1,dv+n+1)-dv-1;
	int j=1;for(i=1;i<=n;++i) {while(dv[j]<a[i]) ++j;++c[j];}
	int t,w=0,ct=0;long long ans=0;for(i=dc;i;--i)
	{
		t=0;while(c[i]&&w) --w,q[++ct]=dv[i],--c[i];
		while(c[i]&&!Q.empty()&&Q.top()<dv[i]) ans+=Q.top(),Q.pop(),q[++ct]=dv[i],--c[i],c[i]?(q[++ct]=dv[i],--c[i]):++w;
		while(c[i]>=2&&!Q.empty()&&Q.top()<2*dv[i]) ans+=Q.top(),q[++ct]=2*dv[i]-Q.top(),q[++ct]=Q.top(),Q.pop(),c[i]-=2;
		while(ct) Q.push(q[ct--]);while(c[i]--) ans+=dv[i],++w;
	}return printf("%lld\n",ans),0;	
}