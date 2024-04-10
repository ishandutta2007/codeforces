#include <bits/stdc++.h>

using namespace std;

long long Solve(long long n) {
  if (n == 0) return 0;
  if (n % 2 == 1) return 1 - Solve(n - 1);
  else if (n <= 8 || n % 4 == 2) {
    return n / 2 - Solve(n / 2);
  } else return 1 - Solve(n - 1);
}

void Test() {
  int N = 10000;
  vector<int> dp(N, 0);
  for (int i = 1; i < N; ++i) {
    if (i % 2 == 1) dp[i] = 1 - dp[i - 1];
    else {
      dp[i] = max(1 - dp[i - 1], i / 2 - dp[i / 2]);
    }
  }

  for (int i = 1; i < N; ++i)
    assert(dp[i] == Solve(i));

  for (int i = 1; i <= 10; ++i)
    cout << dp[i] << " ";
  cout << endl;

  exit(0);
}

int main() {
  // Test();
  
  int t; cin >> t;
  while (t--) {
    long long n; cin >> n; 
    long long delta = Solve(n);
    // a - b == delta a + b == n
    // delta + n
    cout << (delta + n) / 2 << endl;
  }
}