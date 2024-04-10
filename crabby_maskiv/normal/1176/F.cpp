#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
vector<ll> v[5];
ll a[N][5],b[N][5];
ll dp[N][15];
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	memset(dp,-1,sizeof(dp));
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	cin>>n;
	dp[0][0]=0;
	for(i=1;i<=n;i++){
		int k;cin>>k;
		for(j=1;j<=3;j++) v[j].clear();
		while(k--){
			ll x,y;cin>>y>>x;
			v[y].push_back(x);
		}
		for(j=1;j<=3;j++) sort(v[j].begin(),v[j].end(),cmp);
		if(v[1].size()>=3){
			a[i][3]=max(a[i][3],v[1][0]+v[1][1]+v[1][2]);
			b[i][3]=max(b[i][3],v[1][0]*2+v[1][1]+v[1][2]);
		}
		if(v[2].size()&&v[1].size()){
			a[i][2]=max(a[i][2],v[1][0]+v[2][0]);
			b[i][2]=max(b[i][2],max(v[1][0],v[2][0])+v[1][0]+v[2][0]);
		}
		if(v[3].size()){
			a[i][1]=max(a[i][1],v[3][0]);
			b[i][1]=max(b[i][1],v[3][0]*2);
		}
		if(v[2].size()){
			a[i][1]=max(a[i][1],v[2][0]);
			b[i][1]=max(b[i][1],v[2][0]*2);
		}
		if(v[1].size()>=2){
			a[i][2]=max(a[i][2],v[1][0]+v[1][1]);
			b[i][2]=max(b[i][2],v[1][0]*2+v[1][1]);
		}
		if(v[1].size()){
			a[i][1]=max(a[i][1],v[1][0]);
			b[i][1]=max(b[i][1],v[1][0]*2);
		}
	}
	for(i=1;i<=n;i++){
		for(j=9;j>=0;j--){
			dp[i][j]=dp[i-1][j];
			for(int k=1;k<=3;k++){
				if(a[i][k]==-1) continue;
				if(j<k){
					if(dp[i-1][j-k+10]==-1) continue;
					dp[i][j]=max(dp[i][j],dp[i-1][j-k+10]+b[i][k]);
				}
				else{
					if(dp[i-1][j-k]==-1) continue;
					dp[i][j]=max(dp[i][j],dp[i-1][j-k]+a[i][k]);
				}
			}
		}
	}
	ll ans=0;
	for(i=0;i<10;i++) ans=max(ans,dp[n][i]);
	cout<<ans;
	return 0;
}