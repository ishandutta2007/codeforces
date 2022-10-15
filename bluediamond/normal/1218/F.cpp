#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n, k, x[N], gain, cost[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x[i];
  cin >> gain;
  for (int i = 1; i <= n; i++) cin >> cost[i];
  multiset<int> costs;
  ll pay = 0;
  for (int i = 1; i <= n; i++) {
    costs.insert(cost[i]);
    while (k < x[i]) {
      if (costs.empty()) {
        cout << "-1\n";
        return 0;
      }
      k += gain;
      pay += *costs.begin();
      costs.erase(costs.begin());
    }
  }
  cout << pay << "\n";
}