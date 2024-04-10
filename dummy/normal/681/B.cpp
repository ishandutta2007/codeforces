#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int a = 1234567, b= 123456, c=1234;
  bool ans = false;
  while(n >= 0 && !ans) {
    int now = n;
    while(now >= 0 && !ans) {
      ans |= (now % c) == 0;
      now -= b;
    }
    n -= a;
  }
  puts(ans ? "YES" : "NO");
  return 0;
}