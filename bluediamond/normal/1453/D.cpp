#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    if (n % 2 == 1) {
      cout << "-1\n";
    } else {
      vector<int> ret;
      for (int bit = 60; bit >= 2; bit--) {
        while ((1LL << bit) - 2 <= n) {
          ret.push_back(1);
          for (int j = 2; j < bit; j++) {
            ret.push_back(0);
          }
          n -= ((1LL << bit) - 2);
        }
      }
      cout << (int) ret.size() << "\n";
      for (auto &x : ret) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }

}