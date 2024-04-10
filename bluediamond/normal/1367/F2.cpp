#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, a[N], l[N], r[N], f[N], pt[N], su[N], x[N], y[N];
vector<int> p[N];

void se() {
  map<int, int> tr;
  for (int i = 1; i <= n; i++) {
    tr[a[i]] = i;
  }
  int sh = 0;
  for (auto &it : tr) {
    it.second = ++sh;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = tr[a[i]];
  }
}

int get(int x, int pr) {
  int l = 0, r = (int) p[x].size() - 1, sol = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (p[x][m] <= pr) {
      sol = m + 1;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return sol;
}

int get(int x, int l, int r) {
  return get(x, r) - get(x, l - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    se();
    for (int i = 1; i <= n; i++) r[a[i]] = i;
    for (int i = n; i >= 1; i--) l[a[i]] = i;
    for (int i = 1; i <= n; i++) f[a[i]]++;
    for (int i = 1; i <= n; i++) p[a[i]].push_back(i);
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      sol = max(sol, get(a[i], 1, i) + get(a[i] + 1, i + 1, n));
    }
    for (int i = n; i >= 1; i--) {
      if (f[i] == 0) continue;
      su[i] = f[i];
      if (i + 1 <= n && f[i + 1] && r[i] < l[i + 1]) {
        pt[i] = pt[i + 1];
        su[i] += su[i + 1];
      } else {
        pt[i] = i;
      }
      int j = pt[i];
      int cur = su[i];
      cur += get(i - 1, 1, l[i] - 1);
      cur += get(j + 1, r[j] + 1, n);
      sol = max(sol, cur);
    }
    for (int i = 1; i <= n; i++) {
      a[i] = l[i] = r[i] = f[i] = pt[i] = su[i] = x[i] = y[i] = 0;
      p[i].clear();
    }
    cout << n - sol << "\n";
  }
  return 0;
}