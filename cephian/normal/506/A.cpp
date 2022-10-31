#include <iostream>

using namespace std;

int n, d, offs;
int dp[30001][400];
int gem[30001]={0};

int solve(int island, int jump) {
  if(island > 30000) return 0;
  int j = jump - offs;
  if(dp[island][j] == -1) {
    int ans = max(solve(island+jump, jump), solve(island+jump+1, jump+1));
    if(jump > 1)
      ans = max(ans, solve(island+jump-1, jump-1));
    dp[island][j] = ans + gem[island];
  }
  return dp[island][j];
}

int minjump(int d) {
  int l = d+1;
  int isl = 0;
  while(isl <= 30000) {
    l = max(l-1, 1);
    isl += l;
  }
  return l;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> d;
  for(int i = 0; i <= 30000; ++i)
    fill(dp[i], dp[i]+ 400, -1);
  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    ++gem[t];
  }
  offs = minjump(d);
  cout << solve(d, d) << "\n";

  return 0;
}