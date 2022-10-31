#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n; cin >> n;
  long long tag[n], score[n], dp[n];
  for(int i = 0; i<n; i++) cin >> tag[i];
  for(int i = 0; i<n; i++) cin >> score[i], dp[i] = 0;
  long long ans = 0;
  for(int i = 0; i<n; i++){
    for(int j = i-1; j >= 0; j--){
      if(tag[j] != tag[i]){
        long long t1 = dp[i], t2 = dp[j];
        dp[i] = max(dp[i], t2 + abs(score[i]-score[j]));
        dp[j] = max(dp[j], t1 + abs(score[i]-score[j]));
        ans = max({ans, dp[i], dp[j]});
      }
    }
  }
  cout << ans << endl;
}

int main() {
  // freopen("a.in", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while(t--) solve();
}