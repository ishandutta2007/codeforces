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
    cout << (n % 10 - 1) * 10 + (n >= 1) + (n >= 10) * 2 + (n >= 100) * 3 + (n >= 1000) * 4 << "\n";
  }
}