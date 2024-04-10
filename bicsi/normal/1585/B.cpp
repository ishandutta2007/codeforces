#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> stk;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      while (stk.size() && stk.back() <= x)
        stk.pop_back();
      stk.push_back(x);
    }
    cout << stk.size() - 1 << '\n';
  }

  return 0;
}