#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 7;
bool taken[N];
int n, l, r, s;

bool ok(int len, int sum) {
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    if (!taken[i]) {
      a.push_back(i);
    }
  }
  assert((int) a.size() >= len);
  int mn = 0, mx = 0;
  for (int i = 0; i < len; i++) {
    mn += a[i];
    mx += a[(int) a.size() - 1 - i];
  }
  return mn <= sum && sum <= mx;
}

int print[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> l >> r >> s;
    for (int i = 1; i <= n; i++) {
      taken[i] = 0;
      print[i] = 0;
    }
    if (!ok(r - l + 1, s)) {
      cout << "-1\n";
      continue;
    }
    vector<int> solu;
    while ((int) solu.size() < r - l + 1) {
      bool found = 0;
      for (int x = 1; x <= n; x++) {
        if (!taken[x]) {
          if (ok(r - l - (int) solu.size(), s - x)) {
            taken[x] = 1;
            solu.push_back(x);
            found = 1;
            s -= x;
            break;
          }
        }
      }
      assert(found);
    }
    int cur = 1;
    for (int i = l; i <= r; i++) {
      print[i] = solu[i - l];
    }
    for (int i = 1; i <= n; i++) {
      if (!print[i]) {
        while (taken[cur]) {
          cur++;
        }
        taken[cur] = 1;
        print[i] = cur;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << print[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}