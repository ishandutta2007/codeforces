#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct T {
  int i;
  int cnt;
};

bool operator < (T a, T b) {
  if (a.cnt == b.cnt) {
    return a.i < b.i;
  } else {
    return a.cnt > b.cnt;
  }
}

const int N = (int) 2e5 + 7;
int n, k, cnt[N];
vector<int> edges[N];
bool deleted[N];
set<int> g[N], l[N];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  for (int tt = 1; tt <= tests; tt++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
      deleted[i] = 0;
      g[i].clear();
      l[i].clear();
      cnt[i] = 0;
    }
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      edges[x].push_back(y);
      edges[y].push_back(x);
    }
    set<T> s;
    for (int i = 1; i <= n; i++) {
      for (auto &j : edges[i]) {
        if ((int) edges[j].size() == 1) {
          l[i].insert(j);
          cnt[i]++;
        } else {
          g[i].insert(j);
        }
      }
      s.insert({i, (int) l[i].size()});
    }
    int sol = 0;
    while (!s.empty()) {
      auto bgs = s.begin();
      int i = bgs->i;
      s.erase({i, cnt[i]});
      if (deleted[i]) {
        continue;
      }
      if (cnt[i] < k) {
        break;
      }
      sol++;
      for (int step = 1; step <= k; step++) {
        int j = *l[i].begin();
        deleted[j] = 1;
        l[i].erase(j);
      }
      cnt[i] -= k;
      if (cnt[i] > 0) {
        s.insert({i, cnt[i]});
      } else {
        int lol = 0;
        for (auto &j : g[i]) {
          lol += (deleted[j] == 0);
        }
        if (lol != 1) {
          continue;
        }
        for (auto &j : g[i]) {
          s.erase({j, cnt[j]});
          cnt[j]++;
          s.insert({j, cnt[j]});
          g[j].erase(i);
          l[j].insert(i);
        }
      }
    }
    cout << sol << "\n";
  }
  return 0;
}