/*
result of thinking: Pure.

start coding: 21:48
AC:
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <climits>
#include <tuple>
#define maxn 100005

using namespace std;
typedef long long ll;

void solve(int l, int r) { // 2 | r - l.
  printf("YES\n%d\n", r - l - 1);
  for (int i = l; i <= r - 2; i += 2) {
    printf("%d %d %d\n", i, i + 1, i + 2);
  }
  for (int i = r - 4; i >= l; i -= 2) {
    printf("%d %d %d\n", i, i + 1, i + 2);
  }
}

int n, a[maxn], xorSum;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    xorSum ^= a[i];
  }
  if (n & 1) {
    solve(1, n);
  } else if (!xorSum) {
    solve(1, n - 1);
  } else {
    puts("NO");
  }
  return 0;
}