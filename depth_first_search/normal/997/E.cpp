#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 120000
#define LL long long
using namespace std;
int n,a[N+5],p[N+5];LL ans[N+5];struct Q {int p,l,r;I bool operator < (Cn Q& o) Cn {return r<o.r;}}q[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define Tf(x,v) (Mn[x]+=v,F[x]+=v)
		#define Tg(x,v) (V[x]+=1LL*(v)*C[x],G[x]+=v)
		LL V[N<<2];int Mn[N<<2],C[N<<2],F[N<<2],G[N<<2];
		I void PU(CI x)
		{
			V[x]=V[x<<1]+V[x<<1|1];if(Mn[x<<1]==Mn[x<<1|1]) return (void)(Mn[x]=Mn[x<<1],C[x]=C[x<<1]+C[x<<1|1]);
			Mn[x<<1]<Mn[x<<1|1]?(Mn[x]=Mn[x<<1],C[x]=C[x<<1]):(Mn[x]=Mn[x<<1|1],C[x]=C[x<<1|1]);
		}
		I void PD(CI x)
		{
			F[x]&&(Tf(x<<1,F[x]),Tf(x<<1|1,F[x]),F[x]=0);
			G[x]&&(Mn[x<<1]==Mn[x]&&Tg(x<<1,G[x]),Mn[x<<1|1]==Mn[x]&&Tg(x<<1|1,G[x]),G[x]=0);
		}
	public:
		I void Bd(PT) {if(C[rt]=1,l==r) return;RI mid=l+r>>1;Bd(LT),Bd(RT);} 
		I void A(CI L,CI R,CI v,PT)
		{
			if(L<=l&&r<=R) return (void)Tf(rt,v);RI mid=l+r>>1;PD(rt),L<=mid&&(A(L,R,v,LT),0),R>mid&&(A(L,R,v,RT),0),PU(rt); 
		}
		I void M(CI L,CI R,PT)
		{
			if(Mn[rt]>1) return;if(L<=l&&r<=R) return (void)Tg(rt,1);RI mid=l+r>>1;PD(rt),L<=mid&&(M(L,R,LT),0),R>mid&&(M(L,R,RT),0),PU(rt);
		}
		I LL Q(CI L,CI R,PT)
		{
			if(L<=l&&r<=R) return V[rt];RI mid=l+r>>1;return PD(rt),(L<=mid?Q(L,R,LT):0)+(R>mid?Q(L,R,RT):0);
		}
}S;
int main()
{
	RI Qt,i;for(read(n),i=1;i<=n;++i) read(a[i]),p[a[i]]=i;
	for(read(Qt),i=1;i<=Qt;++i) read(q[i].l,q[i].r),q[i].p=i;
	RI j=1;for(sort(q+1,q+Qt+1),S.Bd(),i=1;i<=n;++i)
	{
		S.A(1,i,1),a[i]^1&&p[a[i]-1]<i&&(S.A(1,p[a[i]-1],-1),0),a[i]^n&&p[a[i]+1]<i&&(S.A(1,p[a[i]+1],-1),0);
		S.M(1,i);W(j<=Qt&&q[j].r==i) ans[q[j].p]=S.Q(q[j].l,i),++j;
	}
	for(i=1;i<=Qt;++i) writeln(ans[i]);return clear(),0;
}