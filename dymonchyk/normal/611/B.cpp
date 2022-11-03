#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long calc(long long n) {
  vector<int> v;
  while (n > 0) {
    v.push_back(n & 1);
    n >>= 1;
  }
  reverse(v.begin(), v.end());

  long long dp[66][2][2][66] = {0};
  dp[0][0][0][0] = 1;
  for (int i = 0; i < v.size(); ++i) {
    for (int ls = 0; ls < 2; ++ls) {
      for (int ho = 0; ho < 2; ++ho) {
        for (int zr = 0; zr < 64; ++zr) {
          for (int d = 0; d <= (ls ? 1 : v[i]); ++d) {
            dp[i + 1][ls || (d < v[i])][ho || (d == 1)][zr + (ho ? d == 0 : 0)]
                += dp[i][ls][ho][zr];
          }
        }
      }
    }
  }

  return dp[v.size()][0][1][1] + dp[v.size()][1][1][1];
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << calc(b) - calc(a - 1) << endl;
  return 0;
}