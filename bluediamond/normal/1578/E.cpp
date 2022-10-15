#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, l;
  cin >> n >> l;
  vector<pair<string, int>> a(n);
  n = 0;
  for (auto &x : a) {
    cin >> x.first;
    x.second = ++n;
  }
  for (int i = 1; i < l; i += 2) {
    for (auto &x : a) {
      x.first[i] *= -1;
    }
  }
  sort(a.begin(), a.end());
  for (int i = 1; i < l; i += 2) {
    for (auto &x : a) {
      x.first[i] *= -1;
    }
  }
  for (auto &x : a) {
    cout << x.second << " ";
  }
  cout << "\n";

  return 0;
}