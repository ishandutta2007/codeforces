#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int lis(vector<int> v) {
  map<int, int> tr;
  int n = (int) v.size();
  for (auto &x : v) {
    tr[x] = 0;
  }
  int sc = 0;
  for (auto &it : tr) {
    it.second = ++sc;
  }
  for (auto &x : v) {
    x = tr[x];
  }
  vector<int> t(n + 1, 0);
  function<int(int)> mx = [&] (int i) {
    int sol = 0;
    while (i) {
      sol = max(sol, t[i]);
      i -= i & (-i);
    }
    return sol;
  };
  function<void(int, int)> upd = [&] (int i, int x) {
    while (i <= n) {
      t[i] = max(t[i], x);
      i += i & (-i);
    }
  };
  for (auto &x : v) {
    upd(x, mx(x) + 1);
  }
  return mx(n);
}

const int N = (int) 5e5 + 7;
int n;
int k;
int a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  a[0] = -(int) 1e9;
  a[n + 1] = (int) 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] -= i;
  }
  vector<int> f;
  f.push_back(0);
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    f.push_back(x);
  }
  f.push_back(n + 1);
  int sol = 0;
  for (int i = 0; i + 1 < (int) f.size(); i++) {
    if (a[f[i]] > a[f[i + 1]]) {
      cout << "-1\n";
      return 0;
    }
    int vmin = a[f[i]];
    int vmax = a[f[i + 1]];
    int l = f[i] + 1, r = f[i + 1] - 1;
    vector<int> vals;
    for (int j = l; j <= r; j++) {
      if (vmin <= a[j] && a[j] <= vmax) {
        vals.push_back(a[j]);
      }
    }
    sol += r - l + 1 - lis(vals);
  }
  cout << sol << "\n";
}