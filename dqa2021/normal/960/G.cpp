#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=998244353,inv2=Mod+1>>1;
inline int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
inline int upd(int x){return x+(x>>31&Mod);}
int fac[100010],ifac[100010];
int C(int n,int m){return n<m?0:1LL*fac[n]*ifac[n-m]%Mod*ifac[m]%Mod;}

int n,A,B;
namespace NTT
{
const int MAXX=1<<17;
int Wn[MAXX|1],imaxw[40],MAXW;
int maxw,btw,id[MAXX];
void prepare(int len){
	imaxw[0]=1; for (int i=1;i<40;i++) imaxw[i]=1LL*imaxw[i-1]*inv2%Mod;
	for (MAXW=1;MAXW<=len;MAXW<<=1);
	Wn[0]=1; for (int i=1,t=qpow(3,(Mod-1)/MAXW);i<=MAXW;i++) Wn[i]=1LL*Wn[i-1]*t%Mod;
}
void init(int len,bool tp=1){
	for (maxw=1,btw=0;maxw<=len;maxw<<=1,btw++);
	if (tp) for (int i=1,t=btw-1;i<maxw;i++) id[i]=(id[i>>1]>>1)|((i&1)<<t);
}
void ntt(int *w,int tp){
	for (int i=0;i<maxw;i++) if (i<id[i]) swap(w[i],w[id[i]]);
	for (int midlen=1,len=2;midlen<maxw;midlen=len,len<<=1){
		for (int l=0,stp=MAXW/len*tp;l<maxw;l+=len){
			for (int u=l,cur=(tp==1?0:MAXW),x,y;u-l<midlen;u++,cur+=stp){
				x=w[u],y=1LL*w[u+midlen]*Wn[cur]%Mod;
				w[u]=upd(x+y-Mod); w[u+midlen]=upd(x-y);
			}
		}
	}
}
void solve(int n,int *f){  //f[i(n)]  //clear  //
	static int g[MAXX],h[MAXX];
	if (!n) return f[0]=1,void();
	int m=n>>1; solve(m,f); init(m<<1);
	for (int i=0,t=1;i<=m;i++,t=1LL*t*m%Mod) g[m-i]=1LL*f[i]*fac[i]%Mod,h[i]=1LL*ifac[i]*t%Mod;
	for (int i=m+1;i<maxw;i++) g[i]=h[i]=0;
	ntt(g,1); ntt(h,1); for (int i=0;i<maxw;i++) g[i]=1LL*g[i]*h[i]%Mod; ntt(g,-1);
	for (int i=0;i<=m;i++) h[i]=1LL*ifac[i]*g[m-i]%Mod*imaxw[btw]%Mod; for (int i=m+1;i<maxw;i++) h[i]=0;
	ntt(f,1); ntt(h,1); for (int i=0;i<maxw;i++) f[i]=1LL*f[i]*h[i]%Mod; ntt(f,-1);
	for (int i=m<<1;i>=0;i--) f[i]=1LL*f[i]*imaxw[btw]%Mod; for (int i=m<<1|1;i<maxw;i++) f[i]=0;
	if (n&1){m=n-1; for (int i=n-1;i>=0;i--) f[i+1]=upd(f[i+1]+f[i]-Mod),f[i]=1LL*f[i]*m%Mod;}
}
}
using namespace NTT;
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	if (!A||!B) return puts("0"),0;
	if (A+B-2>n-1) return puts("0"),0;
	prepare(n);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%Mod;
	ifac[n]=qpow(fac[n],Mod-2); for (int i=n;i;i--) ifac[i-1]=1LL*ifac[i]*i%Mod;
	static int f[MAXX]; solve(n-1,f);
	int ans=1LL*f[A+B-2]*C(A+B-2,A-1)%Mod;
	printf("%d\n",ans);
	return 0;
}