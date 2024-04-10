#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 2000 + 7;
int n;
int C;
int x[N];
int y[N];
int down[N][N];

ll f(int i, int j) {
  return (ll) (x[i] - x[j]) * (y[i] + y[j]);
}

ll f(int i, int j, int k) {
  return f(i, j) + f(j, k) + f(k, i);
}

int cadran(int x, int y) {
  if (x >= 0) {
    if (y >= 0) {
      return 1;
    } else {
      return 2;
    }
  } else {
    if (y < 0) {
      return 3;
    } else {
      return 4;
    }
  }
}

bool cmp(int i, int j) {
  int x1 = x[i] - x[C];
  int y1 = y[i] - y[C];
  int c1 = cadran(x1, y1);
  int x2 = x[j] - x[C];
  int y2 = y[j] - y[C];
  int c2 = cadran(x2, y2);
  if (c1 != c2) {
    return c1 > c2;
  }
  if (x1 == 0) {
    assert(c1 == 1 || c1 == 2);
    return (c1 == 2);
  }
  if (x2 == 0) {
    assert(c1 == 1 || c1 == 2);
    return (c1 == 1);
  }

  bool t = ((ll) y1 * x2 < (ll) y2 * x1);
  return t;
}

bool is_down(int i, int j, int k) {
  return f(i, j, k) < 0;
}

ll g(ll x) {
  return x * (x - 1) / 2;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; i++) {
    vector<int> rem;
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        rem.push_back(j);
      }
    }
    C = i;
    sort(rem.begin(), rem.end(), cmp);
    for (int it = 0; it < n - 1; it++) {
      int j = rem[it];
      int sol = 0;
      int lo = it + 1, hi = it + n - 2;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (is_down(i, j, rem[mid % (n - 1)])) {
          sol = it + n - 1 - mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      down[i][j] = sol;
    }
  }
  ll sol = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int up = n - 2 - down[i][j];
      sol += g(up) * g(down[i][j]);
    }
  }
  cout << sol << "\n";
}