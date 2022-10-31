#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define F first
#define S second

using heap = __gnu_pbds::priority_queue<int>;

int n, a[100010];

pair<heap, int> v[100010];
int sz = 0;

long long solve() {
  for (int i = 0; i < n; ++i) {
    v[sz].F.push(a[i]);
    v[sz].S = 0;
    sz++;
    while (sz >= 2 && v[sz - 2].F.top() > v[sz - 1].F.top()) {
      v[sz - 2].F.join(v[sz - 1].F);
      v[sz - 2].S += v[sz - 1].S;
      sz--;
      while ((int)v[sz - 1].F.size() > v[sz - 1].S + 1) {
        v[sz - 1].F.pop();
        v[sz - 1].S++;
      }
    }
  }
  long long sum = 0;
  for (int i = 0, k = 0; i < sz; ++i) {
    int len = v[i].S + v[i].F.size();
    while (len--) {
      sum += llabs(v[i].F.top() - a[k++]);
    }
  }
  return sum;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }
  printf("%lld\n", solve());
  return 0;
}