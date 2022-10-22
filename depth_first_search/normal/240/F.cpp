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
using namespace std;
int n,a[30];char s[N+5];class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU(x) (V[x]=V[x<<1]+V[x<<1|1])
		#define PD(x) (~F[x]&&(T(x<<1,l,mid,F[x]),T(x<<1|1,mid+1,r,F[x]),F[x]=-1))
		#define T(x,l,r,v) (V[x]=v*((r)-(l)+1),F[x]=v)
		int V[N<<2],F[N<<2];
	public:
		I void Bd(CI o,PT)
		{
			if(F[rt]=-1,l==r) return (void)(V[rt]=(s[l]&31)==o);RI mid=l+r>>1;Bd(o,LT),Bd(o,RT),PU(rt);
		}
		I void U(CI L,CI R,CI v,PT)
		{
			if(L<=l&&r<=R) return (void)T(rt,l,r,v);RI mid=l+r>>1;PD(rt),L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0),PU(rt);
		}
		I int Q(CI L,CI R,PT)
		{
			if(L<=l&&r<=R) return V[rt];RI mid=l+r>>1;PD(rt);return (L<=mid?Q(L,R,LT):0)+(R>mid?Q(L,R,RT):0);
		}
		I void P(CI o,PT)
		{
			if(!V[rt]) return;if(l==r) return (void)(s[l]=96|o);RI mid=l+r>>1;PD(rt),P(o,LT),P(o,RT);
		}
}S[30];
int main()
{
	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout); 
	RI Qt,i,x,y,t;for(scanf("%d%d%s",&n,&Qt,s+1),i=1;i<=26;++i) S[i].Bd(i);W(Qt--)
	{
		for(scanf("%d%d",&x,&y),t=0,i=1;i<=26;++i) (a[i]=S[i].Q(x,y))&1&&++t;if(t>1) continue;for(i=1;i<=26;++i) S[i].U(x,y,0);
		for(i=1;i<=26;++i) a[i]&&(a[i]&1&&(t=i),a[i]>>=1,S[i].U(x,x+a[i]-1,1),S[i].U(y-a[i]+1,y,1),x+=a[i],y-=a[i]);t&&(S[t].U(x,x,1),0);
	}
	for(i=1;i<=26;++i) S[i].P(i);return puts(s+1),0;
}