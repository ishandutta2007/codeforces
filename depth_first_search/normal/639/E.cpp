#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 150000
#define LL long long
#define DB double
#define eps 1e-8
using namespace std;
int n;LL T;struct node {int p,t;LL L,R;I bool operator < (Con node& o) Con {return p<o.p;}}s[N+5];
I bool cmp(Con node& x,Con node& y) {return 1LL*x.p*y.t>1LL*y.p*x.t;}
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
I bool Check(Con DB& c)
{
	DB Mx,Tx=0;for(RI i=1;i<=n;Tx=max(Tx,s[i].p*(T-c*s[i].L)),++i)
		if((i==1||s[i-1]<s[i])&&(Mx=Tx),Mx>s[i].p*(T-c*s[i].R)) return 0;return 1;
}
int main()
{
	RI i;LL t,tt;for(read(n),i=1;i<=n;++i) read(s[i].p);for(i=1;i<=n;++i) read(s[i].t);sort(s+1,s+n+1,cmp);
	for(tt=0,i=1;i<=n;++i) (i==1||cmp(s[i-1],s[i]))&&(t=tt),tt+=s[i].t,s[i].L=t+s[i].t;
	for(T=tt,i=n;i>=1;--i) (i==n||cmp(s[i],s[i+1]))&&(t=tt),tt-=s[i].t,s[i].R=t;
	DB l=0,r=1,mid;sort(s+1,s+n+1);W(r-l>eps) Check(mid=(l+r)/2)?l=mid:r=mid;return printf("%.8lf\n",l),0;
}