#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 /// freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> sol;
    for (int p = 10000; p >= 1; p /= 10) {
      int c = n / p;
      if (c) {
        sol.push_back(p * c);
        n -= p * c;
      }
    }
    cout << (int) sol.size() << "\n";
    for (auto &it : sol) {
      cout << it << " ";
    }
    cout << "\n";
  }
  return 0;
}