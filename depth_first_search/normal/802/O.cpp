#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500000
using namespace std;
int n,k,a[N+5],b[N+5];long long ans;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
typedef pair<int,int> Pr;priority_queue<Pr,vector<Pr>,greater<Pr> > Q;I bool Check(CI x)
{
	RI i,t=ans=0;W(!Q.empty()) Q.pop();for(i=1;i<=n;++i)
	{
		if(Q.push(make_pair(a[i]+x,1)),Q.top().first+(b[i]+x)>0) continue;
		ans+=Q.top().first+(b[i]+x),t+=Q.top().second,Q.pop(),Q.push(make_pair(-(b[i]+x),0));
	}return t>=k;
}
int main()
{
	RI i;for(read(n,k),i=1;i<=n;++i) read(a[i]);for(i=1;i<=n;++i) read(b[i]);
	RI l=-1e9,r=0,mid;W(l^r) Check(mid=l+r+1>>1)?l=mid:r=mid-1;return Check(l),printf("%lld\n",ans-2LL*k*l),0;
}