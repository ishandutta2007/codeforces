#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    vector<int> a(n),dp(n);
    for (auto &x:a)cin>>x;
    int b=0;
    for (int i=n-1;i>=0;i--) {
      dp[i]=a[i];
      if (i+a[i]<n)dp[i]+=dp[i+a[i]];
      b=max(b,dp[i]);
    }
    cout<<b<<"\n";
  }

}