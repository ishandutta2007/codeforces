#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
#define LL long long
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,Qt,a[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];LL ans[N+5];
vector<pair<int,int> > q[N+5];vector<pair<int,int> >::iterator it;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int ff,OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0,ff=1;W(!isdigit(oc=tc())) ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));x*=ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {x<0&&(pc('-'),x=-x);W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int Rt[N+5];class SegmentTree
{
	private:
		#define PT CI l=-N,CI r=0
		#define LT l,mid
		#define RT mid+1,r
		#define New() (Et?Ep[Et--]:++Nt)
		#define E(x) (Ep[++Et]=x,O[x].Mx=O[x].K=O[x].B=O[x].S[0]=O[x].S[1]=0)
		#define PU(x) (O[x].Mx=O[O[x].S[1]].Mx+1LL*O[x].K*r+O[x].B)
		#define T(x,r,k,b) (O[x].Mx+=1LL*k*(r)+b,O[x].K+=k,O[x].B+=b)
		int Nt,Et,Ep[N*35];struct node {LL Mx,B;int K,S[2];}O[N*35];
	public:
		I void U(int& rt,CI B,PT) {!rt&&(rt=New()),T(rt,r,1,B);}
		I void G(int& rt,RI k=0,LL b=0,PT)
		{
			if(!rt) {if(1LL*k*l+b>=0) return;rt=New();}if(O[rt].Mx+1LL*k*r+b<=0) return (void)(E(rt),rt=New(),T(rt,r,-k,-b));if(l==r) return;RI mid=l+r>>1;
			k+=O[rt].K,b+=O[rt].B;LL t=O[O[rt].S[0]].Mx+1LL*k*mid+b;G(O[rt].S[0],k,b,LT),(!O[rt].S[0]||t<0)&&(G(O[rt].S[1],k,b,RT),0),PU(rt);
		}
		I void M(int& x,int& y,PT)
		{
			if(!x||!y) return (void)(x|=y);if(l==r) return (void)(O[x].Mx+=O[y].Mx,E(y));
			RI mid=l+r>>1;O[x].K+=O[y].K,O[x].B+=O[y].B,O[x].Mx+=O[y].Mx,M(O[x].S[0],O[y].S[0],LT),M(O[x].S[1],O[y].S[1],RT),E(y);
		}
		I LL Q(CI rt,CI x,PT)
		{
			if(!rt||l==r) return O[rt].Mx;RI mid=l+r>>1;return (x<=mid?Q(O[rt].S[0],x,LT):Q(O[rt].S[1],x,RT))+1LL*O[rt].K*x+O[rt].B;
		}
}S;
I void dfs(CI x,CI lst=0)
{
	for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(dfs(e[i].to,x),S.M(Rt[x],Rt[e[i].to]),++a[x]);
	for(it=q[x].begin();it!=q[x].end();++it) ans[it->first]=a[x]+S.Q(Rt[x],-it->second);S.U(Rt[x],a[x]-1),S.G(Rt[x]);
}
int main()
{
	RI i,x,y;for(read(n),i=1;i^n;++i) read(x,y),add(x,y),add(y,x);for(read(Qt),i=1;i<=Qt;++i) read(x,y),q[x].push_back(make_pair(i,y));
	for(dfs(1),i=1;i<=Qt;++i) writeln(ans[i]);return clear(),0;
}