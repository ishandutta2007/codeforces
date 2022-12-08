#include <bits/stdc++.h>
typedef long long LL;
const int mod=1e9+7;
LL dp[500][500],C[500][500],fact[500];
int cnt[500],a[500],vis[500],sz;
int Min(int x,int y) {
	if (x<y) return x;
	else return y;
}
int check(LL x) {
	LL l=1,r=1e9;
	LL now=l;
	while (l<=r) {
		LL mid=(l+r)>>1;
		if (mid*mid<=x)now=mid,l=mid+1;
		else r=mid-1;
	}
	return now*now==x;
}
inline LL M(LL x) {
	return x%mod;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",a+i);
	}
	for (int i=0; i<n; i++) {
		if (vis[i]==0) {
			for (int j=i; j<n; j++) {
				if (check(1LL*a[i]*a[j])) {
					cnt[sz]++;
					vis[j]=1;
				}
			}
			sz++;
		}
	}
	C[0][0]=1;
	fact[0]=1;
	for (int i=1; i<=300; i++) {
		C[i][0]=1;
		for (int j=1; j<=i; j++) {
			C[i][j]=M(C[i-1][j]+C[i-1][j-1]);
		}
	}
	for (int i=1; i<=300; i++)
		fact[i]=M(fact[i-1]*i);
	dp[0][cnt[0]-1]=1;
	int lim=cnt[0];
	for (int i=1; i<sz; i++) {
		for (int j=0; j<lim; j++) {
			for (int k=0; k<cnt[i]; k++) {
				for (int m=0; m<=Min(j,k+1); m++) {
					dp[i][j+cnt[i]-1-k-m]=M(dp[i][j+cnt[i]-1-k-m]+dp[i-1][j]*C[cnt[i]-1][k]%mod*C[j][m]%mod*C[lim-1-j+2][k+1-m]);
				}
			}
		}
		lim+=cnt[i];
	}
	LL ans=dp[sz-1][0];
	for (int i=0; i<sz; i++) {
		ans*=fact[cnt[i]];
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}