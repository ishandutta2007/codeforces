#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define LL long long
using namespace std;
int n,A,B,C;multiset<int> SB,SC;
struct Data {int A,B,C;I bool operator < (Con Data& o) Con {return A<o.A;}}s[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
}using namespace FastIO;
class SegmentTree
{
	private:
		#define PT CI l=0,CI r=B,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU(x) (S[x]=S[x<<1]+S[x<<1|1],Mn[x]=Mn[x<<1])
		#define PD(x) ~G[x]&&(T(x<<1,G[x],mid-l+1),T(x<<1|1,G[x],r-mid),G[x]=-1)
		#define T(x,v,l) (S[x]=1LL*(v)*(l),Mn[x]=G[x]=v)
		LL S[N<<2];int Mn[N<<2],G[N<<2];
	public:
		I void Bd(PT) {if(G[rt]=-1,l==r) return (void)(S[rt]=Mn[rt]=l?C:0);RI mid=l+r>>1;Bd(LT),Bd(RT),PU(rt);}
		I void U(CI L,CI R,CI v,PT)
		{
			if(L<=l&&r<=R) return (void)T(rt,v,r-l+1);RI mid=l+r>>1;PD(rt);
			L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0),PU(rt);
		}
		I int F(CI v,PT)
		{
			if(l==r) return l;RI mid=l+r>>1;PD(rt);return Mn[rt<<1|1]>v?F(v,LT):F(v,RT);
		}
		I LL Q(CI L,CI R,PT)
		{
			if(L<=l&&r<=R) return S[rt];RI mid=l+r>>1;PD(rt);return (L<=mid?Q(L,R,LT):0LL)+(R>mid?Q(L,R,RT):0LL);
		}
}S;
int main()
{
	RI i;for(read(n),read(A),read(B),read(C),i=1;i<=n;++i)
		read(s[i].A),read(s[i].B),read(s[i].C),SB.insert(s[i].B),SC.insert(s[i].C);
	RI j,o,MB,MC;LL t=0;for(sort(s+1,s+n+1),S.Bd(),i=j=1;i<=A;++i)
	{
		#define Max(SS) (SS.empty()?0:*--SS.end())
		MB=Max(SB),MC=Max(SC),(o=S.F(C-MC))>MB?t+=S.Q(MB+1,o):o=MB,t+=1LL*(B-o)*(C-MC);
		W(s[j].A==i) (o=S.F(C-s[j].C))<s[j].B&&(S.U(o+1,s[j].B,C-s[j].C),0),SB.erase(SB.find(s[j].B)),SC.erase(SC.find(s[j++].C));
	}return printf("%lld\n",t),0;
}