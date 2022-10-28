#include <bits/stdc++.h>
using namespace std;
int cnt[205][2];
int dp[205][5050];
int dp2[205][5050];
bool check[205][5050];
bool check2[205][5050];
int main() {
	int n, k;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		long long int x;
		cin>>x;
		int cnt1=0;
		while(x%5==0){
			x=x/5;
			cnt1++;
		}
		int cnt2=0;
		while(x%2==0){
			x=x/2;
			cnt2++;
		}
		cnt[i][0]=cnt1;
		cnt[i][1]=cnt2;
	}
	dp[1][cnt[0][0]]=cnt[0][1];
	dp[0][0]=0;
	check[0][0]=1;
	check[1][cnt[0][0]]=1;
	dp2[1][cnt[0][0]]=cnt[0][1];
	check2[0][0]=1;
	check2[1][cnt[0][0]]=1;
	
	dp2[0][0]=0;
	for(int i=1; i<n; i++){
		for(int j=0; j<=i+1; j++){
			for(int k=0; k<=5000; k++){
				if(j>0 && k>=cnt[i][0]){
					if(check[j-1][k-cnt[i][0]]){
						dp2[j][k]=max(dp[j][k], dp[j-1][k-cnt[i][0]]+cnt[i][1]);
						check2[j][k]=1;
					}
				}
			}
		}
		for(int j=0; j<=i+1; j++){
			for(int k=0; k<=5000; k++){
				if(dp2[j][k]>dp[j][k]){
					dp[j][k]=dp2[j][k];
				}
				check[j][k]=(check[j][k] || check2[j][k]);
			}
		}
	}
	int ans=0;
	
	for(int i=0; i<=5000; i++){
		ans=max(ans, min(i, dp[k][i]));
	}
	cout<<ans;
	return 0;
}