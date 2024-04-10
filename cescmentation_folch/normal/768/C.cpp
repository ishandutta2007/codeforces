#include<bits/stdc++.h>
using namespace std;

int main(){
  int x,k,n;
  cin >> n >> k >> x;
  vector<vector<int> > dp(2,vector<int> (1050,0));
  int mn = 1033, mx = 0;
  for(int i = 0; i < n; ++i){
      int a;
      cin >> a;
      dp[0][a]++;
  }
  for(int i = 0; i < k; ++i){
    int change = 0;
    for(int j = 0; j < 1024; ++j){
      if(change){
	dp[(i+1)%2][j^x] += (dp[i%2][j])/2;
	dp[(i+1)%2][j] += (dp[i%2][j]+1)/2;
	if(dp[i%2][j] % 2){
	  change = 0;
	}
	dp[i%2][j] = 0;
      }
      else{
	dp[(i+1)%2][j] += (dp[i%2][j])/2;
	dp[(i+1)%2][j^x] += (dp[i%2][j]+1)/2;
	if(dp[i%2][j] % 2){
	  change = 1;
	}
	dp[i%2][j] = 0;
      }
    }
  }
  for(int i = 0; i < 1024; ++i){
    if(dp[k%2][i]){
      mn = min(mn,i);
      mx = i;
    }
  }
   cout << mx << ' ' << mn << endl;
}