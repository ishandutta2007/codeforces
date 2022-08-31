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
    vector<int> a(n), b(n);
    int sum = 0, sq_sum = 0;
    for (auto& i : a) {
      cin >> i;
      sum += i;
      sq_sum += i * i;
    }
    for (auto& i : b) {
      cin >> i;
      sum += i;
      sq_sum += i * i;
    }
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
      vector<bool> nxt(sum + 1, false);
      for (int s = sum; s >= 0; --s) {
        if (dp[s]) {
          nxt[s + a[i]] = true;
          nxt[s + b[i]] = true;
        }
      }
      dp = nxt;
    }
    int ans = sq_sum * (n - 2);
    for (int i = sum / 2; i >= 0; --i) {
      if (dp[i]) {
        ans += i * i + (sum - i) * (sum - i);
        break;
      }
    }
    cout << ans << '\n';
  }
}