#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

multiset<int> f;

bool go(int x) {
  if (f.size()) {
    multiset<int>::iterator it = f.upper_bound(x);
    if (it != f.begin()) {
      --it;
      f.erase(it);
      return true;
    }
  }
  return false;
}

int main() {
  int n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    f.insert(x);
  }

  vector<int> t = {a, b, c};
  sort(t.begin(), t.end());
  a = t[0]; b = t[1]; c = t[2];

  int ans = 0;
  while (f.size()) {
    multiset<int>::iterator it = f.end(); --it;
    int cur = *it;
    if (cur > a + b + c) {
      puts("-1");
      return  0;
    }

    if (a >= cur) {
      go(a); go(b); go(c);
      ++ans;
    } else if (b >= cur) {
      go(b);
      if (!go(a)) go(a + c);
      else go(c);
      ++ans;
    } else if (c >= cur) {
      go(c);
      if (!go(a)) go(a + b);
      else go(b);
      ++ans;
    } else if (a + b >= cur) {
      f.erase(it); go(c);
      ++ans;
    } else if (a + c >= cur) {
      f.erase(it); go(b);
      ++ans;
    } else if (b + c >= cur) {
      f.erase(it); go(a);
      ++ans;
    } else {
      f.erase(it);
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}