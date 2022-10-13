#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> order;

  vector<pair<int, int>> stk;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] %= 2;
    if (stk.size() && stk.back().first == a[i]) {
      stk.back().second += 1;
    } else {
      stk.emplace_back(a[i], 1);
    }
    
    while (stk.size() >= 2) {
      if (stk.back().second % 2 == 0) {
        int cnt = stk.back().second;
        stk.pop_back();
        stk.back().second += cnt;
        continue;
      }
      
      if (stk[stk.size() - 2].second % 2 == 0) {
        int cnt = stk.back().second;
        stk.pop_back();
        stk.back().second += cnt;
        stk.back().first ^= 1;
        continue;
      }
      break;
    
    }
  }

  if (stk.size() == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}