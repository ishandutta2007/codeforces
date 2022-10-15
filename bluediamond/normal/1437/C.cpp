#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    vector<int> dp(2 * n + 13, 0);
    for (auto &x : a) {
      vector<int> dp2(2 * n + 13, INF);
      int mx = INF;
      for (int j = 0; j <= 2 * n + 7; j++) {
        dp2[j] = mx + abs(j - x);
        mx = min(mx, dp[j]);
      }
      dp = dp2;
    }
    int sol = INF;
    for (auto &v : dp) {
      sol = min(sol, v);
    }
    cout << sol << "\n";
  }

}