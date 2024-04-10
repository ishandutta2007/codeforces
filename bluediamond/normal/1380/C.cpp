#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int) 1e5+7;
int n, dp[N];
ll x,a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    cin>>n>>x;
    for (int i=1;i<=n;i++) {
      cin>>a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    /// consecutive with some skips
    for (int i=1;i<=n;i++) {
      /// a[i]*len>=x
      ll len;
      if (x%a[i]==0) {
        len=x/a[i];
      } else {
        len=x/a[i]+1;
      }
      dp[i]=dp[i-1];
      if (i-len>=0) dp[i]=max(dp[i],dp[i-len]+1);
    }
    cout<<dp[n]<<"\n";
  }
  return 0;
}