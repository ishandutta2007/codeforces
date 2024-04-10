#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define SZ 1000000
#define V 998244353
#define X 1000000007
#define LL long long
#define Dec(x) (!x--&&(x+=X))
using namespace std;
LL n,nn,p;int ans,tn[7],c[7][7],s[7][7][SZ+1];
void Init(RI x,RI l,CI k)
{
	s[k][l][++c[k][l]]=(++p)-x;if(l==k) return;for(RI i=0;i<=9;++i) Init(x*10+i,l+1,k);
}
void BF(LL x,RI l)
{
	if(x>n) return;++p;ans=(ans+(p-x)/V-(p<x)+X)%X;for(RI i=0;i<=9;++i) BF(x*10+i,l+1);
}
void Solve(RI x,RI l)
{
	if(l^6) {++p,ans=(ans+(p-x)/V-(p<x)+X)%X;for(RI i=0;i<=9;++i) Solve(x*10+i,l+1);return;}
	if(x==nn) return BF(x,0);
	RI i,k;LL v;for(k=0,v=x;k<=6&&v<=n;++k,v*=10);--k;
	for(i=0;i<=k;++i) v=p-1LL*x*tn[i],ans=(ans+1LL*(v/V-(v<0)+X)*tn[i])%X,
		v=(v%V+V)%V,ans=(ans+tn[i]-(lower_bound(s[k][i]+1,s[k][i]+tn[i]+1,V-v)-s[k][i])+1)%X;
	for(i=0;i<=k;++i) p+=tn[i];
}
int main()
{
	RI i,k,dc;for(scanf("%lld",&n),tn[0]=i=1;i<=6;++i) tn[i]=tn[i-1]*10;
	for(k=0;k<=6;++k) for(p=0,Init(0,0,k),i=0;i<=k;++i) sort(s[k][i]+1,s[k][i]+tn[i]+1);
	if(p=0,n<1e6) for(i=1;i<=9;++i) BF(i,1);else {nn=n;W(nn>=1e6) nn/=10;for(i=1;i<=9;++i) Solve(i,1);}
	return printf("%d\n",(int)(1LL*(X-ans)*V%X)),0;
}