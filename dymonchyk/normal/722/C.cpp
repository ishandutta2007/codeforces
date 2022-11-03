#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100005], p[100005];
long long s[100005];

long long get(int l, int r) {
  if (l > r) return 0;
  return s[r] - (l > 0 ? s[l - 1] : 0);
}

multiset<long long> f, pos;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    if (i) s[i] = s[i - 1];
    s[i] += arr[i];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]); --p[i];
  }

  f.insert(get(0, n - 1));
  pos.insert(-1);
  pos.insert(n);

  for (int i = 0; i < n; ++i) {
    int R = *pos.upper_bound(p[i]);
    multiset<long long>::iterator it = pos.upper_bound(p[i]); --it;
    int L = *it;
    f.erase(f.find(get(L + 1, R - 1)));
    f.insert(get(L + 1, p[i] - 1));
    f.insert(get(p[i] + 1, R - 1));
    pos.insert(p[i]);

    it = f.end(); --it;
    printf("%lld\n", *it);
  }

  return 0;
}