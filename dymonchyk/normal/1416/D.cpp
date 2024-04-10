#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int val[200005];
pair<int, int> e[300005];
bool del[300005];
int qT[500005], qV[500005];

int color[200005];

inline int repr(int x) {
  return color[x] == x ? x : (color[x] = repr(color[x]));
}

vector<int> f[200005];
pair<int, int> op[500005];

inline void join(int x, int y, int ind) {
  x = repr(x); y = repr(y);

  if (x != y) {
    if (f[x].size() < f[y].size())  swap(x, y);
    f[x].insert(f[x].end(), f[y].begin(), f[y].end());
    color[y] = x;

    // if (f[y].size() > f[x].size()) exit(-1);

    if (ind != -1) {
      op[ind] = {x, y};
    }
  }
}

int root[200005];
set<pair<int, int>> ff[200005];

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i) cin >> val[i];
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &e[i].first, &e[i].second);
    e[i].first--; e[i].second--;
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &qT[i], &qV[i]), qV[i]--;
    if (qT[i] == 2) del[qV[i]] = true;
  }

  for (int i = 0; i < n; ++i) {
    color[i] = i;
    f[i].push_back(i);
  }

  for (int i = 0; i < m; ++i) {
    if (del[i]) continue;
    join(e[i].first, e[i].second, -1);
  }

  for (int i = q - 1; i >= 0; --i) {
    if (qT[i] == 2) {
      join(e[qV[i]].first, e[qV[i]].second, i);
    }
  }

  for (int i = 0; i < n; ++i) {
    ff[repr(i)].insert({-val[i], i});
    root[i] = repr(i);
    // cout << i << "  " << repr(i) << endl;
  }

  // for (int i = 0; i < q; ++i)
  //   if (op[i].second.size() > 0 && op[i].second != f[op[i].first.second]) exit(-1);

  for (int i = 0; i < q; ++i) {
    if (qT[i] == 1) {
      int p = root[qV[i]];
      if (ff[p].size() > 0) {
        printf("%d\n", -ff[p].begin()->first);
        val[ff[p].begin()->second] = 0;
        ff[p].erase(ff[p].begin());
      } else {
        puts("0");
      }
    } else if (op[i].first != op[i].second) {
      for (int t : f[op[i].second]) {
        root[t] = op[i].second;
        if (val[t] > 0) {
          ff[op[i].first].erase({-val[t], t});
          ff[op[i].second].insert({-val[t], t});
        }
      }
    }
  }

  return 0;
}