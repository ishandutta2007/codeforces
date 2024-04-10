#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#include <map>
#define maxn 1000005

using namespace std;
typedef long long ll;

char s[maxn], t[maxn];
// len(t): m.
int T, n, m, same;
int calc() {
  int ans = 0;
  vector<int> d1(m);
  for (int i = 0, l = 0, r = -1; i < m; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
    while (0 <= i - k && i + k < m && t[i - k] == t[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  for (int i = 0; i < m; i++)
    if (d1[i] == i + 1) ans = max(ans, d1[i] * 2 - 1);
  vector<int> d2(m);
  for (int i = 0, l = 0, r = -1; i < m; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < m && t[i - k - 1] == t[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }
  for (int i = 1; i < m; i++) 
    if (d2[i] == i) ans = max(ans, i * 2);
  return ans;
}
void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  same = 0;
  while (same < n && s[same + 1] == s[n - same]) same++;
  if (same == n) {
    printf("%s\n", s + 1);
    return;
  }
  int ansf = 0, ansb = 0;
  m = 0;
  for (int i = same + 1; i <= n - same; i++) t[m++] = s[i];
  ansf = calc();
  m = 0;
  for (int i = n - same; i >= same + 1; i--) t[m++] = s[i];
  ansb = calc();
  if (ansf > ansb) {
    for (int i = 1; i <= same + ansf; i++) printf("%c", s[i]);
    for (int i = n - same + 1; i <= n; i++) printf("%c", s[i]);
  } else {
    for (int i = 1; i <= same; i++) printf("%c", s[i]);
    for (int i = n - same - ansb + 1; i <= n; i++) printf("%c", s[i]);
  }
  puts("");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}