#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 300000
#define INF (int)1e9
using namespace std;
int n,m,a[N+5],w[N+5],s[N+5];set<int> G;
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
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		int F[N<<2];
	public:
		I void Bd(PT) {if(F[rt]=INF+1,l==r) return;RI mid=l+r>>1;Bd(LT),Bd(RT);}
		I void U(CI L,CI R,CI v,PT) {if(L<=l&&r<=R) return (void)(F[rt]=min(F[rt],v));RI mid=l+r>>1;L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0);}
		I int Q(CI x,PT) {if(l==r) return F[rt];RI mid=l+r>>1;return min(x<=mid?Q(x,LT):Q(x,RT),F[rt]);}
}S;
class SegmentTree2
{
	private:
		#define PU(x) (V[x]=max(V[x<<1],V[x<<1|1]))
		int V[N<<2];
	public:
		I void Bd(PT) {if(V[rt]=-1,l==r) return;RI mid=l+r>>1;Bd(LT),Bd(RT);}
		I void U(CI x,CI v,PT) {if(l==r) return (void)(V[rt]=v);RI mid=l+r>>1;x<=mid?U(x,v,LT):U(x,v,RT),PU(rt);}
		I int Q(CI L,CI R,PT) {if(L<=l&&r<=R) return V[rt];RI mid=l+r>>1;return max(L<=mid?Q(L,R,LT):-1,R>mid?Q(L,R,RT):-1);}
}T; 
int main()
{
	RI Qt,i,j,op,x,y,z,t;for(read(n,Qt),S.Bd(),T.Bd(),i=1;i<=n;++i) w[i]=-1;W(Qt--)
	{
		if(read(op,x,y),op==1) {if(read(z),(t=T.Q(x,y))>z) return puts("NO"),0;S.U(x,y,z),t^z&&(G.insert(z),0);continue;}
		!~w[x]&&(w[x]=S.Q(x)),T.U(x,y);
	}
	#define Set(x,y) (s[x]|=y,t|=y)
	for(t=0,i=1;i<=n;++i) !~w[i]&&(w[i]=S.Q(i)),G.find(w[i])!=G.end()&&(G.erase(w[i]),Set(i,w[i]),w[i]=-1),w[i]=min(w[i],INF);
	if(!G.empty()) return puts("NO"),0;
	for(i=1;i<=n;++i) if(~w[i]) for(j=30;~j;--j) if(w[i]>=(1<<j)) {if(w[i]==(1<<j+1)-1) {Set(i,w[i]);break;}if(t>>j&1) {Set(i,(1<<j)-1);break;}Set(i,1<<j),w[i]^=1<<j;}
	for(puts("YES"),i=1;i<=n;++i) write(s[i]);return clear(),0;
}