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
    vector<int> fun(n);
    for (int i = 0; i < n; i++) {
      cin >> fun[i];
    }
    if (fun[0] < fun[n - 1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}