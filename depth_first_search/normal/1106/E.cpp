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
#define M 200
#define LL long long
#define INF (LL)1e18
using namespace std;
int n,m,k;LL f[N+5][M+1];struct G {int s,t,d,w;I bool operator < (Cn G& o) Cn {return w^o.w?w>o.w:d>o.d;}}s[N+5],g[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU(x) (P[rt]=P[rt<<1]+P[rt<<1|1])
		int P[N<<2]; 
	public:
		I void U(CI L,CI R,Cn G& o,PT)
		{
			if(P[rt]==r-l+1) return;if(l==r) return (void)(g[l]=o,P[rt]=1);
			RI mid=l+r>>1;L<=mid&&(U(L,R,o,LT),0),R>mid&&(U(L,R,o,RT),0),PU(rt);
		}
}S;
int main()
{
	RI i,j;for(read(n,m,k),i=1;i<=k;++i) read(s[i].s,s[i].t,s[i].d,s[i].w);
	for(sort(s+1,s+k+1),i=1;i<=k;++i) S.U(s[i].s,s[i].t,s[i]);
	for(i=n;i;--i) for(j=0;j<=m;++j) f[i][j]=g[i].w?min(j^m?f[i+1][j+1]:INF,f[g[i].d+1][j]+g[i].w):f[i+1][j];
	return printf("%lld\n",f[1][0]),0;
}