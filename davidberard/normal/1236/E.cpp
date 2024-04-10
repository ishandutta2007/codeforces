#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> solve(const vector<int>& a, int n, int m) {
  vector<int> f(n+m+5);
  for (int i=0; i<n; ++i) {
    f[i] = i;
  }
  for (int i=n; i<m; ++i) {
    f[i] = -1;
  }
  for (int i=0; i<a.size(); ++i) {
    int x = a[i]+i;
    if (f[x] != -1) {
      f[x+1] = max(f[x], f[x+1]);
    }
    f[x] = -1;
  }
  vector<int> ans(n);
  int j = 0;
  for (int i=0; i<n+m+1; ++i) {
    for (; j<=f[i]; ++j) {
      ans[j] = max(i-m, 1);
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << 0 << "\n";
    return 0;
  }
  vector<int> a,b;
  for (int i=0; i<m; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
    b.push_back(n+1-x);
  }

  auto lo = solve(a, n, m);
  auto hi = solve(b, n, m);
  for (auto& x : hi) {
    x = n+1-x;
  }
  reverse(hi.begin(), hi.end());

  ll ans = 0;
  for (int i=0; i<n; ++i) {
    ans += (hi[i]-lo[i]+1);
  }

  cout << ans << "\n";

  return 0;
}