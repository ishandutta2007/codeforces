#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<pair<int, int>> cops(m), robbers(n);
  for (int i = 0; i < n; ++i) {
    cin >> robbers[i].first >> robbers[i].second;
  }
  for (int i = 0; i < m; ++i) {
    cin >> cops[i].first >> cops[i].second;
  }

  const int MAX = 1000008;

  vector<int> ymax(MAX, -1);
  for (int i = 0; i < m; ++i)
    ymax[cops[i].first] = max(ymax[cops[i].first], cops[i].second);

  vector<int> inter;
  for (int x = MAX - 2; x >= 0; --x) {
    ymax[x] = max(ymax[x], ymax[x + 1]);
    if (ymax[x + 1] < ymax[x]) {
      inter.push_back(x + 1);
    }
  }
/*
for (auto x : inter) {
    cerr << x << " " << ymax[x - 1] << " -> " << ymax[x] << endl;
  }*/
  inter.push_back(0);
  
  
  vector<tuple<int, int, int>> evs;
  vector<int> req(n);
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; ++i) {
    auto [x, y] = robbers[i];
    req[i] = max(0, ymax[x] + 1 - y);
    pq.emplace(req[i], i);
    for (auto xp : inter) {
      if (xp > x) {
        int delta = xp - x;
        // cerr << "ev: " << delta << " " << i << " " << max(0, ymax[xp] + 1 - y) << endl;
        evs.emplace_back(delta, i, max(0, ymax[xp] + 1 - y));
      }
    }
  }
  /*
cerr << "req" << endl;
  for (int i = 0; i < n; ++i) cerr << req[i] << " "; cerr << endl;
  */
  sort(evs.begin(), evs.end());
  int best = 1e9, at = 0;
  for (int delta = 0; delta <= MAX; ++delta) {
    while (at < (int)evs.size() && get<0>(evs[at]) == delta) {
      auto [zzz, j, new_req] = evs[at];
      req[j] = new_req;
      pq.emplace(new_req, j);
      ++at;
    }
    while (req[pq.top().second] != pq.top().first) pq.pop();
    int now = delta + pq.top().first;
    best = min(best, now);
    // cerr << "delta: " << delta << " now: " << now << endl;
  }
  cout << best << endl;

  return 0;
}