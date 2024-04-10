#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  n *= 2;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  if (v[0] == v[n - 1]) cout << "-1\n";
  else for (auto &x : v) cout << x << " ";
}