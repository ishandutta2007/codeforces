#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int mod=998244353,N=510;
int n,m,a[N],st[N][12],g[N][12],dp[N][N];
int solve(int l,int r){
	if(dp[l][r])return dp[l][r];
	if(l>r)return 1;
	LL r1=0,r2=0;
	int pos,lo=log2(r-l+1);
	if(st[l][lo]<st[r-(1<<lo)+1][lo])pos=g[l][lo];
	else pos=g[r-(1<<lo)+1][lo];
	for(int i=l;i<=pos;i++)r1+=1ll*solve(l,i-1)*solve(i,pos-1)%mod;
	for(int i=pos;i<=r;i++)r2+=1ll*solve(pos+1,i)*solve(i+1,r)%mod;
	r1%=mod;r2%=mod;
	return dp[l][r]=1ll*r1*r2%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),st[i][0]=a[i],g[i][0]=i;
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			int y=j+(1<<(i-1));
			if(st[j][i-1]<st[y][i-1])g[j][i]=g[j][i-1];
			else g[j][i]=g[y][i-1];
			st[j][i]=min(st[j][i-1],st[y][i-1]);
		}
	}
	printf("%d\n",solve(1,n));
	return 0;
}