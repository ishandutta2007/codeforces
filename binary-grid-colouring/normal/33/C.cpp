#include<bits/stdc++.h>
using namespace std;
int dp1[100010];
int dp2[100010];
int a[100010];
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    std::cin >> a[i];
  }
  dp1[0] = 0;
  int sum = 0;

  for(int i=1;i<=n;i++) {
     sum += a[i];
     dp1[i] = dp1[i-1] + a[i];
     if(dp1[i] < -sum){
       dp1[i] = -sum;
     }
  }
  // for(int i=1;i<=n;i++){
  //   std::cout << i<< " " << dp1[i]<< '\n';
  // }
  // std::cout << '\n';
  dp2[n+1] = 0;
  sum = 0;
  for(int i=n;i>=1;--i){
    sum += a[i];
    dp2[i] = dp2[i+1] + a[i];
    if(dp2[i] < -sum){
      dp2[i] = -sum;
    }
  }
  // for(int i=n;i>=1;i--){
  //   cout<<i<<" "<<dp2[i]<<endl;
  // }
  int ans = 0;
  for(int i=1;i<=n+1;i++) {
    ans = max(ans,dp1[i-1]+dp2[i]);
  }
  std::cout << ans << '\n';
  return 0;
}