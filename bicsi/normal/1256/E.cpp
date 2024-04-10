#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end());

  vector<long long> dp(n + 1, 4e18);
  vector<int> last(n + 1, -1);
  dp[0] = 0;

  for (int i = 0; i <= n; ++i) {
    for (int j = 3; j <= 10; ++j) {
      if (i - j >= 0) {
        long long now = v[i - 1].first - v[i - j].first + dp[i - j];
        if (dp[i] > now) {
          dp[i] = now;
          last[i] = i - j;
        }
      }
    }
  }

  vector<int> team(n, -1);
  int teams = 0;

  int i = n;
  while (i > 0) {
    for (int t = last[i]; t < i; ++t)
      team[v[t].second] = teams;
    ++teams;
    i = last[i];
  }

  cout << dp[n] << " " << teams << endl;
  for (int i = 0; i < n; ++i)
    cout << team[i] + 1 << " ";
  cout << endl;
  
  return 0;
}