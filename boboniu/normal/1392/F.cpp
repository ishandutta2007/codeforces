#include <bits/stdc++.h>
using namespace std;
#define maxN 1111111

int n;
long long b[maxN];
int main() {
  scanf("%d", &n);
  long long x, s = 0;
  for (int i = 0; i < n; i++)
    scanf("%lld", &x), s += x;
  long long p1 = (s - 1ll * n * (n - 1) / 2) / n;
  long long t = 0;
  for (int i = 1; i <= n; i++)
    b[i] = p1 + i - 1, t += b[i];
  for (int i = 1; i <= n; i++) {
    if (t < s)
      b[i] += 1, t++;
  }
  for (int i = 1; i <= n; i++)
    printf("%lld ", b[i]);
  printf("\n");
}