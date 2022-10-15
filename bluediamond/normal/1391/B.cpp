#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, sol = 0;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
      string s;
      cin >> s;
      sol += (s.back() == 'R');
    }
    string s;
    cin >> s;
    for (int i = 0; i < m - 1; i++) {
      sol += (s[i] == 'D');
    }
    cout << sol << "\n";
  }
  return 0;
}