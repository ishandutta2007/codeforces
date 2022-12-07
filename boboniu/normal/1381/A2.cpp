#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 555555

int T, n;
char s[maxN], t[maxN];

int main() {
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    scanf("%d", &n);
    scanf("%s%s", s, t);
    auto build = [&](char *s) {
      vector<int> ans;
      for (int i = 0; i < n - 1; i++)
        if (s[i] != s[i + 1])
          ans.push_back(i + 1);
      return ans;
    };
    auto ans1 = build(s);
    if (s[n - 1] != t[n - 1]) {
      ans1.push_back(n);
    }
    auto ans2 = build(t);
    reverse(ans2.begin(), ans2.end());
    for (auto op : ans2)
      ans1.push_back(op);
    printf("%d", ans1.size());
    for (auto op : ans1)
      printf(" %d", op);
    printf("\n");
  }
}