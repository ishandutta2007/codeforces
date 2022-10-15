/// I'm the President of the United States of America

#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 1e5 + 7;
int n, a[N], cost;
vector<pair<int, int>> history;

void op(int i, int j) {
  cost += (i - j) * (i - j);
  history.push_back({i, j});
  swap(a[i], a[j]);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cost = 0;
    history.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
      a[i] = i;
    }
    op(1, n);
    for (int i = 2; i < n; i++) {
      if (i - 1 > n - i) {
        op(i, 1);
      } else {
        op(i, n);
      }
    }
    reverse(history.begin(), history.end());
    cout << cost << "\n";
    for (int i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
    cout << n - 1 << "\n";
    for (auto &it : history) {
      cout << it.first << " " << it.second << "\n";
    }
  }

}