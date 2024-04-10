#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;

const int INF = (int)1e9 + 7;

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int n, k;
  cin >> n >> k;

  vector<int> dp(2 * n + 2, INF);

  dp[n] = 0;

  int last = 0;
  for (int i = 1; i <= k; i++) {
    int l, r;
    cin >> l >> r;
    int dif = l - last;

    {
      vector<int> ndp(2 * n + 2, INF);
      for (int j = 0; j + dif <= 2 * n + 1; j++) {
        ndp[j + dif] = min(ndp[j + dif], dp[j]);
      }
      dp = ndp;
    }
    dif = r - l;
    {
      vector<int> ndp(2 * n + 2, INF);

      for (int j = 0; j + dif <= 2 * n + 1; j++) {
        ndp[j + dif] = min(ndp[j + dif], dp[j]);
      }

      deque<int> d;
      int r = 0;


      for (int j = 2 * n + 1; j >= 0; j--) {
        int L = max(0, dif - 2 * dif + 2 * n - j), R = min(2 * n + 1, dif + 2 * n - j);
        while (r <= R) {
          while (!d.empty() && dp[r] <= dp[d.back()])d.pop_back();
          d.push_back(r);
          r++;
        }
        while (!d.empty() && d.front() < L) {
          d.pop_front();
        }
        if (!d.empty()) {

          int mn = dp[d.front()];
          ndp[j] = min(ndp[j], 1 + mn);
        }
      }
      dp = ndp;
    }
    {
      vector<int> ndp = dp;
      for (int j = -n; j <= +n; j++) {

        ndp[-j + n] = min(ndp[-j + n], dp[j + n] + 1);
      }
      dp = ndp;
    }

    last = r;
  }
  {
    int dif = 2 * n - last;

    {
      vector<int> ndp(2 * n + 2, INF);
      for (int j = 0; j + dif <= 2 * n + 1; j++) {
        ndp[j + dif] = dp[j];
      }
      dp = ndp;
    }
  }

  if (dp[n] == INF) {
    cout << "Hungry\n";
    return 0;
  }
  cout << "Full\n";
  cout << dp[n] << "\n";
}