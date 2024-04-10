#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  vector<int> g = p;
  vector<pii> od;
  auto _sw = [&](int a, int b) {
    if (a == b)
      return;
    swap(g[a], g[b]);
    // if (n == 6) {
    //   for (int x : g)
    //     cout << x << " ";
    //   cout << endl;
    // }
    // cout << a << ' ' << b << endl;
    assert(2 * abs(a - b) >= n);
    od.push_back({a, b});
  };
  auto sw = [&](int a, int d) {
    if (2 * abs(a - d) >= n)
      _sw(a, d);
    else if (2 * (a - 0) >= n && 2 * (d - 0) >= n) {
      _sw(a, 0);
      _sw(0, d);
      _sw(a, 0);
    } else if (2 * ((n - 1) - a) >= n && 2 * ((n - 1) - d) >= n) {
      _sw(a, n - 1);
      _sw(n - 1, d);
      _sw(a, n - 1);
    } else {
      // cout << "!!!" << a << ' ' << d << endl;
      int b = 0, c = n - 1;
      if (2 * a < n)
        swap(b, c);
      _sw(a, b);
      _sw(b, c);
      _sw(c, d);
      _sw(b, c);
      _sw(a, b);
    }
  };
  vector<bool> vis(n);
  for (int i = 0; i < n; i++) {
    if (vis[i])
      continue;
    int j = i;
    vis[j] = 1;
    while (!vis[p[j]]) {
      sw(i, p[j]);
      j = p[j];
      vis[j] = 1;
    }
  }
  cout << od.size() << endl;
  for (auto [u, v] : od)
    cout << u + 1 << ' ' << v + 1 << endl;
  // for (int i = 0; i < n; i++)
  //   assert(g[i] == i);
}