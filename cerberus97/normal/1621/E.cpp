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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> b(m);
    for (auto& i : b) {
      int k; cin >> k;
      i.resize(k);
      for (auto& j : i) {
        cin >> j;
      }
    }
    auto min_teacher = [&](ll num, int den) {
      if (den == 0) {
        return 0;
      }
      int cl = (num + den - 1) / den;
      auto it = lower_bound(a.begin(), a.end(), cl);
      return int(it - a.begin()) + 1;
    };
    vector<int> f(n + 2, 0);
    vector<ll> sum(m);
    for (int i = 0; i < m; ++i) {
      sum[i] = accumulate(b[i].begin(), b[i].end(), 0ll);
      int p = min_teacher(sum[i], int(b[i].size()));
      --f[p];
    }
    int cur = 0;
    for (int i = n + 1; i >= 1; --i) {
      cur += f[i];
      f[i] = cur;
    }
    int min_neg = n + 2, max_neg = 0;
    bool ok = true;
    for (int i = 1; i <= n + 1; ++i) {
      f[i] += (n - i + 1);
      if (f[i] < -1) {
        ok = false;
      } else if (f[i] == -1) {
        min_neg = min(min_neg, i);
        max_neg = i;
      }
    }
    vector<int> nxt_zero(n + 3, n + 3);
    for (int i = n + 1; i >= 1; --i) {
      nxt_zero[i] = (f[i] == 0 ? i : nxt_zero[i + 1]);
    }
    string ans;
    for (int i = 0; i < m; ++i) {
      int old_p = min_teacher(sum[i], int(b[i].size()));
      for (auto& val : b[i]) {
        int p = min_teacher(sum[i] - val, int(b[i].size()) - 1);
        bool check = (min_neg == n + 2);
        if (p > old_p) {
          check &= (nxt_zero[old_p + 1] > p);
        }
        if (p < old_p) {
          check |= (p < min_neg and max_neg <= old_p);
        }
        if (ok and check) {
          ans += '1';
        } else {
          ans += '0';
        }
      }
    }
    cout << ans << '\n';
  }
}