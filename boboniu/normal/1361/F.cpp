#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                                                            \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>
using i64 = long long;
#define maxN 444444

int tl[maxN], tr[maxN], pos[maxN], par[maxN], p[maxN], w[maxN], id;
int n, m, x, y;
ordered_set number[maxN];
i64 ltr[maxN], rtl[maxN], tot[maxN], ans;

int build(int l, int r) {
  if (l - 1 == r) {
    int t = ++id;
    number[t].insert(p[l]);
    pos[l] = t;
    return t;
  } else {
    int t = ++id;
    int mid = min_element(w + l, w + r + 1) - w;
    tl[t] = build(l, mid - 1);
    par[tl[t]] = t;
    tr[t] = build(mid + 1, r);
    par[tr[t]] = t;
    for (int i = l; i <= r + 1; i++) {
      number[t].insert(p[i]);
    }
    for (auto x : number[tr[t]]) {
      rtl[t] += number[tl[t]].order_of_key(x);
    }
    tot[t] = (i64)number[tl[t]].size() * number[tr[t]].size();
    ltr[t] = tot[t] - rtl[t];
    ans += min(rtl[t], ltr[t]);
    return t;
  }
}

void modify(int x, int y, int z) {
  int u = par[pos[x]];
  int v = pos[x];
  // int z = p[x];
  while (true) {
    ans -= min(rtl[u], ltr[u]);
    if (tl[u] == v) {
      number[tl[u]].erase(z);
      number[tl[u]].insert(y);
      ltr[u] -= number[tr[u]].order_of_key(z);
      ltr[u] += number[tr[u]].order_of_key(y);
      rtl[u] = tot[u] - ltr[u];
      ans += min(ltr[u], rtl[u]);
    } else {
      number[tr[u]].erase(z);
      number[tr[u]].insert(y);
      rtl[u] -= number[tl[u]].order_of_key(z);
      rtl[u] += number[tl[u]].order_of_key(y);
      ltr[u] = tot[u] - rtl[u];
      ans += min(ltr[u], rtl[u]);
    }
    if (par[u] == -1) {
      number[u].erase(z);
      number[u].insert(y);
      break;
    }
    v = u;
    u = par[u];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &p[i]);
  for (int i = 1; i <= n - 1; i++)
    scanf("%d", &w[i]);
  int root = build(1, n - 1);
  par[root] = -1;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    if (x != y) {
      modify(x, -1, p[x]);
      modify(y, p[x], p[y]);
      modify(x, p[y], -1);
      swap(p[x], p[y]);
    }
    printf("%lld\n", ans);
  }
}