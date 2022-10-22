#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e3+5;
int n,k;
ll dp[15][N];
ll ans;
vector<ll> a[N];
int sz[N];
void solve(int id,int l,int r){
	int i,j;
	if(l==r){
		for(i=0;i<=k;i++)
			ans=max(ans,dp[id][i]+a[l][min(sz[l],k-i)]);
		return;
	}
	int mid=l+r>>1;
	memcpy(dp[id+1],dp[id],sizeof(dp[id]));
	for(i=l;i<=mid;i++){
		for(j=k;j>=sz[i];j--)
			dp[id+1][j]=max(dp[id+1][j],dp[id+1][j-sz[i]]+a[i][sz[i]]);
	}
	solve(id+1,mid+1,r);
	memcpy(dp[id+1],dp[id],sizeof(dp[id]));
	for(i=mid+1;i<=r;i++){
		for(j=k;j>=sz[i];j--)
			dp[id+1][j]=max(dp[id+1][j],dp[id+1][j-sz[i]]+a[i][sz[i]]);
	}
	solve(id+1,l,mid);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	memset(dp,0xf3,sizeof(dp));
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>sz[i];
		a[i].resize(sz[i]+1);
		for(j=1;j<=sz[i];j++){
			cin>>a[i][j];
			a[i][j]+=a[i][j-1];
		}
	}
	dp[0][0]=0;
	solve(0,1,n);
	cout<<ans;
	return 0;
}