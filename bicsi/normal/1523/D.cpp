#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m, p; cin >> n >> m >> p;

  vector<long long> msks(n);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    long long msk = 0;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1') 
        msk |= (1LL << j);
    }
    msks[i] = msk;
  }
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long best = 0;
  for (int it = 0; it < 50; ++it) {
    long long msk = msks[rng() % n];
    vector<int> remap(m, -1);
    int bits = 0;
    for (int i = 0; i < m; ++i) {
      if (msk & (1LL << i)) 
        remap[i] = bits++;
    }
    assert(bits <= p);
    vector<int> cnt(1 << bits, 0);
    for (int i = 0; i < n; ++i) {
      int nmsk = 0;
      for (int j = 0; j < m; ++j) {
        if ((msks[i] & (1LL << j)) && remap[j] != -1)
          nmsk |= (1 << remap[j]);
      }
      cnt[nmsk] += 1;
    }
    for (int i = 0; i < bits; ++i) {
      for (int j = 0; j < (1 << bits); ++j) {
        if (!(j & (1 << i)))
          cnt[j] += cnt[j | (1 << i)];
      }
    }
    int maxx = (1 << bits) - 1;
    for (int sub = maxx; sub; sub = ((sub - 1) & maxx)) {
      if (__builtin_popcount(sub) <= __builtin_popcountll(best))
        continue;
      if (cnt[sub] >= (n + 1) / 2) {
        best = 0;
        for (int i = 0; i < m; ++i) {
          if (remap[i] == -1) continue;
          int j = remap[i];
          if (sub & (1 << j))
            best |= (1LL << i);
        }
        assert(__builtin_popcount(sub) == __builtin_popcountll(best));
      }
    }
  }

  for (int i = 0; i < m; ++i)
    if (best & (1LL << i))
      cout << 1;
    else cout << 0;
  cout << endl;

  return 0;
}