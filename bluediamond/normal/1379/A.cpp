#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 50 + 7;
int n;
string s;

bool good(string s) {
  int cnt = 0;
  for (int i = 0; i + 6 < n; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'a' && s[i + 3] == 'c' && s[i + 4] == 'a' && s[i + 5] == 'b' && s[i + 6] == 'a') {
      cnt++;
    }
  }
  return (cnt == 1);
}

void print(string s) {
  for (auto &x : s) {
    if (x == '?') {
      cout << "z";
    } else {
      cout << x;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    bool found = 0;
    for (int l = 0; l + 6 < n; l++) {
      int r = l + 6;
      bool ok = 1;
      if (s[l] != 'a' && s[l] != '?') ok = 0;
      if (s[l + 1] != 'b' && s[l + 1] != '?') ok = 0;
      if (s[l + 2] != 'a' && s[l + 2] != '?') ok = 0;
      if (s[l + 3] != 'c' && s[l + 3] != '?') ok = 0;
      if (s[l + 4] != 'a' && s[l + 4] != '?') ok = 0;
      if (s[l + 5] != 'b' && s[l + 5] != '?') ok = 0;
      if (s[l + 6] != 'a' && s[l + 6] != '?') ok = 0;
      if (ok == 0) continue;
      string t1, t2;
      for (int i = 0; i < l; i++) {
        t1 += s[i];
      }
      for (int i = r + 1; i < n; i++) {
        t2 += s[i];
      }
      string t = t1 + "abacaba" + t2;
      if (good(t)) {
        found = 1;
        cout << "Yes\n";
        print(t1);
        cout << "abacaba";
        print(t2);
        cout << "\n";
        break;
      }
    }
    if (found == 0) {
      cout << "No\n";
    }
  }
  return 0;
}