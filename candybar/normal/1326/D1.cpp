#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#include <map>
#define maxn 100005

using namespace std;
typedef long long ll;

char s[maxn];
int t, n, same;
int calc1(int cen) {
  for (int i = 1; i <= n; i++) {
    if (cen - i <= same || cen + i > n - same || s[cen - i] != s[cen + i])
      return i * 2 - 1;
  }
}
int calc2(int cen) {
  for (int i = 0; i <= n; i++) {
    if (cen - i <= same || cen + i + 1 > n - same || s[cen - i] != s[cen + 1 + i])
      return i * 2;
  }
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
  for (int i = same + 1; i <= n / 2; i++) {
    if (calc1(i) == (i - same) * 2 - 1) ansf = max(ansf, calc1(i));
    if (calc2(i) == (i - same) * 2) ansf = max(ansf, calc2(i));
  }
  for (int i = n / 2 + 1; i <= n - same; i++) {
    if (calc1(i) == (n - same - i) * 2 + 1) ansb = max(ansb, calc1(i));
    if (calc2(i) == (n - same - i) * 2) ansb = max(ansb, calc2(i));
  }
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
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}