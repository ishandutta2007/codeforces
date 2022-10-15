#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

vector<int> zz(string s) {
  int n = (int) s.size();
  vector<int> ret(n, 0);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i <= r) ret[i] = min(ret[i - l], r - i + 1);
    while (i + ret[i] < n && s[i + ret[i]] == s[ret[i]]) ret[i]++;
    if (i + ret[i] - 1 > r) {
      r = i + ret[i] - 1;
      l = i;
    }
  }
  return ret;
}

int n, m, k;
string s, t;

vector<int> compute() {
  vector<int> ret(m + 1, (int) 1e9);
  vector<pair<int, int>> kek;
  auto com = zz(t + "@" + s);
  for (int i = 1; i <= n; i++) kek.push_back({com[i + m], i});
  sort(kek.rbegin(), kek.rend());
  int p = 0;
  set<int> s;
  for (int x = m; x >= 1; x--) {
    while (p < n && kek[p].first >= x) {
      s.insert(kek[p].second);
      p++;
    }
    auto it = s.lower_bound(k - x + 1);
    if (it != s.end()) {
      ret[x] = *it;
    }
  }
  for (auto &x : ret) {
    if (x == (int) 1e9) {
      x = -1;
    }
  }
  return ret;
}

signed realMain() {
  cin >> n >> m >> k >> s >> t;
  vector<int> lol = zz(t + "@" + s);
  for (int i = 1; i <= n; i++) {
    if (m <= k && lol[i + m] == m) {
			cout << "Yes\n" << min(i, n - 2 * k + 1) << " " << min(i, n - 2 * k + 1) + k  << "\n";
			return 0;
    }
  }
  auto mn = compute();
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  auto mx = compute();
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  for (int i = 1; i <= m; i++) {
    if (mx[i] != -1) mx[i] = n + 1 - mx[i];
  }
  for (int i = 1; i <= min(m - 1, k); i++) {
    int j = m - i;
    if (j > k) continue;
    if (mn[i] == -1 || mx[j] == -1) continue;
    if (mn[i] + i - 1 < mx[j] - j + 1) {
      cout << "Yes\n" << mn[i] + i - 1 - k + 1 << " " << mx[j] - j + 1 << "\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
  cout << "mn : ";
  for (int i = 1; i <= m; i++) {
    cout << mn[i] << " ";
  }
  cout << "\n";
  cout << "mx : ";
  for (int i = 1; i <= m; i++) {
    cout << mx[i] << " ";
  }
  cout << "\n";
  return 0;
  for (int i = 1; i <= n; i++) {
    cout << lol[i + m] << " ";
  }
  cout << "\n";
  return 0;
}