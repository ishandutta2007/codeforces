#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, herr;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> herr;
  cout << n * 3 << "\n";
  for (int i = 0; i < n; i += 2) {
    cout << "1 " << i + 1<< " " << i + 2 << "\n";
    cout << "2 " << i + 1<< " " << i + 2 << "\n";
    cout << "1 " << i + 1<< " " << i + 2 << "\n";
    cout << "1 " << i + 1<< " " << i + 2 << "\n";
    cout << "2 " << i + 1<< " " << i + 2 << "\n";
    cout << "1 " << i + 1<< " " << i + 2 << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}