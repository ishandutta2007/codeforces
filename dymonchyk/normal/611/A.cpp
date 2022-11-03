#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int d; char s[15] = {0};
  scanf("%d of %s\n", &d, s);
  
  int ans = 0;
  if (s[0] == 'w') {
    int cd = 5;
    for (int i = 0; i < 366; ++i) {
      if (cd == d) ++ans;
      cd = (cd) % 7 + 1;
    }
  } else {
    int f[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int x : f)
      ans += x >= d;
  }
  cout << ans << endl;
  return 0;
}