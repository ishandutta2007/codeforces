#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;
const int Mod=998244353,inv2=Mod+1>>1;
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
int upd(int x){return x+(x>>31&Mod);}

int n; ll K;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int fat[100010],siz[100010],son[100010],lsiz[100010];
void dfs1(int cur,int f){
	fat[cur]=f; siz[cur]=1;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f){
			dfs1(v,cur);
			siz[cur]+=siz[v];
			if (siz[v]>siz[son[cur]]) son[cur]=v;
		}
	lsiz[cur]=siz[cur];
}
struct Node{
	int ls,rs,ms,siz;
}node[100010];
int seq[100010],seqtot;
int build(int l,int r){
	int tot=0,ltot=0;
	for (int i=l;i<=r;i++) tot+=lsiz[seq[i]];
	for (int i=l;i<=r;i++){
		ltot+=lsiz[seq[i]];
		if ((tot-ltot<<1)>tot) continue;
		int j=seq[i];
		if (l<i) node[j].ls=build(l,i-1);
		if (i<r) node[j].rs=build(i+1,r);
		node[j].siz=tot;
		return j;
	}
}
int dfs2(int cur){
	for (int i=cur;i;i=son[i])
		for (int j=last[i],v;j;j=edge[j].nxt)
			if ((v=edge[j].to)!=fat[i]&&v!=son[i]){
				node[i].ms=dfs2(v);
			}
	seqtot=0;
	for (int i=cur;i;i=son[i]) seq[++seqtot]=i,lsiz[i]-=siz[son[i]];
	return build(1,seqtot);
}
namespace NTT
{
const int X=1<<17;
int Wn[X|1],imaxw[40],W;
void prepare(int len){
	imaxw[0]=1; for (int i=1;i<=30;i++) imaxw[i]=1LL*imaxw[i-1]*inv2%Mod;
	for (W=1;W<=len;W<<=1);
	Wn[0]=1; for (int i=1,t=qpow(3,(Mod-1)/W);i<=W;i++) Wn[i]=1LL*Wn[i-1]*t%Mod;
}
int maxw,id[X],btw;
void init(int len,bool tp=1){
	for (maxw=1,btw=0;maxw<=len;maxw<<=1,btw++);
	if (tp) for (int i=1,t=btw-1;i<maxw;i++) id[i]=(id[i>>1]>>1)|((i&1)<<t);
}
void ntt(int *w,int tp){
	for (int i=0;i<maxw;i++) if (i<id[i]) swap(w[i],w[id[i]]);
	for (int midlen=1,len=2;midlen<maxw;midlen=len,len<<=1)
		for (int l=0,stp=W/len*tp;l<maxw;l+=len)
			for (int u=l,cur=(~tp?0:W),x,y;u-l<midlen;u++,cur+=stp){
				x=w[u],y=1LL*Wn[cur]*w[u+midlen]%Mod;
				w[u]=upd(x+y-Mod); w[u+midlen]=upd(x-y);
			}
}
} //namespace NTT
using namespace NTT;
vector<int> g[100010],h[100010];
int A[X],B[X],C[X],D[X],E[X],G[X],H[X];
void dfs3(int cur){
	int L=node[cur].ls,M=node[cur].ms,R=node[cur].rs;
	int siz1=node[node[cur].ms].siz,siz2=node[node[cur].ls].siz,siz3=node[node[cur].rs].siz,siz=node[cur].siz;
	if (L) dfs3(L); if (R) dfs3(R); if (M) dfs3(M);
	init(siz); g[cur].resize(siz+1); h[cur].resize(siz+1);
	A[0]=0; for (int i=1;i<=siz1;i++) A[i+1]=h[M][i]; A[1]=1; for (int i=siz1+2;i<maxw;i++) A[i]=0;
	B[0]=D[0]=0; for (int i=1;i<=siz2;i++) B[i]=h[L][i],D[i]=g[L][i]; for (int i=siz2+1;i<maxw;i++) B[i]=D[i]=0;
	C[0]=E[0]=0; for (int i=1;i<=siz3;i++) C[i]=h[R][i],E[i]=g[R][i]; for (int i=siz3+1;i<maxw;i++) C[i]=E[i]=0;
	ntt(A,1); if (L) ntt(B,1),ntt(D,1); if (R) ntt(C,1),ntt(E,1);
	for (int i=0;i<maxw;i++) G[i]=A[i];
	if (L) for (int i=0;i<maxw;i++) G[i]=1LL*G[i]*D[i]%Mod;
	if (R) for (int i=0;i<maxw;i++) G[i]=1LL*G[i]*E[i]%Mod;
	if (L) for (int i=0;i<maxw;i++) H[i]=(B[i]+1LL*D[i]*A[i]%Mod*(1+C[i]))%Mod;
	else for (int i=0;i<maxw;i++) H[i]=1LL*A[i]*(1+C[i])%Mod;
	ntt(G,-1); ntt(H,-1);
	for (int i=0;i<=siz;i++) g[cur][i]=1LL*G[i]*imaxw[btw]%Mod,h[cur][i]=1LL*H[i]*imaxw[btw]%Mod;
}
int ifac[100010],fac[100010];
int main()
{
	scanf("%d%I64d",&n,&K); K%=Mod; prepare(n);
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs1(1,0); int rt=dfs2(1); dfs3(rt);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%Mod;
	ifac[n]=qpow(fac[n],Mod-2); for(int i=n;i;i--) ifac[i-1]=1LL*ifac[i]*i%Mod;
	int ans=0;
	for (int i=1,t=1;i<=n;t=t*(K+i)%Mod,i++){
		ans=(ans+1LL*t*ifac[i-1]%Mod*h[rt][i])%Mod;
	}
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}