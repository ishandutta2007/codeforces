#include <bits/stdc++.h>

using namespace std;

void solve(int n, vector<int> a, vector<int> b) {
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i] && a[i] % b[0] != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    b = a;
    sort(b.begin(), b.end());
    solve(n, a, b);
  }
  return 0;
}