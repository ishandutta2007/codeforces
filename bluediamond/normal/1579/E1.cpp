#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    deque<int> dq;
    for (auto &x : a) {
      if (dq.empty()) {
        dq.push_back(x);
      } else {
        if (x < dq.front()) {
          dq.push_front(x);
        } else {
          dq.push_back(x);
        }
      }
    }
    for (auto &x : dq) {
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}