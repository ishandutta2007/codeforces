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
#define V 300000
#define Pr pair<int,int>
using namespace std;
int n,v[N+5],l[N+5],r[N+5];pair<Pr,int> t;struct OP {int op,x,l,r;I bool operator < (Cn OP& o) Cn {return x<o.x;}}s[2*N+5];
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
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=V,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU(x) (G[x]=max(G[x<<1],G[x<<1|1]),G[x].first+=F[x])
		#define T(x,v) (G[x].first+=v,F[x]+=v)
		pair<int,int> G[V<<2];int F[V<<2];
	public:
		I void Bd(PT) {if(l==r) return (void)(G[rt].second=l);RI mid=l+r>>1;Bd(LT),Bd(RT),PU(rt);}
		I void U(CI L,CI R,CI v,PT) {if(L<=l&&r<=R) return (void)T(rt,v);RI mid=l+r>>1;L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0),PU(rt);}
		I pair<int,int> Q() {return G[1];}
}S;
int main()
{
	RI i,j;for(read(n),i=1;i<=n;++i) read(l[i],v[i],r[i]),s[i]=(OP){1,l[i],v[i],r[i]},s[i+n]=(OP){-1,v[i]+1,v[i],r[i]};
	for(sort(s+1,s+2*n+1),S.Bd(),i=j=1;i<=V;++i) {W(j<=2*n&&s[j].x==i) S.U(s[j].l,s[j].r,s[j].op),++j;t=max(t,make_pair(S.Q(),i));}
	RI x=t.second,y=t.first.second;for(printf("%d\n",t.first.first),i=1;i<=n;++i) l[i]<=x&&x<=v[i]&&v[i]<=y&&y<=r[i]&&(write(i),0);return clear(),0;
}