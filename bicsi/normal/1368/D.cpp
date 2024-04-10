#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
  
  vector<int> cnt(20, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 20; ++j) {
      if (v[i] & (1 << j))
        cnt[j] += 1;
    }
  }

  vector<vector<int>> stop(n + 1);
  for (int i = 0; i < 20; ++i) {
    stop[cnt[i]].push_back(i);
  }
  
  int msk = (1 << 20) - 1;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (auto p : stop[i])
      msk ^= (1 << p);
    ans += 1LL * msk * msk;
  }

  cout << ans << endl;
  return 0;
}