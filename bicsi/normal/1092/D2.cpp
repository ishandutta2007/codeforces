#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> order;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    order.emplace_back(a[i], i);
  }
  
  vector<int> lft(n), rgt(n);
  for (int i = 0; i < n; ++i) {
    lft[i] = i;
    rgt[i] = i;
  }

  sort(order.begin(), order.end());
  for (auto p : order) {
    int pos = p.second;
    int l = lft[pos], r = rgt[pos];
    int h = p.first;

    if (l == 0 && r == n - 1) {
      cout << "YES" << endl;
      return 0;
    }
    
    bool to_the_left = true;
    if (l == 0) to_the_left = false;
    else {
      if (r < n - 1 && a[r + 1] < a[l - 1])
        to_the_left = false;
    }
    
    if (to_the_left) {
      int delta = a[l - 1] - h;
      if (delta > 0 && (r - l + 1) % 2 == 1) {
        cout << "NO" << endl;
        return 0;
      }
      rgt[l - 1] = r;
    } else {
      int delta = a[r + 1] - h;
      if (delta > 0 && (r - l + 1) % 2 == 1) {
        cout << "NO" << endl;
        return 0;
      }
      lft[r + 1] = l;
    }
  }

  return 0;
}