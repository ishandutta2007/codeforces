#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

///#define int ll

bool good(int a, int b) {
  return __gcd(a, b) == 1;
}

bool used[(int) 1e6];
int n, k, v[4], start;
vector<vector<int>> sol;

void bkt(int pos) {
  for (int i = 0; i < pos; i++) {
    if (used[v[i]]) return;
  }
  if (pos == 4) {
    n--;
    used[v[0]] = used[v[1]] = used[v[2]] = used[v[3]] = 1;
    sol.push_back({v[0], v[1], v[2], v[3]});
    start = v[0] + 1;
    if (n == 0) {
      int mx = 0;
      for (auto &it : sol) {
        for (auto &x : it) {
          x *= k;
          mx = max(mx, x);
        }
      }
      cout << mx << "\n";
      for (auto &it : sol) {
        for (auto &x : it) {
          cout << x << " ";
        }
        cout << "\n";
      }
      exit(0);
    }
    return;
  }
  v[pos] = start;
  if (pos && v[pos] == v[pos - 1]) return;
  while (1) {
    while (used[v[pos]]) {
      v[pos]++;
      if (pos && v[pos] == v[pos - 1]) return;
    }
    bool ok = 1;
    for (int i = 0; i < pos; i++) {
      if (!good(v[pos], v[i])) {
        ok = 0;
        break;
      }
    }
    if (!ok) {
      v[pos]++;
      if (pos && v[pos] == v[pos - 1]) return;
      continue;
    }
    bkt(pos + 1);
    v[pos]++;
    if (pos && v[pos] == v[pos - 1]) return;
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

///  freopen ("input", "r", stdin);

  cin >> n >> k;

  bkt(0);


  return 0;
}