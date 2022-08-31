/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    vector<int> nxt(n, n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i] == a[j]) {
          nxt[i] = j;
          break;
        }
      }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int sz = 2; sz <= n; ++sz) {
      for (int l = 0, r = l + sz - 1; r < n; ++l, ++r) {
        dp[l][r] = dp[l + 1][r];
        int x = nxt[l];
        while (x <= r) {
          dp[l][r] = max(dp[l][r], 1 + dp[l + 1][x - 1] + dp[x][r]);
          x = nxt[x];
        }
      }
    }
    cout << (n - 1) - dp[0][n - 1] << '\n';
  }
}