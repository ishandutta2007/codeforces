#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,ll>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e5+5,P=1e9+7; int inv[N],dp[N],g[N];
void solve(int n,int k){
	if (n==1){ dp[0]=dp[1]=1; return; }
	int m=n>>1; solve(m,k);
	static int pw[N];
	pw[0]=1; rep(i,1,k) pw[i]=(ll)pw[i-1]*m%P;
	rep(j,0,k){
		g[j]=0; int C=1;//C=C(m-i,j-i)
		per(i,j,0){
			if (j!=i) C=(ll)C*(m-i)%P*inv[j-i]%P;
			g[j]=(g[j]+(ll)pw[j-i]*dp[i]%P*C)%P;
		}
	}
	static int f[N]; rep(j,0,k) f[j]=dp[j],dp[j]=0;
	rep(i,0,k) rep(j,0,k) 
		if (i+j<=k) dp[i+j]=(dp[i+j]+(ll)f[i]*g[j])%P;
	if (n&1) per(i,k,1) dp[i]=(dp[i]+(ll)dp[i-1]*n)%P;
}
int ans[N];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	inv[1]=1; rep(i,2,k) inv[i]=(ll)inv[P%i]*(P-P/i)%P;
	solve(n-1,k);
	rep(i,0,k) ans[i]=(dp[i]+(i>=2?ans[i-2]:0))%P;
	rep(i,1,k) printf("%d ",ans[i]);
	return 0;
}