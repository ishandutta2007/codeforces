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
#define LN 18
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
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
int n,a[N+5],p[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N+5];
int D[N+5],f[N+5][LN+1];I void dfs(CI x)
{
	RI i;for(i=1;f[x][i]=f[f[x][i-1]][i-1];++i);for(i=lnk[x];i;i=e[i].nxt) D[e[i].to]=D[x]+1,dfs(e[i].to);
}
I int LCA(RI x,RI y)
{
	RI i;for(D[x]<D[y]&&(swap(x,y),0),i=0;D[x]^D[y];++i) (D[x]^D[y])>>i&1&&(x=f[x][i]);if(x==y) return x;
	for(i=0;f[x][i]^f[y][i];++i);for(--i;~i;--i) f[x][i]^f[y][i]&&(x=f[x][i],y=f[y][i]);return f[x][0];
}
I bool cmp(CI x,CI y) {return D[x]<D[y];}
I bool Mg(pair<int,int> A,pair<int,int> B,pair<int,int>& S)
{
	RI p[4]={A.first,A.second,B.first,B.second};sort(p,p+4,cmp);
	RI i,x=p[0],y=0;for(i=1;i<=3;++i) if(LCA(x,p[i])==x) x=p[i];else if(!y) y=p[i];else if(LCA(y,p[i])==y) y=p[i];else return 0;
	if(!y&&(y=p[0]),D[LCA(x,y)]>D[p[0]]) return 0;return S=make_pair(x,y),1;
}
class SegmentTree
{
	private:
		#define PT CI l=0,CI r=n-1,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU(x) (P[x]=P[x<<1]&&P[x<<1|1]&&Mg(G[x<<1],G[x<<1|1],G[x]))
		pair<int,int> g,G[N<<2];int P[N<<2];
		I int Q(PT)
		{
			if(l==r) return l;RI mid=l+r>>1;return P[rt<<1]&&(g.first?Mg(g,G[rt<<1],g):(g=G[rt<<1],1))?Q(RT):Q(LT);
		}
	public:
		I void Bd(PT)
		{
			if(l==r) return (void)(G[rt]=make_pair(p[l],p[l]),P[rt]=1);RI mid=l+r>>1;Bd(LT),Bd(RT),PU(rt);
		}
		I void U(CI x,CI v,PT)
		{
			if(l==r) return (void)(G[rt]=make_pair(v,v));RI mid=l+r>>1;x<=mid?U(x,v,LT):U(x,v,RT),PU(rt);
		}
		I int S() {if(P[1]) return n;return g=make_pair(0,0),Q();}
}S;
int main()
{
	RI Qt,i,op,x,y;for(read(n),i=1;i<=n;++i) read(a[i]),p[a[i]]=i;for(i=2;i<=n;++i) read(f[i][0]),add(f[i][0],i);dfs(1),S.Bd();
	read(Qt);W(Qt--) read(op),op==1?(read(x,y),x=a[x],y=a[y],S.U(x,p[y]),S.U(y,p[x]),swap(p[x],p[y]),a[p[x]]=x,a[p[y]]=y):(writeln(S.S()),0);
	return clear(),0;
}