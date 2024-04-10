#include <bits/stdc++.h>

using namespace std;

#define int long long
bool home = 1;
const int N=(int)1e6+7;
int n,dp[N],mx[N],par[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
    //freopen ("testing place","w",stdout);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n;
  int sol=0;
  for (int i=2;i<=n+1;i++){
    cin>>par[i];
    dp[i]=1;
    int a=i;
    while (par[a]!=1){
      int p=par[a],bef=dp[p];
      if (mx[p]==a){
        dp[p]=max(dp[p],dp[a]);
      }else{
        if (dp[a]>dp[mx[p]]){
          mx[p]=a;
          dp[p]=dp[a];
        }else{
          dp[p]=max(dp[p],dp[a]+1);
        }
      }
      if (bef==dp[p])break;
      a=p;
    }
    sol=max(sol,dp[a]);
    cout<<sol<<" ";
  }
  cout<<"\n";
  return 0;
}