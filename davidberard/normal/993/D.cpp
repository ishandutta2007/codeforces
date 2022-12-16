#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 55;
int a[N], b[N];
int n;

void upd(ld& res, ld va) {
  res = min(res, va);
}

bool solve(ld r) {
  vector<vector<ld>> dp(n+1, vector<ld>(n+1, 1e27));
  vector<pair<int, int>> vec;
  vec.push_back({0, 0});
  for (int i=1; i<=n; ++i) {
    vec.push_back({a[i], i});
  }
  dp[0][0] = 0;
  sort(vec.begin()+1, vec.end());
  reverse(vec.begin()+1, vec.end());
  for (int i=1; i<=n; ++i) {
    int j;
    for (j = i; j<=n && vec[j].first == vec[i].first; ++j);
    sort(vec.begin()+i, vec.begin()+j, [&](const pair<int, int>& x, const pair<int, int>& y) {
      return a[x.second] - r * b[x.second] < a[y.second] - r * b[y.second];
    });
    int avail = j-i;
    for (int z=0; z<i; ++z) {
      //cerr << " dp[" << i-1 << "][" << z << "] = " << dp[i-1][z] << endl;
      ld add = 0;
      for (int d=0; d<=avail; ++d) {
        if (z-avail+d >= 0) {
          upd(dp[j-1][z-avail+2*d], dp[i-1][z] + add);
        }
        //cerr << " :: " << i+d << " vs " << vec.size() << endl;
        if (d != avail) {
          add += a[vec[i+d].second] - r * b[vec[i+d].second];
        }
      }
    }
    i = j-1;
  }
  /*
  {
    int i=n+1;
    for (int z=0; z<i; ++z) {
      cerr << " dp[" << i-1 << "][" << z << "] = " << dp[i-1][z] << endl;
    }
  }
  */
  ld res = 1e27;
  for (int i=0; i<=n; ++i) {
    res = min(res, dp[n][i]);
  }
  return (res <= 0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=1; i<=n; ++i) {
    cin >> b[i];
  }
  ld lo = 0, hi = 1e8;
  for (int zz=0; zz<100; ++zz) {
    ld mid = (lo+hi)/2;
    if (solve(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << (ll) (lo*1000 + 0.999) << endl;
  solve(8.75);
  return 0;
}