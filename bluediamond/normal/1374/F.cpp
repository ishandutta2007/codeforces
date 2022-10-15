#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/// x y z => z x y

const int N = 500 + 7;
int n, a[N], o[N];
vector<int> sol;

void add(int i) {
  sol.push_back(i);
  int x = a[i], y = a[i + 1], z = a[i + 2];
  a[i] = z;
  a[i + 1] = x;
  a[i + 2] = y;
  x = o[i], y = o[i + 1], z = o[i + 2];
  o[i] = z;
  o[i + 1] = x;
  o[i + 2] = y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    sol.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool dub = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (a[i] == a[j]) {
          dub = 1;
        }
      }
    }
    if (dub == 0) {
      int invs = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
          if (a[i] > a[j]) {
            invs++;
          }
        }
      }
      if (invs & 1) {
        cout << "-1\n";
        continue;
      }
      for (int i = 1; i <= n; i++) {
        int p = i;
        for (int j = i + 1; j <= n; j++) {
          if (a[j] < a[p]) {
            p = j;
          }
        }
        while (p >= i + 2) {
          add(p - 2);
          p -= 2;
        }
        if (p == i + 1) {
          add(i);
          add(i);
        }
      }
    } else {
      vector<pair<int, int>> e;
      for (int i = 1; i <= n; i++) {
        e.push_back({a[i], i});
      }
      sort(e.begin(), e.end());
      for (int i = 0; i < n; i++) {
        o[e[i].second] = i + 1;
      }
      int invs = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
          if (a[i] > a[j]) {
            invs++;
          }
        }
      }
      if (invs & 1) {
        bool found = 0;
        for (int i = 1; i <= n && !found; i++) {
          for (int j = i + 1; j <= n && !found; j++) {
            if (a[i] == a[j] && abs(o[i] - o[j]) == 1) {
              swap(o[i], o[j]);
              found = 1;
            }
          }
        }
        if (found == 0) {
          cout << "error 1 : not found\n";
          return 0;
        }
      }
      for (int i = 1; i <= n; i++) {
        int p = i;
        for (int j = i + 1; j <= n; j++) {
          if (o[j] < o[p]) {
            p = j;
          }
        }
        while (p >= i + 2) {
          add(p - 2);
          p -= 2;
        }
        if (p == i + 1) {
          add(i);
          add(i);
        }
      }
    }
    cout << (int) sol.size() << "\n";
    for (auto &i : sol) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}