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
#define LL long long
using namespace std;
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
int n,a[N+5],g[N+5],m[N+5];
int Rt1[N+5],Rt2[N+5];class ChairmanTree
{
	private:
		int Nt;struct node {LL V;int S[2];}O[N*19];
	public:
		I void U(int& o,CI x,CI v,RI l=0,RI r=N)
		{
			if((O[++Nt]=O[o]).V+=v,o=Nt,l==r) return;RI u=l+r>>1;x<=u?U(O[o].S[0],x,v,l,u):U(O[o].S[1],x,v,u+1,r);
		}
		I LL Q(CI o,CI L,CI R,RI l=0,RI r=N) Cn
		{
			if(!o||L<=l&&r<=R) return O[o].V;RI u=l+r>>1;return (L<=u?Q(O[o].S[0],L,R,l,u):0)+(R>u?Q(O[o].S[1],L,R,u+1,r):0);
		}
}C1,C2;
namespace G
{
	#define IT set<Il>::iterator
	struct Il {int t,l,r;bool operator < (Cn Il& o) Cn {return l<o.l;}};set<Il> S;
	I void Init() {for(RI i=1;i<=n;++i) S.insert((Il){0,i,i});}
	I IT Sp(CI x)
	{
		IT it=S.lower_bound((Il){0,x,0});if(it->l==x) return it;
		--it;RI t=it->t,l=it->l,r=it->r;return S.erase(it),S.insert((Il){t,l,x-1}),S.insert((Il){t,x,r}).first;
	}
	I LL Q(CI t,CI l,CI r)
	{
		LL ans=0;IT tr=Sp(r+1),tl=Sp(l);for(IT ti=tl;ti!=tr;++ti)
		{
			if(!ti->t) {ans+=min((LL)m[ti->l],a[ti->l]+1LL*g[ti->l]*t);continue;}
			t-ti->t<=N&&(ans+=(C1.Q(Rt1[ti->r],t-ti->t,N)-C1.Q(Rt1[ti->l-1],t-ti->t,N))*(t-ti->t));
			ans+=C2.Q(Rt2[ti->r],0,min(t-ti->t-1,N))-C2.Q(Rt2[ti->l-1],0,min(t-ti->t-1,N));
		}return S.erase(tl,tr),S.insert((Il){t,l,r}),ans;
	}
}
int main()
{
	RI Qt,i;for(read(n),i=1;i<=n;++i) read(a[i],m[i],g[i]);
	for(i=1;i<=n;++i) Rt1[i]=Rt1[i-1],Rt2[i]=Rt2[i-1],g[i]&&(C1.U(Rt1[i],m[i]/g[i],g[i]),C2.U(Rt2[i],m[i]/g[i],m[i]),0);
	RI t,x,y;G::Init();read(Qt);W(Qt--) read(t,x,y),writeln(G::Q(t,x,y));return clear(),0;
}