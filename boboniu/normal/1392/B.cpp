#include <bits/stdc++.h>
using namespace std;
#define maxN 222222

int n;
long long k;
int a[maxN];
int main() {
  int tc;
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    k = (k - 1) % 2 + 1;
    for (int i = 0; i < k; i++) {
      int d = *max_element(a, a + n);
      for (int j = 0; j < n; j++)
        a[j] = d - a[j];
    }
    for (int i = 0; i < n; i++)
      printf("%d ", a[i]);
    printf("\n");
  }
}