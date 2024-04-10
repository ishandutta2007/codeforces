#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home = 1;
#define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
      int num = 1;
      for (int j = 1; j <= x; j++) {
        num *= 10;
      }
      x = num;
    }

    reverse(a.begin(), a.end());

    function<int(int)> require = [&] (int value) {
      int sol = 0;
      for (auto &x : a) {
        sol += value / x;
        value %= x;
      }
      return sol;
    };

    vector<int> coefs;
    int value = 0, cur = 1;
    while (require(value) <= k) {
      value = value * 10 + 9;
      coefs.push_back(cur);
      cur *= 10;
    }

    reverse(coefs.begin(), coefs.end());

    for (auto &pt : coefs) {
      while (require(value - pt) > k) {
        value -= pt;
      }
    }

    cout << value << "\n";
  }
  return 0;
}