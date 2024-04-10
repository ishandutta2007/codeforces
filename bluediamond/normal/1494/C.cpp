#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

vector<int> v;

int cnts(int lim) {
  int l = 0, r = (int) v.size() - 1, ret = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (v[m] <= lim) {
      ret = m + 1;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return ret;
}

int get(vector<int> a, vector<int> b) {
  for (auto &x : a) x = abs(x);
  for (auto &x : b) x = abs(x);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  v = b;
  set<int> s;
  for (auto &x : b) {
    s.insert(x);
  }
  int n = (int) a.size(), m = (int) b.size();
  a.push_back((int) 1e18 + 1);
  int ret = 0, add = 0;
  for (int i = 0; i < n; i++) {
    add += s.count(a[i]);
  }
  int pos = 0;
  for (int pre = -1; pre < n; pre++) {
    if (pre != -1) {
      add -= s.count(a[pre]);
    }
    int now = 0;
    int cnt = pre + 1;
    int mn, mx = a[pre + 1] - 1;
    if (pre == -1) {
      mn = 0;
    } else {
      mn = a[pre];
    }
    while (pos < m) {
      int x = b[pos];
      if (x < mn) {
        pos++;
        continue;
      }
      if (x > mx) {
        break;
      }
      assert(mn <= x && x <= mx);
      pos++;
      int matching = 0;
      int lo = x - (cnt - 1), hi = x;
      now = max(now, cnts(hi) - cnts
                (lo - 1));
    }
    ret = max(ret, now + add);
  }
  return ret;
}

const int N = (int) 2e5 + 7;
int n, m, a[N], b[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
    }
    vector<int> a1, a2, b1, b2;
    for (int i = 1; i <= n; i++) {
      if (a[i] > 0) a1.push_back(a[i]); else a2.push_back(a[i]);
    }
    for (int i = 1; i <= m; i++) {
      if (b[i] > 0) b1.push_back(b[i]); else b2.push_back(b[i]);
    }
    int ret = get(a1, b1) + get(a2, b2);
    cout << ret << "\n";
  }

}