#include <bits/stdc++.h>
using namespace std;
#define maxN 222222

int n;
int a[maxN];
int main() {
  int tc;
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    if (*max_element(a, a + n) == *min_element(a, a + n))
      printf("%d\n",n);
    else
      printf("1\n");
  }
}