#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int qpow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
inline int upd(int x){return x+(x>>31&Mod);}
const int MAXW=1e7;
int fac[MAXW+10],idk[MAXW+10],ifac[MAXW+10]; int prm[MAXW+10];

int n,m,k,p,q; int ans;
int force(){
	if (!q) return printf("%d\n",ans=1LL*qpow(n,k)*qpow(p,n)%Mod),0;
	for (int i=0,s=1,t=1,u=qpow(q,n),v=qpow(q,Mod-2);i<=n;i++,s=1LL*s*(n-i+1)%Mod,t=1LL*t*p%Mod,u=1LL*u*v%Mod){
		ans=(ans+1LL*idk[i]*s%Mod*ifac[i]%Mod*t%Mod*u)%Mod;
	}
	printf("%d\n",ans);
	return 0;
}
int S[MAXW+10];
int main()
{
	scanf("%d%d%d",&n,&m,&k); p=qpow(m,Mod-2),q=upd(1-p);
	idk[1]=1; fac[0]=fac[1]=1;
	for (int i=2;i<=MAXW;i++){
		fac[i]=1LL*fac[i-1]*i%Mod;
		if (!idk[i]) prm[++*prm]=i,idk[i]=qpow(i,k);
		for (int j=1;j<=*prm&&i*prm[j]<=MAXW;j++){
			int t=i*prm[j]; idk[t]=1LL*idk[i]*idk[prm[j]]%Mod;
			if (i%prm[j]==0) break;
		}
	}
	ifac[MAXW]=qpow(fac[MAXW],Mod-2);
	for (int i=MAXW;i;i--) ifac[i-1]=1LL*ifac[i]*i%Mod;
	if (n<=k) return force();
	S[k]=1;
	for (int i=k-1,t=upd(-p),s=t,u=n-k;i>=0;i--,s=1LL*s*t%Mod,u=1LL*u*(n-i-1)%Mod){
		S[i]=(1LL*q*S[i+1]+1LL*s*u%Mod*ifac[k-i])%Mod;
	}
	for (int i=0,s=1,t=1;i<=k;i++,s=1LL*s*(n-i+1)%Mod,t=1LL*t*p%Mod){
		ans=(ans+1LL*idk[i]*s%Mod*ifac[i]%Mod*t%Mod*S[i])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}