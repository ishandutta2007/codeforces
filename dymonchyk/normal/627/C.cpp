#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int fen[200002];

void upd(int pos, int add) {
  for ( ; pos <= 200000; pos |= (pos + 1))
    fen[pos] += add;
}

int fnd(int pos) {
  int ret = 0;
  for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1)
    ret += fen[pos];
  return ret;
}

int tree[800008];
int add[800008];

void update(int i, int l, int r, int L, int R, int val) {
  if (l == L && r == R) {
    add[i] += val;
    return;
  }
  if (add[i] != 0) {
    tree[i] += add[i];
    add[2 * i] += add[i];
    add[2 * i + 1] += add[i];
    add[i] = 0;
  }
  int m = (l + r) >> 1;
  if (R <= m) update(2 * i, l, m, L, R, val);
  else if (L > m) update(2 * i + 1, m + 1, r, L, R, val);
  else {
    update(2 * i, l, m, L, m, val);
    update(2 * i + 1, m + 1, r, m + 1, R, val);
  }
  tree[i] = min(tree[2 * i] + add[2 * i], tree[2 * i + 1] + add[2 * i + 1]);
}

int find(int i, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return tree[i] + add[i];
  }
  if (add[i] != 0) {
    tree[i] += add[i];
    add[2 * i] += add[i];
    add[2 * i + 1] += add[i];
    add[i] = 0;
  }
  int m = (l + r) >> 1;
  if (R <= m) return find(2 * i, l, m, L, R);
  if (L > m) return find(2 * i + 1, m + 1, r, L, R);
  return min(find(2 * i, l, m, L, m), find(2 * i + 1, m + 1, r, m + 1, R));
}

priority_queue<pair<int, int>> q;

int main() {
  int n, d, m;
  scanf("%d%d%d", &d, &n, &m);
  vector<pair<int, int>> v(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &v[i].first, &v[i].second);
  }
  sort(v.begin(), v.end());
  v.push_back({d, -1});
  long long ans = 0;
  int have = n;
  for (int i = 0; i < m; ++i) {
    q.push({-v[i].second, i});
    update(1, 0, m - 1, i, i, v[i].first - (have - n));
    // cout << "Add: " << i << " " << v[i].first - (have - n) << endl;
    while (q.size() && have < v[i + 1].first) {
      auto p = q.top(); q.pop();
      int left = find(1, 0, m - 1, p.second, i);
      int can = min(v[i + 1].first - have, left);
      have += can;
      left -= can;
      ans += 1LL * can * v[p.second].second;
      // cout << "Buy: " << p.second << "  " << can << " " << -p.first << endl;
      update(1, 0, m - 1, p.second, i, -can);

      if (left) {
        q.push(p);
      }
    }

    // cout << have << " " << ans << endl;

    if (have < v[i + 1].first) {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;

  return 0;
}