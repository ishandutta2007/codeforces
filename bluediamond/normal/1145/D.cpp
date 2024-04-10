#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int __min = v[n - 1];
  for (int i = 0; i + 1 < n; i++) {
    __min = min(__min, v[i]);
  }
  cout << 2 + (v[2] ^ __min) << "\n";
}