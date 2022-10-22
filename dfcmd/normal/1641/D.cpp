#include <bits/stdc++.h>

constexpr int BLOCK = 25000;

constexpr int INF = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, std::vector<int>>> a(n);
  for (int i = 0; i < n; ++i) {
    a[i].second.resize(m);
    for (int &x : a[i].second) {
      std::cin >> x;
    }
    std::cin >> a[i].first;
  }

  std::sort(a.begin(), a.end());

  int ans = INF;
  for (int L = 0; L < n; L += BLOCK) {
    int R = std::min(n, L + BLOCK);
    std::map<int, std::bitset<BLOCK>> mp;
    for (int i = L; i < R; ++i) {
      for (int x : a[i].second) {
        mp[x].set(i - L);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i].first + a[0].first >= ans) {
        continue;
      }
      std::bitset<BLOCK> tmp;
      for (int x : a[i].second) {
        if (mp.count(x)) {
          tmp |= mp[x];
        }
      }
      int p = L + (~tmp)._Find_first();
      if (p < R) {
        ans = std::min(ans, a[i].first + a[p].first);
      }
    }
  }
  std::cout << (ans == INF ? -1 : ans) << "\n";
}