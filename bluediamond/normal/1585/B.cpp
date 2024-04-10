#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, a[N];

int main() {
  bool isHome;

  isHome = true;
  isHome = false;

  if (isHome) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> stk;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      while (!stk.empty() && stk.back() <= x) {
        stk.pop_back();
      }
      stk.push_back(x);
    }
    cout << (int) stk.size() - 1 << "\n";
  }

  return 0;
}