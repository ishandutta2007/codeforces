#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool need[20][20];

int solve() {
  for (int i = 0; i < 20; i++) {
    for (int j = i + 1; j < 20; j++) {
      if (need[i][j]) {
        need[i][j] = 0;
        for (int k = j; k < 20; k++) {
          if (need[i][k]) {
            need[i][k] = 0;
            need[j][k] = 1;
          }
        }
        return 1 + solve();
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
        need[i][j] = 0;
      }
    }
    int n;
    bool bad = 0;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
      if (s[i] > t[i]) {
        bad = 1;
        break;
      }
      if (s[i] < t[i]) {
        need[s[i] - 'a'][t[i] - 'a'] = 1;
      }
    }
    if (bad) {
      cout << "-1\n";
      continue;
    }
    cout << solve() << "\n";
  }
}