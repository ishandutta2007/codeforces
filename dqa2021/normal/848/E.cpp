#pragma GCC optimize(2,3,"Ofast")
#pragma GCC optimize("-unroll-loops")

#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=998244353,inv2=Mod+1>>1;
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
inline int upd(int x){return x+(x>>31&Mod);}

int n;
namespace NTT
{
const int X=65536;
int Wn[X|1],W,imaxw[40];
int maxw,btw,id[X];
void prepare(int x){
	imaxw[0]=1; for(int i=1;i<=30;i++) imaxw[i]=1LL*imaxw[i-1]*inv2%Mod;
	for (W=1;W<=x;W<<=1);
	Wn[0]=1; for (int i=1,t=qpow(3,(Mod-1)/W);i<=W;i++) Wn[i]=1LL*Wn[i-1]*t%Mod;
}
void init(int x,bool tp=1){
	for (maxw=1,btw=0;maxw<=x;maxw<<=1,btw++);
	if (tp) for (int i=1,t=btw-1;i<maxw;i++) id[i]=(id[i>>1]>>1)|((i&1)<<t);
}
void ntt(int *w,int tp){
	for (int i=0;i<maxw;i++) if (i<id[i]) swap(w[i],w[id[i]]);
	for (int md=1,len=2;md<maxw;md=len,len<<=1)
		for (int l=0,stp=W/len*tp;l<maxw;l+=len)
			for (int u=l,cur=~tp?0:W,x,y;u-l<md;u++,cur+=stp){
				x=w[u],y=1LL*Wn[cur]*w[u+md]%Mod;
				w[u]=upd(x+y-Mod); w[u+md]=upd(x-y);
			}
}
}  //namespace NTT
using namespace NTT;
int h[50010];
int g[2][2][50010];
int f[2][2][50010];
inline void add(int &x,int y){x=upd(x+y-Mod);}
inline void add(int &x,ll y){x=(x+y)%Mod;}
void solve(int l,int r){
	if (l==r){
		if (l-2<3) return;
		add(f[0][0][l],f[0][1][l-2]);
		add(f[0][1][l],f[0][0][l-2]);
		add(f[1][0][l],f[1][1][l-2]);
		add(f[1][1][l],f[1][0][l-2]);
		return;
	}
	int mid=l+r>>1; solve(l,mid);
	init(r-l);
	static int F[2][2][X],G[2][2][X],H[2][2][X];
	for (int u=0;u<2;u++)
		for (int v=0;v<2;v++){
			for (int i=l;i<=mid;i++) F[u][v][i-l]=f[u][v][i];
			for (int i=mid-l+1;i<maxw;i++) F[u][v][i]=0;
			for (int i=0;i<=r-l;i++) G[u][v][i]=g[u][v][i];
			for (int i=r-l+1;i<maxw;i++) G[u][v][i]=0;
			ntt(F[u][v],1); ntt(G[u][v],1);
		}
	for (int u=0;u<2;u++)
		for (int v=0;v<2;v++){
			int *A=H[u][v];
			for (int i=0;i<maxw;i++) A[i]=0;
			for (int e=0;e<2;e++){
				int *B=F[u][e],*C=G[e][v];
				for (int i=0;i<maxw;i++) add(A[i],1LL*B[i]*C[i]);
			}
			ntt(A,-1);
			for (int i=mid+1;i<=r;i++){
				add(f[u][v][i],1LL*A[i-l]*imaxw[btw]);
			}
		}
	solve(mid+1,r);
}
int main()
{
	scanf("%d",&n);
	if (n==3) return puts("24"),0;
	if (n==4) return puts("4"),0;
	h[0]=h[2]=1;
	for (int i=4;i<=n;i+=2) h[i]=upd(h[i-2]+h[i-4]-Mod);
	for (int i=2;i<=n;i++){
		for (int u=0;u<2;u++)
			for (int v=0;v<2;v++){
				g[u][v][i+1]=1LL*h[i-(u^1)-(v^1)]*i%Mod*i%Mod;
			}
	}
	f[0][0][2]=2;
	for (int i=2;i<n;i++)
		for (int u=0;u<2;u++)
			for (int v=0;v<2;v++){
				f[u][v][i+1]=1LL*g[u][v][i+1]*(i+1)%Mod;
			}
	add(f[0][0][4],f[0][0][2]); add(f[1][1][4],f[0][0][2]);
	for (int j=3;2+j<=n;j++){
		add(f[0][1][2+j],1LL*f[0][0][2]*g[1][1][j]);
		add(f[0][0][2+j],1LL*f[0][0][2]*g[1][0][j]);
		add(f[1][0][2+j],1LL*f[0][0][2]*g[0][0][j]);
		add(f[1][1][2+j],1LL*f[0][0][2]*g[0][1][j]);
	}
	prepare(n-3);
	solve(3,n);
	int ans=upd(f[0][0][n]+f[1][1][n]-Mod);
	printf("%d\n",ans);
	return 0;
}