#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
const int Mod=1e9+7;
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
inline int upd(int x){return x+(x>>31&Mod);}
int fac[100100],ifac[100100];
void init(int x){
	fac[0]=1; for (int i=1;i<=x;i++) fac[i]=1LL*fac[i-1]*i%Mod;
	ifac[x]=qpow(fac[x],Mod-2); for (int i=x;i;i--) ifac[i-1]=1LL*ifac[i]*i%Mod;
}
int C(int n,int m){return n<m?0:1LL*fac[n]*ifac[n-m]%Mod*ifac[m]%Mod;}

int n,m,p,q,k;
int f[1510],g[1510];
int dp[3][1510][1510];
int pre[1510];   //to right; for B
int suf[1510];
int main()
{
	n=read(),m=read();
	int a=read(),b=read(); p=1LL*a*qpow(b,Mod-2)%Mod; q=upd(1-p);
	k=read(); init(k+10);
	for (int i=1;i<=m;i++){
		if (i-1<=k) g[i]=1LL*C(k,i-1)*qpow(p,i-1)%Mod*qpow(q,k-i+1)%Mod;
		f[i]=upd(f[i-1]+g[i]-Mod);
	}
	for (int i=1;i<=m;i++) dp[0][1][i]=1;
	for (int i=1;i<n;i++){
		memset(pre,0,sizeof pre);
		memset(suf,0,sizeof suf);
		for (int j=1;j<=m;j++){
			if (!dp[i][j]) continue;
			//A
			suf[j-1]=(suf[j-1]+1LL*dp[0][i][j]*g[m-j+1])%Mod;
			dp[2][i+1][j]=(dp[2][i+1][j]+1LL*dp[0][i][j]*g[m-j+1]%Mod*f[j])%Mod;
			//B
			pre[j+1]=(pre[j+1]+1LL*dp[1][i][j]*g[j])%Mod;
			dp[2][i+1][j]=(dp[2][i+1][j]+1LL*dp[1][i][j]*f[m-j+1]%Mod*g[j])%Mod;
			//C
			suf[j-1]=(suf[j-1]+1LL*dp[2][i][j]*f[m-j+1])%Mod;
			pre[j+1]=(pre[j+1]+1LL*dp[2][i][j]*f[j])%Mod;
			dp[2][i+1][j]=(dp[2][i+1][j]+1LL*dp[2][i][j]*f[m-j+1]%Mod*f[j])%Mod;
		}
		for (int j=1;j<=m;j++){
			pre[j]=upd(pre[j]+pre[j-1]-Mod);
			dp[1][i+1][j]=(dp[1][i+1][j]+1LL*pre[j]*f[m-j+1])%Mod;
		}
		for (int j=m;j;j--){
			suf[j]=upd(suf[j]+suf[j+1]-Mod);
			dp[0][i+1][j]=(dp[0][i+1][j]+1LL*suf[j]*f[j])%Mod;
		}
	}
	int ans=0;
	for (int i=1;i<=m;i++){
		ans=(ans+1LL*dp[0][n][i]*f[i]%Mod*g[m-i+1]+1LL*dp[1][n][i]*f[m-i+1]%Mod*g[i]+1LL*dp[2][n][i]*f[i]%Mod*f[m-i+1])%Mod;
	}
	printf("%d\n",upd(ans));
	return 0;
}