#include<iostream>
#include<algorithm>
using namespace std;
long long n,a,b,c,dp[30];
int main(){
  cin>>n>>a>>b>>c;
  for(int i=0;i<30;i++)dp[i]=9999999999;
  dp[n%4]=0;
  for(int i=n%4+1;i<30;i++){
    dp[i]=min(dp[i-1]+a,min(dp[i-2]+b,dp[i-3]+c));
  }
  long long maxn=9999999999;
  for(int i=0;i<30;i+=4)maxn=min(maxn,dp[i]);
  cout<<maxn<<endl;
  return 0;
}