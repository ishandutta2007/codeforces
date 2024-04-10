#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    int n;
    cin >> n;
    vector<int> a(n), init;
    for (auto &x : a) {
      cin >> x;
      x--;
    }
    init = a;
    while (1) {
      int components = 0;
      vector<int> component(n, -1);
      for (int i = 0; i < n; i++) {
        if (component[i] == -1) {
          components++;
          int current = i;
          while (component[current] == -1) {
            component[current] = components;
            current = a[current];
          }
        }
      }
      if (components == 1) {
        break;
      }

      bool found = 0;
      for (int i = 0; i < n - 1; i++) {
        if (component[i] != component[i + 1]) {
          int p1 = -1, p2 = -1;
          for (int j = 0; j < n; j++) {
            if (a[j] == i) p1 = j;
            if (a[j] == i + 1) p2 = j;
          }
          assert(p1 != -1);
          assert(p2 != -1);
          swap(a[p1], a[p2]);
          found = 1;
          break;
        }
      }
      assert(found);
    }
    vector<int> path;
    int i = 0;
    for (int step = 0; step < n; step++) {
      path.push_back(i);
      i = a[i];
    }
    reverse(path.begin() + 1, path.end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += abs(path[i] - init[path[(i + 1) % n]]);
    }
    for (auto &x : path) {
      cout << x + 1 << " ";
    }
    cout << "\n";
  }
}