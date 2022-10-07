#include <bits/stdc++.h>

int ask(int x, int y);

const int M = 1e9;

int main() {
  int now1 = ask(1, 1), now2 = ask(M, 1);
  int l = 1, r = 1e9;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int nowm = ask(mid, 1);
    bool f1 = (mid - 1 == now1 - nowm);
    bool f2 = (M - mid == now2 - nowm);
    if (f1 == f2) {
      ans = nowm;
      break;
    } else if (f1) {
      l = mid + 1;
      ans = nowm;
    } else {
      r = mid - 1;
    }
  }
  int a = now1 - ans, b = now2 - ans;
  int now3 = ask(1, M), c = now3 - a;
  std::cout << "! " << a + 1 << ' ' << ans + 1 << ' ' << M - b << ' ' << M - c << std::endl;
  return 0;
}

int ask(int x, int y) {
  std::cout << "? " << x << ' ' << y << std::endl;
  int a;
  std::cin >> a;
  return a;
}