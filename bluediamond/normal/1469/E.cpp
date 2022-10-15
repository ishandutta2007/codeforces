#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char inv(char c) {
  if (c == '0') {
    return '1';
  } else {
    return '0';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s, t;
    cin >> n >> k >> s;
    vector<int> partial(n);
    int su = 0;
    for (int i = 0; i < n; i++) {
      t += inv(s[i]);
      su += t.back() - '0';
      partial[i] = su;
    }
    function<int(int, int)> sum = [&] (int l, int r) {
      if (l > r) {
        return 0;
      } else {
        if (l == 0) {
          return partial[r];
        } else {
          return partial[r] - partial[l - 1];
        }
      }
    };
    set<int> blocked;
    int len = min(k, 30);
    for (int r = k - 1; r < n; r++) {
      int l = r - len + 1;
      int num = 0;
      for (int j = l; j <= r; j++) {
        num = num * 2 + t[j] - '0';
      }
      if (sum(r - k + 1, l - 1) == 0) {
        blocked.insert(num);
      }
    }
    int x = 0;
    int p = (1 << len);
    while (x < p && blocked.count(x)) {
      x++;
    }
    if (x == p) {
      cout << "NO\n";
    } else {
      string sol;
      for (int j = 1; j <= k - len; j++) {
        sol += "0";
      }
      for (int j = len - 1; j >= 0; j--) {
        if (x & (1 << j)) {
          sol += "1";
        } else {
          sol += "0";
        }
      }
      cout << "YES\n" << sol << "\n";
    }
  }
}