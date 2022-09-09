#include <iostream>
using namespace std;
const int SIZE = 1 << 20;
long long dp[SIZE][3];
// 0 , 1  , 2 
void upd(long long &x, long long v) {
  if(x < v) x = v;
}
int main() {
  int n;
  cin >> n;
  dp[0][2] = 0;
  dp[0][0] = dp[0][1] = -1e18;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for(int j = 0 ; j < 3; j++) dp[i][j] = -1e18;
    // 2 to others
    upd(dp[i][2], dp[i - 1][2]);
    upd(dp[i][0], dp[i - 1][2] + x);
    upd(dp[i][1], dp[i - 1][2] - x);
    // 1 to others
    upd(dp[i][2], dp[i - 1][1] + x);
    upd(dp[i][1], dp[i - 1][1]);
    // 0 to others
    upd(dp[i][2], dp[i - 1][0] - x);
    upd(dp[i][0], dp[i - 1][0]);
  }
  cout << dp[n][2] << '\n';
  return 0;
}