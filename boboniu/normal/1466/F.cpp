#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 1234567
#define P 1000000007

int par[maxN];
int n, m;
int getPar(int x) {
  if (par[x] == x)
    return x;
  else {
    par[x] = getPar(par[x]);
    return par[x];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= m; i++)
    par[i] = i;
  vector<int> ans;
  int s[5];
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &s[j]);
    }
    int u = s[0], v = 0;
    if (k == 2)
      v = s[1];
    if (getPar(u) != getPar(v)) {
      ans.push_back(i);
      par[getPar(u)] = getPar(v);
    }
  }
  int t = ans.size();
  assert(t <= m);
  int ans2 = 1;
  for (int i = 0; i < t; i++)
    ans2 = ans2 * 2 % P;
  printf("%d %d\n", ans2, t);
  for (auto x : ans)
    printf("%d ", x);
  printf("\n");
}