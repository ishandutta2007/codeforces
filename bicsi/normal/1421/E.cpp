#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long 

using namespace std;


vector<long long> combine(vector<long long> dp, int val) {
  vector<long long> ret = dp;
  for (int i = 0; i < 3; ++i)
    ret[i] += val;
  for (int i = 0; i < 3; ++i) {
    ret[(i + 1) % 3] = max(ret[(i + 1) % 3], dp[i] - val);
  }
  return ret;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  if (n == 1) {
    cout << sum << '\n';
    return 0;
  }

  long long best = -2e18;
  int req = (n % 3 == 1 ? 0 : (n % 3 == 0 ? 1 : 2));
  vector<vector<long long>> pref(n + 1, vector<long long>(3)), suff(pref);
  
  vector<long long> acc = {0, best, best};
  pref[0] = acc;
  for (int i = 0; i < n; ++i) {
    acc = combine(acc, a[i]);
    pref[i + 1] = acc;
  }
  acc = {0, best, best};
  suff[n] = acc;
  for (int i = n - 1; i >= 0; --i) {
    acc = combine(acc, a[i]);
    suff[i] = acc;
  }

  for (int i = 1; i < n; ++i) {
    {
      int now_req = req;
      int delta = +(a[i] + a[i - 1]);
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if ((j + k) % 3 == now_req) {
            // cerr << "prop+: " << i << " " << j << " " << k << endl;
            int add = pref[i - 1][j] + suff[i + 1][k];
            // cerr << add << " " << delta << endl;
            best = max(best, add + delta);
          }
        }
      }
    }
    {
      int now_req = (req + 1) % 3;
      int delta = -(a[i] + a[i - 1]);
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if ((j + k) % 3 == now_req) {
            // cerr << "prop-: " << i << " " << j << " " << k << endl;
            int add = pref[i - 1][j] + suff[i + 1][k];
            // cerr << add << " " << delta << endl;
            best = max(best, add + delta);
          }
        }
      }
    }
  }

  
  cout << best << endl;
  return 0;
}