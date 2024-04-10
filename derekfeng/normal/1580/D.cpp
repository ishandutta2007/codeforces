#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s[2][4004],a[4004],rt,sz[4004];
ll dp[4004][4004];
int built(int l,int r){
	if(r<l)return 0;
	int f=l;
	for(int i=l+1;i<=r;i++)if(a[i]<a[f])f=i;
	s[0][f]=built(l,f-1),s[1][f]=built(f+1,r);
	sz[f]=r-l+1;
	return f;
}
void getdp(int x){
	if(s[0][x])getdp(s[0][x]);
	if(s[1][x])getdp(s[1][x]);
	for(int i=0;i<2;i++)
		for(int j=0;j<=sz[s[0][x]];j++)for(int k=0;k<=sz[s[1][x]];k++)
			dp[x][i+j+k]=max(dp[x][i+j+k],dp[s[0][x]][j]+dp[s[1][x]][k]+(ll)i*m*a[x]-2ll*j*k*a[x]-(ll)a[x]*i*(2ll*(j+k)+1));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1e18;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	rt=built(1,n);
	getdp(rt);
	printf("%I64d",dp[rt][m]);
}