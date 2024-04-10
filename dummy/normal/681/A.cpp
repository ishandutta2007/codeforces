#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  bool ok = false;
  while(n--) {
    int bef, aft;
    scanf("%*s%d%d", &bef, &aft);
    if(bef >= 2400 && aft > bef)
      ok = true;
  }
  puts(ok ? "YES" : "NO");
  return 0;
}