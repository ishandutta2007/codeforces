#include<cstdio>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
const int mod=1e4+7;
int inv[mod+10],fac[mod+10],ifac[mod+10];
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=x*x%mod)
		if (y&1) res=res*x%mod;
	return res;
}
void init(){
	inv[1]=1; for (int i=2;i<mod;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=1; for (int i=1;i<mod;i++) fac[i]=fac[i-1]*i%mod;
	ifac[0]=1; for (int i=1;i<mod;i++) ifac[i]=ifac[i-1]*inv[i]%mod;
}

int n,T; char s[210];
int _dp[810][210][210];
bool _vis[810][210][210];
int _dfs(int t,int l,int r){
	if (_vis[t][l][r]) return _dp[t][l][r];
	_vis[t][l][r]=1; int &res=_dp[t][l][r];
	if (!t) return res=l==1&&r==0;
	if (l==1&&r==0) return res=_dfs(t-1,l,r)*26%mod;
	if (t==1) return res=l==r;
	if (s[l]!=s[r]) return res=(_dfs(t-1,l+1,r)+_dfs(t-1,l,r-1)+24*_dfs(t-1,l,r))%mod;
	if (r-l+1<=2) return res=(_dfs(t-1,1,0)+25*_dfs(t-1,l,r))%mod;
	return res=(_dfs(t-1,l+1,r-1)+25*_dfs(t-1,l,r))%mod;
}
int dp[810][210][210];
bool vis[810][210][210];
int dfs(int t,int l,int r){
	if (vis[t][l][r]) return dp[t][l][r];
	vis[t][l][r]=1; int &res=dp[t][l][r];
	if (!t) return res=l==1&&r==0;
	if (l==1&&r==0) return res=dfs(t-1,l,r)*26%mod;
	if (s[l]!=s[r]) return res=(dfs(t-1,l+1,r)+dfs(t-1,l,r-1)+24*dfs(t-1,l,r))%mod;
	if (r-l+1<=2) return res=(dfs(t-1,1,0)+25*dfs(t-1,l,r))%mod;
	return res=(dfs(t-1,l+1,r-1)+25*dfs(t-1,l,r))%mod;
}
//int getans(int k){
//	if (k&1) return _dfs(k+1>>1,1,n);
//	return dfs(k+1>>1,1,n);
//}
int a[310][310],b[310],c[310];
void gauss(int n){
//	printf("matrix:\n");
//	for (int i=1;i<=n;i++)
//		for (int j=1;j<=n;j++)
//			printf("%d%c",a[i][j]," \n"[j==n]);
//	printf("vector:\n");
//	for (int i=1;i<=n;i++) printf("%d\n",b[i]);
	for (int i=1;i<=n;i++){
		int p=-1;
		for(int j=i;j<=n;j++) if (a[j][i]){p=j;break;}
		assert(~p);
		if (i^p){
			for (int j=i;j<=n;j++) swap(a[i][j],a[p][j]);
			swap(b[i],b[p]);
		}
		assert(a[i][i]>0&&a[i][i]<mod);
		int t=inv[a[i][i]];
		for (int j=i+1;j<=n;j++){
			if (!a[j][i]) continue;
			int s=t*a[j][i]%mod;
			for (int u=i;u<=n;u++)
				a[j][u]=(a[j][u]-a[i][u]*s%mod+mod)%mod;
			b[j]=(b[j]-b[i]*s%mod+mod)%mod;
		}
	}
	for (int i=n;i;i--){
		for (int j=i+1;j<=n;j++)
			b[i]=(b[i]-a[i][j]*c[j]%mod+mod)%mod;
		c[i]=b[i]*inv[a[i][i]]%mod;
	}
//	printf("ans:\n");
//	for (int i=1;i<=n;i++) printf("%d ",c[i]); puts("");
}
int main()
{
	init();
	scanf("%s%d",s+1,&T);
	n=strlen(s+1); T+=n;
	if (T&1){
		if (T<=n+n) return printf("%d\n",_dfs(T+1>>1,1,n)),0;
		int A=n-1,B=n-1+(n+1>>1),C=n+(n+1>>1);
		for (int t=1;t<=C;t++){
			int r=t*2+n+n>>1;
			b[t]=_dfs(r,1,n);
			for (int i=1;i<=A;i++) a[t][i]=qpow(r,i-1)*qpow(24,r)%mod;
			for (int i=A+1;i<=B;i++) a[t][i]=qpow(r,i-A-1)*qpow(25,r)%mod;
			for (int i=B+1;i<=C;i++) a[t][i]=qpow(r,i-B-1)*qpow(26,r)%mod;
		}
		gauss(C);
		int ans=0;
		T=T+1>>1;
		for (int i=1;i<=A;i++) ans=(ans+qpow(T%mod,i-1)*qpow(24,T%(mod-1))%mod*c[i])%mod;
		for (int i=A+1;i<=B;i++) ans=(ans+qpow(T%mod,i-A-1)*qpow(25,T%(mod-1))%mod*c[i])%mod;
		for (int i=B+1;i<=C;i++) ans=(ans+qpow(T%mod,i-B-1)*qpow(26,T%(mod-1))%mod*c[i])%mod;
		printf("%d\n",ans);
	}
	else{
		if (T<=n+n) return printf("%d\n",dfs(T+1>>1,1,n)),0;
		int A=n-1,B=n-1+(n+1>>1),C=n+(n+1>>1);
		for (int t=1;t<=C;t++){
			int r=t*2+n+n>>1;
			b[t]=dfs(r,1,n);
			for (int i=1;i<=A;i++) a[t][i]=qpow(r,i-1)*qpow(24,r)%mod;
			for (int i=A+1;i<=B;i++) a[t][i]=qpow(r,i-A-1)*qpow(25,r)%mod;
			for (int i=B+1;i<=C;i++) a[t][i]=qpow(r,i-B-1)*qpow(26,r)%mod;
		}
		gauss(C);
		int ans=0;
		T=T+1>>1;
		for (int i=1;i<=A;i++) ans=(ans+qpow(T%mod,i-1)*qpow(24,T%(mod-1))%mod*c[i])%mod;
		for (int i=A+1;i<=B;i++) ans=(ans+qpow(T%mod,i-A-1)*qpow(25,T%(mod-1))%mod*c[i])%mod;
		for (int i=B+1;i<=C;i++) ans=(ans+qpow(T%mod,i-B-1)*qpow(26,T%(mod-1))%mod*c[i])%mod;
		printf("%d\n",ans);
	}
	return 0;
}