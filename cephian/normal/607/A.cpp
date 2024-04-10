#include <iostream>
#include <algorithm>

using namespace std;

int a[100005], b[100005];
pair<int, int> loc[100005];
int dp[100005];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> loc[i].first >> loc[i].second;
  sort(loc+1, loc + n+1);
  for(int i = 1; i <= n; ++i) {
    a[i] = loc[i].first;
    b[i] = loc[i].second;
  }
  dp[0] = 0;
  for(int i = 1; i <= n; ++i) {
    int tgt = a[i] - b[i];
    int lo = 1, hi = i;
    while(lo < hi) {
      int mid = (lo + hi)/2;
      if(a[mid] < tgt) lo = mid+1;
      else hi = mid;
    }
    dp[i] = dp[lo-1] + i - lo;
  }
  int ans = n;
  for(int i = 1; i <= n; ++i)
    ans = min(ans, dp[i] + n - i);
  cout << ans << "\n";
  return 0;
}