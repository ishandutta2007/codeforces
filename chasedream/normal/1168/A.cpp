#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int t[N], a[N];
int n, m;

bool check(int k) {
  for (int i = 1; i <= n; i++) {
    t[i] = a[i];
    if (t[i] >= t[i - 1]) {
      if (t[i] + k >= m && (t[i] + k) % m >= t[i - 1]) {
        t[i] = t[i - 1];
      }
    }
    else {
      if (t[i] + k >= t[i - 1]) t[i] = t[i - 1];
      else return 0;
    }
  }
  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int l = 0, r = m;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}