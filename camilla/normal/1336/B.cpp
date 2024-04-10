#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int64 sqr(int64 x) {
  return x * x;
}

void check(int64& ret, int64 x, int64 y, int64 z) {
  //cout << x << " " << y << " " << z << endl;
  int64 cur = sqr(x - y) + sqr(y - z) + sqr(x - z);
  ret = min(ret, cur);
}

int64 solve(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
  int lenA = a.size(), lenB = b.size(), lenC = c.size();
  int64 ret = 3LL << 60;
  for (int i = 0; i < lenA; ++i) {
    int u = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    int v = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
    if (u < lenB && v < lenC) check(ret, a[i], b[u], c[v]);
    if (v - 1 >= 0 && u < lenB) check(ret, a[i], b[u], c[v - 1]);
    if (u - 1 >= 0 && v < lenC) check(ret, a[i], b[u - 1], c[v]);
    if (u - 1 >= 0 && v - 1 >= 0) check(ret, a[i], b[u - 1], c[v - 1]);
  }
  return ret;
}

int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int lenA, lenB, lenC;
    scanf("%d%d%d", &lenA, &lenB, &lenC);
    vector<int> a(lenA), b(lenB), c(lenC);
    for (int i = 0; i < lenA; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < lenB; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < lenC; ++i) scanf("%d", &c[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int64 ret = solve(a, b, c);
    ret = min(ret, solve(b, a, c));
    ret = min(ret, solve(c, a, b));
    
    printf("%lld\n", ret);
  }
  
  return 0;
}