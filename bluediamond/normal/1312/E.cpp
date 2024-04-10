#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500 + 7;
int n;
int a[N];
bool ok[N][N];
int dp[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    vector<int> stk;
    for (int j = i; j <= n; j++) {
      stk.push_back(a[j]);
      while ((int) stk.size() >= 2 && stk[(int) stk.size() - 1] == stk[(int) stk.size() - 2]) {
        stk.pop_back();
        stk.back()++;
      }
      if ((int) stk.size() >= 2 && stk[(int) stk.size() - 2] < stk[(int) stk.size() - 1]) {
        break;
      }
      ok[i][j] = ((int) stk.size() == 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = n;
    for (int j = 1; j <= i; j++) {
      if (ok[j][i]) {
        dp[i] = min(dp[i], dp[j - 1] + 1);
      }
    }
  }
  cout << dp[n] << "\n";
}