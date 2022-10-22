#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
using namespace std;
int n,a[N+5],s[N+5],p[N+5];I int gcd(CI x,CI y) {return y?gcd(y,x%y):x;}
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
int main()
{
	RI i,t,g1,g2;for(read(n),i=1;i<=n;++i) read(a[i]),s[i]=i;
	W(1.0*clock()/CLOCKS_PER_SEC<=0.47)
	{
		random_shuffle(s+1,s+n+1),g1=a[s[1]],p[s[1]]=1,g2=a[s[2]],p[s[2]]=0;
		for(i=3;i<=n;++i) (t=gcd(g1,a[s[i]]))<g1?(g1=t,p[s[i]]=1):(g2=gcd(g2,a[s[i]]),p[s[i]]=0);
		if(g1==1&&g2==1) {for(puts("YES"),i=1;i<=n;++i) write(p[i]+1);return clear(),0;}
	}return puts("NO"),0;
}