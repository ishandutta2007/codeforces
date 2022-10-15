#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) {
      cin >> x;
    }
    set<int> s;
    for (auto &x : p) {
      for (auto &x2 : p) {
        s.insert(abs(x - x2));
      }
    }
    cout << (int) s.size() - 1 << "\n";
  }
}