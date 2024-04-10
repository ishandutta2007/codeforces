#include <bits/stdc++.h>

using namespace std;

const int N = 26;
int n, f[N], g, sg[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    g = __gcd(g, f[i]);
  }

  for (int p = g; p >= 1; p--) { /// As many parts as possible
    if (g % p) continue;

    for (int i = 0; i < n; i++) {
      sg[i] = f[i] / p;
    }

    string sol;

    if (p % 2 == 1) {
      /// every single one is a palindrome
      vector<int> odds;
      for (int i = 0; i < n; i++) {
        if (sg[i] & 1) {
          odds.push_back(i);
        }
      }
      if ((int) odds.size() > 1) {
        continue;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < sg[i] / 2; j++) {
          sol += (char) ('a' + i);
        }
      }
      for (int i = 0; i < n; i++) {
        if (sg[i] & 1) {
          sol += (char) ('a' + i);
        }
      }
      for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < sg[i] / 2; j++) {
          sol += (char) ('a' + i);
        }
      }

    } else {
      /// consecutive parts are the reversed of each other
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < sg[i]; j++) {
          sol += (char) ('a' + i);
        }
      }
    }
    cout << p << "\n";
    for (int i = 1; i <= p; i++) {
      cout << sol;
      reverse(sol.begin(), sol.end());
    }
    cout << "\n";
    return 0;
  }

  cout << "0\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < f[i]; j++) {
      cout << (char) ('a' + i);
    }
  }
  cout << "\n";

  return 0;
}