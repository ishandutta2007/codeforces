#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 200000
#define P(i,j) (((i)-1)*m+(j))
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
int n,m,a[N+5],b[N+5];
int main()
{
	int Tt,i,j,k,x,y,l,r;read(Tt);while(Tt--)
	{
		for(read(n,m),i=1;i<=n*m;++i) read(a[i]);
		for(l=r=-1,i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j) b[j]=a[P(i,j)];sort(b+1,b+m+1); 
			for(j=1;j<=m;++j) a[P(i,j)]^b[j]&&((~l?r:l)=j);if(~l) break;
		}
		if(!~l) {puts("1 1");continue;}
		for(i=1;i<=n;++i) swap(a[P(i,l)],a[P(i,r)]);
		for(i=1;i<=n;++i) {for(j=2;j<=m&&a[P(i,j-1)]<=a[P(i,j)];++j);if(j<=m) goto NO;}
		printf("%d %d\n",l,r);continue;NO:puts("-1");
	}return 0;
}