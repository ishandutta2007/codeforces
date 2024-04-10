#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 35000
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
int n,a[N+5],L[N+5],R[N+5];
priority_queue<LL> A;priority_queue<LL,vector<LL>,greater<LL> > B;LL Q(LL x)
{
	while(!A.empty()) A.pop();while(!B.empty()) B.pop();A.push(x),B.push(x);
	LL fA=0,fB=0,l=x,r=x,v=abs(x);for(int i=2;i<=n;++i)
	{
		fA+=L[i]-a[i],fB+=R[i]-a[i],l+=L[i]-a[i],r+=R[i]-a[i];
		if(l>0) v+=abs(A.top()+fA),B.push(A.top()+fA-fB),A.pop(),A.push(l-fA),A.push(l-fA);
		else if(r<0) v+=abs(B.top()+fB),A.push(B.top()+fB-fA),B.pop(),B.push(r-fB),B.push(r-fB);
		else if(A.top()+fA<=0&&0<=B.top()+fB) A.push(-fA),B.push(-fB);
		else if(A.top()+fA>0) v+=abs(A.top()+fA),B.push(A.top()+fA-fB),A.pop(),A.push(-fA),A.push(-fA);
		else v+=abs(B.top()+fB),A.push(B.top()+fB-fA),B.pop(),B.push(-fB),B.push(-fB);
	}
	LL p=a[1]+x-R[1],q=a[1]+x-L[1],m=A.top()+fA;
	if(q<m) while(A.top()+fA>q) v+=A.top()+fA-q,A.pop();if(p>m) while(B.top()+fB<p) v+=p-B.top()-fB,B.pop();return v;
}
int main()
{
	int i;LL s=0;for(read(n),i=1;i<=n;++i) read(a[i],L[i],R[i]),s+=a[i];
	LL l=-s,r=s,u1,u2;while(r-l>2) Q(u1=l+(r-l)/3)<Q(u2=l+(r-l)/3*2)?r=u2:l=u1;
	LL t=1e18;for(LL x=l;x<=r;++x) t=min(t,Q(x));return printf("%lld\n",t),0;
}