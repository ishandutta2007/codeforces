#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n, k;
	cin>>n>>k;
	long long int a[n];
	long long int b[n];
	long long int ans1=0;
	long long int ans2=0;
	long long int xy=k;
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i];
		ans1+=a[i];
		ans2+=b[i];
	}
	if(ans1%k==0 || ans2%k==0){
		cout<<(ans1/k)+(ans2/k)<<endl;
		return 0;
	}
	long long int x=ans1%k;
	
	bool booly=false;
	bool dp[k][n+1];
	for(int i=0; i<k; i++){
		for(int j=0; j<=n; j++){
			dp[i][j]=false;
		}
	}
	for(int i=0; i<=n; i++){
		dp[0][i]=true;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<k; j++){
			if(dp[j][i-1]){
				dp[j][i]=true;
			}
		}
		for(int j=0; j<=min(xy, a[i-1]); j++){
			
			if(b[i-1]+j>=k){
				
				for(int l=0; l<k; l++){
					dp[(l+j)%k][i]=(dp[l][i-1] || dp[(l+j)%k][i-1] || dp[(l+j)%k][i]);
					
				}
			}
		}
		
		
	}
	
	if(dp[x][n]){
		booly=true;
	}
	
	long long int y=ans2%k;
	for(int i=0; i<k; i++){
		for(int j=0; j<=n; j++){
			dp[i][j]=false;
		}
	}
	for(int i=0; i<=n; i++){
		dp[0][i]=true;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<k; j++){
			if(dp[j][i-1]){
				dp[j][i]=true;
			}
		}
		for(int j=0; j<=min(xy, b[i-1]); j++){
			if(a[i-1]+j>=k){
				for(int l=0; l<k; l++){
					dp[(l+j)%k][i]=(dp[l][i-1] || dp[(l+j)%k][i-1]);
				}
			}
		}
		
		
	}
	if(dp[y][n-1]){
		booly=true;
	}
	
	if(!booly){
		cout<<(ans1/k)+(ans2/k);
	}
	else{
		cout<<(ans1+ans2)/k;
	}
	return 0;
}