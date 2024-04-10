#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
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
int main()
{
	RI Tt,i,t,lst;read(Tt);W(Tt--)
	{
		for(read(n),i=1;i<=n;++i) read(a[i]);
		for(t=0,lst=-1,i=2;i<=n;++i)
		{
			if(~lst) W(~a[i]&&a[i-1]==a[i]) a[lst]=a[lst+1]=-1,++lst,++t;
			if(~a[i]&&a[i-1]==a[i]) lst=i;
		}
		printf("%d\n",t);
	}return 0;
}