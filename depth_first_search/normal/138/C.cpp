#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define M 10000
#define DB double
#define G(x) (lower_bound(dv+1,dv+dc+1,x)-dv)
using namespace std;
int n,m,dc,dv[M+5];struct Data {int x,y,p,q;}s[N+5],a[M+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define D isdigit(oc=tc())
	int ff;char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0,ff=1;W(!D) ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),D);x*=ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=dc,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		DB V[N<<2];
	public:
		I void Bd(PT) {if(V[rt]=1,l==r) return;RI mid=l+r>>1;Bd(LT),Bd(RT);}
		I DB Q(CI x,PT) {if(l==r) return V[rt];RI mid=l+r>>1;return (x<=mid?Q(x,LT):Q(x,RT))*V[rt];}
		I void U(CI L,CI R,Con DB& v,PT)
		{
			if(L>R) return;if(L<=l&&r<=R) return (void)(V[rt]*=v);
			RI mid=l+r>>1;L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0);
		}
}S;
int main()
{
	RI i;for(read(n,m),i=1;i<=n;++i) read(s[i].x,s[i].y,s[i].p,s[i].q);
	for(i=1;i<=m;++i) read(a[i].x,a[i].y),dv[i]=a[i].x;sort(dv+1,dv+m+1),dc=unique(dv+1,dv+m+1)-dv-1,S.Bd();
	for(i=1;i<=n;++i) S.U(G(s[i].x-s[i].y),G(s[i].x)-1,1-s[i].p/100.0),S.U(G(s[i].x+1),G(s[i].x+s[i].y+1)-1,1-s[i].q/100.0);
	DB ans=0;for(i=1;i<=m;++i) ans+=S.Q(G(a[i].x))*a[i].y;return printf("%.6lf\n",ans),0;
}