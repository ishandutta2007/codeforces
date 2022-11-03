#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int dv[1000006], cnt[1000006];

void go(int n) {
  while (n > 1) {
    int d = dv[n], c = 0;
    while (n % d == 0) {
      n /= d;
      ++c;
    }
    cnt[d] = max(cnt[d], c);
  }
}

int main() {
  for (int i = 2; i <= 1000000; ++i) {
    if (dv[i] == 0) {
      for (int j = i; j <= 1000000; j += i) {
        if (dv[j] == 0) dv[j] = i;
      }
    }
  }

  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    go(c);
  }

  while (k > 1) {
    int d = dv[k], c = 0;
    while (k % d == 0) {
      k /= d;
      ++c;
    }
    if (cnt[d] < c) {
      puts("No");
      return 0;
    }
  }

  puts("Yes");

  return 0;
}