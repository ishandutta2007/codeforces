#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 32345
int n;
int a[maxN];
bool solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int p1 = a[1], p2 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < p2)
      return false;
    a[i] -= p2;
    if (a[i] <= p1)
      p1 = a[i];
    else
      p2 += a[i] - p1;
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    if (solve()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}