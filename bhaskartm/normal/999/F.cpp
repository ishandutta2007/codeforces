#include <bits/stdc++.h>
using namespace std;
#define int long long int
int cnt[100005];
int ppl[100005];
main() {
	int n, k;
	cin>>n>>k;
	int dp[n+1][n*k+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n*k; j++){
			dp[i][j]=-1;
		}
	}
	int num[k*n];
	for(int i=0; i<k*n; i++){
		cin>>num[i];
		cnt[num[i]]++;
	}
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		ppl[x]++;
	}
	int h[k+1];
	h[0]=0;
	for(int i=1; i<=k; i++){
		cin>>h[i];
	}
	dp[1][0]=0;
	for(int i=1; i<=k; i++){
		dp[1][i]=h[i];
	}
	
	for(int i=2; i<=n; i++){
		for(int j=0; j<=n*k; j++){
			for(int t=0; t<=k; t++){
				if(dp[i-1][j-t]!=-1 && j>=t){
					dp[i][j]=max(dp[i][j], dp[i-1][j-t]+h[t]);
				}
			}
		}
	}
	
	int ans=0;
	for(int i=1; i<=100000; i++){
		if(ppl[i]==0){
			continue;
		}
		ans+=dp[ppl[i]][min(k*ppl[i], cnt[i])];
	}
	cout<<ans;
	return 0;
}