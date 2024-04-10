#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  vector<int> a;
  for (auto &x : s) {
    a.push_back(x);
  }
  for (int i = 0; i + 2 < (int) a.size(); i++) {
    if (a[i + 1] == a[i] + 1 && a[i + 2] == a[i] + 2) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

}