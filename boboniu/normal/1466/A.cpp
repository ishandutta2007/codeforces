#include <bits/stdc++.h>
using namespace std;

int tc,n;
int a[55];
int main() {
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    set<int> ans;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        ans.insert(a[j] - a[i]);
    printf("%d\n", (int)ans.size());
  }
}