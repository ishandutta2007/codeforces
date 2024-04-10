#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int n;
struct el {
  int x, w;
  int val;
  bool operator<(const el& e) const {
    if (x + w == e.x + e.w) {
      return x < e.x;
    }
    return x + w < e.x + e.w;
  }
} e[200020];

inline bool cmp(const el& a, const el& b) {
  return a.x - a.w < b.x - b.w;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &e[i].x, &e[i].w);
  }

  sort(e, e + n, cmp);
  set<el> cand;
  int mx = 0;
  int ans = 1;

  for (int i = 0; i < n; ++i) {
    while (cand.size() && cand.begin()->x + cand.begin()->w <= e[i].x - e[i].w) {
      set<el>::iterator it = cand.begin();
      mx = max(mx, it->val);
      cand.erase(it);
    }
    e[i].val = mx + 1;
    cand.insert(e[i]);
    if (e[i].val > ans)
      ans = e[i].val;
  }

  printf("%d\n", ans);
  return 0;
}