#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<pair<int, int>> v2;
vector<pair<int, pair<int, int>>> v1;

int ans[100005], l[100005], r[100005], k[100005];

set<pair<int, int>> f;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    v1.push_back(make_pair(b, make_pair(a, i)));
  }
  sort(v1.begin(), v1.end());
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d%d", &a, &b, &k[i]);
    l[i] = a; r[i] = b;
    v2.push_back(make_pair(b, i));
  }
  sort(v2.begin(), v2.end());
  int pos = 0;
  for (int i = 0; i < v2.size(); ++i) {
    while (pos < v1.size() && v1[pos].first <= v2[i].first) {
      f.insert(v1[pos].second);
      ++pos;
    }
    while (f.size() && k[v2[i].second]) {
      set<pair<int, int>>::iterator it = f.lower_bound(make_pair(l[v2[i].second], 0));
      if (it != f.end()) {
        ans[it->second] = v2[i].second + 1;
        f.erase(it);
        --k[v2[i].second];
      } else break;
    }
  }
  if (f.size() || pos != n) puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < n; ++i) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}