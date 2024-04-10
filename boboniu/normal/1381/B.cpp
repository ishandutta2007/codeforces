#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 555555

int T, n, p[maxN];

int main() {
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++)
      scanf("%d", &p[i]);
    auto check = [&]() {
      vector<int> block_head;
      vector<int> block_size;
      for (int l = 1; l <= 2 * n; l++) {
        int r = l;
        while (r + 1 <= 2 * n && p[r + 1] < p[l])
          r++;
        block_head.push_back(p[l]);
        block_size.push_back(r - l + 1);
        l = r;
      }
      bitset<4001> dp;
      dp[0] = 1;
      for (int num : block_size)
        dp |= dp << num;
      return dp.test(n);
    };
    if (check())
      printf("YES\n");
    else
      printf("NO\n");
  }
}