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
#define V 7000
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,Pt,P[V+5];bitset<V+5> mu,a[N+5],v[N+5],g[N+5];
int main()
{
	RI Qt,i,j,op,x,y,z;read(n,Qt);
	for(mu.set(1),i=2;i<=V;++i) for(!P[i]&&(mu.set(i),P[++Pt]=i),
		j=1;i*P[j]<=V;++j) if(P[i*P[j]]=1,i%P[j]) mu.test(i)&&(mu.set(i*P[j]),0);else break;
	for(i=1;i<=V;++i) for(j=i;j<=V;j+=i) v[j].set(i),mu.test(j/i)&&(g[i].set(j),0);
	W(Qt--) switch(read(op,x,y),op)
	{
		case 1:a[x]=v[y];break;case 2:read(z),a[x]=a[y]^a[z];break;case 3:read(z),a[x]=a[y]&a[z];break;
		case 4:putchar(48|(a[x]&g[y]).count()&1);break;
	}return 0;
}