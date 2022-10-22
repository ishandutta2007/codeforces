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
int n,a[N+5],b[N+5],c[N+5];
int main()
{
	RI Tt,i,j,x;read(Tt);W(Tt--)
	{
		for(read(n),i=1;i<=n;++i) read(a[i]),c[a[i]]=0;for(i=1;i<=n;++i) read(b[i]),c[b[i]]=0;
		for(i=1;i<=n;++i) ++c[a[i]],--c[b[i]];for(i=1;i<=n;++i) if(c[a[i]]) break;if(i<=n) goto NO;
		for(i=j=1;i<=n;)
		{
			x=b[i];W(j<=n&&a[j]^x) ++c[a[j++]];if(j>n) goto NO;
			++i,++j;W(i<=n&&b[i]==x&&c[x]) ++i,--c[x];
		}
		puts("YES");continue;NO:puts("NO");
	}return 0;
}