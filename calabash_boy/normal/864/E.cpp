#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxd = 3005;
int t[maxn],d[maxn],p[maxn],rk[maxn];
int dp[maxn][maxd],pre[maxn][maxd];
int n;
const int INF = 0x3f3f3f3f;
bool cmp(int x,int y){
	return d[x]<d[y];
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>t[i]>>d[i]>>p[i];
		rk[i]=i;
	}
	sort(rk+1,rk+n+1,cmp);
	int k=1;
	memset(dp,0,sizeof dp);
	for (int i=1;i<=n;i++){
		k=i;
		memcpy(dp[k],dp[k-1],sizeof dp[k]);
		int x = rk[i];
		for (int j=1;j<=d[x]-t[x];j++){
			dp[k][j+t[x]-1] = max(dp[k-1][j+t[x]-1],dp[k-1][j-1]+p[x]);
			if (dp[k-1][j+t[x]-1]<dp[k-1][j-1]+p[x]){
				pre[k][j+t[x]-1] =1;
			}
		}
//		cout<<"_____________  "<<i<<"  _________"<<endl;
//		for (int i=0;i<=100;i++){
//			printf("dp[%d]=%d\n",i,dp[k][i]);
//		}
	}
	int mx =0;
	int now =-1;
	for (int i=1;i<maxd;i++){
		if (dp[n][i]>mx){
			mx = dp[n][i];
			now =i;
		}
	}
	cout<<dp[n][now]<<endl;
	vector<int> ans;
	for (int i=n;i>=1;i--){
		if (pre[i][now]){
			now -= t[rk[i]];
			ans.push_back(rk[i]);
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for (int val:ans){
		cout<<val<<" ";
	} 
	cout<<endl;
	return 0;
}