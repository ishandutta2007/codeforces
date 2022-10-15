#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

void print(vector<int> a) {
  if (home) {
    cout << " -> ";
    for (auto &x : a) {
      cout << x << " ";
    }
    cout << "\n";
  } else {
    cout << (int) a.size() << "\n";
    for (auto &x : a) {
      cout << x << " ";
    }
    cout << "\n";
  }
}

int a[2], cop[2];
vector<int> ret[2];

void baga(int i, int x) {
  ret[i].push_back(x);
  a[i] -= x;
}

bool ok(int n) {
  ret[0].clear();
  ret[1].clear();
  a[0] = cop[0];
  a[1] = cop[1];
  for (int i = n; i >= 1; i--) {
    if (i > a[0]) {
      if (i > a[1]) {
        return 0;
      }
      baga(1, i);
    } else {
      if (i > a[1]) {
        baga(0, i);
      } else {
        if (a[0] < a[1]) {
          baga(1, i);
        } else {
          baga(0, i);
        }
      }
    }
  }
  return 1;
}

signed realMain() {
  cin >> cop[0] >> cop[1];
  int l = 0, r = (int) 1e9, sol;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ok(m)) {
      sol = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  ok(sol);
  print(ret[0]);
  print(ret[1]);
  return 0;
}