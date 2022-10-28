#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
int arr[5005];
int lo[5005];
int dp[5005][5005][2];
pair<int, int> st[5005][15];

int mini(int l, int r){
	int j=lo[r-l+1];
	
	if(st[l][j].f<st[r - (1 << j) + 1][j].f){
		return st[l][j].s;
	}
	else{
		return st[r - (1 << j) + 1][j].s;
	}
}

int fun(int l, int r, int t){
	if(l>r){
		return 0;
	}
	if(dp[l][r][t]!=-1){
		return dp[l][r][t];
	}
	int ind=mini(l, r);
	dp[l][r][t]=(r-l+1);
	if(t==0){
		if(arr[ind]==arr[l-1]){
			dp[l][r][t]=min(dp[l][r][t], fun(l, ind-1, 1)+fun(ind+1, r, 0));
		}
		else{
			dp[l][r][t]=min(dp[l][r][t], (arr[ind]-arr[l-1])+fun(l, ind-1, 1)+fun(ind+1, r, 0));
		}
	}
	else{
		if(arr[ind]==arr[r+1]){
			dp[l][r][t]=min(dp[l][r][t], fun(l, ind-1, 1)+fun(ind+1, r, 0));
		}
		else{
			dp[l][r][t]=min(dp[l][r][t], (arr[ind]-arr[r+1])+fun(l, ind-1, 1)+fun(ind+1, r, 0));
		}
	}
	return dp[l][r][t];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;

	lo[1]=0;
	for(int i=2; i<5005; i++){
		lo[i]=(1+lo[i/2]);
	}
	arr[0]=0;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}

	for(int i=0; i<=n; i++){
		st[i][0]={arr[i], i};
	}
	
	for (int j = 1; j < 15; j++){
		 for (int i = 0; i + (1 << j) <= (n+1); i++){
		 	if((st[i][j-1].f)<(st[i + (1 << (j - 1))][j - 1].f)){
		 		st[i][j]=st[i][j-1];
		 	}
		 	else{
		 		st[i][j]=st[i + (1 << (j - 1))][j - 1];
		 	}
		 }
	}
	for(int i=0; i<5005; i++){
		for(int j=0; j<5005; j++){
			for(int k=0; k<2; k++){
				dp[i][j][k]=-1;
			}
		}
	}
	

	cout<<fun(1, n, 0)<<endl;
	return 0;
}