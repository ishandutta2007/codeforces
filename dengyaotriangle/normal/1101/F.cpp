#include<bits/stdc++.h>

using namespace std;

const int maxn=405;

int n;
long long dp[maxn][maxn][2];
long long a[maxn];
vector<pair<pair<int,int>,int> >v[maxn];

int main(){
	ios::sync_with_stdio(0);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j][0]=a[j]-a[i];
		}
	}
	while(m--){
		int s,t,c,q;
		cin>>s>>t>>c>>q;
		v[q].push_back(make_pair(make_pair(s,t),c)); 
	}
	long long ans=0;
	for(int sk=1;sk<=n+1;sk++){
		int k=sk&1;
		for(int i=0;i<v[sk-1].size();i++){
			ans=max(ans,dp[v[sk-1][i].first.first][v[sk-1][i].first.second][k^1]*v[sk-1][i].second);
		} 
		for(int i=1;i<=n;i++){
			int cp=i;
			for(int j=i;j<=n;j++){
				dp[i][j][k]=dp[i][j][k^1];
				while(cp<j&&dp[i][cp+1][k^1]<=a[j]-a[cp+1])cp++;
				dp[i][j][k]=min(dp[i][j][k],max(dp[i][cp][k^1],a[j]-a[cp]));
				if(cp<j)dp[i][j][k]=min(dp[i][j][k],max(dp[i][cp+1][k^1],a[j]-a[cp+1]));
			}
		}
	}
	cout<<ans;
	/*
	for(int k=0;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				cout<<k<<i<<j<<' '<<dp[i][j][k]<<endl;
			}
		}
	}*/
	return 0;
}