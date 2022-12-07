#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 223456

int n;
i64 W;
pair<int, int> w[maxN];

void solve() {
  scanf("%d%lld", &n, &W);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i].first);
    w[i].second = i + 1;
  }
  sort(w, w + n);
  reverse(w, w + n);
  vector<int> item;
  i64 s = 0;
  for (int i = 0; i < n; i++) {
    if (s + w[i].first <= W) {
      item.push_back(w[i].second);
      s += w[i].first;
    }
  }
  if (s <= W && s >= (W + 1) / 2) {
    printf("%d\n", (int)item.size());
    for (auto id : item)
      printf("%d ", id);
    printf("\n");
  } else {
    printf("-1\n");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    solve();
  }
}