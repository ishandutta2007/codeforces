#include <bits/stdc++.h>

using namespace std;

const vector<string> DIGITS = {
"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, k; cin >> n >> k;

  auto trans = [&](string s) {
    int ans = 0;
    for (int i = 0; i < 7; ++i) {
      if (s[i] == '1') 
        ans |= (1 << i);
    }
    return ans;
  };

  vector<int> digits(10);
  for (int i = 0; i < 10; ++i)
    digits[i] = trans(DIGITS[i]);


  vector<int> init(n);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    init[i] = trans(s);
  }

  auto gcost = [&](int i, int target) -> int {
    if ((digits[target] & init[i]) != init[i]) return 1e9;
    return __builtin_popcount(digits[target] ^ init[i]);
  };

  vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));
  dp[n][0] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int target = 0; target <= 9; ++target) {
      int cost = gcost(i, target);
      for (int s = 0; s + cost <= k; ++s) {
        if (dp[i + 1][s]) {
          dp[i][s + cost] = true;
        }
      } 
    }
  }

  if (dp[0][k]) {
    for (int i = 0; i < n; ++i) {
      for (int target = 9; target >= 0; --target) {
        int cost = gcost(i, target);
        if (cost <= k && dp[i + 1][k - cost]) {
          cout << target;
          k -= cost;
          break;
        }
      }
    }
  } else cout << -1 << endl;

  return 0;
}