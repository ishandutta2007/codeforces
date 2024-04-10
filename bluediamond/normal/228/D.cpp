#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
int n;
int q;
ll a[N];

ll coef(int z, int i) {
  i %= (2 * (z - 1));
  if (i < 0) {
    i += 2 * (z - 1);
  }
  if (i == 0) {
    return 2;
  }
  if (i <= z) {
    return i;
  }
  return 2 * z - i;
}

ll t[7][13][N];

void add(int x, int y, int i, ll val) {
  while (i <= n) {
    t[x][y][i] += val;
    i += i & (-i);
  }
}

ll get(int x, int y, int i) {
  ll sol = 0;
  while (i >= 1) {
    sol += t[x][y][i];
    i -= i & (-i);
  }
  return sol;
}

int rep(int x, int val) {
  x = 2 * (x - 1);
  val %= x;
  if (val < 0) {
    val += x;
  }
  return val;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> q;
  for (int z = 2; z <= 6; z++) {
    for (int m = 0; m < 2 * (z - 1); m++) {
      for (int i = 1; i <= n; i++) {
        add(z, m, i, a[i] * coef(z, m + i));
      }
    }
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, x;
      cin >> i >> x;
      for (int z = 2; z <= 6; z++) {
        for (int m = 0; m < 2 * (z - 1); m++) {
          add(z, m, i, -a[i] * coef(z, m + i));
        }
      }
      a[i] = x;
      for (int z = 2; z <= 6; z++) {
        for (int m = 0; m < 2 * (z - 1); m++) {
          add(z, m, i, a[i] * coef(z, m + i));
        }
      }
      continue;
    }
    int l, r, z;
    cin >> l >> r >> z;
    int mod = 2 * (z - 1);
    int x = (r - l) / mod;
    ll sol = 0;
    for (int j = l + x * mod; j <= r; j++) {
      sol += a[j] * coef(z, j - l + 1);
    }
    int m = rep(z, -(l - 1));
    sol += get(z, m, l + x * mod - 1);
    sol -= get(z, m, l - 1);
    cout << sol << "\n";
  }
}